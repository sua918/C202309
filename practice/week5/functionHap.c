#include <stdio.h>

// �Լ� ���� �����ϱ�
int hapf(int value);

int main()
{
	// �Լ����� ����� ����� �����
	printf("1����      10������ ���� %d\n", hapf(10));
	printf("1����    100������ ���� %d\n", hapf(100));
	printf("1����  1000������ ���� %d\n", hapf(1000));

	return 0;
}

// �Լ� �����ϱ�
int hapf(int value)
{
	int i = 1;
	int hap = 0;

	// i ���� value�� �� ������ hap�� i�� ����
	while (i <= value) {
		hap = hap + i;
		i = i + 1;
	}

	return hap;
}