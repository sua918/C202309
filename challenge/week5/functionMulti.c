#include <stdio.h>

// �Լ� ���� �����ϱ�
long multiF(int value);

void main()
{
	// �Լ����� ����� ����� �����
	printf("1���� 2������ ���� %d\n", multiF(2));
	printf("1���� 3������ ���� %d\n", multiF(3));
	printf("1���� 5������ ���� %d\n", multiF(5));
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