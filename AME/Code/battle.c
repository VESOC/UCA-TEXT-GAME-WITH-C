#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "special-places.h"
#include "mc.h"
#include "item.h"
#include "deathevent.h"
#include "inventory.h" 

void fight(char p, int id){
	srand(time(NULL));
	charset player = MC(0, 0, 0, 0, 0, 0);
	charset enemy = pawn();
	if(id == 6){
		charset enemy = pawn();
	}else{
		charset enemy = king();
	}
	Sleep(1500);
	puts("�ο��� �� ���۵˴ϴ�. �� ������ ������ ����");
	int enestat[5] = {enemy.hp, enemy.speed, enemy.str, enemy.fire, enemy.elect};
	int playstat[5] = {player.hp, player.speed, player.str, player.fire, player.elect};
	char* eRoar[5] = {"����!", "������!", "���ۿ�Ʈ���¼����¼������!", "�� ����!", "������ �� �������� ����!"};
	char* pRoar[5] = {"�������!", "����������!", "��������!", "(��2�� ����)", "(���� �����ϴ� ��)"};
	char pInput, cmdC;
	int cmd; 
	int efireDmg = 0, pfireDmg = 0, eParal = 0, pParal = 0;
	while(1){
		Sleep(100);
		if(enestat[0] < 0 && playstat[0] > 0){ //�¸���  
			printf("�����մϴ�! %s�� óġ�ϰ� [%s ���Ա���(1ȸ��)]�� ȹ���߽��ϴ�!", enemy.name); //�� ó�� �� ���  
			MC(2, playstat[0], playstat[2], playstat[1], 0, 0); //���� ������Ʈ  
			return;
		} else if(enestat[0] > 0 && playstat[0] < 0){ //�й��  
			printf("�� ��� %s���� ��ü���� ����...�ٽ��ض�", enemy.name);
			Sleep(500);
			death(); //�׾����� �����ϴ� �Լ� 
			return;
		}
		if(enestat[1] >= playstat[1]){ //���� ���� �켱���� ������  
			if(eParal > 0){ //���� ���� �Ǵ�  
				eParal--;
				continue;
			}
			printf("%s�� �ʺ��� ����\n", enemy.name);
			if(enestat[3] > playstat[3]){
				efireDmg = enestat[3] - playstat[3]; //ȭ�� ������ ����  
			}else{
				efireDmg = 0;
			}
			if(enestat[4] > playstat[4]){
				if(rand()%5 == 3){
					eParal = (enestat[4] - playstat[4])%7; //���� ���� ����  
				}
			}
			printf("%s�� %s\n", enemy.name, eRoar[rand()%5]);
			playstat[0] -= (enestat[2] + efireDmg); //����  
		}else{ //�÷��̾� ���� �켱�� 
			if(pParal > 0){
				pParal--;
				continue;
			}
			puts("������ ���� �� ����");
			printf("�׷� ���� ���Ұ���? ����-0, ������ ���-1  : ");
			while(1){
				printf(">>> "); scanf("%c", &cmd); while ((getchar()) != '\n');  //Ŀ�ǵ� �Է�  
				if(pInput-'0' != 0 && pInput-'0' != 1){ //�Է��� ����� ���� ������ �ٽ� �ϱ�  
					printf("\n���ϴ°ų� ����� �Է¾���? : ");
					continue; 
				}else{
					if(pInput==0){ //���� ����Ǵ� �͵��� �� �ڵ�� ����  
						if(enestat[3] < playstat[3]){
							pfireDmg = -enestat[3] + playstat[3];
						}else{
							pfireDmg = 0;
						}
						if(enestat[4] < playstat[4]){
							if(rand()%5 == 3){
								pParal = (playstat[4] - enestat[4])%7;
							}
						}
						printf("%s  a\n", &player.name);
						printf("%s�� %s\n", &player.name, pRoar[rand()%5]);
						enestat[0] -= (playstat[2] + pfireDmg);
						break;
					}else{ 
						puts("----------��Ʋ�� ����� �� �ִ� �����۵�(1�Ͽ� 1��|��ȣ�Է�)----------");
						printf("1: ������(7)     -%4d��   2: ������(10) -%4d��   	 3: �ӵ�����(7) -%4d�� \n4: �ӵ�����(10)  -%4d��   5: �������(7) -%4d��      6: �������(10) -%4d�� \n7: �ӵ������(7) -%4d��   8: �ӵ������(10) -%4d��   9: ���絿�� -%4d��\n", inventory(3,4,0),inventory(3,5,0),inventory(3,6,0),inventory(3,7,0),inventory(3,8,0),inventory(3,9,0),inventory(3,10,0),inventory(3,11,0),inventory(3,3,0));
						int cmd, t = 0;
						while(1){
							printf(">>>> "); scanf("%c", &cmdC); while ((getchar()) != '\n'); 
							cmd = cmdC - '0';
							if(cmd<1 || cmd>9){
								puts("���� �߸� �־���? ����� ����");
								continue; 
							}
							else if(cmd>=1 && cmd<=9){
								t++;
								cmd += 3;
								if(cmd==4){
									if(inventory(3, cmd, 0) <=0) {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,4,-1);
									playstat[2] += 7;
									puts("���� 7��ŭ �����߽��ϴ�.");
									break;
								}else if(cmd==5){
									if(inventory(3, cmd, 0) <=0) {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,5,-1);
									playstat[2] += 10;
									puts("���� 10��ŭ �����߽��ϴ�.");
									break;
								}else if(cmd==6){
									if(inventory(3, cmd, 0) <=0)  {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,6,-1);
									playstat[1] += 7;
									puts("�ӵ��� 7��ŭ �����߽��ϴ�.");
									break;
								}else if(cmd==7){
									if(inventory(3, cmd, 0) <=0)  {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,7,-1);
									playstat[1] += 10;
									puts("�ӵ��� 10��ŭ �����߽��ϴ�.");
									break;
								}else if(cmd==8){
									if(inventory(3, cmd, 0) <=0)  {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,8,-1);
									enestat[2] -= 7;
									puts("���� ���� 7��ŭ �پ����ϴ�.");
									break;
								}else if(cmd==9){
									if(inventory(3, cmd, 0) <=0)  {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,9,-1);
									enestat[2] -= 10;
									puts("���� ���� 10��ŭ �پ����ϴ�.");
									break;
								}else if(cmd==10){
									if(inventory(3, cmd, 0) <=0)  {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,10,-1);
									enestat[1] -= 7;
									puts("���� �ӵ��� 7��ŭ �پ����ϴ�.");
									break;
								}else if(cmd==11){
									if(inventory(3, cmd, 0) <=0)  {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,11,-1);
									enestat[1] -= 10;
									puts("���� �ӵ��� 10��ŭ �پ����ϴ�."); 
									break;
								}else if(cmd==12){
									if(inventory(3, 3, 0) <=0)  {
										puts("��ȣ ����� ��������� ���� ��ȸ ��?");
										break; 
									}
									inventory(1,3,-1);
									eParal+=5;
									puts("���� 5�ϰ� ���ϵ˴ϴ�.");
									break;
								}
							} 
						}
						if(t!=0)continue;
					}
				}
			}
		}
	}
}
