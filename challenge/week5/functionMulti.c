#include <stdio.h>

// �Լ� ���� �����ϱ�
long multiF(int value);

int main()
{
	// �Լ����� ����� ����� �����
	printf("1���� 2������ ���� %ld\n", multiF(2));
	printf("1���� 3������ ���� %ld\n", multiF(3));
	printf("1���� 5������ ���� %ld\n", multiF(5));

	return 0;
}

// �Լ� �����ϱ�
long multiF(int value)
{
	int i;
	long multi = 1;

	// i ���� value�� �� ������ multi�� i�� ����
	for (i = 1; i <= value; i = i + 1)
	{
		multi = multi * i;
	}
	
	return multi;
}