#include <stdio.h>
#define STUDENTS 5

// �л� ������ ������ ���� �з��ϴ� �Լ� ����
void classifyStudents(int *scores, char targetGrade) {
  printf("�л� ���� �з�:\n");
  char grade = ' ';
  for (int i = 0; i < STUDENTS; i++) {
    // �Էµ� �л��� ������ ���� �з�
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
      printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1, targetGrade);
    }
  }
}

// �л� ���� �� ���� ����ϴ� �Լ� ����
int sumScores(int *scores) {
  int sum = 0;

  // �л����� ������ ������� ���ϴ� for��
  for (int i = 0; i < STUDENTS; i++) {
    sum += *scores;
    scores += 1;
  }

  // ������ �� �� ��ȯ
  return sum;
}

// �л� ���� ��� ���� ����ϴ� �Լ� ����
double averageScores(int *scores) {
  int sum = 0;
  int num = STUDENTS;
  double average;

  // �Լ� ȣ��
  int sum = sumScores(scores);

  // �л����� ������ ����� ���
  average = (double)sum / (double)num;

  // �л����� ������ ����� ��ȯ
  return average;
}

// �л� �� ���� ������ ����ϴ� �Լ� ����
void printRanks(int *scores) {
  // �л����� ������ ���� ���ϴ� ���� for��
  for (int i = 0; i < STUDENTS; i++) {
    int rank = 1;
    for (int j = 0; j < STUDENTS; j++) {
      // ������ �� ��� �������� ���� ��� ����� 1�� ����
      if (scores[i] < scores[j]) {
        rank += 1;
      }
    }
    printf("%d �л��� ������ %d �Դϴ�.\n", i + 1, rank);
  }
}

int main() {
  int scores[STUDENTS];

  // �л����� ������ �Է¹޴� for��
  for (int i = 0; i < STUDENTS; i++) {
    printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);
    scanf_s("%d", &scores[i]);
  }

  char ch = getchar();  // ���� �ӽ� ���� ����, ���� ����� ����

  // Ư�� ������ �Է¹���
  char target;
  printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�: ");
  scanf_s("%c", &target, 1);

  classifyStudents(scores, target);  // �Լ� ȣ��

  int sum = sumScores(scores);             // �Լ� ȣ��
  double average = averageScores(scores);  // �Լ� ȣ��
  printf("�л��� ������ �� ���� %d �̰�, ��� ���� %lf�Դϴ�.\n", sum, average);

  printRanks(scores);  // �Լ� ȣ��

  return 0;
}