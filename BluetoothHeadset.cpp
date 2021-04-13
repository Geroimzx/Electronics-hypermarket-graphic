#include "BluetoothHeadset.h"

string BluetoothHeadset::getBluetoothVersion()
{
    return bluetoothVersion;
}

BluetoothHeadset BluetoothHeadset::getBluetoothHeadsetByID(int id)
{
    return bluetoothHeadsetList[id - 1];
}

int BluetoothHeadset::listSizeCheck()
{
	int i = 0;
	ifstream base("BluetoothHeadsetList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void BluetoothHeadset::viewProducts(string filePath, DataGridView^ dataGridView)
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
			bluetoothHeadsetList = new BluetoothHeadset[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				bluetoothHeadsetList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(bluetoothHeadsetList[i].ID,
					bluetoothHeadsetList[i].available,
					bluetoothHeadsetList[i].price,
					gcnew String(bluetoothHeadsetList[i].brand.c_str()),
					gcnew String(bluetoothHeadsetList[i].type.c_str()),

					gcnew String(bluetoothHeadsetList[i].bluetoothVersion.c_str())
				);
			}
		}
		file.close();
	}
}

void BluetoothHeadset::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> bluetoothVersion;
	}
}

bool BluetoothHeadset::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (bluetoothHeadsetList[id - 1].isAvailable() && bluetoothHeadsetList[id - 1].getAvailable() >= amount)
	{
		bluetoothHeadsetList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("BluetoothHeadsetList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << bluetoothHeadsetList[i].ID << ' ';
			outFile << bluetoothHeadsetList[i].available << ' ';
			outFile << bluetoothHeadsetList[i].price << ' ';
			outFile << bluetoothHeadsetList[i].brand << ' ';
			outFile << bluetoothHeadsetList[i].type << ' ';
			outFile << bluetoothHeadsetList[i].bluetoothVersion << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
