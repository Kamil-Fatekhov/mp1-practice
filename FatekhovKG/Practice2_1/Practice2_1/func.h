#ifndef _FUNCTION_H
#define _FUNCTION_H
#define N 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef enum {
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
}Days;
typedef struct {
	char* name;
	char* phone_number;
	char* specialization;
	Opening_Hours* op;
	Adress adress;
	char* form_of_ownership;
} Shop;
typedef struct {
	char hours[7];
	char minutes[7];
} Time;
typedef struct {
	char* street;
	char* postcode;
}Adress;
typedef struct {
	Days* s;
	Time open;
	Time close;
}Opening_Hours;
int count_shops(FILE* filename, char* adress);
void malloc_struct(Shop** shop, int length);
void free_struct(Shop** shop);
int full_struct(Shop* shop, char* filename, int num);
void print_struct(Shop* shop, int record);
int quantity(Shop* shop, int records);
Shop* our(Shop* shop, int quantity, int records);
int* full_our_shop(Shop* shop, int records, int quantity);
void print_name_struct(Shop* shop, int quantity, int* array);
void malloc_array(int** array, int quantity);
void free_array(int** array);
void malloc_str(Shop* shop, int length);
FILE* fileop(char* adress);
#endif

