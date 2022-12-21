#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define N 10
#define ghostmane main
int quantity[N];
int Cheque[N];
int Make_A_Cheque();
int barcodescan();
int totalprice(inta);
int s = 0;
int discount();
int disc[10];
int j, d, n;
char* products[N] = { "Milk","Snickers","Potato","Bread","Cat food","Razor","Bubble gum","Doritos","Marmalade","Water" };
char* barcode[N] = {
	"0000", // Milk
	"1111",// Snickers
	"2222", // Potato
	"3333", // Bread
	"4444", // Cat food
	"5555", // Razor
	"6666", // Bubble gum
	"7777", // Doritos
	"8888", // Marmalade
	"9999"// Water
};
int price[N] = { 100,75,25,30,10,700,50,203,79,34 };
int ghostmane() {
	int c = 0, i = 0;
	do {
		printf("Enter barcode ---->\t");
		j = barcodescan();
		for (i = 0; i < N; i++) {
			Cheque[j] = j;
		}
		d = discount();
		printf("Enter the quantity\t");
		scanf_s("%d", &n);
		for (i = 0; i < N; i++) {
			quantity[j] += n;
		}
		printf("Index = %d\n", j);
		printf("Discount= %d\t", disc[j]);
		totalprice(j);
		printf("For continue press '1'\t");
		printf("For end press any number\t");
		scanf_s("%d", &c);
		getchar();
	} while (c == 1);
	Make_A_Cheque();
}
int barcodescan() {
	int i = 0, c = 0;
	char ps[5];
D:gets(ps);
	char* b = ps;
	i = 0;
	while (i < N) {
		c = strcmp(ps, barcode[i]);
		if (c == 0) {

			return i;
		}
		i++;
	}
	if (i >= N) {
		printf("Wrong barcode\t Enter barcode ---->\t");  goto D;
	}
}
int totalprice(int a) {
	int totalprice = 0;
	s += (price[j] - price[j] * disc[j] / 100) * n;
	return s;
}
int discount() {
	int b, discount = 0, i = 0;
	srand(time(NULL));
	b = rand() % (1 - 0 + 1);
	if (b == 1)
	{
		discount = rand() % (50 - 1 + 1);
		disc[j] = discount;
	}
	return disc[i];
}
int Make_A_Cheque() {
	int i = 0;
	printf("\t\t\t\tCash receipt\n");
	printf("\t\t***********************************************************\n");
	for (j = 0; j < N; j++) {
		if (quantity[j] != 0) {
			printf("\t\t\t%d\t", quantity[j] / 10);
			if (Cheque[j] != 0) {
				printf("\t%s\t", products[Cheque[j]]);
				printf("\t%d\n", (price[j] - price[j] * disc[j] / 100) * quantity[j] / 10);
			}
		}
	}
	printf("\t\t\t\tTotal price\t%d", totalprice(j));
}