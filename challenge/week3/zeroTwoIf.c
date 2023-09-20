#include <stdio.h>

int main() {

	// num 선언
	int num = 0;

	// 메시지 출력 후 사용자에게 num 값을 입력받음
    printf("숫자를 입력하시오: ");
	scanf_s("%d", &num);

	// if-else문으로 사용자가 입력한 값에 따라 다른 결과가 나오게 함
	if (num == 0) {
		printf("zero");
	}
	else if (num == 1) {
		printf("one");
	}
	else if (num == 2) {
		printf("two");
	}
	else {
		printf("not 0 ~ 2");
	}
	return 0;
}