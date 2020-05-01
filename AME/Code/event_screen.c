#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "game_function.h"
#include "mc.h" 
#include "map.h"
#include "item.h"

extern x, y; 

void tutorial(){
	puts("�̵��Ϸ��� w,a,s,d�� �����ּ���");
	puts("����â�� ����Ϸ��� v�� �����ּ���");
	puts("�κ��丮�� ����Ϸ��� e�� �����ּ���");
	puts("���߷��� p�� �����ּ���"); 
	puts("��, �׸��� ��� �Դٰ��� �ϰ� �������ٵ�, \n�׷��� �ڽſ��Ը� ������ ���� �־��(��Ż��)\n");
	return ;
}

void start_screen(){
	srand(time(NULL));
	int i = 1;
	while(i){
		if(kbhit()) break;
		printf("*******************************\n");
		printf("*  Android Maze Escape: 2253  *\n");
		printf("*                  -AME: 2253 *\n");
		printf("* (�����ڵ� ������ ��ģ ����) *\n");
		if(i%2 == 1){
			printf("*   Enter�� ���� �����ϼ���   *\n");
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
	while ((getchar()) != '\n');
	system("cls");
	tutorial();
	int id = rand()%6+1;
	map(id, -2, 0);
	MC(0,0,0,0,0,0);
	game_start(id, 0);
}

void stop(char type){
	system("cls");
	switch(type){
		case 'n':
			puts("AME�� �÷��� ���ּż� �����մϴ�");
			Sleep(400);
			puts("�������� ��:");
			puts("�׷��� ���� ���̳׿�?");
			puts("���������� ��ư� �ߴٰ� ���������� �ʾҴµ�");
			puts("���߿� ��ȸ�� �ȴٸ� �� ��ư� �����ڽ��ϴ�.");
			puts("(������2-�� �� ���� �÷��� �����߽��ϴ�)"); 
			Sleep(400);
			break;
		case 'm':
			puts("���� ���� �����ϱ� ���ݱ��� �Ѱ͵� �ٽ��ؾ� �Ѵٴ� �� �˾Ƶνð�");
			Sleep(400);
			puts("�߰�����");
			Sleep(1000);
			puts("�� �´� ������ �����Ҷ� �̹� ���� �ƴҼ��� �־�䤻��");
			Sleep(3000);
			break;
		default:
			puts("error: �����ڰ� �ٺ��� �ڵ� ����� ���� ·�� ����");
			break; 
	}
	exit(0);
}

void reset(int id){
	x = 10; y = 10;
	int i;
	inventory(5, 0, 0);
	map(id, 2, 0);
	money(4,0);
	resting_area(0, 1);
	map_interact(101, id);
	MC(6,0,0,0,0,0);
	time_spent(-1);
}

void map_clear(int prev){
	reset(prev);
	system("cls");
	srand(time(NULL));
	puts("�����մϴ�! Ż�⼺��!\n");
	Sleep(400);
	puts("���� ���Ұž�?\n"); 
	Sleep(400);
	printf("�ɼ� 1: ���� �� Ŭ�����ϱ�(�� ���� �ٽ� �����ڴ����� �𸣰�����)\n");
	Sleep(400);
	printf("�ɼ� 2: ��� �� �� �ϵ��� Ŭ�����ϱ� (�ð����� ����)\n");
	Sleep(400);
	printf("�ɼ� 3: ���ظ԰ڴ� (������: ����)\n");
	Sleep(200);
	int input=0;
	while(input!= 1 && input != 2 && input != 3){  
		printf(">> "); scanf("%d", &input); while ((getchar()) != '\n');
		if(input == 1){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			system("cls");
			game_start(i, 0);
		}else if(input == 2){
			system("cls");
			game_start(prev, 1);
		}else if(input == 3){
			system("cls");
			stop('n');
		}else{
			printf("�̻��Ѱ� ġ�� ���� ����� ġ����: ");
			continue;
		}
	}
}

void fail(int prev){
	reset(prev);
	srand(time(NULL)); 
	system("cls");
	printf("�����߱���...�� 20�и��� Ŭ����� �� ���������?\n");
	Sleep(750);
	printf("��¿ �� ����, �����ϼ���\n");
	Sleep(750);
	puts("1: �ٽ� ���� �Ѵ� \n2: �Ϲ��̳� �ؾ߰ڴ� \n3:�ٸ��� �ϵ��� �غ��� \n4: �׳� ���ҷ� �̵� ����");
	int input=0;
	printf(">> "); scanf("%d", &input); while ((getchar()) != '\n');
	while(input != 1 && input != 2 && input != 3 && input != 4){  
		printf(">> "); scanf("%s", input);
		if(input == 1){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			game_start(i, 0);
		}else if(input == 2){
			game_start(prev, 1);
		}else if(input == 3){
			int i = rand() % 4;
			while(i == prev){
				i = rand() % 4;
			}
			game_start(i, 1);
		}else if(input == 4){
			stop('n');
		}else{
			printf("�̻��Ѱ� ġ�� ���� ����� ġ����: ");
			continue;
		}
	}
}

