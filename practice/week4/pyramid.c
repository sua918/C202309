#include <stdio.h>

int main() 
{
	int floor;
	printf("�� ���� �װڽ��ϱ�? (5~100)");
	// ����ڿ��Լ� floor ���� �Է¹���
	scanf_s("%d", &floor);

	// floor���� ���� �����
	for (int i = 0; i < floor; i++) {
		// �� �ٿ� S�� floor-1-j�� �����
		for (int j = i; j < floor - 1; j++) {
			printf("S");
		}
		// �� �ٿ� *�� 1, 3, 5, 7, ... , i*2+1�� �����
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}