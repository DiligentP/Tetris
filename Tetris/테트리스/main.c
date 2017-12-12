#include "Header.h"

int main() 
{
	int Count;

	Cursor(0);					// 커서 숨기기 : 0 숨기기 1 보이기

	while (1) 
	{
		Count = Main_Menu();
		
		enum menu { GAME = 1, RANK, SYSTEM, EXIT };

		switch (Count)
		{
		case GAME:
			Game_main();							// 게임 메인 함수
			break;

		case RANK:
			Rank_main();							// 랭크 메인 함수
			break;
			
		case SYSTEM:
			System_main();							// 시스템 메인 함수
			break;

		case EXIT:
			system("cls");							// 게임 종료
			return 0;

		default:
			Login_main(Count);						// 반환된 카운트 함수가 5이상이면 로그인 함수를 리턴합니다.
			break;
		}
	}
}