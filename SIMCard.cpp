#include "SIMCard.h"

string SIMCard::getVipNumber()
{
    return vipNumber;
}

SIMCard SIMCard::getSIMCardByID(int id)
{
    return simCardList[id - 1];
}

int SIMCard::listSizeCheck()
{
	int i = 0;
	ifstream base("SIMCardList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void SIMCard::viewProducts(string filePath, DataGridView^ dataGridView)
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
			simCardList = new SIMCard[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				simCardList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(simCardList[i].ID,
					simCardList[i].available,
					simCardList[i].price,
					gcnew String(simCardList[i].brand.c_str()),
					gcnew String(simCardList[i].type.c_str()),

					gcnew String(simCardList[i].vipNumber.c_str())
				);
			}
		}
		file.close();
	}
}

void SIMCard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> vipNumber;
	}
}

bool SIMCard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (simCardList[id - 1].isAvailable() && simCardList[id - 1].getAvailable() >= amount)
	{
		simCardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("SIMCardList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << simCardList[i].ID << ' ';
			outFile << simCardList[i].available << ' ';
			outFile << simCardList[i].price << ' ';
			outFile << simCardList[i].brand << ' ';
			outFile << simCardList[i].type << ' ';
			outFile << simCardList[i].vipNumber << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
