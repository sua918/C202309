#include <stdio.h>

int main() {
	// choice 선언
	int choice;

	// 메뉴 출력 후 사용자에게 choice 값을 입력받음
	printf("1. 파일 저장\n");
	printf("2. 저장 없이 닫기\n");
	printf("3. 종료\n");
	scanf_s("%d", &choice);

	// if-else문으로 사용자가 입력한 값에 따라 다른 결과가 나오게 함
	if (choice == 1) {
		printf("파일을 저장합니다.");
	}
	else if (choice == 2) {
		printf("저장 없이 닫습니다.");
	}
	else if (choice == 3) {
		printf("종료합니다.");
	}
	else {
		printf("잘못 입력하셨습니다.");
	}
	return 0;
}