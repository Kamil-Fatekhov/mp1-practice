#include "func.h"
int main() {
	Shop* shop;

	FILE* file = NULL;
	char* adress = "shops.txt";
	int i = 0;
	int num = 7;
	int records = 0;
	int* index;
	file = fileop(adress);
	int length = count_shops(file, adress);
	//printf("%d", length);
	malloc_struct(&shop, length);
	malloc_str(shop, length);
	records = full_struct(shop, file, num);
	print_struct(shop, records);
	i = quantity(shop, records);
	malloc_array(&index, i);
	//printf("Size %d\n", i);
	index = full_our_shop(shop, records, i);
	Shop* our_shop = our(shop, i, records);
	printf("\nSituable stores: \n");
	print_struct(our_shop, i);
	//printf("SDS%d\t", index[2]);
	//print_name_struct(shop, i, index);
	free_struct(&shop);
	free_struct(&our_shop);
	free_array(&index);

	return 0;
}