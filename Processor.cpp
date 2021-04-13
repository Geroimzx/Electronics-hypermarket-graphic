#include "Processor.h"

Processor Processor::getProcessorByID(int id)
{
	return processorList[id - 1];
}

int Processor::listSizeCheck()
{
	int i = 0;
	ifstream base("ProcessorsList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Processor::viewProducts(string filePath, DataGridView^ dataGridView)
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
			processorList = new Processor[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				processorList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(processorList[i].ID,
					processorList[i].available,
					processorList[i].price,
					gcnew String(processorList[i].brand.c_str()),
					gcnew String(processorList[i].type.c_str()),

					gcnew String(processorList[i].chipSerie.c_str()),
					gcnew String(processorList[i].socket.c_str()),
					processorList[i].coresCount,
					processorList[i].frequency
				);
			}
		}
		file.close();
	}
}

void Processor::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> chipSerie;
		file >> socket;
		file >> coresCount;
		file >> frequency;
	}
}

bool Processor::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (processorList[id - 1].isAvailable() && processorList[id - 1].getAvailable() >= amount)
	{
		processorList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("ProcessorsList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << processorList[i].ID << ' ';
			outFile << processorList[i].available << ' ';
			outFile << processorList[i].price << ' ';
			outFile << processorList[i].brand << ' ';
			outFile << processorList[i].type << ' ';

			outFile << processorList[i].chipSerie << ' ';
			outFile << processorList[i].socket << ' ';
			outFile << processorList[i].coresCount << ' ';
			outFile << processorList[i].frequency << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
