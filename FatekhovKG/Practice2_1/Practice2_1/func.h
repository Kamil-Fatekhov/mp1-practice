#ifndef _FUNCTION_H
#define _FUNCTION_H
#define N 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct {
	char name[30];
	char adress[100];
	char phone_number[100];
	char specialization[100];
	char opening_hours[60];
	char opening_days[15];
	char form_of_ownership[10];
} Shop;
int count_shops(FILE* filename, char* adress);
void malloc_struct(Shop** shop, int length);
void free_struct(Shop** shop);
int full_struct(Shop* shop, char* filename, int num);
void print_struct(Shop* shop, int record);
int quantity(Shop* shop, int records);
int* full_our_shop(Shop* shop, int records, int quantity);
void print_name_struct(Shop* shop, int quantity, int* array);
void malloc_array(int** array, int quantity);
void free_array(int** array);
FILE* fileop(char* adress);
#endif