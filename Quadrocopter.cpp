#include "Quadrocopter.h"

Quadrocopter Quadrocopter::getQuadrocopterByID(int id)
{
    return quadrocopterList[id - 1];
}

int Quadrocopter::listSizeCheck()
{
	int i = 0;
	ifstream base("QuadrocoptersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Quadrocopter::viewProducts(string filePath, DataGridView^ dataGridView)
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
			quadrocopterList = new Quadrocopter[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				quadrocopterList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(quadrocopterList[i].ID,
					quadrocopterList[i].available,
					quadrocopterList[i].price,
					gcnew String(quadrocopterList[i].brand.c_str()),
					gcnew String(quadrocopterList[i].type.c_str()),

					gcnew String(quadrocopterList[i].camera.c_str()),
					quadrocopterList[i].flyTime,
					quadrocopterList[i].maxDistance,
					quadrocopterList[i].frequency
				);
			}
		}
		file.close();
	}
}

void Quadrocopter::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> camera;
		file >> flyTime;
		file >> maxDistance;
		file >> frequency;
	}
}

bool Quadrocopter::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (quadrocopterList[id - 1].isAvailable() && quadrocopterList[id - 1].getAvailable() >= amount)
	{
		quadrocopterList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("QuadrocoptersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << quadrocopterList[i].ID << ' ';
			outFile << quadrocopterList[i].available << ' ';
			outFile << quadrocopterList[i].price << ' ';
			outFile << quadrocopterList[i].brand << ' ';
			outFile << quadrocopterList[i].type << ' ';

			outFile << quadrocopterList[i].camera << ' ';
			outFile << quadrocopterList[i].flyTime << ' ';
			outFile << quadrocopterList[i].maxDistance << ' ';
			outFile << quadrocopterList[i].frequency << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
