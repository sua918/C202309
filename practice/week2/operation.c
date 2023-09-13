#include <stdio.h>

int main()
{
	// 변수 x, y, z 선언
	int x = 4;
	int y = 2;
	int z;

	// x와 y를 더한 결과 값을 z에 저장 후 출력
	z = x + y;
	printf("z = x + y = %d\n", z);

	// x와 y를 뺀 결과 값을 z에 저장 후 출력
	z = x - y;
	printf("z = x - y = %d\n", z);

	// x와 y를 곱한 결과 값을 z에 저장 후 출력
	z = x * y;
	printf("z = x * y = %d\n", z);

	// x를 y로 나눈 결과 값을 z에 저장 후 출력
	z = x / y;
	printf("z = x / y = %d\n", z);

}