#include <stdio.h>

int main()
{
	// i 선언
	int i = 0;
	// i가 10보다 작으면 반복
	while (i < 10){
		// i가 짝수이면 반복문 처음으로 돌아감
		if (i % 2 == 0) {
			i += 1;
			continue;
		}
		// i가 짝수가 아닌 경우 그냥 출력함
		printf("%d Hello World!\n", i);
		i += 1;
	}
	return 0;
}