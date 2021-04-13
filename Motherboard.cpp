#include "Motherboard.h"

Motherboard Motherboard::getMotherboardByID(int id)
{
    return motherboardList[id - 1];
}

int Motherboard::listSizeCheck()
{
	int i = 0;
	ifstream base("MotherboardsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Motherboard::viewProducts(string filePath, DataGridView^ dataGridView)
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
			motherboardList = new Motherboard[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				motherboardList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(motherboardList[i].ID,
					motherboardList[i].available,
					motherboardList[i].price,
					gcnew String(motherboardList[i].brand.c_str()),
					gcnew String(motherboardList[i].type.c_str()),

					gcnew String(motherboardList[i].socket.c_str()),
					gcnew String(motherboardList[i].RAMType.c_str()),
					gcnew String(motherboardList[i].formFactor.c_str())
				);
			}
		}
		file.close();
	}
}

void Motherboard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> socket;
		file >> RAMType;
		file >> formFactor;
	}
}

bool Motherboard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (motherboardList[id - 1].isAvailable() && motherboardList[id - 1].getAvailable() >= amount)
	{
		motherboardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("MotherboardsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << motherboardList[i].ID << ' ';
			outFile << motherboardList[i].available << ' ';
			outFile << motherboardList[i].price << ' ';
			outFile << motherboardList[i].brand << ' ';
			outFile << motherboardList[i].type << ' ';

			outFile << motherboardList[i].socket << ' ';
			outFile << motherboardList[i].RAMType << ' ';
			outFile << motherboardList[i].formFactor << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
