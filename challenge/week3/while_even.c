#include <stdio.h>

int main()
{
	// i ����
	int i = 0;
	// i�� 10���� ������ �ݺ�
	while (i < 10){
		// i�� ¦���̸� �ݺ��� ó������ ���ư�
		if (i % 2 == 0) {
			i += 1;
			continue;
		}
		// i�� ¦���� �ƴ� ��� �׳� �����
		printf("%d Hello World!\n", i);
		i += 1;
	}
	return 0;
}