#include <stdio.h>

typedef struct Types{
	char* name;
	int stat;
}Type;

typedef struct Spirits{
	char* name;
	Type type;
}Spirit;

Spirit Ifrit(){
	Spirit Ifrit;
	Ifrit.name = "������Ʈ";
	Ifrit.type.name = "fire";
	Ifrit.type.stat = 100;
	return Ifrit;
}

Spirit Electron(){
	Spirit Electron;
	Electron.name = "�Ϸ�Ʈ��";
	Electron.type.name = "electric";
	Electron.type.stat = 100;
	return Electron;
}
	
Spirit Aegis(){
	Spirit Aegis;
	Aegis.name = "���̱⽺";
	Aegis.type.name = "normal";
	Aegis.type.stat = 50;
	return Aegis;
}
	
Spirit spirit(char type){
	switch(type){
		case 'f':
			return Ifrit();
		case 'e':
			return Electron();
		case 'n':
			return Aegis();
		default:
			puts("Error with getting Spirit");
			break;
	}
}

