#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "inventory.h"
#include "mc.h"

extern x;
extern y;
extern spi_chk[];

void death(){			//���� �̺�Ʈ&�г�Ƽ ���ñ� ��� 
	printf("����ϼ̽��ϴ�.\n�������� ������. ����� ���� ������ �������� ��ĥ���ϱ�.\n�������� �ٽ� �����ϴ°ͺ��� �̵����� �ʳ�?\n\n\n");
	money(2,0);
	Sleep(700);
	printf("������ �������ϴ�. �ٵ� ������ �־��.\n\n���⿡�� ����� ������ ���ϴ� ȯ���̰ŵ��. �׷��� �Ƹ� ó���� ��� ��������? �װ� ������ ���ϰſ���.\n");
	Sleep(50);
	printf("�׷� ��Ȳ�� ���ϰ� �ʹٸ� ���� ��������� ����ؿ�.\n�����Ͻðھ��?\n\n");
	int an,dp=inventory(3,24,0),num=0;
	char answer;
	Sleep(100);
	printf("��������-1 �Ⱦ� ���� ���̰� ����-2\n");
	do{
		printf(">>> "); scanf("%c",&answer); while((getchar()) != '\n');
		an=answer-'0';
		num++;
	}while(an!=1 && an!=2 && num<5);
	if(dp>0){
		printf("��� �׷������� �г�Ƽ���ñ��� �־��ݾ�? ���� �׳� �г�Ƽ �������߳�.\n�׳ɰ��� ���� ��������� ��¥�ϱ� ���ݰ����� ����.\n");
		inventory(1,24,-1); 
	}else if(an==1){
		printf("�� ���ƿ�. �׷��� ��������� �����ϵ�������.\n\n\n");
		Sleep(700);
		printf("�� ������� �׷� ������������ �ٽ� �����ϼ���.\n���� �󸶳� ������������? �ٽð��� Ȯ���غ���~\n");
		money(2,0);
	}else if(an==2){
		printf("�����ϴٴ� �������� �����ϴٴ°ǰ�?\n��¿������ �׷� �׳� ����. �´�, �Ʊ� ������ ���ߴµ� Ȥ�ø����? �κ��丮�� ������ ���� ������ �����������~\n���� ����Ǯ��� ���� �׷����� ������\n");
		MC(5,0,0,0,0,0);
		srand(time(NULL));
		if(rand()%1000 == 728) spi_chk[rand()%3] = 0;
	}else if(num==5){
		printf("���ؿ�? ��� �峭ĥ �ð��� ������ ���� �밡�ٳ� ���Ͻ���?\n\n");
		Sleep(700);
		printf("���ƿ� �� ������ ���� ���� �� ��Ƶ�Ⱦ��. ����ҳİ���?\n�밡���϶�� ��ü������ ��Ҿ�� ��������\n�������� �밡�ٳ� �ϼ���\n");
		MC(5,0,0,0,0,0);
		MC(5,0,0,0,0,0);
	}
	num=0;
	MC(3,0,0,0,0,0);
	x = 10; y = 10;//����ٰ� �ٽ� ������������ mc��ǥ �ű�� �ڵ� �ʿ� 
}