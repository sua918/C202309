#include <stdio.h>

int main()
{
	int floor;
	printf("�� ���� �װڽ��ϱ�? (5~100)");
	// ����ڿ��Լ� floor ���� �Է¹���
	scanf_s("%d", &floor);

	for (int i = floor; i > 0; i--) {
		// �� �ٿ� S�� floor-i�� �����
		for (int j = floor - i; j > 0; j--) {
			printf("S");
		}
		// �� �ٿ� *�� i*2-1, ... , 11, 9, 7, 5, 3, 1�� �����
		for (int k = 0 ; k < i * 2 - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}