#include <stdio.h>

typedef struct Types{
	char* name;
	int stat;
}Type;

typedef struct Spirits{
	char* name;
	Type type;
}Spirit;

int main(void){
	Spirit Ifrit;
	Ifrit.name = "������Ʈ";
	Ifrit.type.name = "fire";
	Ifrit.type.stat = 100;
	
	Spirit Electron;
	Electron.name = "�Ϸ�Ʈ��";
	Electron.type.name = "electric";
	Electron.type.stat = 100;
	
	Spirit Aegis;
	Aegis.name = "���̱⽺";
	Aegis.type.name = "normal";
	Aegis.type.stat = 100;
}


