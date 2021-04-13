#include "Tablet.h"

Tablet Tablet::getTabletByID(int id)
{
    return tabletList[id - 1];
}

int Tablet::listSizeCheck()
{
	int i = 0;
	ifstream base("TabletsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Tablet::viewProducts(string filePath, DataGridView^ dataGridView)
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
			tabletList = new Tablet[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				tabletList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(tabletList[i].ID,
					tabletList[i].available,
					tabletList[i].price,
					gcnew String(tabletList[i].brand.c_str()),
					gcnew String(tabletList[i].type.c_str()),

					tabletList[i].storageMemory,
					tabletList[i].RAM,
					gcnew String(tabletList[i].chipset.c_str()),
					gcnew String(tabletList[i].operatingSystem.c_str()),
					tabletList[i].displaySize,
					gcnew String(tabletList[i].displayType.c_str()),
					tabletList[i].mainCamera,
					tabletList[i].selfieCamera,
					gcnew String(tabletList[i].color.c_str()),
					tabletList[i].batteryCapacity,
					gcnew String(tabletList[i].features.c_str())
				);
			}
		}
	}
}

void Tablet::initProduct(std::ifstream& file)
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

bool Tablet::updateProductList(int id, int amount)
{
	if (tabletList[id - 1].isAvailable() && tabletList[id - 1].getAvailable() >= amount)
	{
		tabletList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TabletsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << tabletList[i].ID << ' ';
			outFile << tabletList[i].available << ' ';
			outFile << tabletList[i].price << ' ';
			outFile << tabletList[i].brand << ' ';
			outFile << tabletList[i].type << ' ';
			outFile << tabletList[i].storageMemory << ' ';
			outFile << tabletList[i].RAM << ' ';
			outFile << tabletList[i].chipset << ' ';
			outFile << tabletList[i].operatingSystem << ' ';
			outFile << tabletList[i].displaySize << ' ';
			outFile << tabletList[i].displayType << ' ';
			outFile << tabletList[i].mainCamera << ' ';
			outFile << tabletList[i].selfieCamera << ' ';
			outFile << tabletList[i].color << ' ';
			outFile << tabletList[i].batteryCapacity << ' ';
			outFile << tabletList[i].features << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
