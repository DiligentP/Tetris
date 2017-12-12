#include "Header.h"

int board[BOARD_HEIGHT][BOARD_WIDTH] = { EMPTY, };   //// 현재 사용중인 테트리스 메인 보드판   EMPTY = 0  //초기값
int board_cpy[BOARD_HEIGHT][BOARD_WIDTH] = { 100, }; //// 메인보드를 카피한 보드판             100        //초기값  //100으로 준 이유는 메인보드와 겹치는 배열이 없게 하기 위함임.

////////////////////////// 테트리스 블럭 배열 //////////////////////////////////
const int blocks[7][4][4][4] = {
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
}; //블록모양 저장 4*4공간에 블록을 표현 blocks[b_type][b_rotation][i][j]로 사용 

int Block_flag = True;		// 새로운 블럭이 필요함을 알리는 FLAG
int Crush_flag = True;		// 블럭의 충돌 유무를 판단하는 FLAG
int Space_flag = False;		// 스페이스 키가 눌렸는지 판단하는 FLAG

int Bx, By;			//블럭의 생성위치
int B_type;			//블록 종류를 저장 
int B_rotation;		//블록 회전값 저장 
int B_type_next;	//다음 블록값 저장 

int Level = 1;		// 게임의 레벨에 따라서 게임속도와 점수가 배율이 올라감
int Speed = 100;	// 초당 5번의 입력을 받기때문에 100 이지만 실제로는 500임.(500 = 0.5초)
int Score = 0;		// 게임 점수


extern info Player[10];	// 랭킹에 올릴 10명의 데이터 공간
extern int Player_count;//랭킹에 올라간 플레이어의 카운터

//게임 메인 함수
void Game_main()
{
	int Key, C;

	PlaySound("Tetris_background_music.wav", NULL, SND_ASYNC | SND_LOOP);  // 테트리스 음악 재생

	Game_Reset();             // 게임을 리셋합니다.

	while (1)
	{
		New_block();		// 새로운 블럭을 만듭니다.
		Score_Board();		//스코어 보드생성

		for (int i = 0; i < 5; i++)
		{
			Key = Check_key();    // 초당 5번의 입력을 받고 명령을 수행합니다.

			if (Key == ESC) { break; }
			if (Space_flag == True) { // 스페이스바를 누르면 바로 다음 블럭을 생성합니다.
				Space_flag = False;
				break;
			}

			Draw_Board();	 // 보드를 그립니다.
			Sleep(Speed);
		}
		Drop_block();       // 1초후에 블럭을 내립니다.
		C = Check_line();		 // 라인을 체크합니다.(게임 오버 판별, 블럭의 한줄완성 판별)
		if (C == True) { break; }
		if (Key == ESC) { break; }
	}
}

//게임 리셋 하는 함수
void Game_Reset() {

	// 블럭 데이터 초기화
	srand((unsigned)time(NULL));  // 난수 생성

	Score = 0;
	B_type = 0;
	B_rotation = 0;
	B_type_next = 0;
	Bx = (BOARD_WIDTH / 2) - 1;
	By = 0;

	New_Board();		// 새로운 보드를 만듭니다.
	New_block();		// 새로운 블럭을 만듭니다.

	
}

