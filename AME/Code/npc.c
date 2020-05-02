#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "item.h"
#include "inventory.h"

typedef struct NQ{			//NPC 
	int name;				//�̸� 
	char quest[100];			//����Ʈ ���� �� 
	char talk[100];			//���ɸ� ������ ù��° �� 
	char endt[100];			//����Ʈ�� ���������� ������ ��
	char sc[100];			//����Ʈ ���� 
	int item;				//����Ʈ ������ 
}NQ;
void assist_c(int mode,int code){	//mode 0=npc�̸� 1=���ΰ� ���code=�ڵ� 
	if(mode==0){
		char* namekind[16]={"AND","Sari","VSV","ATM","IWC","DNA","RNA","WIN","DOW","PIZ","PIE","CIC","AIA","APP","COK","ILY"};
		printf("%s : ",namekind[code]);
	}else if(mode==1){
		char* talk[8]={"���� �°ž�?\n","���� ��� �͵� �����ھ�?\n","��� �湮���ִ°� ������ �ʹ� �ð������ ������. ���� �����Ұ͵� ���ŵ�\n","���� ���� �Ҹ��� ���µ�..\n","��.. �ݰ���?\n","�󸥰��� ������ �ؾ����� �ʾ�?\n","�����ڵ��� ������ ������ �����־�?\n","�Ƹ� �� �̷ΰ� �������ص� ������ �ƴҲ���\n"};
		printf("%s",talk[code]);
	}
}

