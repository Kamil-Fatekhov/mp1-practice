#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
#include <vector>
using namespace std;
#ifndef _TITLE_H
#define _TITLE_H
class Shops {
private:
	string name;
	string adress;
	string phone_number;
	string specialization;
	string opening_hours;
	string opening_days;
	string form_of_ownership;
public:
	int fileinf;
	Shops();
	Shops& operator =(const Shops& shop);
	void print();
	friend Shops* info(int n, const string adress);
	friend Shops* quantity(Shops* shop, int records);
};
void print_class(Shops* shop, int n);
Shops* info(int n, const string adress);
int file_info(const string& adress);
Shops* quantity(Shops* shop, int records);
#endif