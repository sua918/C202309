#include <stdio.h>

// 함수 원형 선언하기
long multiF(int value);

int main()
{
	// 함수에서 계산한 결과를 출력함
	printf("1부터 2까지의 곱은 %ld\n", multiF(2));
	printf("1부터 3까지의 곱은 %ld\n", multiF(3));
	printf("1부터 5까지의 곱은 %ld\n", multiF(5));

	return 0;
}

// 함수 정의하기
long multiF(int value)
{
	int i;
	long multi = 1;

	// i 값이 value가 될 때까지 multi에 i를 곱함
	for (i = 1; i <= value; i = i + 1)
	{
		multi = multi * i;
	}
	
	return multi;
}