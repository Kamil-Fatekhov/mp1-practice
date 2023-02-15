#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
void main() {
	int n,constant;
	TMatrix* m1, * m2,*pcres1,*pcres2;
	printf("input size of square matrix\t");
	scanf_s("%d", &n);
	allocate_matrix(&m1, n);
	allocate_matrix(&m2, n);
	printf("input numbers of first matrix\n");
	fill_matrix(m1);
	print_matrix(m1, n);
	printf("input numbers of second matrix\n");
	fill_matrix(m2);
	print_matrix(m2, n);
	printf("input const\n");
	scanf_s("%d", &constant);
	plus_const(m1,constant,n);
	plus_const(m2,constant,n);
	multiplied_const(m1, constant,n);
	multiplied_const(m2, constant,n);
	complition_matrix(m1, m2, n);
	multiplication_matrix(m1, m2, n);
	free(&m1);
	free(&m2);
	return 0;
}