#include <stdio.h>

int main()
{
	// i ����
	int i = 0;
	// ������ �ѹ� ����
	do {
		// i�� ¦���̸� �ݺ��� ó������ ���ư�
		if (i % 2 == 0) {
			i += 1;
			continue;
		}
		// i�� ¦���� �ƴ� ��� �׳� �����
		printf("%d Hello World!\n", i++);
	} while (i < 10);

	return 0;
}