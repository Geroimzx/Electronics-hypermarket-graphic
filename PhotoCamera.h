#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class PhotoCamera :
    public Product
{
private:
	string resolution;
	string sizeMatrix;
	string opticZoom;
	string powerType;
	string color;

	PhotoCamera* photoCameraList;
	int listSize;
public:
	//повертає об'єкт за ID
	PhotoCamera getPhotoCameraByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath, DataGridView^ dataGridView) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

