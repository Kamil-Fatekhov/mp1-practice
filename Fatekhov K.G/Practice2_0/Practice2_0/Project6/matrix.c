#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
void allocate_matrix(TMatrix** matrix, int n) {
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix));
	(*matrix)->n = n * n;
	(*matrix)->x = (int*)malloc(sizeof(int) * (*matrix)->n);
}
void fill_matrix(TMatrix* matrix) {
	for (int i = 0; i < matrix->n; i++) {
		 scanf_s("%d", &(matrix->x[i]));

	}
}
void print_matrix(TMatrix* matrix,int n) {
		int i = 0, j = 0;
		for (; j < n; j++) {
			for (i=0; i < n; i++) {
				printf("%d\t",matrix->x[j * n + i]);
			}
			printf("\n");
		}
	}
TMatrix* plus_const(TMatrix* matrix,int constant, int n) {
	TMatrix* res;
	allocate_matrix(&res, matrix->n);
	for (int i = 0; i < matrix->n; i++) {
		res->x[i] =matrix->x[i] + constant;
	}
	print_matrix(res, n);
	printf("\n");
}
TMatrix* multiplied_const(TMatrix* matrix, int constant,int n) {
	TMatrix* res;
	allocate_matrix(&res, matrix->n);
	for (int i = 0; i < matrix->n; i++) {
		res->x[i] =matrix->x[i] * constant;
	}
	print_matrix(res, n);
	printf("\n");
}
TMatrix* complition_matrix(TMatrix* matrix, TMatrix* matrix2,int n) {
	TMatrix* res;
	allocate_matrix(&res, n);
	for (int i = 0; i < matrix->n; i++) {
		res->x[i]=matrix->x[i]+matrix2->x[i];
	}
	print_matrix(res, n);
	printf("\n");
}
TMatrix* multiplication_matrix(TMatrix* matrix, TMatrix* matrix2, int n) {
	TMatrix* res;
	allocate_matrix(&res, n);
	int flag = 0,j=0,i=0,count=0,countj=0,counti=0;
	for (count; count < matrix->n; count++) {
		flag = 0;
		if (j  == n ) {
			j = 0; countj = 0;
			counti++;
			i = n * counti;
		}
		res->x[count] = 0;
		while (flag < n) {
			res->x[count] += matrix->x[i] * matrix2->x[j];
			j += n; i++;
			flag++;
		}countj++; j = countj;  i = n*counti;
	}
	print_matrix(res, n);
	printf("\n");
}
void free_matrix(TMatrix** matrix) {
	free((*matrix)->x);
	free(*matrix);
}