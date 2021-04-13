#include "Television.h"

Television Television::getTVByID(int id)
{
    return televisionList[id - 1];
}

int Television::listSizeCheck()
{
	int i = 0;
	ifstream base("TVsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Television::viewProducts(string filePath, DataGridView^ dataGridView)
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
			televisionList = new Television[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				televisionList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(televisionList[i].ID,
					televisionList[i].available,
					televisionList[i].price,
					gcnew String(televisionList[i].brand.c_str()),
					gcnew String(televisionList[i].type.c_str()),

					televisionList[i].diagonal,
					gcnew String(televisionList[i].resolution.c_str()),
					gcnew String(televisionList[i].technology.c_str()),
					gcnew String(televisionList[i].operatingSystem.c_str())
				);
			}
		}
		file.close();
	}
}

void Television::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> diagonal;
		file >> resolution;
		file >> technology;
		file >> operatingSystem;
	}
}

bool Television::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (televisionList[id - 1].isAvailable() && televisionList[id - 1].getAvailable() >= amount)
	{
		televisionList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TVsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << televisionList[i].ID << ' ';
			outFile << televisionList[i].available << ' ';
			outFile << televisionList[i].price << ' ';
			outFile << televisionList[i].brand << ' ';
			outFile << televisionList[i].type << ' ';

			outFile << televisionList[i].diagonal << ' ';
			outFile << televisionList[i].resolution << ' ';
			outFile << televisionList[i].technology << ' ';
			outFile << televisionList[i].operatingSystem << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
