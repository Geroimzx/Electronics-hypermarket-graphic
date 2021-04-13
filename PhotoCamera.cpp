#include "PhotoCamera.h"

PhotoCamera PhotoCamera::getPhotoCameraByID(int id)
{
    return photoCameraList[id - 1];
}

int PhotoCamera::listSizeCheck()
{
	int i = 0;
	ifstream base("PhotoCamerasList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void PhotoCamera::viewProducts(string filePath, DataGridView^ dataGridView)
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
			photoCameraList = new PhotoCamera[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				photoCameraList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(photoCameraList[i].ID,
					photoCameraList[i].available,
					photoCameraList[i].price,
					gcnew String(photoCameraList[i].brand.c_str()),
					gcnew String(photoCameraList[i].type.c_str()),

					gcnew String(photoCameraList[i].resolution.c_str()),
					gcnew String(photoCameraList[i].sizeMatrix.c_str()),
					gcnew String(photoCameraList[i].opticZoom.c_str()),
					gcnew String(photoCameraList[i].powerType.c_str()),
					gcnew String(photoCameraList[i].color.c_str())
				);
			}
		}
		file.close();
	}
}

void PhotoCamera::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> resolution;
		file >> sizeMatrix;
		file >> opticZoom;
		file >> powerType;
		file >> color;
	}
}

bool PhotoCamera::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (photoCameraList[id - 1].isAvailable() && photoCameraList[id - 1].getAvailable() >= amount)
	{
		photoCameraList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PhotoCamerasList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << photoCameraList[i].ID << ' ';
			outFile << photoCameraList[i].available << ' ';
			outFile << photoCameraList[i].price << ' ';
			outFile << photoCameraList[i].brand << ' ';
			outFile << photoCameraList[i].type << ' ';

			outFile << photoCameraList[i].resolution << ' ';
			outFile << photoCameraList[i].sizeMatrix << ' ';
			outFile << photoCameraList[i].opticZoom << ' ';
			outFile << photoCameraList[i].powerType << ' ';
			outFile << photoCameraList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
