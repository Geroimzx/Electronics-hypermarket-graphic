#include "SmartWatches.h"

SmartWatches SmartWatches::getSmartWatchesByID(int id)
{
    return smartWatchesList[id - 1];
}

int SmartWatches::listSizeCheck()
{
	int i = 0;
	ifstream base("SmartWatchesList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void SmartWatches::viewProducts(string filePath, DataGridView^ dataGridView)
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
			smartWatchesList = new SmartWatches[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				smartWatchesList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(smartWatchesList[i].ID,
					smartWatchesList[i].available,
					smartWatchesList[i].price,
					gcnew String(smartWatchesList[i].brand.c_str()),
					gcnew String(smartWatchesList[i].type.c_str()),

					gcnew String(smartWatchesList[i].appointment.c_str()),
					gcnew String(smartWatchesList[i].displayForm.c_str()),
					gcnew String(smartWatchesList[i].displaySize.c_str()),
					gcnew String(smartWatchesList[i].material.c_str()),
					gcnew String(smartWatchesList[i].workTime.c_str())
				);
			}
		}
		file.close();
	}
}

void SmartWatches::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> appointment;
		file >> displayForm;
		file >> displaySize;
		file >> material;
		file >> workTime;
	}
}

bool SmartWatches::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (smartWatchesList[id - 1].isAvailable() && smartWatchesList[id - 1].getAvailable() >= amount)
	{
		smartWatchesList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("SmartWatchesList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << smartWatchesList[i].ID << ' ';
			outFile << smartWatchesList[i].available << ' ';
			outFile << smartWatchesList[i].price << ' ';
			outFile << smartWatchesList[i].brand << ' ';
			outFile << smartWatchesList[i].type << ' ';

			outFile << smartWatchesList[i].appointment << ' ';
			outFile << smartWatchesList[i].displayForm << ' ';
			outFile << smartWatchesList[i].displaySize << ' ';
			outFile << smartWatchesList[i].material << ' ';
			outFile << smartWatchesList[i].workTime << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
