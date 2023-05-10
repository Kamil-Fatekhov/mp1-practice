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
	Shop* shop = (Shop*)malloc(sizeof(Shop) * length);
	int read = 0;
	int j = 0;
	for (int i = 0; i < length; i++) {
		shop[i].name = (char*)malloc(sizeof(char) * 30);
		shop[i].adress.postcode = (char*)malloc(sizeof(char) * 30);
		shop[i].specialization = (char*)malloc(sizeof(char) * 30);
		shop[i].phone_number = (char*)malloc(sizeof(char) * 30);
		shop[i].adress.street = (char*)malloc(sizeof(char) * 30);
		shop[i].op = (Opening_Hours*)malloc(sizeof(Opening_Hours) * length * 7);
		shop[i].form_of_ownership = (char*)malloc(sizeof(char) * 30);

		fscanf(filename, "%s %s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %s %s", shop[i].name, shop[i].adress.street, shop[i].phone_number, shop[i].specialization, &shop[i].op[Monday].s, &shop[i].op[Monday].open.hours, &shop[i].op[Monday].open.minutes, &shop[i].op[Monday].close.hours, &shop[i].op[Monday].close.minutes, &shop[i].op[Tuesday].s, &shop[i].op[Tuesday].open.hours, &shop[i].op[Tuesday].open.minutes, &shop[i].op[Tuesday].close.hours, &shop[i].op[Tuesday].close.minutes, &shop[i].op[Wednesday].s, &shop[i].op[Wednesday].open.hours, &shop[i].op[Wednesday].open.minutes, &shop[i].op[Wednesday].close.hours, &shop[i].op[Wednesday].close.minutes, &shop[i].op[Thursday].s, &shop[i].op[Thursday].open.hours, &shop[i].op[Thursday].open.minutes, &shop[i].op[Thursday].close.hours, &shop[i].op[Thursday].close.minutes, &shop[i].op[Friday].s, &shop[i].op[Friday].open.hours, &shop[i].op[Friday].open.minutes, &shop[i].op[Friday].close.hours, &shop[i].op[Friday].close.minutes, &shop[i].op[Saturday].s, &shop[i].op[Saturday].open.hours, &shop[i].op[Saturday].open.minutes, &shop[i].op[Saturday].close.hours, &shop[i].op[Saturday].close.minutes, &shop[i].op[Sunday].s, &shop[i].op[Sunday].open.hours, &shop[i].op[Sunday].open.minutes, &shop[i].op[Sunday].close.hours, &shop[i].op[Sunday].close.minutes, shop[i].form_of_ownership, shop[i].adress.postcode);
	}

	fclose(filename);
	return shop;
}
void print_struct(Shop* shop, int length) {
	for (int i = 0; i < length; i++) {
		printf("\nName: %s\nAdress: %s\nPhone Number: %s\nSpecialization: %s\nPostcode: %s\nForm of ownership:%s\n", shop[i].name, shop[i].adress.street, shop[i].phone_number, shop[i].specialization, shop[i].adress.postcode, shop[i].form_of_ownership);
		for (int j = 0; j < 7; j++) {
			switch (shop[i].op[j].s) {
			case 0:
				printf("Monday: %d:%d-%d:%d\n", shop[i].op[Monday].open.hours, shop[i].op[Monday].open.minutes, shop[i].op[Monday].close.hours, shop[i].op[Monday].close.minutes);
				break;
			case 1:
				printf("Tuesday: %d:%d-%d:%d\n", shop[i].op[Tuesday].open.hours, shop[i].op[Tuesday].open.minutes, shop[i].op[Tuesday].close.hours, shop[i].op[Tuesday].close.minutes);
				break;
			case 2:
				printf("Wednesday: %d:%d-%d:%d\n", shop[i].op[Wednesday].open.hours, shop[i].op[Wednesday].open.minutes, shop[i].op[Wednesday].close.hours, shop[i].op[Wednesday].close.minutes);
				break;
			case 3:
				printf("Thursday: %d:%d-%d:%d\n", shop[i].op[Thursday].open.hours, shop[i].op[Thursday].open.minutes, shop[i].op[Thursday].close.hours, shop[i].op[Thursday].close.minutes);
				break;
			case 4:
				printf("Friday: %d:%d-%d:%d\n", shop[i].op[Friday].open.hours, shop[i].op[Friday].open.minutes, shop[i].op[Friday].close.hours, shop[i].op[Friday].close.minutes);
				break;
			case 5:
				printf("Saturday: %d:%d-%d:%d\n", shop[i].op[Saturday].open.hours, shop[i].op[Saturday].open.minutes, shop[i].op[Saturday].close.hours, shop[i].op[Saturday].close.minutes);
				break;
			case 6:
				printf("Sunday: %d:%d-%d:%d\n", shop[i].op[Sunday].open.hours, shop[i].op[Sunday].open.minutes, shop[i].op[Sunday].close.hours, shop[i].op[Sunday].close.minutes);
				break;
			}
		}
	}
}
int count_shop(Shop* shops, int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (strcmp(shops[i].specialization, "Products") == 0) {
			for (int j = 0; j < 7; j++) {
				if (shops[i].op[j].open.hours != 0 || shops[i].op[j].open.minutes != 0 || shops[i].op[j].close.hours != 0 || shops[i].op[j].close.minutes != 0)
					break;
				else {
					if (j == 6) count++;
				}
			}
		}
	}
	return count;
}

