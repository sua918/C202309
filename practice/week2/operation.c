#include <stdio.h>

int main()
{
	// ���� x, y, z ����
	int x = 4;
	int y = 2;
	int z;

	// x�� y�� ���� ��� ���� z�� ���� �� ���
	z = x + y;
	printf("z = x + y = %d\n", z);

	// x�� y�� �� ��� ���� z�� ���� �� ���
	z = x - y;
	printf("z = x - y = %d\n", z);

	// x�� y�� ���� ��� ���� z�� ���� �� ���
	z = x * y;
	printf("z = x * y = %d\n", z);

	// x�� y�� ���� ��� ���� z�� ���� �� ���
	z = x / y;
	printf("z = x / y = %d\n", z);

}