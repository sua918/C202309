#include <stdio.h>

int main() 
{
	int floor;
	printf("몇 층을 쌓겠습니까? (5~100)");
	// 사용자에게서 floor 값을 입력받음
	scanf_s("%d", &floor);

	// floor개의 줄을 출력함
	for (int i = 0; i < floor; i++) {
		// 한 줄에 S를 floor-1-j개 출력함
		for (int j = i; j < floor - 1; j++) {
			printf("S");
		}
		// 한 줄에 *을 1, 3, 5, 7, ... , i*2+1개 출력함
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}