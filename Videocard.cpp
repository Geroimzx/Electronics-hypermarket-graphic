#include "Videocard.h"

Videocard Videocard::getVideocardByID(int id)
{
    return videocardList[id - 1];
}

int Videocard::listSizeCheck()
{
	int i = 0;
	ifstream base("VideocardsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Videocard::viewProducts(string filePath, DataGridView^ dataGridView)
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
			videocardList = new Videocard[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				videocardList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(videocardList[i].ID,
					videocardList[i].available,
					videocardList[i].price,
					gcnew String(videocardList[i].brand.c_str()),
					gcnew String(videocardList[i].type.c_str()),

					gcnew String(videocardList[i].chipmaker.c_str()),
					gcnew String(videocardList[i].chipSerie.c_str()),
					videocardList[i].videoMemory,
					gcnew String(videocardList[i].memoryType.c_str())
				);
			}
		}
		file.close();
	}
}

void Videocard::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> chipmaker;
		file >> chipSerie;
		file >> videoMemory;
		file >> memoryType;
	}
}

bool Videocard::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (videocardList[id - 1].isAvailable() && videocardList[id - 1].getAvailable() >= amount)
	{
		videocardList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("VideocardsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << videocardList[i].ID << ' ';
			outFile << videocardList[i].available << ' ';
			outFile << videocardList[i].price << ' ';
			outFile << videocardList[i].brand << ' ';
			outFile << videocardList[i].type << ' ';

			outFile << videocardList[i].chipmaker << ' ';
			outFile << videocardList[i].chipSerie << ' ';
			outFile << videocardList[i].videoMemory << ' ';
			outFile << videocardList[i].memoryType << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
