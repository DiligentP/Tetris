#include "Header.h"

///////////////////// 전역 변수 선언 ///////////////////
int board[BOARD_HEIGHT][BOARD_WIDTH] = { EMPTY, };   //// 현재 사용중인 보드판   EMPTY = 0  //초기값


int main() {

	int Count,C;         // T_START_Display(); 함수에서 반환한 반환값
	extern int Speed, Space_flag;

	Cursor(0);         // 커서 숨기기 : 0 숨기기 1 보이기

	while (1)
	{
		Count = START_Display();       // 1 : GAME START  2 : RANK  3 : SYSTEM  4 : EXIT 

		enum menu {GAMESTART=1,RANK,SYSTEM,EXIT};

		switch (Count)
		{
		case GAMESTART:
			PlaySound("Tetris_background_music.wav", NULL, SND_ASYNC | SND_LOOP);  // 테트리스 음악 재생

			New_Board(board);   // 새로운 보드를 만듭니다.

			while (1) {
				New_block(board);		// 새로운 블럭을 만듭니다.

				for (int i = 0; i < 5; i++) {
					Check_key(board);    // 초당 5번의 입력을 받고 명령을 수행합니다.
					
					if (Space_flag == True) { // 스페이스바를 누르면 바로 다음 블럭을 생성합니다.
						Space_flag = False;
						break; 
					}  
					Draw_Board(board);	 // 보드를 그립니다.
					Sleep(Speed);
				}

				Drop_block(board);       // 1초후에 블럭을 내립니다.
				C = Check_line(board);		 // 라인을 체크합니다.(게임 오버 판별, 블럭의 한줄완성 판별)

				if (C == True) { break; }
			}
			break;

		case RANK:
			gotoxy(3 + (BOARD_HEIGHT / 2) - 1, 7); printf("COMBO!");
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