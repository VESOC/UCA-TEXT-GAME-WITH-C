#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "special-places.h"
//#include "custom header"

int fight(/*charset enemy, charstat player,*/ char p){
	srand(time(NULL));
//	int enestat[5] = [enemy.hp, enemy.speed, enemy.str, enemy.fire, enemy.elect];
//	int playstat[5] = [player.hp, player.speed, player.str, player.fire, player.elect];
//	char* eRoar[] = {"����!", "������!", "���ۿ�Ʈ���¼����¼������!", "�� ����!", "������ �� �������� ����!"};
//	char* pRoar[] = {"�������!", "����������!", "��������!", "(��2�� ����)", "(���� �����ϴ� ��)"}
//	char* pInput; 
//	int efireDmg = 0, pfireDmg = 0, eParal = 0, pParal = 0;
//	for(;;){
//		if(enestat[0] < 0 && playstat[0] > 0){
//			printf("�����մϴ�! %s�� óġ�ϰ� \"%s ���Ա���(1ȸ��)\"�� ȹ���߽��ϴ�!", enemy.name, pName(p));
//			MC(playstat[0], playstat[2], playstat[1]);
//			return 0;
//		} else if(enestat[0] > 0 && playstat[0] < 0){
//			printf("�� ��� %s���� ��ü���� ����...�ٽ��ض�", enemy.name);
//			death();
//			return 1;
//		}
//		if(enestat[1] >= platstat[1]){
//			if(eParal > 0){
//				eParal--;
//				continue;
//			}
//			printf("%s�� �ʺ��� ����\n", enemy.name);
//			if(enestat[3] > playstat[3]){
//				efireDmg = enestat[3] - playstat[3];
//			}else{
//				efireDmg = 0;
//			}
//			if(enestat[4] > playstat[4]){
//				if(rand()%5 == 3){
//					eParal = (enestat[4] - playstat[4])%7+1;
//				}
//			}
//			printf("%s�� %s\n", enemy.name, eRoar[rand()%5]);
//			playstat[0] -= enestat[2] + efireDmg;
//		}else{
//			if(pParal > 0){
//				pParal--;
//				continue;
//			}
//			puts("������ ���� �� ����");
//			printf("�׷� ���� ���Ұ���? ����-"atk", ������ ���-"inven"  : ");
//			while(1){
//				scanf("%s", pInput);
//				if(strcmp(pInput, "atk") !=0 || strcmp(pInput, "inven") !=0){
//					printf("\n���ϴ°ų� ����� �Է¾���? : ");
//					continue; 
//				}else{
//					if(strcmp(pInput, "atk")==0){
//						if(enestat[3] < playstat[3]){
//							pfireDmg = -enestat[3] + playstat[3];
//						}else{
//							pfireDmg = 0;
//						}
//						if(enestat[4] < playstat[4]){
//							if(rand()%5 == 3){
//								pParal = (playstat[4] - enestat[4])%7+1;
//							}
//						}
//						printf("%s�� %s\n", player.name, pRoar[rand()%5]);
//						enestat[0] -= playstat[2] + pfireDmg;
//					}else{
//						//inventory
//					}
//				}
//			}
//		}
//	}
}
