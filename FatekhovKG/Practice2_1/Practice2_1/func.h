#ifndef _FUNC_H
#define _FUNC_H
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
FILE* fileop(char* adress);
typedef struct {
	char* hours;
	char* minutes;
} Time;
typedef struct {
	Days* s;
	Time open;
	Time close;
}Opening_Hours;
typedef struct {
	char* street;
	char* postcode;
}Adress;
typedef struct {
	char* name;
	char* phone_number;
	char* specialization;
	Opening_Hours* op;
	Adress adress;
	char* form_of_ownership;
}Shop;
int count_shops(FILE* filename, char* adress);
void print_struct(Shop* shop, int length);
Shop* our_shop(char* adress, int length);
#endif

