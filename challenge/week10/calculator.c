#include <stdio.h>

// 함수 원형 선언
void summation(double* value1, double* value2, double* result);
void subtraction(double* value1, double* value2, double* result);
void multification(double* value1, double* value2, double* result);
void division(double* value1, double* value2, double* result);

int main()
{
	double a = 2, b = 3;
	double result;
	summation(&a, &b, &result);
	printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

	subtraction(&a, &b, &result);
	printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

	multification(&a, &b, &result);
	printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

	division(&a, &b, &result);
	printf("%.0lf / %.0lf = %.2lf \n", a, b, result);

	return 0;
}

// 함수 정의, 포인터를 사용하여 함수 호출만으로 값을 변경한다
void summation(double* value1, double* value2, double* result) {
	*result = *value1 + *value2;
}

void subtraction(double* value1, double* value2, double* result) {
	*result = *value1 - *value2;
}

void multification(double* value1, double* value2, double* result) {
	*result = *value1 * *value2;
}

void division(double* value1, double* value2, double* result) {
	*result = *value1 / *value2;
}