#include <stdio.h>

int main(){
	char a = 8;
	char b = 1;
	int c = 2749;
	a--;//produces 7
	b = b + c%7;//produces 6
	printf("\nThe product of %d and %d is %d\n\n", b, a, a*b);//prints out 7 * 6

	float x = 0;
	float y = 4;
	x++;//produces 1
	y = y - x;//produces 3
	printf("%f divided by %f is %f\n\n", x, y, x/y);

	return 0;
}













