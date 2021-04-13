#include "Router.h"

Router Router::getRouterByID(int id)
{
    return routerList[id - 1];
}

int Router::listSizeCheck()
{
	int i = 0;
	ifstream base("RoutersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Router::viewProducts(string filePath, DataGridView^ dataGridView)
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
			routerList = new Router[listSize];

			int rowSize = listSize;
			dataGridView->RowCount = rowSize;

			for (int i = 0; i < rowSize; i++)
			{
				routerList[i].initProduct(file);
				dataGridView->Rows[i]->SetValues(routerList[i].ID,
					routerList[i].available,
					routerList[i].price,
					gcnew String(routerList[i].brand.c_str()),
					gcnew String(routerList[i].type.c_str()),

					gcnew String(routerList[i].appointment.c_str()),
					gcnew String(routerList[i].frequency.c_str()),
					gcnew String(routerList[i].maxSpeed.c_str())
				);
			}
		}
		file.close();
	}
}

void Router::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> appointment;
		file >> frequency;
		file >> maxSpeed;
	}
}

bool Router::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (routerList[id - 1].isAvailable() && routerList[id - 1].getAvailable() >= amount)
	{
		routerList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("RoutersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << routerList[i].ID << ' ';
			outFile << routerList[i].available << ' ';
			outFile << routerList[i].price << ' ';
			outFile << routerList[i].brand << ' ';
			outFile << routerList[i].type << ' ';

			outFile << routerList[i].appointment << ' ';
			outFile << routerList[i].frequency << ' ';
			outFile << routerList[i].maxSpeed << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
