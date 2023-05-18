#include <iostream>
#include <fstream>
#include<string>
#include<string.h>
using namespace std;
#ifndef _TITLE_H
#define _TITLE_H
class Adress;
class Opening_Hours;
class Time;
class Adress {
	friend class List;
	friend class Shop;
public:
	Adress();
	Adress& operator =(const Adress& other);
	friend ostream& operator<<(ostream& os, const List& list);
	string street;

private:
	string postcode;
};
class Opening_Hours {
	friend class List;
	friend class Time;
	friend class Shop;
public:
	Opening_Hours();
	Opening_Hours& operator = (const Opening_Hours& other);
	friend ostream& operator<<(ostream& os, const List& list);

private:
	string Day;

	class Time {
		friend class Opening_Hours;
		friend class List;
		friend class Shop;
	public:
		friend ostream& operator<<(ostream& os, const List& list);
		Time();
		Time& operator = (const Time& other);
	private:
		string minutes;
		string hours;
	};

	Time open;
	Time close;
};
class List {
public:
	List& operator=(const List& other);
	
	friend ostream& operator<<(ostream& os, const List& list);
	List();
	List(const List& other);
	~List();
	List(string adress);
	List correct_base();

private:


	class Shop {
		friend class List;
		
	public:
		Shop& operator =(const Shop& other);
		Shop();
		friend ostream& operator<<(ostream& os, const List& list);
	private:
		string name;
		Adress adress;
		string phone_number;
		string specialization;
		Opening_Hours* op;
		string form_of_ownership;
	};


	int count;
	Shop* shop;
};

ostream& operator<<(ostream& os, const List& list);
#endif
