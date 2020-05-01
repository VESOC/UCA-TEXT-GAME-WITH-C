#ifndef MC_H
#define MC_H

typedef struct charset{		//ĳ���Ϳ� �� ���� 
	char* name;			    	//�̸� 
	int hp;						//ü�� 
	int speed;					//���� 
	int str;					//�� 
	int fire;					//�Ӽ�(��) 
	int elect; 					//�Ӽ�(����) 
}charset;

charset MC(int mode, int hp, int str, int speed, int fire, int elect);

charset pawn();

charset king();

#endif
