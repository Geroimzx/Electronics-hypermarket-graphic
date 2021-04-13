#include "Cover.h"

string Cover::getCompatible()
{
    return compatible;
}

string Cover::getColor()
{
    return color;
}

Cover Cover::getCoverByID(int id)
{
    return сoverList[id - 1];
}

int Cover::listSizeCheck()
{
	int i = 0;
	ifstream base("CoverList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Cover::viewProducts(string filePath, DataGridView^ dataGridView)
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
			сoverList = new Cover[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				сoverList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(сoverList[i].ID,
					сoverList[i].available,
					сoverList[i].price,
					gcnew String(сoverList[i].brand.c_str()),
					gcnew String(сoverList[i].type.c_str()),

					gcnew String(сoverList[i].compatible.c_str()),
					gcnew String(сoverList[i].color.c_str())
				);
			}
		}
		file.close();
	}
}

void Cover::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> compatible;
		file >> color;
	}
}

bool Cover::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (сoverList[id - 1].isAvailable() && сoverList[id - 1].getAvailable() >= amount)
	{
		сoverList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("CoverList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << сoverList[i].ID << ' ';
			outFile << сoverList[i].available << ' ';
			outFile << сoverList[i].price << ' ';
			outFile << сoverList[i].brand << ' ';
			outFile << сoverList[i].type << ' ';
			outFile << сoverList[i].compatible << ' ';
			outFile << сoverList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
