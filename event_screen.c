#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

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
	puts("���� ���Ұž�?"); 
	printf("�ɼ� 1: ���ο� �� Ŭ�����ϱ�(�� ���� �ٽ� �����ڴ����� �𸣰����� Ŀ�ǵ�: new)");
	Sleep(400);
	printf("�ɼ� 2: ��� �� �� �ϵ��� Ŭ�����ϱ� (�ð����� �����ϱ� ������ �غ��� Ŀ�ǵ�: again)");
	Sleep(400);
	printf("�ɼ� 3: ���ظ԰ڴ� (������: ���� Ŀ�ǵ�: fk)");
	Sleep(200);
	char* input;
	scanf("%s", )
	if(input == "new"){
		int i = rand() % 4;
		while(i == prev){
			i = rand() % 4;
		}
		//game_start(i);
	}else if(input == "again"){
		game_start_hardcore(prev);
	}else if(input == "fk"){
		stop();
	}else{
		printf("�̻��Ѱ� ġ�� ���� ����� ġ����: "); scanf("%s", input); 
	}
	
}

int main() {
	start_screen();
}
