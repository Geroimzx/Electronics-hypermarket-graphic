#include "EBook.h"

EBook EBook::getEBookByID(int id)
{
    return ebookList[id - 1];
}

int EBook::listSizeCheck()
{
	int i = 0;
	ifstream base("EBooksList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void EBook::viewProducts(string filePath, DataGridView^ dataGridView)
{
	if (listSizeCheck() > 0)
	{
		ifstream file;
		file.open(filePath);
		if (!file) {
			cout << "Cannot open file" << endl;
		}
		else {
			listSizeCheck();
			ebookList = new EBook[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				ebookList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(ebookList[i].ID,
					ebookList[i].available,
					ebookList[i].price,
					gcnew String(ebookList[i].brand.c_str()),
					gcnew String(ebookList[i].type.c_str()),

					gcnew String(ebookList[i].storageMemory.c_str()),
					gcnew String(ebookList[i].RAM.c_str()),
					gcnew String(ebookList[i].formatSupport.c_str()),
					gcnew String(ebookList[i].operatingSystem.c_str()),
					gcnew String(ebookList[i].displaySize.c_str()),
					gcnew String(ebookList[i].displayType.c_str()),
					gcnew String(ebookList[i].color.c_str()),
					gcnew String(ebookList[i].batteryCapacity.c_str())
				);
			}
		}
		file.close();
	}
}

void EBook::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> storageMemory;
		file >> RAM;
		file >> formatSupport;
		file >> operatingSystem;
		file >> displaySize;
		file >> displayType;
		file >> color;
		file >> batteryCapacity;
	}
}

bool EBook::updateProductList(int id, int amount)
{
	if (ebookList[id - 1].isAvailable() && ebookList[id - 1].getAvailable() >= amount)
	{
		ebookList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("EBooksList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << ebookList[i].ID << ' ';
			outFile << ebookList[i].available << ' ';
			outFile << ebookList[i].price << ' ';
			outFile << ebookList[i].brand << ' ';
			outFile << ebookList[i].type << ' ';
			outFile << ebookList[i].storageMemory << ' ';
			outFile << ebookList[i].RAM << ' ';
			outFile << ebookList[i].formatSupport << ' ';
			outFile << ebookList[i].operatingSystem << ' ';
			outFile << ebookList[i].displaySize << ' ';
			outFile << ebookList[i].displayType << ' ';
			outFile << ebookList[i].color << ' ';
			outFile << ebookList[i].batteryCapacity << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
