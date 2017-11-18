#include "Header.h"

///////////////////// 전역 변수 선언 ///////////////////
int board[BOARD_HEIGHT][BOARD_WIDTH] = { EMPTY, };   //// 현재 사용중인 보드판   EMPTY = 0  //초기값


int main() {

	int Count;         // T_START_Display(); 함수에서 반환한 반환값

	Cursor(0);         // 커서 숨기기 : 0 숨기기 1 보이기

	while (1)
	{
		Count = T_START_Display();       // 1 : GAME START  2 : RANK  3 : SYSTEM  4 : EXIT 

		switch (Count)
		{
		case 1:
			//while (1) {
				//for (int i = 0; i < 5; i++) { // 블록이 한칸 떨어질때 5번의 키입력을 받을 수 있도록 함.
					//Chack_key();   // 키입력을 확인함.
			while (1) {
				Update_Board(board);  // 화면을 새로 그려줌.
				New_block(board);	  // 새로운 블럭을 만듬
				_getch();
			}
					
				//}
			//}
			
			break;
		case 2:
			printf("\t\t\t랭킹은 현재 준비중입니다.\n\n");
			getc(stdin);
			break;
		case 3:
			printf("\t\t\t시스템은 현재 준비중입니다.\n\n");
			getc(stdin);
			break;
		case 4:
			exit(0);
		}
	}

	return 0;
}