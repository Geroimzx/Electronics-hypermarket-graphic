#include "VideoCamera.h"

VideoCamera VideoCamera::getVideoCameraByID(int id)
{
    return videoCameraList[id - 1];
}

int VideoCamera::listSizeCheck()
{
	int i = 0;
	ifstream base("VideoCamerasList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void VideoCamera::viewProducts(string filePath, DataGridView^ dataGridView)
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
			videoCameraList = new VideoCamera[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				videoCameraList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(videoCameraList[i].ID,
					videoCameraList[i].available,
					videoCameraList[i].price,
					gcnew String(videoCameraList[i].brand.c_str()),
					gcnew String(videoCameraList[i].type.c_str()),

					gcnew String(videoCameraList[i].matrixType.c_str()),
					gcnew String(videoCameraList[i].stabilization.c_str()),
					gcnew String(videoCameraList[i].resolution.c_str()),
					gcnew String(videoCameraList[i].opticZoom.c_str()),
					gcnew String(videoCameraList[i].sensorScreen.c_str()),
					gcnew String(videoCameraList[i].audiosystem.c_str()),
					videoCameraList[i].batteryCapacity,
					gcnew String(videoCameraList[i].color.c_str())
				);
			}
		}
		file.close();
	}
}

void VideoCamera::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> matrixType;
		file >> stabilization;
		file >> resolution;
		file >> opticZoom;
		file >> sensorScreen;
		file >> audiosystem;
		file >> batteryCapacity;
		file >> color;
	}
}

bool VideoCamera::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (videoCameraList[id - 1].isAvailable() && videoCameraList[id - 1].getAvailable() >= amount)
	{
		videoCameraList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("VideoCamerasList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << videoCameraList[i].ID << ' ';
			outFile << videoCameraList[i].available << ' ';
			outFile << videoCameraList[i].price << ' ';
			outFile << videoCameraList[i].brand << ' ';
			outFile << videoCameraList[i].type << ' ';

			outFile << videoCameraList[i].matrixType << ' ';
			outFile << videoCameraList[i].stabilization << ' ';
			outFile << videoCameraList[i].resolution << ' ';
			outFile << videoCameraList[i].opticZoom << ' ';
			outFile << videoCameraList[i].sensorScreen << ' ';
			outFile << videoCameraList[i].audiosystem << ' ';
			outFile << videoCameraList[i].batteryCapacity << ' ';
			outFile << videoCameraList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
