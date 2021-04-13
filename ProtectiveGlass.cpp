#include "ProtectiveGlass.h"

string ProtectiveGlass::getCompatible()
{
    return compatible;
}

string ProtectiveGlass::getCoatingType()
{
    return coatingType;
}

ProtectiveGlass ProtectiveGlass::getProtectiveGlassByID(int id)
{
    return protectiveGlassList[id - 1];
}

int ProtectiveGlass::listSizeCheck()
{
	int i = 0;
	ifstream base("ProtectiveGlassList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void ProtectiveGlass::viewProducts(string filePath, DataGridView^ dataGridView)
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
			protectiveGlassList = new ProtectiveGlass[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				protectiveGlassList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(protectiveGlassList[i].ID,
					protectiveGlassList[i].available,
					protectiveGlassList[i].price,
					gcnew String(protectiveGlassList[i].brand.c_str()),
					gcnew String(protectiveGlassList[i].type.c_str()),

					gcnew String(protectiveGlassList[i].compatible.c_str()),
					gcnew String(protectiveGlassList[i].coatingType.c_str())
				);
			}
		}
		file.close();
	}
}

void ProtectiveGlass::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> compatible;
		file >> coatingType;
	}
}

bool ProtectiveGlass::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (protectiveGlassList[id - 1].isAvailable() && protectiveGlassList[id - 1].getAvailable() >= amount)
	{
		protectiveGlassList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("ProtectiveGlassList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << protectiveGlassList[i].ID << ' ';
			outFile << protectiveGlassList[i].available << ' ';
			outFile << protectiveGlassList[i].price << ' ';
			outFile << protectiveGlassList[i].brand << ' ';
			outFile << protectiveGlassList[i].type << ' ';
			outFile << protectiveGlassList[i].compatible << ' ';
			outFile << protectiveGlassList[i].coatingType << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
