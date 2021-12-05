#include "Header.h"

extern info Player[100];	// 모든 플레이어의 데이터를 가져옴
extern int Player_count;	// 플레이어의 수

info Player_Top[10];		// 랭킹에 올릴 플레이어의 데이터 공간을 만듬.

info Temp;					// 랭킹 정렬에 사용될 임시 저장 공간;

void Rank_main()
{
	Info_data_read();
	Rank_Load();

	Draw_Rank();		//랭킹 그리는 함수

	Rank_Save();
}

void Rank_Load() {
	int i, j;
	// 정렬////////////////////////////////////////////
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