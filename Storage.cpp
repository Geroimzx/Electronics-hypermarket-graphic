#include "Storage.h"

Storage Storage::getStorageByID(int id)
{
    return storageList[id - 1];
}

int Storage::listSizeCheck()
{
	int i = 0;
	ifstream base("StoragesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Storage::viewProducts(string filePath, DataGridView^ dataGridView)
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
			storageList = new Storage[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				storageList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(storageList[i].ID,
					storageList[i].available,
					storageList[i].price,
					gcnew String(storageList[i].brand.c_str()),
					gcnew String(storageList[i].type.c_str()),

					storageList[i].memoryCapacity,
					gcnew String(storageList[i].formFactor.c_str()),
					gcnew String(storageList[i].connectionInterface.c_str())
				);
			}
		}
		file.close();
	}
}

void Storage::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> memoryCapacity;
		file >> formFactor;
		file >> connectionInterface;
	}
}

bool Storage::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (storageList[id - 1].isAvailable() && storageList[id - 1].getAvailable() >= amount)
	{
		storageList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("StoragesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << storageList[i].ID << ' ';
			outFile << storageList[i].available << ' ';
			outFile << storageList[i].price << ' ';
			outFile << storageList[i].brand << ' ';
			outFile << storageList[i].type << ' ';

			outFile << storageList[i].memoryCapacity << ' ';
			outFile << storageList[i].formFactor << ' ';
			outFile << storageList[i].connectionInterface << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
