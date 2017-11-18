#include "Header.h"

////////////////////////// ��Ʈ���� �� �迭 //////////////////////////////////
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
}; //��ϸ�� ���� 4*4������ ����� ǥ�� blcoks[b_type][b_rotation][i][j]�� ��� 
//////////////////////////////////////////////////////////////////////////////
int Board_flag = True;    //  ���ο� ���尡 �ʿ����� �˸��� FLAG
int Block_flag = True;    // ���ο� ���� �ʿ����� �˸��� FLAG
int Crush_flag = False;   // ���� �浹 ������ �Ǵ��ϴ� FLAG

int SPEED = 500;

int Bx, By;		//���� ������ġ
int B_type; //��� ������ ���� 
int B_rotation; //��� ȸ���� ���� 
int B_type_next; //���� ��ϰ� ���� 

// ��Ʈ���� �� ó�� ���� ȭ�� 
int T_START_Display() {
	int KeyBoard = 0; int count = 0; //  KeyBoard : Ű���� ���� �޴� ���� , count : UP(72) = +1, DOWN(80) = -1

	system("title T E T R I S");

	int i = 0;

	///////////////////// ��Ʈ���� �ΰ� ///////////////////////
	/*
	printf("\t �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� \n");
	printf("\t�ӡ����� ����� ������ �����  ���� ������\n");
	printf("\t��    ��     ��           ��     ��     ��   ��   ��      ��\n");
	printf("\t��    ��     �����     ��     �����    ��   ������\n");
	printf("\t��    ��     ��           ��     ��     ��   ��         ���\n");
	printf("\t��    ��     �����     ��     ��     �� ���� ������\n");
	printf("\t �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� \n\n\t");

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
				textColor(12); printf("��");
			}
			else if (TETRIS_LOGO[i] == 2) {
				textColor(10); printf("��");
			}
			else if (TETRIS_LOGO[i] == 3) {
				textColor(14); printf("��");
			}
			else if (TETRIS_LOGO[i] == 4) {
				textColor(9); printf("��");
			}
			else if (TETRIS_LOGO[i] == 5) {
				textColor(11); printf("��");
			}
			else if (TETRIS_LOGO[i] == 6) {
				textColor(13); printf("��");
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

		///////////////////// ��Ʈ���� �޴� ///////////////////////

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
			return count;									//  ī��Ʈ�� ��ȯ�ϰ� �Լ��� ����.
		}

		//textColor(240);  ��� ���
		//textColor(7);		�⺻

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

// ���� ����ȭ
void Update_Board(int board[][BOARD_WIDTH]) {
	int x, y;

	////////////////////// ���ο� ������ ���� ////////////////////
	if (Board_flag == True) {
		
		//memset(����, �ʱ�ȭ��, ����ũ��)
		memset(board, EMPTY, sizeof(board)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //���� �޸� �ʱ�ȭ   [������ ��簪�� EMPTY = 0(�����) ���� ����ϴ�]

		// �� �� �����//
		for (y = 0; y < BOARD_HEIGHT; y++) {
			for (x = 0; x < BOARD_WIDTH; x++) {

				if (x == 0) { board[y][x] = WALL; }                              //������ ������ ���� ����ϴ�(��)

				if (x == BOARD_WIDTH - 1) { board[y][x] = WALL; }                //������ ���� ���� ����ϴ�(��)

				if (y == BOARD_HEIGHT - 1) { board[y][x] = WALL; }				  //������ �Ʒ��� ���� ����ϴ�(��)
			}
		}
		//////////////////
		Board_flag = False;
	}
	///////////////////////////////////////////////////////////

	system("cls");

	// �� �� �����//
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {

			if (x == 0) { board[y][x] = WALL; }                              //������ ������ ���� ����ϴ�(��)

			if (x == BOARD_WIDTH - 1) { board[y][x] = WALL; }                //������ ���� ���� ����ϴ�(��)

			if (y == BOARD_HEIGHT - 1) { board[y][x] = WALL; }				  //������ �Ʒ��� ���� ����ϴ�(��)
		}
	}

	

	// �� �׸���
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {
			if (board[y][x] == ACTIVE_BLOCK) {			// ������ ACTIVE_BLOCK = -2 (�����ϼ� �ִ� ��)
				gotoxy(6 + (x * 2), 2 + y);
				printf("��");
			}
			if (board[y][x] == WALL)					// ������ WALL = 1  (��)
			{
				gotoxy(6 + (x * 2), 2 + y);
				printf("��");
			}
			if (board[y][x] == EMPTY)					// ������ EMPTY = 0 (�����)
			{
				gotoxy(6 + (x * 2), 2 + y);
				printf("  ");
			}
			if (board[y][x] == INACTIVE_BLOCK) {
				gotoxy(6 + (x * 2), 2 + y);
				printf("��");
			}
		}
	}
}

// �� ����ȭ
void New_block(int board[][BOARD_WIDTH]) {

	srand((unsigned)time(NULL));  // ���� ����

	Bx = (BOARD_WIDTH / 2) - 1;
	By = 0;
	B_type_next = rand() % 7; //���� ���� ���� 
	B_type = B_type_next; //���������� ������ 
	B_rotation = 0;  //ȸ���� 0������ ������ 

	/////////////// NEW BLOCK ///////////////
	if (Block_flag == True) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1)
				{
					board[By+i][Bx+j] = ACTIVE_BLOCK;
				}
			}
		}
		Block_flag = False;
	}
	/////////////////////////////////////////
}

// �浹�� Ȯ���ϴ� �Լ� (True  , False)
int Crush_check(int board[][BOARD_WIDTH], int Bx, int By, int B_rotation) {
	int i, j;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) { //������ ��ġ�� �����ǰ� ������� ���ؼ� ��ġ�� false�� ���� 
			if (blocks[B_type][B_rotation][i][j] == 1 && board[By + i][Bx + j]>0)
				return False;
		}
	}
	return True; //�ϳ��� �Ȱ�ġ�� true���� 
}

// ���� ����
void Game_over() {
	system("cls");

	gotoxy(23,  5); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�"); //���ӿ��� �޼��� 
	gotoxy(23,  6); printf("��                              ��");
	gotoxy(23,  7); printf("��  +-----------------------+   ��");
	gotoxy(23,  8); printf("��  |   G A M E  O V E R    |   ��");
	gotoxy(23,  9); printf("��  +-----------------------+   ��");
	gotoxy(23, 10); printf("��                              ��");
	gotoxy(23, 11); printf("��    YOUR SCORE: ...           ��");
	gotoxy(23, 12); printf("��                              ��");
	gotoxy(23, 13); printf("��                              ��");
	gotoxy(23, 14); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");

	getc(stdin);
}

// Ű�Է��� �ִ��� Ȯ�δ� �Լ�
void Check_key() {
	int key = 0; //Ű�� �ʱ�ȭ

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

//���� �̵���Ű�� �Լ�
void Move_block(int board[][BOARD_WIDTH] ,int Dir) {
	int i, j;
	
	switch (Dir) {
	case LEFT: //���ʹ��� 
		for (i = 0; i<4; i++) { //������ǥ�� ���� ���� 
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = EMPTY;
			}
		}
		for (i = 0; i<4; i++) { //�������� ��ĭ���� active block�� ���� 
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j - 1] = ACTIVE_BLOCK;
			}
		}
		Bx--; //��ǥ�� �̵� 
		break;

	case RIGHT:    //������ ����. ���ʹ����̶� ���� ������ ���� 
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

	case DOWN:    //�Ʒ��� ����. ���ʹ����̶� ���� ������ ����
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

	case UP: //Ű���� ���� �������� ȸ����Ŵ. 
		for (i = 0; i<4; i++) { //������ǥ�� ���� ����  
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = EMPTY;
			}
		}
		B_rotation = (B_rotation + 1) % 4; //ȸ������ 1������Ŵ(3���� 4�� �Ǵ� ���� 0���� �ǵ���) 
		for (i = 0; i<4; i++) { //ȸ���� ����� ���� 
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) board[By + i][Bx + j] = ACTIVE_BLOCK;
			}
		}
		break;

	case 100: //����� �ٴ�, Ȥ�� �ٸ� ��ϰ� ���� ���¿��� ��ĭ���� �÷� ȸ���� ������ ��� 
			  //�̸� ���۽�Ű�� Ư������ 
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

//���� ��ĭ ������ �Լ�
void Drop_block(int board[][BOARD_WIDTH]) {
	int i, j;

	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == True) { Crush_flag = False;}  // ���� ��������� Crush_flag �� ��.

	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == False) // ���� ������� ������ 
	{
		///////////////////////////////////////////          // �������� ���� ����.
		for (i = 0; i < BOARD_HEIGHT; i++) {
			for (j = 0; j < BOARD_WIDTH; j++) {
				if (board[i][j] == ACTIVE_BLOCK) {
					board[i][j] = INACTIVE_BLOCK;
				}
			}
		}
		//////////////////////////////////////////
		Crush_flag = False;
		//Check_line();
		Block_flag = True;
		return;
	}
	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == True) { Move_block(board, DOWN); }  // ���� ��������� ���� ��ĭ �Ʒ��� �̵���Ŵ
	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == False) { Crush_flag = True; }  // ������ �̵��� �ȵǸ� Crush_flag �� ��.
}

// ���� �迭�� ���� �Լ�
void board_Check(int board[][BOARD_WIDTH]) {
	int y, x;
	// �迭 ����

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