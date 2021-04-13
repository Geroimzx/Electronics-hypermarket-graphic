#include "Projectors.h"

Projectors Projectors::getProjectorByID(int id)
{
    return projectorsList[id - 1];
}

int Projectors::listSizeCheck()
{
	int i = 0;
	ifstream base("ProjectorsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Projectors::viewProducts(string filePath, DataGridView^ dataGridView)
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
			projectorsList = new Projectors[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				projectorsList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(projectorsList[i].ID,
					projectorsList[i].available,
					projectorsList[i].price,
					gcnew String(projectorsList[i].brand.c_str()),
					gcnew String(projectorsList[i].type.c_str()),

					gcnew String(projectorsList[i].resolution.c_str()),
					gcnew String(projectorsList[i].connectionInterface.c_str())
				);
			}
		}
		file.close();
	}
}

void Projectors::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> resolution;
		file >> connectionInterface;
	}
}

bool Projectors::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (projectorsList[id - 1].isAvailable() && projectorsList[id - 1].getAvailable() >= amount)
	{
		projectorsList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("ProjectorsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << projectorsList[i].ID << ' ';
			outFile << projectorsList[i].available << ' ';
			outFile << projectorsList[i].price << ' ';
			outFile << projectorsList[i].brand << ' ';
			outFile << projectorsList[i].type << ' ';

			outFile << projectorsList[i].resolution << ' ';
			outFile << projectorsList[i].connectionInterface << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
