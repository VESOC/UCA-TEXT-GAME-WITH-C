#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "inventory.h"
#include "mc.h"
#include "spirit-type.h"

extern int x,y; 		//mc��ǥ 

void assist_i(int code){		//������ �̸� ��� ���� �Լ�(code=�ڵ� �Է�)
	char* kind[26]={"��","â","����","���絿��","����(�� 7)","����(�� 10)","����(�ӵ� 7)","����(�ӵ� 10)","�����(�� 7)","�����(�� 10)","�����(�ӵ� 7)","�����(�ӵ� 10)","��������(��)","��������(ü��)","��������(�ӵ�)","��������(�κ��丮 3����)","��������(�κ��丮 5����)","ö��","����","����","cpu","�ð���","���ɾ�","IBuf","�г�Ƽ���ñ�"};
	printf("%s",kind[code]); 	
} 

int money(int mode,int give){	//��������(mode 0=���������,1=��� ����,2=����� ������ ��� give=����) 
	static int gold=0;
	if(mode==0){			//��������� ��� 
		printf("���� ������ : %03d\n",gold);
	}else if(mode==1){		//��� ����
		gold+=give;
		if(give>0){
			printf("%d��带 �����!\n",give);
		}else if(give<0){
			printf("%d��带 ����ߴ�.\n", give);
		}
	}else if(mode==2){		//����� ������ ��� 
		gold=gold/2;
	}else if(mode==3){
		return gold;
	}else if(mode == 4){
		gold = 0;
	}
}
int de_buff(int mode, int kind){	//���� ����� ������(mode 0=����, 1=�����,2=���絿�� ,kind 0=��7, 1=��10, 2�ӵ�7, 3=�ӵ�10)
	int code[4]={4,5,6,7};			//��������� �ڵ� 
	char* name[4]={"����(�� 7)","����(�� 10)","����(�ӵ� 7)","����(�ӵ� 10)"};	//�Ĺ� ��¿�� 
	int n;
	if(mode==0){
		printf("%s!\n",name[kind]);
		n = inventory(1,code[kind],1); 
	}else if(mode==1){
		printf("��%s!\n",name[kind]);
		n = inventory(1,code[kind]+4,1); 
	}else if(mode==2){
		printf("���絿��!\n");
		n = inventory(1,3,1);	
	}
	return n;
}
int weapon(int mode,int number){		//�����Լ�(mode 0=���� �Ĺ�,1=���� ����,2=���� ��������, number 0=��,1=â,2=����)
	int stat[3]={15,20,30};		//����� ���� ���� 
	int code[3]={0,1,2};		//���� �ڵ� 
	char* kind[3]={"��","â","����"};
	int n;
	if(mode==0){
		printf("%s!\n",kind[number]);
		n = inventory(1,code[number],1);
		return n;
	}else if(mode==1){
		MC(4,0,stat[number],0,0,0);
		printf("%s��(��) �����Ͽ����ϴ�.\n",kind[number]);
		inventory(1,code[number],-1);
		inventory(4,code[number],0); 
	}else if(mode==2){
		MC(4,0,-stat[number],0,0,0);
		printf("%s��(��) ���������Ͽ����ϴ�.\n",kind[number]);
		inventory(1,code[number],1);
	}
}
void statopen(int number){		//�������� ���Խ� ��� ���� ����(number 0=���� ��ݱ�,1=������) 
	srand(time(NULL));
	int stat=10;
	char* kind[2]={"����","ȭ��"};
	static int num[2]={0,0};
	if(num[number]==0){
		printf("%s������ ����Ǿ����ϴ�.\n",kind[number]);
		if(number==0){
			printf("���⽺���� ������ ����Ȯ���� ���� ���ݽ� ���� ���� ���¿� ������ �����Դϴ�.\n");
		}else{
			printf("ȭ�������� ������ ���ݸ�ŭ �߰��������� ���� �����Դϴ�.\n");
		}
		num[number]++;
	}
	Sleep(1000);
	printf("%s���� %d ��ŭ �����Ͽ����ϴ�.\n",kind[number],stat);
	if(number==0){
		MC(1,0,0,0,0,stat);
	}else if(number==1){
		MC(1,0,0,0,stat,0);
	}
}
int repair(int mode,int number){		//�ִ뽺�� ����(mode 0=�Ĺ�,1=���, number 0=��,1=ü��,2=����) , ���� ���� ������ �������� ���ؼ��ٲ㵵 �� 
	int code[3]={12,13,14};
	int stat[3]={5,10,7};
	char* kind[3]={"��","ü��","�ӵ�"};
	int n;
	if(mode==0){
		printf("��������(%s)!\n",kind[number]);
		n = inventory(1,code[number],1);
		return n;
	}else if(mode==1){
		printf("�ش� �ִ� ������ %d��ŭ ���� �Ͽ����ϴ�.\n",stat[number]);
		inventory(1,code[number],-1);
		if(number==0){
			MC(1,5,0,0,0,0);	
		}else if(number==1){
			MC(1,0,10,0,0,0); 
		}else{
			MC(1,0,0,7,0,0);
		}	
	}
}
void bag(int number){		//������� ������ ȹ�� ǥ��(number 0=3����,1=5����) 
	int code[4]={3,5};
	printf("�κ��丮 %d����!\n",code[number]);
	inventory(0,0,code[number]);
}
int quest(int number){		//����Ʈ������ ȹ�� (number 0=ö��,1=����,2=����,3=cpu,4=�ð���)
	int code[5]={17,18,19,20,21};
	char* kind[5]={"ö��","����","����","cpu","�ð���"};
	printf("%s!\n",kind[number]);
	int n = inventory(1,code[number],1);
	return n;
}
void spirit(){ 		//���ɾ� ���Խ� �Լ� 
	printf("���ɾ��� �����ߴ�! ����ѵ�?\n");
	inventory(1,22,1); 
}
void NB(int mode){		//���̳��� �Լ� (mode 1=map1 2=map2 . . . 5=map5)
	int epx,epy;		//Ż����ǥ �Լ� 
	if(mode==1){		//�� �ʸ����� Ż����ǥ 
		epx=13;
		epy=20;
	}else if(mode==2){
		epx=20;
		epy=17;
	}else if(mode==3){
		epx=8;
		epy=7;
	}else if(mode==4){
		epx=2;
		epy=0;
	}else if(mode==5){
		epx=20;
		epy=13;
	}
	printf("Ż�ⱸ�� ����� ��ġ���� X=%2d, X=%2d ���̰� ���ϴ�.\n", epx-x,epy-y); 
}
int dp(){		//�г�Ƽ ���ñ� ȹ�� 
	printf("�г�Ƽ ���ñ�!\n");
	int n = inventory(1,24,1);
	return n;
}
void itemuse(int code,int mode){			//code ������ �ڵ� mode 1=������ ��� (code�� 0,1,2�϶� 2=���� �������� , 23�϶� �ʼ���)
	if(code==0||code==1||code==2){
		weapon(mode,code);
	}else if(code==12||code==13||code==14){
		repair(mode,code-12); 
	}else if(code==22){
		if(inventory(3, 22, 0) > 0)
			spirit_open(); 
	}else if(code==23){
		if(inventory(3, 23, 0) > 0)
			NB(mode); 
	}
}
