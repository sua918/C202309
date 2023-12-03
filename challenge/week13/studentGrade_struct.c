#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생의 이름과 성적을 저장할 구조체 정의
typedef struct Student {
  int scores;
  char *name;
} STUDENT;

int numStudent;

// 함수 원형 선언
void InitializeStudent(STUDENT *student);
void ClassifyStudents(STUDENT *student, int num, char targetGrade);
int SumScores(STUDENT *student, int num);
double AverageScores(STUDENT *student, int num);
void PrintRanks(STUDENT *student, int num);

int main() {
  int numStudent;
  printf("학생 수를 입력하세요: ");
  scanf_s("%d", &numStudent);

  // 구조체 포인터를 사용하여 동적으로 배열 할당
  STUDENT *students = (STUDENT *)malloc(numStudent * sizeof(STUDENT));

  if (students == NULL) {
    return 1;
  }
  // 각 구조체에 값을 입력
  for (int i = 0; i < numStudent; i++) {
    InitializeStudent(&students[i]);
  }

  // 특정 점수를 입력받음
  char target;
  printf("특정 점수 (A,B,C,D,F)를 입력하시오: ");
  scanf_s("%c", &target, 1);

  ClassifyStudents(students, numStudent, target);  // 함수 호출

  int sum = SumScores(students, numStudent);             // 함수 호출
  double average = AverageScores(students, numStudent);  // 함수 호출
  printf("학생들 점수의 총 합은 %d 이고, 평균 값은 %lf입니다.\n", sum, average);

  PrintRanks(students, numStudent);  // 함수 호출

    // 할당된 메모리 해제
  for (int i = 0; i < numStudent; i++) {
    free(students[i].name);
  }
  free(students);

  return 0;
}

// 구조체 초기화 함수
void InitializeStudent(STUDENT *student) {
  // 문자열을 입력받아 동적으로 메모리 할당
  printf("학생 이름을 입력하세요: ");
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  char ch1 = getchar();  // 버퍼 임시 저장 변수, 엔터 지우기 위함

  student->name = (char *)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(student->name, strlen(temp) + 1, temp);

  // 나머지 구조체 멤버에 대해서도 동일하게 수행
  printf("학생 성적을 입력하세요: ");
  scanf_s("%d", &student->scores);
  char ch2 = getchar();  // 버퍼 임시 저장 변수, 엔터 지우기 위함
}

// 학생 성적을 점수에 따라 분류하는 함수 정의
void ClassifyStudents(STUDENT *student, int num, char targetGrade) {
  printf("학생 성적 분류:\n");
  char grade = ' ';
  for (int i = 0; i < num; i++) {
    // 입력된 학생의 점수에 따라 분류
    if (student[i].scores >= 90) {
      grade = 'A';
    } else if (student[i].scores >= 80) {
      grade = 'B';
    } else if (student[i].scores >= 70) {
      grade = 'C';
    } else if (student[i].scores >= 60) {
      grade = 'D';
    } else {
      grade = 'F';
    }
    if (targetGrade == grade) {
      printf("%s 학생은 %c 점수를 받았습니다.\n", student[i].name, targetGrade);
    }
  }
}

// 학생 성적 총 합을 출력하는 함수 정의
int SumScores(STUDENT *student, int num) {
  int sum = 0;

  // 학생들의 성적을 순서대로 더하는 for문
  for (int i = 0; i < num; i++) {
    sum += student[i].scores;
  }

  // 성적의 총 합 반환
  return sum;
}

// 학생 성적 평균 수를 출력하는 함수 정의
double AverageScores(STUDENT *student, int num) {
  double average;

  // 함수 호출
  int sum = SumScores(student, num);

  // 학생들의 성적의 평균을 계산
  average = (double)sum / (double)num;

  // 학생들의 성적의 평균을 반환
  return average;
}

// 학생 별 성적 순위를 출력하는 함수 정의
void PrintRanks(STUDENT *student, int num) {
  // 학생들의 성적을 서로 비교하는 이중 for문
  for (int i = 0; i < num; i++) {
    int rank = 1;
    for (int j = 0; j < num; j++) {
      // 성적이 비교 대상 성적보다 작은 경우 등수에 1을 더함
      if (student[i].scores < student[j].scores) {
        rank += 1;
      }
    }
    printf("%s 학생의 순위는 %d 입니다.\n", student[i].name, rank);
  }
}