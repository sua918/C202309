#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

// �Լ� ����
void printStudentResults(char studentNames[STUDENTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]);
void printSubjectResults(char subjectNames[SUBJECTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]);

int main() {
  char subjectNames[SUBJECTS][CHARNUM] = {"����", "�߰����", "�⸻���"};
  char studentNames[STUDENTS][CHARNUM] = {""};  // �л� �̸��� ����� �迭
  double studentScores[STUDENTS][SUBJECTS] = {
      0.0};  // �л��� ���� �� ������ ������ ����� �迭

  // �л� �̸��� �Է¹���
  printf("�л� %d���� �̸��� �Է��� �����մϴ�. \n", STUDENTS);
  for (int i = 0; i < STUDENTS; i++) {
    printf("\t%d��° �л��� �̸��� �Է��ϼ���: ", i + 1);
    scanf_s("%s", studentNames[i], (int)sizeof(studentNames[i]));
  }

  // �Է¹��� �л� �̸��� ����� ����Ǿ����� Ȯ����
  printf("�л� �̸��� ��� �ԷµǾ����ϴ�. \n");
  printf("�Էµ� �л� �̸��� ������ �����ϴ�. \n");
  for (int i = 0; i < STUDENTS; i++) {
    printf("%s", studentNames[i]);
    if (i != STUDENTS - 1) {
      printf(", ");
    }
  }
  printf("\n");
  printf("--------------------\n");

  // �л����� ���� �� ������ �Է¹���
  printf(
      "�� �л��� %s, %s, %s ������ ���ʴ�� �Է����ּ���. (���� ����)\n ",
      subjectNames[0], subjectNames[1], subjectNames[2]);
  for (int i = 0; i < STUDENTS; i++) {
    printf("\t%s�� ����: ", studentNames[i]);
    scanf_s("%lf %lf %lf", &studentScores[i][0], &studentScores[i][1],
            &studentScores[i][2]);
  }

  printf("�л����� ���� ������ ��� �Է� �Ǿ����ϴ�.\n");
  printf("--------------------\n");
  printf("�л� �� ������ ������ �����ϴ� \n");

  // �л� �� ��� ������ ����ϴ� �Լ� ȣ��
  printStudentResults(studentNames, studentScores);

  printf("--------------------\n");
  printf("���� �� ��� ������ �Ʒ��� �����ϴ�. \n");

  // ���� �� ��� ������ ����ϴ� �Լ� ȣ��
  printSubjectResults(subjectNames, studentScores);

  printf("���α׷��� �����մϴ�. ");
  return 0;
}

// �л� �� ��� ������ ����ϴ� �Լ� ����
void printStudentResults(char studentNames[STUDENTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]) {
  double averageScores[STUDENTS];
  // 2�� for���� ����Ͽ� �л��� ������� ���� �հ� ����� ���ϰ� �����
  for (int i = 0; i < STUDENTS; i++) {
    double totalScores = 0;
    for (int j = 0; j < SUBJECTS; j++) {
      totalScores += studentScores[i][j];
    }
    double finalScore = totalScores / SUBJECTS;
    printf("\t%s�� ��� ����: %.2lf\n", studentNames[i], finalScore);
  }
}

// ���� �� ��� ������ ����ϴ� �Լ� ����
void printSubjectResults(char subjectNames[SUBJECTS][CHARNUM],
                         double studentScores[STUDENTS][SUBJECTS]) {
  double averageScores2[SUBJECTS];
  // 2�� for���� ����Ͽ� ���� �л����� ���� �հ� ����� ���ϰ� �����
  for (int i = 0; i < SUBJECTS; i++) {
    double totalScores = 0;
    for (int j = 0; j < STUDENTS; j++) {
      totalScores += studentScores[j][i];
    }
    double subjectScore = totalScores / STUDENTS;
    printf("\t%s�� ��� ������ %.2lf �Դϴ�.\n", subjectNames[i], subjectScore);
  }
}