#include "func.h"
int count_shops(FILE* filename, char* adress) {
	int vacancy_count = 0, lines_count = 1;
	filename = fopen(adress, "r");
	while (!feof(filename))
	{
		if (fgetc(filename) == '\n')
			lines_count++;
	}
	fclose(filename);
	return lines_count;

}
void malloc_struct(Shop** shop, int length) {
	(*shop) = malloc(sizeof(Shop) * length);
}
void malloc_str(Shop* shop, int length) {
	int i = 0;
	for (i = 0; i < length; i++) {
		shop[i].name = (char*)malloc(sizeof(char) * 30);
		shop[i].adress = (char*)malloc(sizeof(char) * 99);
		shop[i].phone_number = (char*)malloc(sizeof(char) * 99);
		shop[i].specialization = (char*)malloc(sizeof(char) * 99);
		shop[i].opening_hours = (char*)malloc(sizeof(char) * 59);
		shop[i].opening_days = (char*)malloc(sizeof(char) * 14);
		shop[i].form_of_ownership = (char*)malloc(sizeof(char) * 4);
	}
}
int full_struct(Shop* shop, char* filename, int num) {
	int read = 0;
	int n = 0;
	int records = 0;


	do {
		read = fscanf(filename, "%30[^,],%99[^,],%99[^,],%99[^,],%59[^,],%14[^,],%4[^,]\n", shop[records].name,
			shop[records].adress, shop[records].phone_number, shop[records].specialization, shop[records].opening_hours,
			shop[records].opening_days, shop[records].form_of_ownership);
		if (read == num)  records++;
		if (read != num && !feof(filename))
		{
			printf("File format incorrect.\n");
			return 1;
		}
		if (ferror(filename)) {
			printf("Error reading file.\n");
			return 1;
		}
		read = 0;
	} while (!feof(filename));
	fclose(filename);
	printf("\n%d records read.\n\n", records);
	return records;
}
void print_struct(Shop* shop, int record) {
	int records = record;
	for (int i = 0; i < record; i++) {
		printf("Name:\t%s\nAdress:\t%s\nPhone number:\t%s\nSpecialization:\t%s\nOpening hours:\t%s\nOpening days:\t%s\nForm of ownership:\t%s\n", shop[i].name,
			shop[i].adress, shop[i].phone_number, shop[i].specialization, shop[i].opening_hours,
			shop[i].opening_days, shop[i].form_of_ownership);
	}
}
void free_struct(Shop** shop) {
	free(*shop);
}
int quantity(Shop* shop, int records) {
	int count = 0;
	char a[10] = "Products";
	char b[10] = "AllDay";
	for (int i = 0; i < records; i++) {

		if ((strcmp(shop[i].specialization, "Products") == 0) && (strcmp(shop[i].opening_hours, "AllDay")) == 0)
			count++;
		//printf("str %d, %d\n", strcmp(shop[i].specialization, "Products"), strcmp(shop[i].opening_hours, "AllDay"));
	}
	return count;
}
int* full_our_shop(Shop* shop, int records, int quantity) {
	int* array;
	malloc_array(&array, quantity);
	int i = 0, j = 0;
	while (i < records && j < quantity) {
		if ((strcmp(shop[i].specialization, "Products") == 0) && (strcmp(shop[i].opening_hours, "AllDay")) == 0) {
			array[j] = i;
			j++;
		}i++;
	}
	return array;
	free(array);
}
void print_name_struct(Shop* shop, int quantity, int* array) {
	printf("\nSuitable stores: \n");
	for (int i = 0; i < quantity; i++) {
		printf("Name:\t%s\nAdress:\t%s\nPhone number:\t%s\nSpecialization:\t%s\nOpening hours:\t%s\nOpening days:\t%s\nForm of ownership:\t%s\n", shop[i].name,
			shop[i].adress, shop[i].phone_number, shop[i].specialization, shop[i].opening_hours,
			shop[i].opening_days, shop[i].form_of_ownership);
	}
}
void malloc_array(int** array, int quantity) {
	*array = (int*)malloc(sizeof(int) * quantity);
}
void free_array(int** array) {
	free(*array);
}
Shop* our(Shop* shop, int quantity, int records) {
	Shop* shops = (Shop*)malloc(sizeof(shop)*quantity);
	const char* str1 = "Products";
	const char* str2 = "AllDay";
	int j = 0;
	while (j < quantity) {
		for (int i = 0; i < records; i++) {
			if ((strcmp(shop[i].specialization, "Products") == 0) && (strcmp(shop[i].opening_hours, "AllDay")) == 0) {
				shops[j] = shop[i];
				j++;
			}
		}
	}
	return shops;
}
FILE* fileop(char* adress) {
	FILE* filename = NULL;
	filename = fopen(adress, "r");
	if (filename == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	else
		printf("file opened successfully\n");
	return filename;
}