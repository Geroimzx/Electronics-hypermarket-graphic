#include "Headphone.h"

string Headphone::getConnectorType()
{
	return connectorType;
}

string Headphone::getNoiseReduction()
{
	return noiseReduction;
}

string Headphone::getColor()
{
	return color;
}

Headphone Headphone::getHeadphoneByID(int id)
{
    return  headphoneList[id - 1];
}

int Headphone::listSizeCheck()
{
	int i = 0;
	ifstream base("HeadphoneList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void Headphone::viewProducts(string filePath, DataGridView^ dataGridView)
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
			headphoneList = new Headphone[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				headphoneList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(headphoneList[i].ID,
					headphoneList[i].available,
					headphoneList[i].price,
					gcnew String(headphoneList[i].brand.c_str()),
					gcnew String(headphoneList[i].type.c_str()),

					gcnew String(headphoneList[i].connectorType.c_str()),
					gcnew String(headphoneList[i].noiseReduction.c_str()),
					gcnew String(headphoneList[i].color.c_str())
				);
			}
		}
		file.close();
	}
}

void Headphone::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> connectorType;
		file >> noiseReduction;
		file >> color;
	}
}

bool Headphone::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (headphoneList[id - 1].isAvailable() && headphoneList[id - 1].getAvailable() >= amount)
	{
		headphoneList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("HeadphoneList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << headphoneList[i].ID << ' ';
			outFile << headphoneList[i].available << ' ';
			outFile << headphoneList[i].price << ' ';
			outFile << headphoneList[i].brand << ' ';
			outFile << headphoneList[i].type << ' ';
			outFile << headphoneList[i].connectorType << ' ';
			outFile << headphoneList[i].noiseReduction << ' ';
			outFile << headphoneList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
