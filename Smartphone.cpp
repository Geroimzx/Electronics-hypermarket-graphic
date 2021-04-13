#include "Smartphone.h"

void Smartphone::viewProducts(string filePath, DataGridView^ dataGridView)
{
	ifstream file;
	file.open(filePath);
	if (!file) {
		cout << "Cannot open file" << endl;
	}else{
		listSizeCheck();
		smartphoneList = new Smartphone[listSize];

		int rowSize = listSize;
		dataGridView->RowCount = rowSize;

		for (int i = 0; i < rowSize; i++)
		{
			smartphoneList[i].initProduct(file);
			dataGridView->Rows[i]->SetValues(smartphoneList[i].ID,
				smartphoneList[i].available,
				smartphoneList[i].price,
				gcnew String(smartphoneList[i].brand.c_str()),
				gcnew String(smartphoneList[i].type.c_str()),

				smartphoneList[i].storageMemory,
				smartphoneList[i].RAM,
				gcnew String(smartphoneList[i].chipset.c_str()),
				gcnew String(smartphoneList[i].operatingSystem.c_str()),
				smartphoneList[i].displaySize,
				gcnew String(smartphoneList[i].displayType.c_str()),
				smartphoneList[i].mainCamera,
				smartphoneList[i].selfieCamera,
				gcnew String(smartphoneList[i].color.c_str()),
				smartphoneList[i].batteryCapacity,
				gcnew String(smartphoneList[i].features.c_str())
			);
		}
	}
	file.close();
}

void Smartphone::initProduct(std::ifstream& file)
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
		file >> chipset;
		file >> operatingSystem;
		file >> displaySize;
		file >> displayType;
		file >> mainCamera;
		file >> selfieCamera;
		file >> color;
		file >> batteryCapacity;
		file >> features;
	}
}

bool Smartphone::updateProductList(int id, int amount)
{
	if (smartphoneList[id - 1].isAvailable() && smartphoneList[id - 1].getAvailable() >= amount)
	{
		smartphoneList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("SmartphonesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << smartphoneList[i].ID << ' ';
			outFile << smartphoneList[i].available << ' ';
			outFile << smartphoneList[i].price << ' ';
			outFile << smartphoneList[i].brand << ' ';
			outFile << smartphoneList[i].type << ' ';
			outFile << smartphoneList[i].storageMemory << ' ';
			outFile << smartphoneList[i].RAM << ' ';
			outFile << smartphoneList[i].chipset << ' ';
			outFile << smartphoneList[i].operatingSystem << ' ';
			outFile << smartphoneList[i].displaySize << ' ';
			outFile << smartphoneList[i].displayType << ' ';
			outFile << smartphoneList[i].mainCamera << ' ';
			outFile << smartphoneList[i].selfieCamera << ' ';
			outFile << smartphoneList[i].color << ' ';
			outFile << smartphoneList[i].batteryCapacity << ' ';
			outFile << smartphoneList[i].features << '\n';
		}
		outFile.close();
		return true;
	}else{
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}

Smartphone Smartphone::getSmartphoneByID(int id)
{
	return smartphoneList[id-1];
}

int Smartphone::listSizeCheck()
{
	int i = 0;
	ifstream base("SmartphonesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}