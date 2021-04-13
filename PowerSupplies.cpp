#include "PowerSupplies.h"

PowerSupplies PowerSupplies::getPowerSuppliesByID(int id)
{
    return powerSuppliesList[id - 1];
}

int PowerSupplies::listSizeCheck()
{
	int i = 0;
	ifstream base("PowerSuppliesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void PowerSupplies::viewProducts(string filePath, DataGridView^ dataGridView)
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
			powerSuppliesList = new PowerSupplies[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				powerSuppliesList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(powerSuppliesList[i].ID,
					powerSuppliesList[i].available,
					powerSuppliesList[i].price,
					gcnew String(powerSuppliesList[i].brand.c_str()),
					gcnew String(powerSuppliesList[i].type.c_str()),

					gcnew String(powerSuppliesList[i].formFactor.c_str()),
					powerSuppliesList[i].outPower
				);
			}
		}
		file.close();
	}
}

void PowerSupplies::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> formFactor;
		file >> outPower;
	}
}

bool PowerSupplies::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (powerSuppliesList[id - 1].isAvailable() && powerSuppliesList[id - 1].getAvailable() >= amount)
	{
		powerSuppliesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PowerSuppliesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << powerSuppliesList[i].ID << ' ';
			outFile << powerSuppliesList[i].available << ' ';
			outFile << powerSuppliesList[i].price << ' ';
			outFile << powerSuppliesList[i].brand << ' ';
			outFile << powerSuppliesList[i].type << ' ';

			outFile << powerSuppliesList[i].formFactor << ' ';
			outFile << powerSuppliesList[i].outPower << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
