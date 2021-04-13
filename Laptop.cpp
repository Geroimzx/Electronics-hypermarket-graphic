#include "Laptop.h"

Laptop Laptop::getLaptopByID(int id)
{
    return laptopList[id - 1];
}

int Laptop::listSizeCheck()
{
	int i = 0;
	ifstream base("LaptopsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Laptop::viewProducts(string filePath, DataGridView^ dataGridView)
{
	ifstream file;
	file.open(filePath);
	if (!file) {
		cout << "Cannot open file" << endl;
	}
	else {
		listSizeCheck();
		laptopList = new Laptop[listSize];

		int rowSize = listSize;
		dataGridView->RowCount = rowSize;

		for (int i = 0; i < rowSize; i++)
		{
			laptopList[i].initProduct(file);
			dataGridView->Rows[i]->SetValues(laptopList[i].ID,
				laptopList[i].available,
				laptopList[i].price,
				gcnew String(laptopList[i].brand.c_str()),
				gcnew String(laptopList[i].type.c_str()),

				laptopList[i].displaySize,
				gcnew String(laptopList[i].displayType.c_str()),
				gcnew String(laptopList[i].resolution.c_str()),
				gcnew String(laptopList[i].chipset.c_str()),
				laptopList[i].coresCount,
				laptopList[i].RAM,
				gcnew String(laptopList[i].videocardSeries.c_str()),
				laptopList[i].storageMemory,
				gcnew String(laptopList[i].operatingSystem.c_str()),
				gcnew String(laptopList[i].color.c_str()),
				gcnew String(laptopList[i].weight.c_str())
			);
		}
	}
	file.close();
}

void Laptop::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> displaySize;
		file >> displayType;
		file >> resolution;
		file >> chipset;
		file >> coresCount;
		file >> RAM;
		file >> videocardSeries;
		file >> storageMemory;
		file >> operatingSystem;
		file >> color;
		file >> weight;
	}
}

bool Laptop::updateProductList(int id, int amount)
{
	if (laptopList[id - 1].isAvailable() && laptopList[id - 1].getAvailable() >= amount)
	{
		laptopList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("LaptopsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << laptopList[i].ID << ' ';
			outFile << laptopList[i].available << ' ';
			outFile << laptopList[i].price << ' ';
			outFile << laptopList[i].brand << ' ';
			outFile << laptopList[i].type << ' ';

			outFile << laptopList[i].displaySize << ' ';
			outFile << laptopList[i].displayType << ' ';
			outFile << laptopList[i].resolution << ' ';
			outFile << laptopList[i].chipset << ' ';
			outFile << laptopList[i].coresCount << ' ';
			outFile << laptopList[i].RAM << ' ';
			outFile << laptopList[i].videocardSeries << ' ';
			outFile << laptopList[i].storageMemory << ' ';
			outFile << laptopList[i].operatingSystem << ' ';
			outFile << laptopList[i].color << ' ';
			outFile << laptopList[i].weight << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