Shop* correct_shop(Shop* shops, int length, int count) {
	Shop* shop = (Shop*)malloc(sizeof(Shop) * count);
	for(int i=0;i<count; i++) {
		shop[i].name = (char*)malloc(sizeof(char) * 30);
		shop[i].adress.postcode = (char*)malloc(sizeof(char) * 30);
		shop[i].specialization = (char*)malloc(sizeof(char) * 30);
		shop[i].phone_number = (char*)malloc(sizeof(char) * 30);
		shop[i].adress.street = (char*)malloc(sizeof(char) * 30);
		shop[i].op = (Opening_Hours*)malloc(sizeof(Opening_Hours) * count * 7);
		shop[i].form_of_ownership = (char*)malloc(sizeof(char) * 30);
	}
	for (int c = 0; c < count; c++) {
		for (int i = 0; i < length; i++) {
			if (strcmp(shops[i].specialization, "Products") == 0) {
				for (int j = 0; j < 7; j++) {
					if (shops[i].op[j].open.hours != 0 || shops[i].op[j].open.minutes != 0 || shops[i].op[j].close.hours != 0 || shops[i].op[j].close.minutes != 0)
						break;
					else {
						if (j == 6) {
							strcpy(shop[c].name, shops[i].name);
							strcpy(shop[c].specialization, shops[i].specialization);
							strcpy(shop[c].phone_number, shops[i].phone_number);
							strcpy(shop[c].adress.street, shops[i].adress.street);
							strcpy(shop[c].adress.postcode, shops[i].adress.postcode);
							strcpy(shop[c].form_of_ownership, shops[i].form_of_ownership);
							for (int b = 0; b < 7; b++) {
								shop[c].op[b].s = shops[i].op[b].s;
								shop[c].op[b].open.hours = shops[i].op[b].open.hours;
								shop[c].op[b].open.minutes = shops[i].op[b].open.minutes;
								shop[c].op[b].close.hours = shops[i].op[b].close.hours;
								shop[c].op[b].close.minutes = shops[i].op[b].close.minutes;
							}
							c++;
						}
					}
				}
			}
		}
	}
	return shop;
}
free_str(Shop** shop, int length) {
	for (int i = 0; i < length; i++) {
		free((*shop)[i].name);
		free((*shop)[i].specialization);
		free((*shop)[i].form_of_ownership);
		free((*shop)[i].adress.street);
		free((*shop)[i].adress.postcode);
		free((*shop)[i].op);
	}
		free(*shop);
}
