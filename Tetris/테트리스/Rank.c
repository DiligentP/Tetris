#include "Header.h"

info Player_Top[10];		// 랭킹에 올릴 10명의 데이터 공간을 만듬.
int Player_count = 0;	//랭킹에 올라간 플레이어의 카운트를 셈.

void Rank_main()
{
	FILE *Ranking = fopen("Ranking_data.txt", "w+");

	//fscanf(Ranking,"%s %s %s %s",Player_Top.);

	Draw_Rank();		//랭킹 그리는 함수

	fclose(Ranking);
}

void Rank_Load() {

}