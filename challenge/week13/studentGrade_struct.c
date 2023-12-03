#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �л��� �̸��� ������ ������ ����ü ����
typedef struct Student {
  int scores;
  char *name;
} STUDENT;

int numStudent;

// �Լ� ���� ����
void InitializeStudent(STUDENT *student);
void ClassifyStudents(STUDENT *student, int num, char targetGrade);
int SumScores(STUDENT *student, int num);
double AverageScores(STUDENT *student, int num);
void PrintRanks(STUDENT *student, int num);

int main() {
  int numStudent;
  printf("�л� ���� �Է��ϼ���: ");
  scanf_s("%d", &numStudent);

  // ����ü �����͸� ����Ͽ� �������� �迭 �Ҵ�
  STUDENT *students = (STUDENT *)malloc(numStudent * sizeof(STUDENT));

  if (students == NULL) {
    return 1;
  }
  // �� ����ü�� ���� �Է�
  for (int i = 0; i < numStudent; i++) {
    InitializeStudent(&students[i]);
  }

  // Ư�� ������ �Է¹���
  char target;
  printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�: ");
  scanf_s("%c", &target, 1);

  ClassifyStudents(students, numStudent, target);  // �Լ� ȣ��

  int sum = SumScores(students, numStudent);             // �Լ� ȣ��
  double average = AverageScores(students, numStudent);  // �Լ� ȣ��
  printf("�л��� ������ �� ���� %d �̰�, ��� ���� %lf�Դϴ�.\n", sum, average);

  PrintRanks(students, numStudent);  // �Լ� ȣ��

    // �Ҵ�� �޸� ����
  for (int i = 0; i < numStudent; i++) {
    free(students[i].name);
  }
  free(students);

  return 0;
}

// ����ü �ʱ�ȭ �Լ�
void InitializeStudent(STUDENT *student) {
  // ���ڿ��� �Է¹޾� �������� �޸� �Ҵ�
  printf("�л� �̸��� �Է��ϼ���: ");
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  char ch1 = getchar();  // ���� �ӽ� ���� ����, ���� ����� ����

  student->name = (char *)malloc((strlen(temp) + 1) * sizeof(char));
  strcpy_s(student->name, strlen(temp) + 1, temp);

  // ������ ����ü ����� ���ؼ��� �����ϰ� ����
  printf("�л� ������ �Է��ϼ���: ");
  scanf_s("%d", &student->scores);
  char ch2 = getchar();  // ���� �ӽ� ���� ����, ���� ����� ����
}

// �л� ������ ������ ���� �з��ϴ� �Լ� ����
void ClassifyStudents(STUDENT *student, int num, char targetGrade) {
  printf("�л� ���� �з�:\n");
  char grade = ' ';
  for (int i = 0; i < num; i++) {
    // �Էµ� �л��� ������ ���� �з�
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
      printf("%s �л��� %c ������ �޾ҽ��ϴ�.\n", student[i].name, targetGrade);
    }
  }
}

// �л� ���� �� ���� ����ϴ� �Լ� ����
int SumScores(STUDENT *student, int num) {
  int sum = 0;

  // �л����� ������ ������� ���ϴ� for��
  for (int i = 0; i < num; i++) {
    sum += student[i].scores;
  }

  // ������ �� �� ��ȯ
  return sum;
}

// �л� ���� ��� ���� ����ϴ� �Լ� ����
double AverageScores(STUDENT *student, int num) {
  double average;

  // �Լ� ȣ��
  int sum = SumScores(student, num);

  // �л����� ������ ����� ���
  average = (double)sum / (double)num;

  // �л����� ������ ����� ��ȯ
  return average;
}

// �л� �� ���� ������ ����ϴ� �Լ� ����
void PrintRanks(STUDENT *student, int num) {
  // �л����� ������ ���� ���ϴ� ���� for��
  for (int i = 0; i < num; i++) {
    int rank = 1;
    for (int j = 0; j < num; j++) {
      // ������ �� ��� �������� ���� ��� ����� 1�� ����
      if (student[i].scores < student[j].scores) {
        rank += 1;
      }
    }
    printf("%s �л��� ������ %d �Դϴ�.\n", student[i].name, rank);
  }
}