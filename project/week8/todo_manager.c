#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

int main() {
	char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 할 일 목록을 저장하는 2차원 배열 선언
	int taskCount = 0; // 할 일의 수를 저장하기 위한 변수 선언

	printf("TODO 리스트 시작! \n");

	while (1) {
		int choice = -1; // choice를 관련 없는 수로 초기화

		// 사용자에게 메뉴를 출력하고 입력받음
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");;
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5. 할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // 나중에 terminate 값을 바꿔서 종료하기 위함
		int delIndex = -1;  // 할 일 삭제를 위해 관련 없는 수로 초기화
		int changeIndex = -1; // 할 일 수정을 위해 관련 없는 수로 초기화

		// 사용자가 선택한 메뉴를 수행함
		switch (choice) {
		case 1:
			// 추가할 할 일을 입력받아 저장함
			printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
			scanf_s("%s", tasks[taskCount], (int)sizeof(tasks[taskCount]));
			printf("할 일 ""%s""가 저장되었습니다\n\n", tasks[taskCount]);
			taskCount++;
			break;
		case 2:
			// 삭제할 할 일의 번호를 입력받음
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작): ");
			scanf_s("%d", &delIndex);

			// 없는 번호를 입력한 경우 실행
			if (delIndex > taskCount || delIndex <= 0) {
				printf("삭제 범위가 벗어났습니다.\n");
			}

			// 번호를 제대로 입력한 경우 실행
			else {
				printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);

				// 배열에 문자 배열인 문자열의 대입이 불가능하므로
				// 문자열 복사 함수로 공백을 복사해 삭제
				strcpy_s(tasks[delIndex - 1], sizeof(tasks[delIndex - 1]), "");

				// 사용자가 선택한 할 일 삭제 후 순서 앞당기기
				for (int i = delIndex; i < taskCount + 1; i++) {
					strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
				}
				taskCount -= 1;
			}
			break;
		case 3:
			// 할 일 목록을 출력함
			printf("할 일 목록\n");
			for (int i = 0; i < taskCount; i++) {
				printf("%d. %s \n", i + 1, tasks[i]);
			}
			printf("\n");
			break;
		case 4:
			// 종료를 위해 terminate 값을 1로 바꿈
			terminate = 1;
			break;
		case 5:
			// 수정할 할 일의 번호를 입력받음
			printf("할 일 수정\n");
			printf("수정할 할 일의 번호를 입력해주세요. (1부터 시작): ");
			scanf_s("%d", &changeIndex);

			// 없는 번호를 입력한 경우 실행
			if (changeIndex > taskCount || changeIndex <= 0) {
				printf("수정 범위가 벗어났습니다.\n");
			}

			// 번호를 제대로 입력한 경우 실행
			else {
				printf("%d. %s : 할 일을 수정합니다.\n", changeIndex, tasks[changeIndex - 1]);

				// 기존의 할 일을 새로운 할 일로 초기화함
				printf("새로운 할 일을 입력하세요 (공백 없이 입력하세요): ");
				scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
				printf("할 일 ""%s""가 저장되었습니다\n\n", tasks[changeIndex - 1]);
			}
			break;

		default:
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}

		// terminate 값이 1이 되면 종료함
		if (terminate == 1) {
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n");
			break;
		}

		// 할 일 10개가 다 찬 경우 실행하고 프로그램을 종료
		if (taskCount == 10) {
			printf("할 일이 다 찼습니다. 프로그램을 종료합니다.\n");
			break;
		}
	}
}