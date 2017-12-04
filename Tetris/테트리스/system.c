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
int board_cpy[BOARD_HEIGHT][BOARD_WIDTH] = { 100, };

int Block_flag = True;    // 새로운 블럭이 필요함을 알리는 FLAG
int Crush_flag = True;   // 블럭의 충돌 유무를 판단하는 FLAG
int Space_flag = False;   // 스페이스 키가 눌렸는지 판단하는 FLAG

int SPEED = 500;

int Bx, By;		//블럭의 생성위치
int B_type; //블록 종류를 저장 
int B_rotation; //블록 회전값 저장 
int B_type_next; //다음 블록값 저장 

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

// 보드 생성
void New_Board(int board[][BOARD_WIDTH]) {
	int x, y,i,j;

	////////////////////// 새로운 보드판 생성 ////////////////////
		
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

		system("cls");
	
	///////////////////////////////////////////////////////////
}

// 블럭 생성
void New_block(int board[][BOARD_WIDTH]) {

	/////////////// NEW BLOCK ///////////////
	srand((unsigned)time(NULL));  // 난수 생성

	if (Block_flag == True) {

		Bx = (BOARD_WIDTH / 2) - 1;
		By = 0;
		B_type_next = rand() % 7; //다음 블럭을 만듦 
		B_type = B_type_next; //다음블럭값을 가져옴 
		B_rotation = 0;  //회전은 0번으로 가져옴 

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1)
				{
					board[By + i][Bx + j] = ACTIVE_BLOCK;
				}
			}
		}
		Block_flag = False;
	}
	/////////////////////////////////////////
}

// 보드 그리기
void Draw_Board(int board[][BOARD_WIDTH]) {
	int i,j,x,y;

	// 천장 만들기//
	for (j = 1; j<BOARD_WIDTH - 1; j++) { //y값이 3인 위치에 천장을 만듦 
		if (board[3][j] == EMPTY) board[3][j] = CEILLING;
	}

	// 블럭 그리기
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {
			if (board_cpy[y][x] != board[y][x]) {
				gotoxy(6 + (x * 2), 2 + y);
				switch (board[y][x]) {
				case EMPTY: // 공기
					printf("  ");
					break;
				case CEILLING: // 천장
					printf(". ");
					break;
				case WALL: // 벽
					printf("▩");
					break;
				case INACTIVE_BLOCK:
					printf("□");
					break;
				case ACTIVE_BLOCK: //움직이고있는 블럭 모양  
					printf("■");
					break;
				}
			}
		}
	}
	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			board_cpy[i][j] = board[i][j];
		}
	}
}

// 충돌을 확인하는 함수 (True  , False)
int Crush_check(int board[][BOARD_WIDTH], int Bx, int By, int B_rotation) {
	int i, j;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) { //지정된 위치의 게임판과 블럭모양을 비교해서 충돌하면 false를 리턴 
			if (blocks[B_type][B_rotation][i][j] == 1 && board[By + i][Bx + j]>0)
				return False;
		}
	}
	return True; //하나도 안충돌하면 true리턴 
}

// 키입력이 있는지 확인는 함수
int Check_key(int board[][BOARD_WIDTH]) {
	int key = 0; //키값 초기화
	
	if (_kbhit()) {				//키 값이 있는 경우
 		key = _getch();

		if (key == 224) {		// 방향키 인 경우
			/**/do { key = _getch(); } while (key == 224);

			switch (key) {
			case LEFT:  // 왼쪽
				if (Crush_check(board, Bx - 1, By, B_rotation) == True) {
					Move_block(board, LEFT);
					break;
				}
			case RIGHT: // 오른쪽
				if (Crush_check(board, Bx + 1, By, B_rotation) == True) {
					Move_block(board, RIGHT);
					break;
				}
			case  DOWN:  // 아래쪽
				if (Crush_check(board, Bx, By + 1, B_rotation) == True) {
					Move_block(board, DOWN);
					break;
				}
			case UP:  // 위쪽
				if (Crush_check(board, Bx, By, (B_rotation + 1) % 4) == True) {
					Move_block(board, UP);
				}
				else if (Crush_flag == 1 && Crush_check(board, Bx, By - 1, (B_rotation + 1) % 4) == True) {
					Move_block(board, 100);
				}
			}
		}
		else {
			switch (key) {
			case SPACE: //스페이스 키를 눌렀을떄
				//printf("스페이스바");
				Space_flag = False;  //스페이스 flag 작동
				while (Crush_check(board, Bx, By + 1, B_rotation) == True) {
					Drop_block(board);
					//Move_block(board, DOWN);
				}
				Space_flag = True;
				return Space_flag;

			case P: //P(대문자) 눌렀을때 
			case p: //p(소문자) 눌렀을때 
				//pause(); //일시정지 
				break;
			case ESC: //ESC눌렀을때 
				system("cls"); //화면을 지우고 
				exit(0); //게임종료
			}
		}
	}
	while (_kbhit()) _getch(); //키버퍼를 비움
}

