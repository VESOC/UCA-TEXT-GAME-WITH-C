#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct charset{		//ĳ���Ϳ� �� ���� 
	char* name;			    	//�̸� 
	int hp;						//ü�� 
	int speed;					//���� 
	int str;					//�� 
	int fire;					//�Ӽ�(��) 
	int elect; 					//�Ӽ�(����) 
}charset;

charset MC(int mode, int hp, int str, int speed, int fire, int elect){	//���ΰ� ���� ���� �Լ�(mode 0=���� ���� ����,1=�ִ뽺�� ����,2=��Ʋ���ݰ��,3=����ȸ��,4=���⽺��,������ ���ڴ� ������ ��½�ų ���� ��) 
	static charset player,maxMC,basic;
	static int istat;
	static int num=0;
	srand(time(NULL));
	if(num==0){
		player.name = "Android-2253";
		player.speed=(rand()%11+10);
		player.hp=100;
		player.str=(rand()%11+10);
		player.elect=0;
		player.fire=0;
		maxMC=player;
		basic=player;
		num++;
	}
	if(mode==0){				//���� mc�� ������ ����
		return player;
	}else if(mode==1){			//�ִ� ���� ���� 
		maxMC.hp+=hp;
		maxMC.str+=str;
		maxMC.speed+=speed;
		player.fire+=fire;
		player.elect+=elect;
	}else if(mode==2){			//��Ʋ�� ���� ���� ��� 
		player.hp=hp;
		player.speed=speed;
		player.str=str;
	}else if(mode==3){			//���� ȸ�� 
		player.hp=maxMC.hp;
		player.speed=maxMC.speed;
		player.str=maxMC.str;
		player.str+=istat;
		printf("��� ������ �����·� ���ƿԴ�.\n");
	}else if(mode==4){         //���������� ���� ������ ��¶Ǵ� �϶� 
        if(str>0){
       		istat=str;
        	player.str+=istat;
        }else{
        	player.str+=str;
        	istat=0;
    	}
	}else if(mode==5){			//����� �г�Ƽ ���� 
		basic.elect/=2;
		basic.fire/=2;
		basic.hp/=2;
		basic.speed/=2;
		basic.str/=2;
		maxMC.hp-=basic.hp;
		maxMC.str-=basic.str;
		maxMC.speed-=basic.speed;
		player.fire-=basic.fire;
		player.elect-=basic.elect;
	}else if(mode==6) num=0;
}
charset pawn(){					//�̺��������� �Ѳ����� �������� 	
	srand(time(NULL));
	charset pn;
	pn.name = "P-2023";
	pn.hp=(rand()%201+300);
	pn.speed=(rand()%26+35);
	pn.str=(rand()%26+35);
	pn.elect=(rand()%26+35);
	pn.fire=(rand()%26+35);
	return pn;
} 
charset king(){					//�������� ���� ����	 +)�ʸ���鼭 ���� 
	charset kg;
	kg.name = "K-3605";
	kg.hp=1000;
	kg.speed=100;
	kg.str=100;
	kg.fire=70;
	kg.elect=70;
	return kg;
} 
