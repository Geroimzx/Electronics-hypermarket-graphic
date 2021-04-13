#include "Multimedia.h"

Multimedia Multimedia::getMultimediaByID(int id)
{
    return multimediaList[id - 1];
}

int Multimedia::listSizeCheck()
{
	int i = 0;
	ifstream base("MultimediasList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Multimedia::viewProducts(string filePath, DataGridView^ dataGridView)
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
			multimediaList = new Multimedia[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				multimediaList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(multimediaList[i].ID,
					multimediaList[i].available,
					multimediaList[i].price,
					gcnew String(multimediaList[i].brand.c_str()),
					gcnew String(multimediaList[i].type.c_str())
				);
			}
		}
		file.close();
	}
}

void Multimedia::initProduct(std::ifstream& file)
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

bool Multimedia::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (multimediaList[id - 1].isAvailable() && multimediaList[id - 1].getAvailable() >= amount)
	{
		multimediaList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("MultimediasList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << multimediaList[i].ID << ' ';
			outFile << multimediaList[i].available << ' ';
			outFile << multimediaList[i].price << ' ';
			outFile << multimediaList[i].brand << ' ';
			outFile << multimediaList[i].type << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
