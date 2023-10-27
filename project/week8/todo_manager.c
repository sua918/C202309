#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

int main() {
	char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϴ� 2���� �迭 ����
	int taskCount = 0; // �� ���� ���� �����ϱ� ���� ���� ����

	printf("TODO ����Ʈ ����! \n");

	while (1) {
		int choice = -1; // choice�� ���� ���� ���� �ʱ�ȭ

		// ����ڿ��� �޴��� ����ϰ� �Է¹���
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");;
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5. �� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // ���߿� terminate ���� �ٲ㼭 �����ϱ� ����
		int delIndex = -1;  // �� �� ������ ���� ���� ���� ���� �ʱ�ȭ
		int changeIndex = -1; // �� �� ������ ���� ���� ���� ���� �ʱ�ȭ

		// ����ڰ� ������ �޴��� ������
		switch (choice) {
		case 1:
			// �߰��� �� ���� �Է¹޾� ������
			printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
			scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));
			printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks[taskCount]);
			taskCount++;
			break;
		case 2:
			// ������ �� ���� ��ȣ�� �Է¹���
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����): ");
			scanf_s("%d", &delIndex);

			// ���� ��ȣ�� �Է��� ��� ����
			if (delIndex > taskCount || delIndex <= 0) {
				printf("���� ������ ������ϴ�.\n");
			}

			// ��ȣ�� ����� �Է��� ��� ����
			else {
				printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);

				// �迭�� ���� �迭�� ���ڿ��� ������ �Ұ����ϹǷ�
				// ���ڿ� ���� �Լ��� ������ ������ ����
				strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

				// ����ڰ� ������ �� �� ���� �� ���� �մ���
				for (int i = delIndex; i < taskCount + 1; i++) {
					strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
				}
				taskCount -= 1;
			}
			break;
		case 3:
			// �� �� ����� �����
			printf("�� �� ���\n");
			for (int i = 0; i < taskCount; i++) {
				printf("%d. %s \n", i + 1, tasks[i]);
			}
			printf("\n");
			break;
		case 4:
			// ���Ḧ ���� terminate ���� 1�� �ٲ�
			terminate = 1;
			break;
		case 5:
			// ������ �� ���� ��ȣ�� �Է¹���
			printf("�� �� ����\n");
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����): ");
			scanf_s("%d", &changeIndex);

			// ���� ��ȣ�� �Է��� ��� ����
			if (changeIndex > taskCount || changeIndex <= 0) {
				printf("���� ������ ������ϴ�.\n");
			}

			// ��ȣ�� ����� �Է��� ��� ����
			else {
				printf("%d. %s : �� ���� �����մϴ�.\n", changeIndex, tasks[changeIndex - 1]);

				// ������ �� ���� ���ο� �� �Ϸ� �ʱ�ȭ��
				printf("���ο� �� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
				scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
				printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", tasks[changeIndex - 1]);
			}
			break;

		default:
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		// terminate ���� 1�� �Ǹ� ������
		if (terminate == 1) {
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}

		// �� �� 10���� �� �� ��� �����ϰ� ���α׷��� ����
		if (taskCount == 10) {
			printf("�� ���� �� á���ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}
	}
}