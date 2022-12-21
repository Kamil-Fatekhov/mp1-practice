#include <locale.h>
#include <stdio.h>
int main()
{
	setlocale(LC_ALL, "rus");
	float dsp = 0.0008, dvp = 0.0007, wood = 0.00065, M; 
	float backwall = 1, h, v, wbw = 0.5; // dvp 
	float sidewall = 2, d, wsw = 1.5; // dsp 
	float cover = 2, wc = 1.5; //dsp, v,d,wsw 
	float door = 1, w = 1; // wood h 
	int count, wp = 1; // dsp 
	printf("Input h  180-220cm\t");
	scanf_s("%f", &h);
	if (h < 180 || h>220)
	{
		printf("Wrong value");
		return;
	}
	printf("Input v  80-120cm\t");
	scanf_s("%f", &v);
	if (v < 80 || v>120)
	{
		printf("Wrong value");
		return;
	}
	printf("Input d   50-90cm\t");
	scanf_s("%f", &d);
	if (d < 50 || d>90)
	{
		printf("Wrong value");
		return;
	}
	if (h > 200) count = 5;
	else count = 4;
	M = backwall * dvp * h * v * wbw + sidewall * dsp * h * d * wsw + cover * dsp * v * d * wc + door * wood * h * v * w + count * dsp * wp * v * d-(count*wbw-wp)*dsp;
	printf("M= %f", M);
	printf("kg\t");
	system("pause");
	return 0;
}