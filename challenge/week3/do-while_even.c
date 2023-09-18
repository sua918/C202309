#include <stdio.h>

int main()
{
	// i 선언
	int i = 0;
	// 무조건 한번 실행
	do {
		// i가 짝수이면 반복문 처음으로 돌아감
		if (i % 2 == 0) {
			i += 1;
			continue;
		}
		// i가 짝수가 아닌 경우 그냥 출력함
		printf("%d Hello World!\n", i++);
	} while (i < 10);

	return 0;
}