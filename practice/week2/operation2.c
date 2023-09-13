#include <stdio.h>

int main()
{
	// 변수 x, y, z 선언
	int x = 4;
	int y = 2;
	int z;

	z = (x + y) * (x - y);
	printf("z = (x + y) * (x - y) = %d\n", z);

	z = (z * y) + (x / y);
	printf("z = (x * y) + (x / y) = %d\n", z);

	z = x + y + 2004;
	printf("z = x + y + 2004 = %d\n", z);
}