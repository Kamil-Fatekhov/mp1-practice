#include "title.h"
int main() {
	setlocale(LC_ALL, "RU");
	const string adress_base = "shops.txt";
	int length = file_info(adress_base);
	Shops* a = info(length, adress_base);
	//print_class(a, length);
	Shops* b = quantity(a, length);
	cout << "Подходящие нам магазины: " << endl;
	print_class(b, b->fileinf);
	delete[] a;
	delete[] b;
	return 0;
}