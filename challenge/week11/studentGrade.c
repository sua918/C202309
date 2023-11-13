#include <stdio.h>
#define STUDENTS 5

// 학생 성적을 점수에 따라 분류하는 함수 정의
void classifyStudents(int *scores, char targetGrade) {
  printf("학생 성적 분류:\n");
  char grade = ' ';
  for (int i = 0; i < STUDENTS; i++) {
    // 입력된 학생의 점수에 따라 분류
    if (scores[i] >= 90) {
      grade = 'A';
    } else if (scores[i] >= 80) {
      grade = 'B';
    } else if (scores[i] >= 70) {
      grade = 'C';
    } else if (scores[i] >= 60) {
      grade = 'D';
    } else {
      grade = 'F';
    }
    if (targetGrade == grade) {
      printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1, targetGrade);
    }
  }
}

// 학생 성적 총 합을 출력하는 함수 정의
int sumScores(int *scores) {
  int sum = 0;

  // 학생들의 성적을 순서대로 더하는 for문
  for (int i = 0; i < STUDENTS; i++) {
    sum += *scores;
    scores += 1;
  }

  // 성적의 총 합 반환
  return sum;
}

// 학생 성적 평균 수를 출력하는 함수 정의
double averageScores(int *scores) {
  int sum = 0;
  int num = STUDENTS;
  double average;

  // 함수 호출
  int sum = sumScores(scores);

  // 학생들의 성적의 평균을 계산
  average = (double)sum / (double)num;

  // 학생들의 성적의 평균을 반환
  return average;
}

// 학생 별 성적 순위를 출력하는 함수 정의
void printRanks(int *scores) {
  // 학생들의 성적을 서로 비교하는 이중 for문
  for (int i = 0; i < STUDENTS; i++) {
    int rank = 1;
    for (int j = 0; j < STUDENTS; j++) {
      // 성적이 비교 대상 성적보다 작은 경우 등수에 1을 더함
      if (scores[i] < scores[j]) {
        rank += 1;
      }
    }
    printf("%d 학생의 순위는 %d 입니다.\n", i + 1, rank);
  }
}

int main() {
  int scores[STUDENTS];

  // 학생들의 성적을 입력받는 for문
  for (int i = 0; i < STUDENTS; i++) {
    printf("학생 %d의 성적을 입력하세요: ", i + 1);
    scanf_s("%d", &scores[i]);
  }

  char ch = getchar();  // 버퍼 임시 저장 변수, 엔터 지우기 위함

  // 특정 점수를 입력받음
  char target;
  printf("특정 점수 (A,B,C,D,F)를 입력하시오: ");
  scanf_s("%c", &target, 1);

  classifyStudents(scores, target);  // 함수 호출

  int sum = sumScores(scores);             // 함수 호출
  double average = averageScores(scores);  // 함수 호출
  printf("학생들 점수의 총 합은 %d 이고, 평균 값은 %lf입니다.\n", sum, average);

  printRanks(scores);  // 함수 호출

  return 0;
}