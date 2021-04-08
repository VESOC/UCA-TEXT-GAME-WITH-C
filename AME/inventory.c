#include <stdio.h>
#include "spirit-type.h"
#include "item.h"
#include "mc.h"
#include "map.h"

extern int itemList[];

int inventory(int mode,int item,int size){		//�κ��丮(mode 0=�κ��丮 ����,1=�ĹֶǴ� ������ �Ҹ�,2=�κ��丮���,3=������ ���� item=������ ������ �ڵ�, size=�κ��丮 ������ �Ǵ� �������������ҷ�) 
	static int ivsize=6,inven[25]={0,},pocket[25]={0,},weaponC=3;
	if(mode==0){			//�κ��丮 ���� 
		printf("�κ��丮�� ������ %d��ŭ �þ���.\n",size);
		ivsize+=size;
		if(ivsize>25){
			printf("�̰��� ������ �� �ִ� ������ �������� ��� ��Ƶ� 25����. �� �׷��� ��ɳ��°ž�? ���̻� �ø�������.\n");
			ivsize=25;
		}
	}else if(mode==1){		//������(item) ���� �� ����(size) �κ��丮 ���� 
		int tem0=0,use=-1;
		for(;tem0<ivsize;tem0++){
			if(inven[tem0]==0){
				use=tem0;
				break;
			}	
		}
		if(!(pocket[item]==0)){
			pocket[item]+=size; 
		}else if(use==-1){
			printf("������ �κ��丮�� �̹� ���ִٰ�� �ɸ��� �ֳ�.\n");
			return -1; 
		}else if(pocket[item]==0&&inven[use]==0&&size>0){		
			inven[use]=item+1;			//inven�� �������ڵ�+1�� ���� 
			pocket[item]=size;
		}
		if(pocket[item]==0){
			int tem1=0;
			for(;tem1<ivsize;tem1++){
				if(inven[tem1]==item+1){
					inven[tem1]=0;	
				}
			}
		}else if(pocket[3]==2){
			printf("������ �̹� ���絿�̸� ���� ä�� ����� �߱⶧���� ���� ���������ϴ�. �����ұ޵� �����?\n");
			itemList[4]++;
			pocket[3]--; 
		}
	}else if(mode==2){		//�κ��丮 ��� 
		int tem2=0,answer=0;
		//charset p = MC(0,0,0,0,0,0);
		printf("%s�� �κ��丮\n", MC(0,0,0,0,0,0).name);
		printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
		for(;tem2<ivsize;tem2++){
			if(inven[tem2]==0){
				printf("---\n");
			}else{
				assist_i(inven[tem2]-1);
				printf(" : %03d",pocket[inven[tem2]-1]);
				if(inven[tem2]==1||inven[tem2]==2||inven[tem2]==3||inven[tem2]==13||inven[tem2]==14||inven[tem2]==15||inven[tem2]==16||inven[tem2]==17||inven[tem2]==23||inven[tem2]==24){
					printf(" - %d",tem2+1);
				}
				printf("\n");
			}	 
		}
		printf("\n��� : ");
		if(weaponC==3){
			printf("����");
		}else{
			 assist_i(weaponC);
		}
		printf("\n���� : "); 
		print_cSpirit();
		printf("\n");
		money(0,0);
		printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n�������� ����Ϸ��� �ش� ��ġ�� ��ȣ�� �Է��ϼ���.(��밡���� �����۸� ��ȣ�� ��ϴ�.)\n��� �����Ϸ��� -1��, �������� 0�� �����ÿ�.\n");
		char cm;
		do{ 
			printf(">>> "); scanf("%d",&answer); while ((getchar()) != '\n');
		}while(!(answer<=ivsize&&answer>=-1));
		if(answer==-1&&!(weaponC==3)){		//���� ���� 
			int tem3=0,num=0,stat[3]={15,25,45};
			for(;tem3<ivsize;tem3++){		//�κ��丮 ���� üũ 
				if(inven[tem3]==0){
					num++;
					break;
				}
			}
			if(num==0){			//�κ��丮�� ������ ������
				printf("�κ��丮�� ������ �����. �ٽ� ���� ���ô���\n");
			}else if(num>=1){				//���� �������� 
				itemuse(weaponC,2);
				weaponC=3;
				num=0;
			} 
		}else if(answer>0){
			if(inven[answer-1]==0){
				printf("�ش� ĭ���� �������� �������� �ʾƿ�.\n");
			}else if(inven[answer-1]==24){
				int map = idRT(0);//����ٰ� �� ��ȣ �־���� ���������� ������ �ɰͰ����� 
				itemuse(23, map);
			}else{
				itemuse(inven[answer-1]-1,1);
			}
		}
	}else if(mode==3){			//�κ��丮 item�� ���� ��ȯ 
		return	pocket[item];
	}else if(mode==4){			//���� ���� item 0=��,1=â,2=����
		int stat[3]={15,25,45}; 
		if(weaponC != 3){
			puts("���? ���Ⱑ �־���?");
			itemuse(weaponC, 2);
			MC(4,0,-stat[weaponC], 0, 0, 0);
		}
		weaponC = item;
	}else if(mode == 5){
		int i;
		for(i=0;i<24;i++){
			inven[i] = 0;
			pocket[i] = 0;
		}
	}
}
