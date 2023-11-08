#include <stdio.h>

// 함수 원형 선언
void Summation(double* value1, double* value2, double* result);
void Subtraction(double* value1, double* value2, double* result);
void Multification(double* value1, double* value2, double* result);
void Division(double* value1, double* value2, double* result);

int main() {
  double a = 2, b = 3;
  double result;
  Summation(&a, &b, &result);
  printf("%.0lf + %.0lf = %.2lf \n", a, b, result);

  Subtraction(&a, &b, &result);
  printf("%.0lf - %.0lf = %.2lf \n", a, b, result);

  Multification(&a, &b, &result);
  printf("%.0lf * %.0lf = %.2lf \n", a, b, result);

  Division(&a, &b, &result);
  printf("%.0lf / %.0lf = %.2lf \n", a, b, result);

  return 0;
}

// 함수 정의, 포인터를 사용하여 함수 호출만으로 값을 변경한다
void Summation(double* value1, double* value2, double* result) {
  *result = *value1 + *value2;
}

void Subtraction(double* value1, double* value2, double* result) {
  *result = *value1 - *value2;
}

void Multification(double* value1, double* value2, double* result) {
  *result = *value1 * *value2;
}

void Division(double* value1, double* value2, double* result) {
  *result = *value1 / *value2;
}