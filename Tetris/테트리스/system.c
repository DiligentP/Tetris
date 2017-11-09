#include "Header.h"

////////////////////////// 테트리스 블럭 배열 //////////////////////////////////
int blocks[7][4][4][4] = {
	{ { 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },
	{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0 } },
	{ { 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0 } },
	{ { 0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0 },{ 0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0 } },
	{ { 0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0 },{ 0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0 } }
}; //블록모양 저장 4*4공간에 블록을 표현 blcoks[b_type][b_rotation][i][j]로 사용 
//////////////////////////////////////////////////////////////////////////////
int Board_flag = True;    //  새로운 보드가 필요함을 알리는 FLAG
int Block_flag = True;    // 새로운 블럭이 필요함을 알리는 FLAG

int SPEED = 500;

// 테트리스 맨 처음 시작 화면 
int T_START_Display() {
	int KeyBoard = 0; int count = 0; //  KeyBoard : 키보드 값을 받는 변수 , count : UP(72) = +1, DOWN(80) = -1

	system("title T E T R I S");

	int i = 0;

	///////////////////// 테트리스 로고 ///////////////////////
	/*
	printf("\t ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("\tㅣ■■■■■ ■■■■ ■■■■■ ■■■■  ■■■ ■■■■ㅣ\n");
	printf("\tㅣ    ■     ■           ■     ■     ■   ■   ■      ㅣ\n");
	printf("\tㅣ    ■     ■■■■     ■     ■■■■    ■   ■■■■ㅣ\n");
	printf("\tㅣ    ■     ■           ■     ■     ■   ■         ■ㅣ\n");
	printf("\tㅣ    ■     ■■■■     ■     ■     ■ ■■■ ■■■■ㅣ\n");
	printf("\t ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n\n\t");

								G A M E S T A R T
								R A N K I N G
								S Y S T E M
								E X I T
	*/

	int TETRIS_LOGO[] =
	{
		9, 8, 0, 1, 1, 1, 0, 2, 2, 2, 0, 3, 3, 3, 0, 4, 4, 4, 0, 5, 0, 6, 6, 6, 0, 10,
		8, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 4, 0, 4, 0, 5, 0, 6, 0, 0, 0,10,
		8, 0, 0, 1, 0, 0, 2, 2, 2, 0, 0, 3, 0, 0, 4, 4, 4, 0, 5, 0, 6, 6, 6, 0,10,
		8, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 4, 4, 0, 0, 5, 0, 0, 0, 6, 0,10,
		8, 0, 0, 1, 0, 0, 2, 2, 2, 0, 0, 3, 0, 0, 4, 0, 4, 0, 5, 0, 6, 6, 6, 0, 7
	};
	while (1)
	{
		//printf("%d",count);
		//printf("%d",KeyBoard);
		system("cls");

		for (int i = 0; ; i++) {
			if (TETRIS_LOGO[i] == 10) {
				printf("\n");
			}
			if (TETRIS_LOGO[i] == 9) {
				printf("\n\n\n\n\n");
			}
			if (TETRIS_LOGO[i] == 8) {
				printf("\t    ");
			}
			if (TETRIS_LOGO[i] == 1) {
				textColor(12); printf("■");
			}
			else if (TETRIS_LOGO[i] == 2) {
				textColor(10); printf("■");
			}
			else if (TETRIS_LOGO[i] == 3) {
				textColor(14); printf("■");
			}
			else if (TETRIS_LOGO[i] == 4) {
				textColor(9); printf("■");
			}
			else if (TETRIS_LOGO[i] == 5) {
				textColor(11); printf("■");
			}
			else if (TETRIS_LOGO[i] == 6) {
				textColor(13); printf("■");
			}
			else if (TETRIS_LOGO[i] == 7) {
				textColor(8); printf(" by JH");
				break;
			}
			else {
				printf("  ");
			}
		}
		printf("\n"); textColor(7); printf("\n\n\n       ");
		///////////////////////////////////////////////////////////

		///////////////////// 테트리스 메뉴 ///////////////////////

		if (KeyBoard == DOWN && count != 4) {
			count++;
		}
		else if (KeyBoard == UP && count != 1) {
			count--;
		}
		else if (KeyBoard == ESC) {
			exit(0);
		}
		else if (KeyBoard == Enter) {
			return count;									//  카운트를 반환하고 함수를 종료.
		}

		//textColor(240);  흰색 배경
		//textColor(7);		기본

		printf("\t\t\t    ");
		if (count == 1) {
			textColor(240);
		}
		printf(">>   GAME START   <<\n\n");
		if (count == 1) {
			textColor(7);
		}
		printf("\t\t\t    ");
		if (count == 2) {
			textColor(240);
		}
		printf(">>     R A N K    <<\n\n");
		if (count == 2) {
			textColor(7);
		}
		printf("\t\t\t    ");
		if (count == 3) {
			textColor(240);
		}
		printf(">>   S Y S T E M  <<\n\n");
		if (count == 3) {
			textColor(7);
		}
		printf("\t\t\t    ");
		if (count == 4) {
			textColor(240);
		}
		printf(">>     E X I T    <<\n");
		if (count == 4) {
			textColor(7);
		}
		KeyBoard = _getch();
	}
}

