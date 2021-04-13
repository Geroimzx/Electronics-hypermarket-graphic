#include "ShoppingCart.h"

void ShoppingCart::viewShoppingCart(DataGridView^ dataGridView, Label^ oplataLabelControl)
{
	oplata = 0;
	if (amountCheck() > 0)
	{
		inFile.open("ShoppingCart.txt");
		if (!inFile)
			cout << "Cannot open file" << endl;
		amountCheck();
		int rowSize = amount;
		dataGridView->RowCount = rowSize;
		products = new Product[amount];
		for (int i = 0; i < amount; i++)
		{
			products[i].initProduct(inFile);
			dataGridView->Rows[i]->SetValues(i+1,
				products[i].getID(),
				products[i].getAvailable(),
				products[i].getPrice(),
				gcnew String(products[i].getBrand().c_str()),
				gcnew String(products[i].getType().c_str())
			);
		}
		cout << "\n";
		inFile.close();
		amountCheck();
		oplataLabelControl->Text = gcnew String(checkOplata().ToString());
	}
	else {
		oplata = 0;
	}
}

void ShoppingCart::initShoppingCartAdd(int& id, int& amount)
{
	cout << "-------------------------------------" << endl;
	cout << "Введіть ID товару:\n";
	cin >> id;
	cout << "Ведіть кількість товару:\n";
	cin >> amount;
}

void ShoppingCart::updateShoppingCartAdd(std::string val)
{
	outFile.open("ShoppingCart.txt", ios::app);
	if (!inFile) {
		cout << "Cannot open file" << endl;
	}
	else {
		std::istringstream input{val};
		std::vector<std::string> result;

		// extract substrings one-by-one
		while (!input.eof()) {
			std::string substring;
			input >> substring;
			result.push_back(substring);
		}
		int scale = 10;
		outFile.setf(ios::left);
		outFile << '\n' << result[0] << ' ';
		outFile << result[1] << ' ';
		outFile << result[2] << ' ';
		outFile << result[3] << ' ';
		outFile << result[4];
		outFile.close();
		amountCheck();
	}
}

void ShoppingCart::addProduct(Product product, int amount)
{
	outFile.open("ShoppingCart.txt", ios::app);
	if (!inFile) {
			cout << "Cannot open file" << endl;
	}
	else {
		int scale = 10;
		outFile.setf(ios::left);
		outFile << '\n' << product.getID() << ' ';
		outFile << amount << ' ';
		outFile << product.getPrice() << ' ';
		outFile << product.getBrand() << ' ';
		outFile << product.getType();
		outFile.close();
		amountCheck();
	}
}

void ShoppingCart::deleteProduct(int number)
{
	if (amountCheck() > 0)
	{
		inFile.open("ShoppingCart.txt");
		if (!inFile) {
			cout << "Cannot open file" << endl;
		}
		else {
			amountCheck();
			products = new Product[amount];
			for (int i = 0; i < amount; i++)
			{
				products[i].initProduct(inFile);
			}
			inFile.close();
			fstream outFile("ShoppingCart.txt", ios::out);
			if (!outFile) {
				cout << "Cannot open file\n" << endl;
			}else {
				outFile.setf(ios::left);
				for (int i = 0; i < amount; i++)
				{
					if ((i + 1) != number)
					{
						outFile << products[i].getID() << ' ';
						outFile << products[i].getAvailable() << ' ';
						outFile << products[i].getPrice() << ' ';
						outFile << products[i].getBrand() << ' ';
						outFile << products[i].getType() << '\n';
					}
				}
			}
			outFile.close();
		}
	}
	else {
		clearShoppingCart();
	}
}

void ShoppingCart::clearShoppingCart()
{
	ofstream oFile;
	oFile.open("ShoppingCart.txt", ios::out | ios::trunc);
	oFile.close();
}

int ShoppingCart::checkOplata()
{
	if (amountCheck() > 0)
	{
		inFile.open("ShoppingCart.txt");
		if (!inFile) {
			cout << "Cannot open file" << endl;
		}
		else {
			amountCheck();
			products = new Product[amount];
			for (int i = 0; i < amount; i++)
			{
				products[i].initProduct(inFile);
				oplata += products[i].getPrice() * products[i].getAvailable();
			}
			cout << "\n";
			inFile.close();
		}
		int tmp = oplata;
		oplata = 0;
		return tmp;
	}
	cout << "Кошик пустий\n";
	return 0;
}

int ShoppingCart::pay()
{
	if (amountCheck() > 1)
	{
		inFile.open("ShoppingCart.txt");
		fstream admFile;
		admFile.open("ShoppingCartAdminList.txt", ios::app);
		if (!inFile || !admFile) {
			cout << "Cannot open file" << endl;
		}
		else {
			// current date/time based on current system
			time_t now = time(0);
			// convert now to string form
			char* _Buffer = new char[50];
			ctime_s(_Buffer, 50, &now);
			string dt = _Buffer;
			admFile << dt << '\n';
			amountCheck();
			products = new Product[amount];
			for (int i = 0; i < amount; i++)
			{
				products[i].initProduct(inFile);
				admFile << products[i].getID() << ' ';
				admFile << products[i].getAvailable() << ' ';
				admFile << products[i].getPrice() << ' ';
				admFile << products[i].getBrand() << ' ';
				admFile << products[i].getType() << '\n';
				oplata += products[i].getPrice() * products[i].getAvailable();
			}
			admFile << oplata << '\n';
			cout << "\n";

		}
		inFile.close();
		admFile.close();
		int tmp = oplata;
		oplata = 0;
		return tmp;
	}
	cout << "Кошик пустий\n";
	return 0;
}

int ShoppingCart::amountCheck()
{
	int i = 0;
	ifstream base("ShoppingCart.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->amount = i-1;
	base.close();
	return i;
}
