#include "Header.h"

///////////////////// 전역 변수 선언 ///////////////////
int board[BOARD_HEIGHT][BOARD_WIDTH] = { EMPTY, };   //// 현재 사용중인 보드판   EMPTY = 0  //초기값


int main() {

	int Count;         // T_START_Display(); 함수에서 반환한 반환값
	int Key,i,j,c=0;

	Cursor(0);         // 커서 숨기기 : 0 숨기기 1 보이기

	while (1)
	{
		Count = T_START_Display();       // 1 : GAME START  2 : RANK  3 : SYSTEM  4 : EXIT 

		enum menu {GAMESTART=1,RANK,SYSTEM,EXIT};

		switch (Count)
		{
		case GAMESTART:
			New_Board(board);   // 새로운 보드를 만듭니다.

			while (1) {
				New_block(board);		// 새로운 블럭을 만듭니다.
				for (i = 0; i < 5; i++) {
					Check_key(board);    // 초당 5번의 입력을 받고 명령을 수행합니다.
					Draw_Board(board);	 // 보드를 그립니다.
					Sleep(100);
				}
				Drop_block(board);       // 1초후에 블럭을 내립니다.
				Check_line(board);		 // 라인을 체크합니다.
			}
			break;

		case RANK:
			printf("\t\t\t랭킹은 현재 준비중입니다.\n\n");
			getc(stdin);
			break;
		
		case SYSTEM:
			printf("\t\t\t시스템은 현재 준비중입니다.\n\n");
			getc(stdin);
			break;
		
		case EXIT:
			return 0;
		}
	}
}