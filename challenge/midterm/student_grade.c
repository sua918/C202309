#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

// 함수 선언
void printStudentResults(char studentNames[STUDENTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]);
void printSubjectResults(char subjectNames[SUBJECTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]);

int main() {
  char subjectNames[SUBJECTS][CHARNUM] = {"퀴즈", "중간고사", "기말고사"};
  char studentNames[STUDENTS][CHARNUM] = {""};  // 학생 이름이 저장될 배열
  double studentScores[STUDENTS][SUBJECTS] = {
      0.0};  // 학생의 시험 별 성적의 점수가 저장될 배열

  // 학생 이름을 입력받음
  printf("학생 %d명의 이름의 입력을 시작합니다. \n", STUDENTS);
  for (int i = 0; i < STUDENTS; i++) {
    printf("\t%d번째 학생의 이름을 입력하세요: ", i + 1);
    scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i]));
  }

  // 입력받은 학생 이름이 제대로 저장되었는지 확인함
  printf("학생 이름이 모두 입력되었습니다. \n");
  printf("입력된 학생 이름은 다음과 같습니다. \n");
  for (int i = 0; i < STUDENTS; i++) {
    printf("%s", studentNames[i]);
    if (i != STUDENTS - 1) {
      printf(", ");
    }
  }
  printf("\n");
  printf("--------------------\n");

  // 학생들의 시험 별 점수를 입력받음
  printf(
      "각 학생의 %s, %s, %s 점수를 차례대로 입력해주세요. (띄어쓰기 구분)\n ",
      subjectNames[0], subjectNames[1], subjectNames[2]);
  for (int i = 0; i < STUDENTS; i++) {
    printf("\t%s의 성적: ", studentNames[i]);
    scanf_s("%lf %lf %lf", &studentScores[i][0], &studentScores[i][1],
            &studentScores[i][2]);
  }

  printf("학생들의 시험 점수가 모두 입력 되었습니다.\n");
  printf("--------------------\n");
  printf("학생 별 성적은 다음과 같습니다 \n");

  // 학생 별 평균 점수를 출력하는 함수 호출
  printStudentResults(studentNames, studentScores);

  printf("--------------------\n");
  printf("과목 별 평균 점수는 아래와 같습니다. \n");

  // 과목 별 평균 점수를 출력하는 함수 호출
  printSubjectResults(subjectNames, studentScores);

  printf("프로그램을 종료합니다. ");
  return 0;
}

// 학생 별 평균 점수를 출력하는 함수 정의
void printStudentResults(char studentNames[STUDENTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]) {
  double averageScores[STUDENTS];
  // 2중 for문을 사용하여 학생별 과목들의 점수 합과 평균을 구하고 출력함
  for (int i = 0; i < STUDENTS; i++) {
    double totalScores = 0;
    for (int j = 0; j < SUBJECTS; j++) {
      totalScores += studentScores[i][j];
    }
    double finalScore = totalScores / SUBJECTS;
    printf("\t%s의 평균 점수: %.2lf\n", studentNames[i], finalScore);
  }
}

// 과목 별 평균 점수를 출력하는 함수 선언
void printSubjectResults(char subjectNames[SUBJECTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]) {
  double averageScores2[SUBJECTS];
  // 2중 for문을 사용하여 과목별 학생들의 점수 합과 평균을 구하고 출력함
  for (int i = 0; i < SUBJECTS; i++) {
    double totalScores = 0;
    for (int j = 0; j < STUDENTS; j++) {
      totalScores += studentScores[j][i];
    }
    double subjectScore = totalScores / STUDENTS;
    printf("\t%s의 평균 점수는 %.2lf 입니다.\n", subjectNames[i], subjectScore);
  }
}