#include "Accessories.h"

Accessories Accessories::getAccessoriesByID(int id)
{
    return accessoriesList[id - 1];
}

int Accessories::listSizeCheck()
{
	int i = 0;
	ifstream base("AccessoriesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Accessories::viewProducts(string filePath, DataGridView^ dataGridView)
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
			accessoriesList = new Accessories[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				accessoriesList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(accessoriesList[i].ID,
					accessoriesList[i].available,
					accessoriesList[i].price,
					gcnew String(accessoriesList[i].brand.c_str()),
					gcnew String(accessoriesList[i].type.c_str())
				);
			}
		}
		file.close();
	}
}

void Accessories::initProduct(std::ifstream& file)
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

bool Accessories::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (accessoriesList[id - 1].isAvailable() && accessoriesList[id - 1].getAvailable() >= amount)
	{
		accessoriesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("AccessoriesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << accessoriesList[i].ID << ' ';
			outFile << accessoriesList[i].available << ' ';
			outFile << accessoriesList[i].price << ' ';
			outFile << accessoriesList[i].brand << ' ';
			outFile << accessoriesList[i].type << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
