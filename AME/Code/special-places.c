#include <stdio.h>
#include <windows.h>

char* pName(char p){
	switch(p){
		case 'e':
			return "Ż�ⱸ";
		case 'v':
			return "���Ǳ�";
		case 'r':
			return "�����ڵ��� �Ƚ�ó";
	}
}

void resting_area(int p){
	static int remainder[4] = {6, 6, 6, 6};
	if(remainder[p-2] == 0){
		//deny access to SP
	}
	//screen
	//healing();
	//NPCs1();
}

void vending_machine(/*item array*/){
	//screen
	//������ ���
	for(;;){
		//���� Ŀ�ǵ� �ݺ�  
	}
}

