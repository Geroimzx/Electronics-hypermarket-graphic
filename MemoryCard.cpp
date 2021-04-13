#include "MemoryCard.h"

int MemoryCard::getStorageMemory()
{
    return storageMemory;
}

string MemoryCard::getSpeedClass()
{
    return speedClass;
}

MemoryCard MemoryCard::getMemoryCardByID(int id)
{
    return memoryCardList[id - 1];
}

int MemoryCard::listSizeCheck()
{
	int i = 0;
	ifstream base("MemoryCardList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void MemoryCard::viewProducts(string filePath, DataGridView^ dataGridView)
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
			memoryCardList = new MemoryCard[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				memoryCardList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(memoryCardList[i].ID,
					memoryCardList[i].available,
					memoryCardList[i].price,
					gcnew String(memoryCardList[i].brand.c_str()),
					gcnew String(memoryCardList[i].type.c_str()),

					memoryCardList[i].storageMemory,
					gcnew String(memoryCardList[i].speedClass.c_str())
				);
			}
		}
		file.close();
	}
}

void MemoryCard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> storageMemory;
		file >> speedClass;
	}
}

bool MemoryCard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (memoryCardList[id - 1].isAvailable() && memoryCardList[id - 1].getAvailable() >= amount)
	{
		memoryCardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("MemoryCardList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << memoryCardList[i].ID << ' ';
			outFile << memoryCardList[i].available << ' ';
			outFile << memoryCardList[i].price << ' ';
			outFile << memoryCardList[i].brand << ' ';
			outFile << memoryCardList[i].type << ' ';
			outFile << memoryCardList[i].storageMemory << ' ';
			outFile << memoryCardList[i].speedClass << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
