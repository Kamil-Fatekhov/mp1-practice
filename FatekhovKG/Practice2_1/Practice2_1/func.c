#include "func.h"
int count_shops(FILE* filename, char* adress) {
	int vacancy_count = 0, lines_count = 0;
	filename = fopen(adress, "r");
	while (!feof(filename))
	{
		if (fgetc(filename) == '\n')
			lines_count++;
	}
	fclose(filename);
	return lines_count-1;

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
Shop* our_shop(char* adress, int length) {
	FILE* filename;
	filename = fopen(adress, "r");
	Shop* shop=(Shop*)malloc(sizeof(Shop) * length);
	int read = 0;
 int j = 0;
 for (int i = 0; i < length; i++) {
	 shop[i].name = (char*)malloc(sizeof(char) * 30);
	 shop[i].adress.postcode = (char*)malloc(sizeof(char) * 30);
	 shop[i].specialization = (char*)malloc(sizeof(char) * 30);
	 shop[i].phone_number = (char*)malloc(sizeof(char) * 30);
	 shop[i].adress.street = (char*)malloc(sizeof(char) * 30);
	 shop[i].op = (Opening_Hours*)malloc(sizeof(Opening_Hours) * 7);
	 shop[i].form_of_ownership = (char*)malloc(sizeof(char) * 30);
	 shop[i].op->s = (Days*)malloc(sizeof(Days) * 7);
	 shop[i].op->open.minutes = (char*)malloc(sizeof(char) * 10);
	 shop[i].op->close.minutes = (char*)malloc(sizeof(char) * 10);
	 shop[i].op->open.hours = (char*)malloc(sizeof(char) * 10);
	 shop[i].op->close.hours = (char*)malloc(sizeof(char) * 10);
	 fscanf(filename, "%s %s %s %s %d %s %s %s %s %d %s %s %s %s %d %s %s %s %s %d %s %s %s %s %d %s %s %s %s %d %s %s %s %s %d %s %s %s %s %s %s",shop[i].name,shop[i].adress.street,shop[i].phone_number,shop[i].specialization, &shop[i].op->s[Monday], &shop[i].op->open.hours[Monday], &shop[i].op->open.minutes[Monday], &shop[i].op->close.hours[Monday],&shop[i].op->close.minutes[Monday], &shop[i].op->s[1], &shop[i].op->open.hours[Tuesday], &shop[i].op->open.minutes[Tuesday], &shop[i].op->close.hours[Tuesday], &shop[i].op->close.minutes[Tuesday], &shop[i].op->s[2], &shop[i].op->open.hours[Wednesday], &shop[i].op->open.minutes[Wednesday], &shop[i].op->close.hours[Wednesday], &shop[i].op->close.minutes[Wednesday], &shop[i].op->s[3], &shop[i].op->open.hours[Thursday], &shop[i].op->open.minutes[Thursday], &shop[i].op->close.hours[Thursday], &shop[i].op->close.minutes[Thursday], &shop[i].op->s[4], &shop[i].op->open.hours[Friday], &shop[i].op->open.minutes[Friday], &shop[i].op->close.hours[Friday], &shop[i].op->close.minutes[Friday], &shop[i].op->s[5], &shop[i].op->open.hours[Saturday], &shop[i].op->open.minutes[Saturday], &shop[i].op->close.hours[Saturday],& shop[i].op->close.minutes[Saturday], &shop[i].op->s[6], &shop[i].op->open.hours[Sunday], &shop[i].op->open.minutes[Sunday], &shop[i].op->close.hours[Sunday], &shop[i].op->close.minutes[Sunday], shop[i].form_of_ownership, shop[i].adress.postcode);
 }
	 fclose(filename);
 return shop;
 }
void print_struct(Shop* shop, int length) {
	for (int i = 0; i < length; i++) {
			printf("Name: %s\nAdress: %s\nPhone Number: %s\nSpecialization: %s\nPostcode: %s\nForm of ownership:%s\n",shop[i].name,shop[i].adress.street,shop[i].phone_number,shop[i].specialization,shop[i].adress.postcode,shop[i].form_of_ownership);
		for (int j = 0; j < 7; j++) {
			switch (shop[i].op->s[j]) {
			case 0:
				printf("Monday: %s:%s-%s:%s\n", &shop[i].op->open.hours[Monday], &shop[i].op->open.minutes[Monday], &shop[i].op->close.hours[Monday], &shop[i].op->close.minutes[Monday]);
				break;
			case 1:
				printf("Tuesday: %s:%s-%s:%s\n", &shop[i].op->open.hours[Tuesday], &shop[i].op->open.minutes[Tuesday], &shop[i].op->close.hours[Tuesday], &shop[i].op->close.minutes[Tuesday]);
				break;
			case 2:
				printf("Wednesday: %s:%s-%s:%s\n", &shop[i].op->open.hours[Wednesday], &shop[i].op->open.minutes[Wednesday], &shop[i].op->close.hours[Wednesday], &shop[i].op->close.minutes[Wednesday]);
				break;
			case 3:
				printf("Thursday: %s:%s-%s:%s\n", &shop[i].op->open.hours[Thursday], &shop[i].op->open.minutes[Thursday], &shop[i].op->close.hours[Thursday], &shop[i].op->close.minutes[Thursday]);
				break;
			case 4:
				printf("Friday: %s:%s-%s:%s\n", &shop[i].op->open.hours[Monday], &shop[i].op->open.minutes[Monday], &shop[i].op->close.hours[Monday], &shop[i].op->close.minutes[Monday]);
				break;
			case 5:
				printf("Saturday: %s:%s-%s:%s\n", &shop[i].op->open.hours[5], &shop[i].op->open.minutes[5], &shop[i].op->close.hours[5], &shop[i].op->close.minutes[5]);
				break;
			case 6:
				printf("Sunday: %s:%s-%s:%s\n", &shop[i].op->open.hours[6], &shop[i].op->open.minutes[6], &shop[i].op->close.hours[6], &shop[i].op->close.minutes[6]);
				break;
			}
		}
	}
}
