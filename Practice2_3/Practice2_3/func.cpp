#include "title.h"
Shops::Shops() {
	name = " ";
	adress = " ";
	specialization = " ";
	phone_number = " ";
	opening_hours = " ";
	opening_days = " ";
	form_of_ownership = " ";
}
 int file_info(const string& adress) {
	ifstream file(adress);
	if (file.is_open()) {
		cout << "File opened successfully" << endl;
	}
	else {
		cout << "Error opening file";
		exit(1);
	}
		string line;
		int lines = 0;
	while (!file.eof()) {
		getline(file, line);
		lines++;
	}
	file.close();
	return lines;
}
 void print_class(Shops * shop) {
	 for (int i = 0; i < shop->fileinf; i++) {
		 shop[i].print();
	 }
}
 
 Shops* info(int n, const string adress) {
	 ifstream file(adress);
	 Shops* shop = new Shops[n];
	 for (int i = 0; i < n; i++)
	 {
		 file >> shop[i].name >> shop[i].adress >> shop[i].phone_number >> shop[i].specialization >> shop[i].opening_hours >> shop[i].opening_days >> shop[i].form_of_ownership;
	 }
	 file.close();
	 return shop;
 }

 void print_class(Shops* shop, int n) {
	 for (int i = 0; i < n; i++) {
		 shop[i].print();
	 }
 }
 void Shops:: print() {
	 cout << "Name: " << name << endl;
	 cout << "Adress: " << adress << endl;
	 cout << "Specialization: " << specialization << endl;
	 cout << "Phone nubmer: " << phone_number << endl;
	 cout << "Opening hours: " << opening_hours << endl;
	 cout << "Opening days: " << opening_days << endl;
	 cout << "Form of ownership: " << form_of_ownership << endl;
 }
 Shops& Shops::operator=(const Shops& other) {
	 this->name = other.name;
	 this->adress = other.adress;
	 this->phone_number = other.phone_number;
	 this->specialization = other.specialization;
	 this->opening_hours = other.opening_hours;
	 this->opening_days = other.opening_days;
	 this->form_of_ownership = other.form_of_ownership;
	 return *this;
 }

 Shops* quantity(Shops* shop, int records) {
	 int count = 0;
	 const string str1 = "Products";
	 const string str2 = "AllDay";
	 for (int i = 0; i < records; i++) {
		 if (((shop[i].specialization.compare(str1)) == 0) && ((shop[i].opening_hours.compare(str2)) == 0))
			 count++;
	 }
	 
	 Shops* shops = new Shops[count];
	 shops->fileinf = count;
	 for (int j = 0; j < count; j++) {
		 for (int i = 0; i < records; i++) {
			 if (((shop[i].specialization.compare(str1)) == 0) && ((shop[i].opening_hours.compare(str2)) == 0)) {
				 shops[j] = shop[i];
				 j++;
				 if (j == count) break;
			 }
		 }
	 }
	 return shops;
 }
 