// 보드 생성
void New_Board() {

	////////////////////// 새로운 보드판 생성 ////////////////////

	//memset(변수, 초기화값, 변수크기)
	memset(board, EMPTY, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //보드 메모리 초기화   [보드의 모든값을 EMPTY = 0(빈공간) 으로 만듭니다]
	memset(board_cpy, 100, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //카피보드 메모리 초기화

																	  // 블럭 벽 만들기//
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {

			if (x == 0) { board[y][x] = WALL; }                              //보드의 오른쪽 벽을 만듭니다(ㅣ)

			if (x == BOARD_WIDTH - 1) { board[y][x] = WALL; }                //보드의 왼쪽 벽을 만듭니다(ㅣ)

			if (y == BOARD_HEIGHT - 1) { board[y][x] = WALL; }				  //보드의 아래쪽 벽을 만듭니다(ㅡ)
		}
	}
	system("cls");

	///////////////////////////////////////////////////////////
}

// 블럭 생성
void New_block() {

	/////////////// NEW BLOCK ///////////////
	srand((unsigned)time(NULL));  // 난수 생성

	if (Block_flag == True) {		// 새로운 블럭이 필요할때,

		Bx = (BOARD_WIDTH / 2) - 1;		// 생성된 블럭의 x 좌표
		By = 0;							// 생성된 블럭의 y 좌표

		B_type = B_type_next; //다음블럭값을 가져옴 
		B_type_next = (rand() % 7); //다음 블럭을 만듦
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

// 메인보드 그리기
void Draw_Board() {
	int i, j, x, y;

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
	// 메인보드의 배열 형태를 복사합니다.
	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			board_cpy[i][j] = board[i][j];
		}
	}
}

// 스코어보드 생성
void Score_Board() {
	Draw_Score();		//스코어보드 그리기
	////////////////// 다음 블럭을 그립니다./////////////
	for (int i = 0; i < 4; i++) {
		gotoxy(39, 6 + i);
		for (int j = 0; j < 4; j++) {

			if (blocks[B_type_next][0][i][j] == 1)
			{
				printf("■");
			}
			else
			{
				printf("  ");
			}
		}
	}
	/////////////////////////////////////////////////////

}

// 키입력이 있는지 확인는 함수
int Check_key() {
	int key = 0; //키값 초기화

	if (_kbhit()) {				//키 값이 있는 경우
		key = _getch();

		if (key == 224) {		// 방향키 인 경우
			do { key = _getch(); } while (key == 224);

			switch (key) {
			case LEFT:  // 왼쪽
				if (Crush_check(Bx - 1, By, B_rotation) == True) {
					Move_block(LEFT);
					break;
				}
				break;
			case RIGHT: // 오른쪽
				if (Crush_check(Bx + 1, By, B_rotation) == True) {
					Move_block(RIGHT);
					break;
				}
				break;
			case  DOWN:  // 아래쪽
				if (Crush_check(Bx, By + 1, B_rotation) == True) {
					Move_block(DOWN);
					break;
				}
				break;
			case UP:  // 위쪽
				if (Crush_check(Bx, By, (B_rotation + 1) % 4) == True) {
					Move_block(UP);
				}
				else if (Crush_flag == 1 && Crush_check(Bx, By - 1, (B_rotation + 1) % 4) == True) {
					Move_block(100);
				}
				break;
			}
		}
		else {
			switch (key) {
			case SPACE: //스페이스 키를 눌렀을떄
				Space_flag = False;  //스페이스 flag 작동
				while (Crush_check(Bx, By + 1, B_rotation) == True) {
					Drop_block();
					Score = Score + 2;
				}
				Space_flag = True;
				break;

			case P: //P(대문자) 눌렀을때 
			case p: //p(소문자) 눌렀을때 
				key = Pause(); //일시정지 
				if (key == 1) { return ESC; }
				memset(board_cpy, 100, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //카피보드 메모리 초기화
				PlaySound("Tetris_background_music.wav", NULL, SND_ASYNC | SND_LOOP);  // 테트리스 음악 재생
				break;
			case ESC: //ESC눌렀을때 
				PlaySound(NULL, NULL, 0); //음악 종료.
				return ESC;
			}
		}
	}
	while (_kbhit()) _getch(); //키버퍼를 비움
	return 0;
}

// 충돌을 확인하는 함수 (True  , False)
int Crush_check(int Bx, int By, int B_rotation) {
	int i, j;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) { //지정된 위치의 게임판과 블럭모양을 비교해서 충돌하면 false를 리턴 
			if (blocks[B_type][B_rotation][i][j] == 1 && board[By + i][Bx + j]>0)
				return False;
		}
	}
	return True; //하나도 안충돌하면 true리턴 
}

