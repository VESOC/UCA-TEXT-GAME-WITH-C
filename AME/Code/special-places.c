#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include "mc.h"
#include "item.h"
#include "npc.h"

char* pName(char p){  //��� �̸� ��¿� �Լ� (���� ���ɼ� ��) 
	switch(p){
		case 'e':
			return "Ż�ⱸ";
		default:
			return "����/���Ǳ�";
	}
}
 
void resting_area(int p, int mode){ //���� �Լ�  
	static int remainder[4] = {6, 6, 6, 6}; //���� ��������
	if(mode == 1){
		remainder[0] = 6;
		remainder[1] = 6;
		remainder[2] = 6;
		remainder[3] = 6;
		return ;
	}
	srand(time(NULL)); 
	if(remainder[p-2] == 0){ //p-2�� ������ ������ id�� 2���� ������ ���� Ƚ���� 0�̸� ����Ұ�  
		printf("%d�� ȸ������ ���ʹ� ���̻� �� �� �����ϴ�. ���� ����� ������ٵ���.\n");
		return ;
	}
	--remainder[p-2]; //����Ƚ�� ����
	printf("%d�� ȸ������ ���Ϳ� �����ϼ̽��ϴ�.\n");
	MC(3, 0, 0, 0, 0, 0); //���� 
	NPCs(rand()%2); //����Ʈ  
	int temp=0, tem = 0;
	if(rand()%1000000 == 153427 || temp > 0){
		tem = trashMC(0);
		temp++;
		if(tem == 1){
			temp = 0;
		}
	} 
}

void vending_machine(){ 
	puts("-------------���Ǳ�-------------");
	printf("\t1: ���絿��-750G 2: �� ����(7����) -175G 3: �� ����(10����) -250G \n4: �ӵ� ����(7����) -175G 5: �ӵ� ����(10����) -250G 6: �� �����(7����) -225G \n\t7: �� �����(10����) -300G 8: �ӵ� �����(7����) -225G 9: �ӵ� �����(10����) -300G \n10: ��������(ü��10��������) -500G 11: ��������(��10��������) -500G 12: ��������(�ӵ�10��������) -500G \n\t13: �κ��丮 3ĭ���� -300G 14: �κ��丮 5ĭ ���� -450G 15: ������ݱ� -1800G \n16: ������ -1800G 17: ���ɾ� -5000G 18: �г�Ƽ ���ñ� -�������� 1/4(�������� 4000G�̻��ϰ��)\n");
	puts("--------------------------------");
	puts("������ ��ȣ�� �Է��ϼ���. �������� 0�� �Է��ϼ���");
	int cmd=-1; 
	for(;cmd!=0;){
		money(0,0);
		printf(">> "); scanf("%d", &cmd);
		if(cmd == 0) return ;
		switch(cmd){
			case 1:
				if(money(3,0) >= 750){
					de_buff(2,0);
					money(1,-750);	
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 2:
				if(money(3,0) >= 175) {
					de_buff(0,0);
					money(1,-175);
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 3:
				if(money(3,0) >= 250){
					de_buff(0,1);
					money(1,-250);	
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 4:
				if(money(3,0) >= 175) {
					de_buff(0,2);
					money(1,-175);
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 5:
				if(money(3,0) >= 250){
					de_buff(0,3);
					money(1,-250);	
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 6:
				if(money(3,0) >= 175) {
					de_buff(1,0);
					money(1,-175);
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 7:
				if(money(3,0) >= 250){
					de_buff(1,1);
					money(1,-250);	
				}else{
					puts("��, �����鼭 �� �����?");
				}	
				break;
			case 8:
				if(money(3,0) >= 175) {
					de_buff(1,2);
					money(1,-175);
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 9:
				if(money(3,0) >= 250){
					de_buff(1,3);
					money(1,-250);	
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 10:
				if(money(3,0) >= 500){
					repair(0, 1);
					money(1,-500);	
				}else{
					puts("��, �����鼭 �� �����?");
				}			
				break;
			case 11:
				if(money(3,0) >= 500){
					repair(0, 0);
					money(1,-500);	
				}else{
					puts("��, �����鼭 �� �����?");
				}	
				break;
			case 12:
				if(money(3,0) >= 500){
					repair(0, 2);
					money(1,-500);	
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 13: 
				if(money(3,0) >= 300){
					bag(0, 0);
					money(1,-300);	
				}else{
					puts("��, �����鼭 �� �����?");
				}					 
				break;
			case 14: 
				if(money(3,0) >= 450){
					bag(0,1);
					money(1,-450);	
				}else{
					puts("��, �����鼭 �� �����?");
				}					
				break;
			case 15:
				if(money(3,0) >= 1800){
					statopen(0);
					money(1,-1800);	
				}else{
					puts("��, �����鼭 �� �����?");
				}					
				break;
			case 16:
				if(money(3,0) >= 1800){
					statopen(1);
					money(1,-1800);	
				}else{
					puts("��, �����鼭 �� �����?");
				}					
				break;
			case 17:
				if(money(3,0) >= 5000){
					spirit();
					money(1,-5000);	
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
			case 18:
				if(money(3,0) >= 4000){
					dp();
					money(1, -(money(3,0)/4));
				}else{
					puts("��, �����鼭 �� �����?");
				}
				break;
		}
	}
}

