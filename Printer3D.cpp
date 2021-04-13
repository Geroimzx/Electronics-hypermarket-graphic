#include "Printer3D.h"

Printer3D Printer3D::getPrinter3DByID(int id)
{
    return printer3DList[id - 1];
}

int Printer3D::listSizeCheck()
{
	int i = 0;
	ifstream base("Printer3DList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Printer3D::viewProducts(string filePath, DataGridView^ dataGridView)
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
			printer3DList = new Printer3D[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				printer3DList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(printer3DList[i].ID,
					printer3DList[i].available,
					printer3DList[i].price,
					gcnew String(printer3DList[i].brand.c_str()),
					gcnew String(printer3DList[i].type.c_str()),

					gcnew String(printer3DList[i].technology.c_str()),
					gcnew String(printer3DList[i].material.c_str()),
					printer3DList[i].nozzlesCount,
					printer3DList[i].maxSpeed
				);
			}
		}
	}
}

void Printer3D::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> technology;
		file >> material;
		file >> nozzlesCount;
		file >> maxSpeed;
	}
}

bool Printer3D::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (printer3DList[id - 1].isAvailable() && printer3DList[id - 1].getAvailable() >= amount)
	{
		printer3DList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("Printer3DList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << printer3DList[i].ID << ' ';
			outFile << printer3DList[i].available << ' ';
			outFile << printer3DList[i].price << ' ';
			outFile << printer3DList[i].brand << ' ';
			outFile << printer3DList[i].type << ' ';

			outFile << printer3DList[i].technology << ' ';
			outFile << printer3DList[i].material << ' ';
			outFile << printer3DList[i].nozzlesCount << ' ';
			outFile << printer3DList[i].maxSpeed << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
