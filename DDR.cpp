#include "DDR.h"

DDR DDR::getDDRByID(int id)
{
    return ddrList[id - 1];
}

int DDR::listSizeCheck()
{
	int i = 0;
	ifstream base("DDRsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void DDR::viewProducts(string filePath, DataGridView^ dataGridView)
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
			ddrList = new DDR[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				ddrList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(ddrList[i].ID,
					ddrList[i].available,
					ddrList[i].price,
					gcnew String(ddrList[i].brand.c_str()),
					gcnew String(ddrList[i].type.c_str()),

					ddrList[i].modulesCount,
					ddrList[i].memoryCapacity,
					ddrList[i].frequency,
					gcnew String(ddrList[i].timings.c_str())
				);
			}
		}
		file.close();
	}
}

void DDR::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> modulesCount;
		file >> memoryCapacity;
		file >> frequency;
		file >> timings;
	}
}

bool DDR::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (ddrList[id - 1].isAvailable() && ddrList[id - 1].getAvailable() >= amount)
	{
		ddrList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("DDRsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << ddrList[i].ID << ' ';
			outFile << ddrList[i].available << ' ';
			outFile << ddrList[i].price << ' ';
			outFile << ddrList[i].brand << ' ';
			outFile << ddrList[i].type << ' ';

			outFile << ddrList[i].modulesCount << ' ';
			outFile << ddrList[i].memoryCapacity << ' ';
			outFile << ddrList[i].frequency << ' ';
			outFile << ddrList[i].timings << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
