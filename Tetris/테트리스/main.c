#include "Header.h"

int main() 
{
	int Count;

	Cursor(0);         // 커서 숨기기 : 0 숨기기 1 보이기

	while (1) 
	{
		Count = START_Display();
		
		enum menu { GAME = 1, RANK, SYSTEM, EXIT };

		switch (Count)
		{
		case GAME:
			Game_main();
			break;

		case RANK:
			Rank_main();
			break;
			
		case SYSTEM:
			System_main();
			break;

		case EXIT:
			system("cls");
			return 0;

		}
	}
}