// 보드 동기화
void Update_Board(int board[][BOARD_WIDTH]) {
	int x, y;

	////////////////////// 새로운 보드판 생성 ////////////////////
	if (Board_flag == True) {
		
		//memset(변수, 초기화값, 변수크기)
		memset(board, EMPTY, sizeof(board)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //보드 메모리 초기화   [보드의 모든값을 EMPTY = 0(빈공간) 으로 만듭니다]

		// 블럭 벽 만들기//
		for (y = 0; y < BOARD_HEIGHT; y++) {
			for (x = 0; x < BOARD_WIDTH; x++) {

				if (x == 0) { board[y][x] = WALL; }                              //보드의 오른쪽 벽을 만듭니다(ㅣ)

				if (x == BOARD_WIDTH - 1) { board[y][x] = WALL; }                //보드의 왼쪽 벽을 만듭니다(ㅣ)

				if (y == BOARD_HEIGHT - 1) { board[y][x] = WALL; }				  //보드의 아래쪽 벽을 만듭니다(ㅡ)
			}
		}
		//////////////////
		Board_flag = False;
	}
	///////////////////////////////////////////////////////////

	system("cls");

	// 블럭 벽 만들기//
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {

			if (x == 0) { board[y][x] = WALL; }                              //보드의 오른쪽 벽을 만듭니다(ㅣ)

			if (x == BOARD_WIDTH - 1) { board[y][x] = WALL; }                //보드의 왼쪽 벽을 만듭니다(ㅣ)

			if (y == BOARD_HEIGHT - 1) { board[y][x] = WALL; }				  //보드의 아래쪽 벽을 만듭니다(ㅡ)
		}
	}

	

	// 블럭 그리기
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {
			if (board[y][x] == ACTIVE_BLOCK) {			// 블럭값이 ACTIVE_BLOCK = -2 (움직일수 있는 블럭)
				gotoxy(6 + (x * 2), 2 + y);
				printf("■");
			}
			if (board[y][x] == WALL)					// 블럭값이 WALL = 1  (벽)
			{
				gotoxy(6 + (x * 2), 2 + y);
				printf("▒");
			}
			if (board[y][x] == EMPTY)					// 블럭값이 EMPTY = 0 (빈공간)
			{
				gotoxy(6 + (x * 2), 2 + y);
				printf("  ");
			}
			if (board[y][x] == INACTIVE_BLOCK) {
				gotoxy(6 + (x * 2), 2 + y);
				printf("■");
			}
		}
	}
}

// 블럭 동기화
void new_Block(int board[][BOARD_WIDTH]) {

	srand((unsigned)time(NULL));  // 난수 생성

	int b_type; //블록 종류를 저장 
	int b_rotation; //블록 회전값 저장 
	int b_type_next; //다음 블록값 저장 

	b_type_next = rand() % 7; //다음 블럭을 만듦 
	b_type = b_type_next; //다음블럭값을 가져옴 
	b_rotation = 0;  //회전은 0번으로 가져옴 

	/////////////// NEW BLOCK ///////////////
	if (Block_flag == True) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (blocks[b_type][0][i][j] == 1)
				{
					board[i-1][j + 5] = ACTIVE_BLOCK;
				}
			}
		}
		Block_flag = False;
	}
	/////////////////////////////////////////
}

// 게임 오버
void Game_over() {
	system("cls");

	gotoxy(23,  5); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤"); //게임오버 메세지 
	gotoxy(23,  6); printf("▤                              ▤");
	gotoxy(23,  7); printf("▤  +-----------------------+   ▤");
	gotoxy(23,  8); printf("▤  |   G A M E  O V E R    |   ▤");
	gotoxy(23,  9); printf("▤  +-----------------------+   ▤");
	gotoxy(23, 10); printf("▤                              ▤");
	gotoxy(23, 11); printf("▤    YOUR SCORE: ...           ▤");
	gotoxy(23, 12); printf("▤                              ▤");
	gotoxy(23, 13); printf("▤                              ▤");
	gotoxy(23, 14); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

	getc(stdin);
}

void check_Key() {
	int key = 0; //키값 초기화

	/*
	while (1)
	{
		key = _getch();

		if (key == 224) {
			key = _getch();
			switch (key) {
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
			}
		}
		else {
			switch (key) {
			case SPACE:
			case ESC:
				
			}
		}
	}
	*/
}

void move_Block(int board[][BOARD_WIDTH]) {
	int x, y;

	for (y = BOARD_HEIGHT - 1; y >= 0; y--) {
		for (x = BOARD_WIDTH - 1; x >= 0; x--) {
			if (board[y][x] == ACTIVE_BLOCK) {
				if (board[y + 1][x] == WALL || board[y + 1][x] == INACTIVE_BLOCK) {
					board[y][x] = INACTIVE_BLOCK;
					break;
				}
				board[y + 1][x] = board[y][x];
				board[y][x] = EMPTY;
			}
		}
	}	
}

// 블럭의 배열을 보는 함수
void board_Check(int board[][BOARD_WIDTH]) {
	int y, x;
	// 배열 보기

	system("cls");
	//gotoxy(6, 2);
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {
			//gotoxy(4 + (x * 2), 2 + y);
			printf("%d ", board[y][x]);
		}
		printf("\n");
	}

	getc(stdin);
}