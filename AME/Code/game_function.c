#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "map.h"
#include "event_screen.h"
#include "inventory.h"
#include "mc.h"

extern int x;
extern int y;
 
int move(char dir, int id){ //�̵� �Լ� ����� �� id�� ���ڷ� ����  
		switch(dir){ //��ǥ �̵��� �̵� �� ��ǥ�� �ִ� �� ��ȯ  
			case 'w': //��  
				x--;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				}  else{
					x+=1;
					//printf("%d %d\n", x, y); 
					puts("���Դϴ� �� ������ ���� �Ͻô� ����?");	
					return 0;
				}
			case 'a': //��  
				y--;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				}  else {
					y++;
					puts("���Դϴ� �� ������ ���� �Ͻô� ����?");	
					return 0;
				}
			case 's': //��  
				x++;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				}  else {
					x--;
					puts("���Դϴ� �� ������ ���� �Ͻô� ����?");	
					return 0;
				}
			case 'd': //��  
				y++;
				if(map(id, 0, 0)[x][y] != 0 && x<21 && x>-1){
					return map(id, 0, 0)[x][y];
				} else {
					y--;
					puts("���Դϴ� �� ������ ���� �Ͻô� ����?");	
					return 0;
				}
			default:
				printf("����ε� �Է��� �ƴմϴ� �ٽ� �Է��ϼ���\n");
				break;
		}
}

void time_spent(int id){
	static int num=0;
	if(id == -1){
		num = 0;
		return ;
	}
	clock_t beg;
	if(num == 0){
		beg = clock();
		num++;
	} 
	double timeS = (double)(clock()-beg) / CLOCKS_PER_SEC;
	if(timeS > 3600) fail(id);
}

void game_start(int id, int mode){ //���� ���� �Լ� id�� �� �Ǻ�  
	idRT(id);
	char cmd, ecmd;
	int code, i;
	if(mode == 1) time_spent(id);
	printf(">> "); scanf("%c", &cmd); while ((getchar()) != '\n');  //Ŀ�ǵ� �Է� / w,a,s,d,e,p,v 
	switch(cmd){
		case 'w':
		case 'a':
		case 's':
		case 'd':
			code = move(cmd, id);
		//	printf("%d %d %d %d\n", id, x, y, code);
			if(code != 0) map_interact(code, id);
			break;
		case 'e':
			inventory(2, 0, 0);
			break;
		case 'v':
			printf("  -------------------------Android: 2253�� ����â-------------------------\n");
			printf("\t\t-ü��: %4d -���ݼӵ�: %4d -��: %4d\n\t\t-�Ӽ�(��): %4d -�Ӽ�(����): %4d\n", MC(0,0,0,0,0,0).hp, MC(0,0,0,0,0,0).speed, MC(0,0,0,0,0,0).str, MC(0,0,0,0,0,0).fire, MC(0,0,0,0,0,0).elect);
			printf("  ------------------------------------------------------------------------\n");
			break; 
		case 'p':
			stop('m');
			break;
	}
	Sleep(400);
	game_start(id, mode);
}

