#include "Printer.h"

Printer Printer::getPrinterByID(int id)
{
    return printerList[id - 1];
}

int Printer::listSizeCheck()
{
	int i = 0;
	ifstream base("PrintersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Printer::viewProducts(string filePath, DataGridView^ dataGridView)
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
			printerList = new Printer[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				printerList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(printerList[i].ID,
					printerList[i].available,
					printerList[i].price,
					gcnew String(printerList[i].brand.c_str()),
					gcnew String(printerList[i].type.c_str()),

					gcnew String(printerList[i].printingTechnology.c_str()),
					gcnew String(printerList[i].paperFormat.c_str()),
					gcnew String(printerList[i].printingColor.c_str())
				);
			}
		}
		file.close();
	}
}

void Printer::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> printingTechnology;
		file >> paperFormat;
		file >> printingColor;
	}
}

bool Printer::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (printerList[id - 1].isAvailable() && printerList[id - 1].getAvailable() >= amount)
	{
		printerList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PrintersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << printerList[i].ID << ' ';
			outFile << printerList[i].available << ' ';
			outFile << printerList[i].price << ' ';
			outFile << printerList[i].brand << ' ';
			outFile << printerList[i].type << ' ';

			outFile << printerList[i].printingTechnology << ' ';
			outFile << printerList[i].paperFormat << ' ';
			outFile << printerList[i].printingColor << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
