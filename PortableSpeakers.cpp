#include "PortableSpeakers.h"

int PortableSpeakers::getOutputPower()
{
    return outputPower;
}

int PortableSpeakers::getBateryLife()
{
    return batteryLife;
}

PortableSpeakers PortableSpeakers::getPortableSpeakersByID(int id)
{
    return portableSpeakersList[id-1];
}

int PortableSpeakers::listSizeCheck()
{
	int i = 0;
	ifstream base("PortableSpeakersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void PortableSpeakers::viewProducts(string filePath, DataGridView^ dataGridView)
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
			portableSpeakersList = new PortableSpeakers[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				portableSpeakersList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(portableSpeakersList[i].ID,
					portableSpeakersList[i].available,
					portableSpeakersList[i].price,
					gcnew String(portableSpeakersList[i].brand.c_str()),
					gcnew String(portableSpeakersList[i].type.c_str()),

					portableSpeakersList[i].outputPower,
					portableSpeakersList[i].batteryLife
				);
			}
		}
		file.close();
	}
}

void PortableSpeakers::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> outputPower;
		file >> batteryLife;
	}
}

bool PortableSpeakers::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (portableSpeakersList[id - 1].isAvailable() && portableSpeakersList[id - 1].getAvailable() >= amount)
	{
		portableSpeakersList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PortableSpeakersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << portableSpeakersList[i].ID << ' ';
			outFile << portableSpeakersList[i].available << ' ';
			outFile << portableSpeakersList[i].price << ' ';
			outFile << portableSpeakersList[i].brand << ' ';
			outFile << portableSpeakersList[i].type << ' ';
			outFile << portableSpeakersList[i].outputPower << ' ';
			outFile << portableSpeakersList[i].batteryLife << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
