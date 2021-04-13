#include "Telephone.h"

Telephone Telephone::getTelephoneByID(int id)
{
	return telephoneList[id - 1];
}

int Telephone::listSizeCheck()
{
	int i = 0;
	ifstream base("TelephoneList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Telephone::viewProducts(string filePath, DataGridView^ dataGridView)
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
			telephoneList = new Telephone[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				telephoneList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(telephoneList[i].ID,
					telephoneList[i].available,
					telephoneList[i].price,
					gcnew String(telephoneList[i].brand.c_str()),
					gcnew String(telephoneList[i].type.c_str())
				);
			}
		}
		file.close();
	}
}

bool Telephone::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (amount > 0 && telephoneList[id - 1].isAvailable() && telephoneList[id - 1].getAvailable() >= amount)
	{
		telephoneList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TelephoneList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << telephoneList[i].ID << ' ';
			outFile << telephoneList[i].available << ' ';
			outFile << telephoneList[i].price << ' ';
			outFile << telephoneList[i].brand << ' ';
			outFile << telephoneList[i].type << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
