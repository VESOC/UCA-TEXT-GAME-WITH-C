#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

void start_screen(){
	int i = 1;
	while(i){
		if(kbhit()) break;
		printf("*******************************\n");
		printf("*  Android Maze Escape: 2253  *\n");
		printf("*                  -AME: 2253 *\n");
		printf("* (�����ڵ� ������ ��ģ ����) *\n");
		if(i%2 == 1){
			printf("*  �ƹ� Ű�� ���� �����ϼ���  *\n");
		}else{
			printf("*                             *\n");
		}
		if(i%2 == 0){
			printf("*      ����, ���� ����!!!     *\n");
		}else{
			printf("*                             *\n");
		}
		printf("*******************************\n");
		Sleep(500);
		system("cls");
		i++;
	}
	//game_start(0);
}

void map_clear(int prev){
	srand(time(NULL));
	puts("�����մϴ�! Ż�⼺��!");
	Sleep(400);
	puts("���� ���Ұž�?"); 
	Sleep(400);
	printf("�ɼ� 1: ���ο� �� Ŭ�����ϱ�(�� ���� �ٽ� �����ڴ����� �𸣰����� Ŀ�ǵ�: new)\n");
	Sleep(400);
	printf("�ɼ� 2: ��� �� �� �ϵ��� Ŭ�����ϱ� (�ð����� �����ϱ� ������ �غ��� Ŀ�ǵ�: again)\n");
	Sleep(400);
	printf("�ɼ� 3: ���ظ԰ڴ� (������: ���� Ŀ�ǵ�: fk)\n");
	Sleep(200);
	char input[6];
	while(strcmp(input, "new") != 0 && strcmp(input, "again") != 0 && strcmp(input, "fk") != 0){ 
		scanf("%s", &input);
		printf("%s\n", &input);
		if(strcmp(input, "new") == 0){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			//game_start(i);
		}else if(strcmp(input, "again") == 0){
			puts("again");
			//game_start(prev, 1);
		}else if(strcmp(input, "fk") == 0){
			puts("fk");
			//stop();
		}else{
			printf("�̻��Ѱ� ġ�� ���� ����� ġ����: ");
			continue;
		}
	}
}
