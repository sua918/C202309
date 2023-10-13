#include <stdio.h>

// 함수 원형 선언하기
int hapf(int value);

int main()
{
	// 함수에서 계산한 결과를 출력함
	printf("1부터      10까지의 합은 %d\n", hapf(10));
	printf("1부터    100까지의 합은 %d\n", hapf(100));
	printf("1부터  1000까지의 합은 %d\n", hapf(1000));

	return 0;
}

// 함수 정의하기
int hapf(int value)
{
	int i = 1;
	int hap = 0;

	// i 값이 value가 될 때까지 hap에 i를 더함
	while (i <= value) {
		hap = hap + i;
		i = i + 1;
	}

	return hap;
}