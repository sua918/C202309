#include <stdio.h>

int main() {

	// num ����
	int num = 0;

	// �޽��� ��� �� ����ڿ��� num ���� �Է¹���
    printf("���ڸ� �Է��Ͻÿ�: ");
	scanf_s("%d", &num);

	// if-else������ ����ڰ� �Է��� ���� ���� �ٸ� ����� ������ ��
	if (num == 0) {
		printf("zero");
	}
	else if (num == 1) {
		printf("one");
	}
	else if (num == 2) {
		printf("two");
	}
	else {
		printf("not 0 ~ 2");
	}
	return 0;
}