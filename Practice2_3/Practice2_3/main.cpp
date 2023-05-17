#include "title.h"
void main() {
	string adress = "shops.txt";
	List a(adress);
	//a.shop[0] = a.shop[1];
	cout << a<<endl;
	cout << "Our shops: " << endl;
	List b;
	b = a.correct_base();
	cout << b;
}
