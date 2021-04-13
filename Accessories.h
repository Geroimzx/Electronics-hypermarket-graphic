#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Accessories :
    public Product
{
private:
	Accessories* accessoriesList;
	int listSize;
public:
	//повертає об'єкт за ID
	Accessories getAccessoriesByID(int id);

	int listSizeCheck();

	//виводить таблицю товарів
	void viewProducts(string filePath, DataGridView^ dataGridView) override;
	//ініціалізує динамічний масив товарів за даними в файлі
	void initProduct(std::ifstream& file) override;
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	bool updateProductList(int id, int amount) override;
};

