typedef struct NQ{			//NPC 
	int name;				//�̸� 
	char* quest;			//����Ʈ ���� �� 
	char* talk;			//���ɸ� ������ ù��° �� 
	char* endt;			//����Ʈ�� ���������� ������ ��
	char* sc;			//����Ʈ ���� 
	int item;				//����Ʈ ������ 
}NQ;
void assist_c(int mode,int code);
int NPCsp(int mode,int who);
void NPCs(int who);
int NPCfp(int mode,int who);
void NPCf(int who);
void trashMC();
