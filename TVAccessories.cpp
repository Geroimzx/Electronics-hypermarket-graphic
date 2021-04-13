#include "TVAccessories.h"

TVAccessories TVAccessories::getTVAccessoriesByID(int id)
{
    return tvAccessoriesList[id - 1];
}

int TVAccessories::listSizeCheck()
{
	int i = 0;
	ifstream base("TVAccessoriesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void TVAccessories::viewProducts(string filePath, DataGridView^ dataGridView)
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
			tvAccessoriesList = new TVAccessories[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				tvAccessoriesList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(tvAccessoriesList[i].ID,
					tvAccessoriesList[i].available,
					tvAccessoriesList[i].price,
					gcnew String(tvAccessoriesList[i].brand.c_str()),
					gcnew String(tvAccessoriesList[i].type.c_str())
				);
			}
		}
		file.close();
	}
}

void TVAccessories::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
	}
}

bool TVAccessories::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (tvAccessoriesList[id - 1].isAvailable() && tvAccessoriesList[id - 1].getAvailable() >= amount)
	{
		tvAccessoriesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("TVAccessoriesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << tvAccessoriesList[i].ID << ' ';
			outFile << tvAccessoriesList[i].available << ' ';
			outFile << tvAccessoriesList[i].price << ' ';
			outFile << tvAccessoriesList[i].brand << ' ';
			outFile << tvAccessoriesList[i].type << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