//블럭을 이동시키는 함수
void Move_block(int board[][BOARD_WIDTH] ,int Dir) {
	int i, j;
	
	switch (Dir) {
	case LEFT: //왼쪽방향 
		for (i = 0; i<4; i++) { //현재좌표의 블럭을 지움 
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = EMPTY;
			}
		}
		for (i = 0; i<4; i++) { //왼쪽으로 한칸가서 active block을 찍음 
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j - 1] = ACTIVE_BLOCK;
			}
		}
		Bx--; //좌표값 이동 
		break;

	case RIGHT:    //오른쪽 방향. 왼쪽방향이랑 같은 원리로 동작 
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = EMPTY;
			}
		}
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j + 1] = ACTIVE_BLOCK;
			}
		}
		Bx++;
		break;

	case DOWN:    //아래쪽 방향. 왼쪽방향이랑 같은 원리로 동작
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = EMPTY;
			}
		}
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i + 1][Bx + j] = ACTIVE_BLOCK;
			}
		}
		By++;
		break;

	case UP: //키보드 위쪽 눌렀을때 회전시킴. 
		for (i = 0; i<4; i++) { //현재좌표의 블럭을 지움  
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = EMPTY;
			}
		}
		B_rotation = (B_rotation + 1) % 4; //회전값을 1증가시킴(3에서 4가 되는 경우는 0으로 되돌림) 
		for (i = 0; i<4; i++) { //회전된 블록을 찍음 
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = ACTIVE_BLOCK;
			}
		}
		break;

	case 100: //블록이 바닥, 혹은 다른 블록과 닿은 상태에서 한칸위로 올려 회전이 가능한 경우 
			  //이를 동작시키는 특수동작 
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = EMPTY;
			}
		}
		B_rotation = (B_rotation + 1) % 4;
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i - 1][Bx + j] = ACTIVE_BLOCK;
			}
		}
		By--;
		break;
	}
}

//블럭을 한칸 내리는 함수
void Drop_block(int board[][BOARD_WIDTH]) {
	int i, j,a=0;

	//if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == True) { Crush_flag = False; }  // 밑이 비어있으면 Crush_flag 를 끔.

	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == False) // 밑이 비어있지 않으면 
	{
		///////////////////////////////////////////          // 조작중인 블럭을 굳힘.
		for (i = 0; i < BOARD_HEIGHT; i++) {
			for (j = 0; j < BOARD_WIDTH; j++) {
				if (board[i][j] == ACTIVE_BLOCK) {
					board[i][j] = INACTIVE_BLOCK;
				}
			}
		}
		//////////////////////////////////////////
		//Check_line();
		Block_flag = True;
		return;
	}
	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == True) { Move_block(board, DOWN); }  // 밑이 비어있으면 블럭을 한칸 아래로 이동시킴
	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == False) { Crush_flag = True;}  // 밑으로 이동이 안되면 Crush_flag 를 켬.
}

// 블럭의 배열을 보는 함수  // 삭제예정
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

void Check_line(int board[][BOARD_WIDTH]) {
	int i, j, k, l;

	int block_amount; //한줄의 블록갯수를 저장하는 변수 
	int combo = 0; //콤보갯수 저장하는 변수 지정및 초기화 

	for (i = BOARD_HEIGHT - 2; i>3;) { //BOARD_HEIGHT - 2 : 밑쪽벽의 윗칸부터,  i>3 : 천장(3)아래까지 검사 
		block_amount = 0; //블록갯수 저장 변수 초기화 
		for (j = 1; j<BOARD_WIDTH - 1; j++) { //벽과 벽사이의 블록갯루를 셈 
			if (board[i][j]>0) block_amount++;
		}
		if (block_amount == BOARD_WIDTH - 2) { //블록이 가득 찬 경우 

			for (k = i; k>1; k--) { //윗줄을 한칸씩 모두 내림(윗줄이 천장이 아닌 경우에만) 
				for (l = 1; l<BOARD_WIDTH - 1; l++) {
					if (board[k - 1][l] != CEILLING) board[k][l] = board[k - 1][l];
					if (board[k - 1][l] == CEILLING) board[k][l] = EMPTY;
					//윗줄이 천장인 경우에는 천장을 한칸 내리면 안되니까 빈칸을 넣음 
				}
			}
		}
		else i--;
	}
	for (j = 1; j<BOARD_WIDTH - 1; j++) { //벽과 벽사이의 블록갯루를 셈 
		if (board[3][j] > 0) {
			Game_over();
		}
	}

}

// 게임 오버
void Game_over() {
	system("cls");

	gotoxy(23, 5); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤"); //게임오버 메세지 
	gotoxy(23, 6); printf("▤                              ▤");
	gotoxy(23, 7); printf("▤  +-----------------------+   ▤");
	gotoxy(23, 8); printf("▤  |   G A M E  O V E R    |   ▤");
	gotoxy(23, 9); printf("▤  +-----------------------+   ▤");
	gotoxy(23, 10); printf("▤                              ▤");
	gotoxy(23, 11); printf("▤    YOUR SCORE: ...           ▤");
	gotoxy(23, 12); printf("▤                              ▤");
	gotoxy(23, 13); printf("▤                              ▤");
	gotoxy(23, 14); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");

	getc(stdin);
}

// 게임 리셋
void T_reset() {
	FILE *FP = fopen("score","rt");

	fclose(FP);
}