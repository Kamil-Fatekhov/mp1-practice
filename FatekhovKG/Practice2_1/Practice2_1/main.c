#include "func.h"
void main() {
	FILE* file = NULL;
	char* adress = "shops.txt";
	file = fileop(adress);
	int length = count_shops(file,adress);
	Shop* shop = our_shop(adress, length);
	print_struct(shop, length);
	
}
