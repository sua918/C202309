#include <stdio.h>
#define STUDENTS 5

// 학생 성적을 점수에 따라 분류하는 함수
void classifyStudents(int scores[], char targetGrade) {
	printf("학생 성적 분류:\n");
	char grade = ' ';
	for (int i = 0; i < STUDENTS; i++) {
		// 입력된 학생의 점수에 따라 분류
		if (scores[i] >= 90) {
			grade = 'A';
		}
		else if (scores[i] >= 80) {
			grade = 'B';
		}
		else if (scores[i] >= 70) {
			grade = 'C';
		}
		else if (scores[i] >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}
		if (targetGrade == grade) {
			printf("%d 학생은 %c 점수를 받았습니다.", i + 1, targetGrade);
		}
	}
}

int main() {
	int scores[STUDENTS];

	// 학생들의 성적을 입력받는 for문
	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입력하세요: ", i + 1);
		scanf_s("%d", &scores[i]);
	}

	char ch = getchar(); // 버퍼 임시 저장 변수, 엔터 지우기 위함

	// 특정 점수를 입력받음
	char target;
	printf("특정 점수 (A,B,C,D,F)를 입력하시오: ");
	scanf_s("%c", &target, 1);

	// 함수 호출
	classifyStudents(scores, target);

	return 0;
}