int NPCsp(int mode,int who){
	static NQ need[2];
	static int number[2]={0,0},tem1,tem2;
	if(mode == -1){
		number[0] = 0;
		number[1] = 0;
		return ;
	}
	if(number[who]==0){
		srand(time(NULL));
		tem1=rand()%10;
		tem2=rand()%5;
		if(tem1==0){
			strcpy(need[who].endt,"�׷��� ���ð��� �ٸ��Ŷ� �Ϸ����� �׷�?");
			need[who].name=tem2;
			strcpy(need[who].quest,"�� 1�� �����.");
			need[who].item=22; 
			strcpy(need[who].sc,"����ٵ� �� �����Գ�?");
		}else{
			strcpy(need[who].endt,"��¼��� �ž�");
			need[who].name=tem2+5;
			strcat(need[who].quest," 1�� ��������.");
			need[who].item=tem2+17;
			strcpy(need[who].sc,"�θ��� �θ� ������ ������ ������ �����ߴ�.");
		}
		number[who]++;
		Sleep(1000);
	}
	assist_c(0,need[who].name);
	if(mode==0){			//���� �λ� 
		printf("�ֱ׷��� �Ĵٺ��°ž�?\n");
	}else if(mode==1){		//����Ʈ ��� �� �������ڵ� ��ȯ
		assist_i(need[who].item);
		printf("%s\n",need[who].quest);
		return need[who].item;
	}else if(mode==2){		//���λ� 
		printf("%s\n",need[who].endt); 
	}else if(mode==3){		//����Ʈ �Ϸ� 
		printf("%s\n",need[who].sc);
		number[who]=0;
	}
}
void NPCs(int who){		//npc���(who 0=1��° npc,1=2��° npc)
	static int gq[2]={0,0},code[2];			//NPC�� ����Ʈ�� �޾Ҵ°� Ȯ��
	if(who == -1){
		gq[0] = 0;
		gq[1] = 0;
		return ;
	}
	int answer,num;
	char ans;
	NPCsp(0,who);
	if(gq[who]==0){
		Sleep(500);
		printf("\n�̾߱⸦ �ұ�?- 1    �׳�Ƣ�� �������� �ƴѰͰ���- 2\n\n");
		do{
			printf(">>> "); scanf("%c",&ans); if(ans == 10) continue; while ((getchar()) != '\n');
			answer = ans - '0';	
		}while(!(answer==2||answer==1));
		if(answer==1){
			code[who]=NPCsp(1,who);
			gq[who]++;
		}else if(answer==2){
			NPCsp(2,who);
		}
	}else{
		num=inventory(3,code[who],0);
		if(num>0){
			printf("����Ʈ �������� �ǳ��־���.\n");
			NPCsp(3,who);
			inventory(1,code[who],-1);
			if(code[who]==22){
				money(1,1000);			//���ɾ� ����Ʈ 
			}else{
				money(1,200);				//������ ����Ʈ 
			}
			gq[who]=0; 
		}
	}
}
int NPCfp(int mode,int who){			//��� ����Ʈ npc����1
	static NQ need[2];
	static int number=0,tem1,tem2;
	if(mode == -1){
		number = 0;
		return ;
	}
	if(number==0){
		srand(time(NULL));
		tem1=rand()%3;
		tem2=rand()%5;
		strcpy(need[0].talk,"��?");
		need[0].item=tem2+17;
		need[0].name=tem1+10;
		strcpy(need[1].talk,"��ü ���� ���°ž�..");
		need[1].name=tem1+13;
		Sleep(1000);
		number++;
	}
	assist_c(0,need[who].name);
	if(mode==0){			//who�� ù�λ� 
		printf("%s\n",need[who].talk);
	}else if(mode==1){		//�ִ����� ���� 
		printf("���ð��� ������ �� �Ƿڳ� ��������?\n");
	}else if(mode==2){		//�ִ����� ����Ʈ 
		assist_i(need[who].item);
		printf(" 1�� �Ƿ��ڿ��� ������. ��ġ�� �˾Ƽ� ã�ƺ�.\n");
		return need[0].item; 
	}else if(mode==3){		//�޴����� ����Ʈ �Ϸ� 
		printf("�ʾ��ݾ�. �̷��� �ϳ� �����µ� �󸶳� �ɸ��°ž�.\n");
		number=0;
	}
}
void NPCf(int who){	//�������Ʈ�� �ִ� npc ����
	static int number=0,gq=0,code;
	if(who = -1){
		number = 0;
		gq = 0;
		return ;
	}
	int answer,num;
	char ans;
	NPCfp(0,who);
	if(who==0&&gq==0){
		Sleep(500);
		printf("\n�̾߱⸦ �ұ�?- 1\t�׳�Ƣ��- 2\n\n");
		do{
			scanf("%c",&ans);	while ((getchar()) != '\n');
			answer = ans - '0';
		}while(!(answer==2||answer==1));
		if(answer==1){
			code=NPCfp(2,0);
			gq++;
		}else if(answer==2){
			NPCfp(1,0);
		}
	}else if(who==1&&gq==1){
		num=inventory(3,code,0);
		if(num>0){
			printf("����Ʈ �������� �ǳ��־���.\n");
			NPCfp(3,0);
			inventory(1,code,-1);
			money(1,350);
			gq=0;
		}
	}
}
int trashMC(int i){			//�μ��� ���ΰ�(Ż�ⱸ �˷��ִ� npc) 
	static int gq=0,tem1;
	if(i==-1){
		gq = 0;
		return ;
	}
	int num;
	if(gq==0){
		printf("�μ��� '���' : �ȳ�.\n\n");
		printf("�̾߱⸦ �մϴ�\n\n");
		printf("�μ��� '���' : ���ڱ� �̷� ��Ź�� �ؼ� �̾������� ���ɾ��� �ϳ� ����ټ� ������?\n");
		gq++;
	}else{
		srand(time(NULL));
		tem1=rand()%8;
		printf("�μ��� '���' : ");
		assist_c(1,tem1);
		num=inventory(3,22,0);
		Sleep(1000);
		if(num>0){
			printf("����Ʈ �������� �ǳ��־���.\n");
			printf("�μ��� '���' : ���� ������ �̰��ٰ� �Ƹ� Ż�ⱸ�� �� �� �����ž�.\n");
			inventory(1,22,-1);
			Sleep(1000);
			printf("IBuf�� �����! Ż�ⱸ�� ��ġ�� �˰ԵǾ����ϴ�.\n");
			inventory(1,23,1); 
			money(1,625);
			printf("�μ��� '���' : �߰�\n"); 
			return 1;
		}
	}	
}
