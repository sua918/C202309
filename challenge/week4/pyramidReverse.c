#include <stdio.h>

int main()
{
	int floor;
	printf("몇 층을 쌓겠습니까? (5~100)");
	// 사용자에게서 floor 값을 입력받음
	scanf_s("%d", &floor);

	for (int i = floor; i > 0; i--) {
		// 한 줄에 S를 floor-i개 출력함
		for (int j = floor - i; j > 0; j--) {
			printf("S");
		}
		// 한 줄에 *을 i*2-1, ... , 11, 9, 7, 5, 3, 1개 출력함
		for (int k = 0 ; k < i * 2 - 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}