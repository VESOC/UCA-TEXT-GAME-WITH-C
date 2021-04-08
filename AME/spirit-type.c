#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "mc.h"
#include "inventory.h"

typedef struct Spirit{  //���� ����ü  
	char* name; //�̸� ĳ������ ������ 
	int stat; //������ ���ȷ� 
}Spirit;

Spirit Ifrit(){
	Spirit Ifrit;
	Ifrit.name = "������Ʈ(ȭ��)";
	Ifrit.stat = 100;
	return Ifrit;
}

Spirit Electron(){
	Spirit Electron;
	Electron.name = "�Ϸ�Ʈ��(����)";
	Electron.stat = 100;
	return Electron;
}
	
Spirit Aegis(){
	Spirit Aegis;
	Aegis.name = "���̱⽺(���)";
	Aegis.stat = 70;
	return Aegis;
}
	
int spi_chk[3] = {0,}; //index 0 = ifrit 1 = electron 2 = aegis  Ư�� ���� ��ȯ ���� ���� Ȯ��

void spirit_open(){ 
	srand(time(NULL));
	Sleep(1500);  
	if(rand()%100 == 15){  //1%�� Ȯ���� ���ɾ˿��� ���� ��ȭ  
		int temp = rand() % 3; //� �������� ����  
		for(;;){
			if(spi_chk[temp] == 0){ //���� ��ȯ���� ���� �������� Ȯ��  
				spi_chk[temp] = 1; //��ȯ�� ������ ��ȯ  
				switch(temp){  //�ش� ���� ���� ȭ�� ��� �� ���� ����  
					case 0:
						MC(1,0,0,0,Ifrit().stat,0);
						printf("�����մϴ�! ���� 1%�� Ȯ���� �հ� %s�� ����߽��ϴ�!", Ifrit().name); 
						break;
					case 1:
						MC(1,0,0,0,0,Electron().stat);
						printf("�����մϴ�! ���� 1%�� Ȯ���� �հ� %s�� ����߽��ϴ�!", Electron().name);
						break;
					case 2:
						MC(1,0,Aegis().stat,0,0,0);
						printf("�����մϴ�! ���� 1%�� Ȯ���� �հ� %s�� ����߽��ϴ�!", Aegis().name);
						break;
				}
				inventory(1, 22, -1);
				break;
			}else{
				continue; //�̹� ��ȯ�� �����̶�� �ٽ� ��ȯ  
			}	
		}
	}else{ //��ȭ ���� �� �ش� ȭ�� ���  
		puts("�� �� �翬�� �����߽��ϴ�. 1% Ȯ���̶���?");
		inventory(1,22,-1);
	}
}

void print_cSpirit(){
	if(spi_chk[0] != 0) printf("\n\t%s", Ifrit().name);
	if(spi_chk[1] != 0) printf("\n\t%s", Electron().name);
	if(spi_chk[2] != 0) printf("\n\t%s", Aegis().name);
}
