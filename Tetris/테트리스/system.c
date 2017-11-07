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

		memset(board, EMPTY, sizeof(board)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //���� �޸� �ʱ�ȭ   memset(����, �ʱ�ȭ��, ����ũ��)

		for (y = 0; y < BOARD_HEIGHT; y++) {
			for (x = 0; x < BOARD_WIDTH; x++) {

				if (x == 0) { board[y][x] = 1; }

				if (x == BOARD_WIDTH - 1) { board[y][x] = 1; }

				if (y == BOARD_HEIGHT - 1) { board[y][x] = 1; }
			}
		}

		Board_flag = False;
	}
	///////////////////////////////////////////////////////////

	system("cls");

	// �� �׸���
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {
			if (board[y][x] == ACTIVE_BLOCK) {
				gotoxy(6 + (x * 2), 2 + y);
				printf("��");
			}
			if (board[y][x] == WALL)
			{
				gotoxy(6 + (x * 2), 2 + y);
				printf("��");
			}
			if (board[y][x] == EMPTY)
			{
				gotoxy(6 + (x * 2), 2 + y);
				printf("0");
			}
		}
	}
}

// �� ����ȭ
void new_Block(int board[][BOARD_WIDTH]) {

	srand((unsigned)time(NULL));  // ���� ����

	int b_type; //��� ������ ���� 
	int b_rotation; //��� ȸ���� ���� 
	int b_type_next; //���� ��ϰ� ���� 

	b_type_next = rand() % 7; //���� ���� ���� 
	b_type = b_type_next; //���������� ������ 
	b_rotation = 0;  //ȸ���� 0������ ������ 

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

void check_Key() {
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

void move_Block(int board[][BOARD_WIDTH]) {
	
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
			printf("%2d ", board[y][x]);
		}
		printf("\n");
	}

	getc(stdin);
}