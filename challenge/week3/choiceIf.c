#include <stdio.h>

int main() {
	// choice ����
	int choice;

	// �޴� ��� �� ����ڿ��� choice ���� �Է¹���
	printf("1. ���� ����\n");
	printf("2. ���� ���� �ݱ�\n");
	printf("3. ����\n");
	scanf_s("%d", &choice);

	// if-else������ ����ڰ� �Է��� ���� ���� �ٸ� ����� ������ ��
	if (choice == 1) {
		printf("������ �����մϴ�.");
	}
	else if (choice == 2) {
		printf("���� ���� �ݽ��ϴ�.");
	}
	else if (choice == 3) {
		printf("�����մϴ�.");
	}
	else {
		printf("�߸� �Է��ϼ̽��ϴ�.");
	}
	return 0;
}