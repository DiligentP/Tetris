#include "Header.h"

info Player_Top[10];		// ��ŷ�� �ø� 10���� ������ ������ ����.
int Player_count = 0;	//��ŷ�� �ö� �÷��̾��� ī��Ʈ�� ��.

void Rank_main()
{
	FILE *Ranking = fopen("Ranking_data.txt", "w+");

	//fscanf(Ranking,"%s %s %s %s",Player_Top.);

	Draw_Rank();		//��ŷ �׸��� �Լ�

	fclose(Ranking);
}

void Rank_Load() {

}