// 블럭을 이동시키는 함수
void Move_block(int Dir) {
	int i, j;

	switch (Dir) {
	case LEFT: //왼쪽방향 
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) {
					board[By + i][Bx + j] = EMPTY; //현재좌표의 블럭을 지움
					board[By + i][Bx + j - 1] = ACTIVE_BLOCK; //왼쪽으로 한칸가서 active block을 찍음 
				}
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

// 블럭을 한칸 내리는 함수
void Drop_block() {
	int i, j, a = 0;

	if (Crush_flag && Crush_check(Bx, By + 1, B_rotation) == False) // 밑이 비어있지 않으면 
	{
		///////////////////////////////////////////          // 조작중인 블럭을 굳힘.
		for (i = 0; i < BOARD_HEIGHT; i++) {
			for (j = 0; j < BOARD_WIDTH; j++) {
				if (board[i][j] == ACTIVE_BLOCK) {
					board[i][j] = INACTIVE_BLOCK;
					Score += 1;
				}
			}
		}
		//////////////////////////////////////////
		Block_flag = True;
		return;
	}
	if (Crush_flag && Crush_check(Bx, By + 1, B_rotation) == True) { Move_block(DOWN); }  // 밑이 비어있으면 블럭을 한칸 아래로 이동시킴
	if (Crush_flag && Crush_check(Bx, By + 1, B_rotation) == False) { Crush_flag = True; }  // 밑으로 이동이 안되면 Crush_flag 를 켬.
}

// 라인을 체크하는 함수
int Check_line() {
	int i, j, k, l;

	int block_amount; //한줄의 블록갯수를 저장하는 변수 
	int combo = 0; //콤보갯수 저장하는 변수 지정및 초기화 

				   ///////////////////////   라인 체크   ///////////////////////////////
	for (i = BOARD_HEIGHT - 2; i>3;) { //BOARD_HEIGHT - 2 : 밑쪽벽의 윗칸부터,  i>3 : 천장(3)아래까지 검사 
		block_amount = 0; //블록갯수 저장 변수 초기화 
		for (j = 1; j<BOARD_WIDTH - 1; j++) { //벽과 벽사이의 블록갯루를 셈 
			if (board[i][j]>0) block_amount++;
		}
		if (block_amount == BOARD_WIDTH - 2) { //블록이 가득 찬 경우 

			combo++;

			for (k = i; k>1; k--) { //윗줄을 한칸씩 모두 내림(윗줄이 천장이 아닌 경우에만) 
				for (l = 1; l<BOARD_WIDTH - 1; l++) {
					if (board[k - 1][l] != CEILLING) board[k][l] = board[k - 1][l];
					if (board[k - 1][l] == CEILLING) board[k][l] = EMPTY;
					//윗줄이 천장인 경우에는 천장을 한칸 내리면 안되니까 빈칸을 넣음 
				}
			}
			Score += 100;
		}
		else i--;
	}

	//////////////////////  콤보 체크  ////////////////////////////////

	if (combo) { //줄 삭제가 있는 경우 점수와 레벨 목표를 새로 표시함  
		if (combo > 1) { //2콤보이상인 경우 경우 보너스및 메세지를 게임판에 띄웠다가 지움 
			Draw_Board();
			gotoxy(6 + (BOARD_HEIGHT / 2), 7); printf("%d COMBO!", combo);
			Sleep(1000);
			Score += (combo * Level * 100);

			memset(board_cpy, 100, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH));	//텍스트를 지우기 위해 main_cpy을 초기화.
																				//(main_cpy와 main_org가 전부 다르므로 다음번 draw()호출시 게임판 전체를 새로 그리게 됨) 
		}
	}

	/////////////////////////// 게임 오버 체크 ///////////////////////////////////////
	for (j = 1; j<BOARD_WIDTH - 1; j++) { //벽과 벽사이의 블록갯루를 셈 
		if (board[3][j] > 0) {
			Draw_Gameover();

			gotoxy(25, 11); printf("   YOUR SCORE : %2d", Score);
			getc(stdin);
			PlaySound(NULL, NULL, 0); //음악 종료.

			return True;
		}
	}
	return False;
}

// 게임을 일시정지 하는 함수
int Pause() {
	int KeyBoard = 0, count = 0;
	while (1) {
		PlaySound(NULL, NULL, 0); //음악 종료.

		Draw_Pause(count);

		if (KeyBoard == DOWN && count != 2) {
			count++;
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
		}
		else if (KeyBoard == UP && count != 1) {
			count--;
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
		}
		else if (KeyBoard == ESC) {
			break;
		}
		else if (KeyBoard == Enter || KeyBoard == SPACE) {
			if (count == 1) {
				system("cls");
				break;
			}
			else if (count == 2) {
				return 1;
			}
		}
		
		KeyBoard = _getch();
	}
	return 0;
}