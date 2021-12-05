#include "Header.h"

extern info Player[100];	// ��� �÷��̾��� �����͸� ������
extern int Player_count;	// �÷��̾��� ��

info Player_Top[10];		// ��ŷ�� �ø� �÷��̾��� ������ ������ ����.

info Temp;					// ��ŷ ���Ŀ� ���� �ӽ� ���� ����;

void Rank_main()
{
	Info_data_read();
	Rank_Load();

	Draw_Rank();		//��ŷ �׸��� �Լ�

	Rank_Save();
}

void Rank_Load() {
	int i, j;
	// ����////////////////////////////////////////////
	for (i = 0; i < Player_count-1; i++) 
	{
		for (j = 0; j < Player_count - 1 - i; j++) 
		{
			if (Player[j].Score < Player[j+1].Score)
			{
				Temp = Player[j];
				Player[j] = Player[j + 1];
				Player[j + 1] = Temp;
			}
		}
	}
	//////////////////////////////////////////////////
	for (i = 0; i < 10; i++) {
		Player_Top[i] = Player[i];
	}
}
void Rank_Save() {
	FILE *Ranking = fopen("Ranking_data.txt", "w+");

	for (int i = 0; i < 10; i++) 
	{
		fprintf(Ranking, "%s %d\n", Player_Top[i].Name, Player_Top[i].Score);
	}
	
	fclose(Ranking);
}