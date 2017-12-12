#include "Header.h"

int board[BOARD_HEIGHT][BOARD_WIDTH] = { EMPTY, };   //// ���� ������� ��Ʈ���� ���� ������   EMPTY = 0  //�ʱⰪ
int board_cpy[BOARD_HEIGHT][BOARD_WIDTH] = { 100, }; //// ���κ��带 ī���� ������             100        //�ʱⰪ  //100���� �� ������ ���κ���� ��ġ�� �迭�� ���� �ϱ� ������.

////////////////////////// ��Ʈ���� �� �迭 //////////////////////////////////
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
}; //��ϸ�� ���� 4*4������ ����� ǥ�� blocks[b_type][b_rotation][i][j]�� ��� 

int Block_flag = True;		// ���ο� ���� �ʿ����� �˸��� FLAG
int Crush_flag = True;		// ���� �浹 ������ �Ǵ��ϴ� FLAG
int Space_flag = False;		// �����̽� Ű�� ���ȴ��� �Ǵ��ϴ� FLAG

int Bx, By;			//���� ������ġ
int B_type;			//��� ������ ���� 
int B_rotation;		//��� ȸ���� ���� 
int B_type_next;	//���� ��ϰ� ���� 

int Level = 1;		// ������ ������ ���� ���Ӽӵ��� ������ ������ �ö�
int Speed = 100;	// �ʴ� 5���� �Է��� �ޱ⶧���� 100 ������ �����δ� 500��.(500 = 0.5��)
int Score = 0;		// ���� ����


extern info Player[10];	// ��ŷ�� �ø� 10���� ������ ����
extern int Player_count;//��ŷ�� �ö� �÷��̾��� ī����

//���� ���� �Լ�
void Game_main()
{
	int Key, C;

	PlaySound("Tetris_background_music.wav", NULL, SND_ASYNC | SND_LOOP);  // ��Ʈ���� ���� ���

	Game_Reset();             // ������ �����մϴ�.

	while (1)
	{
		New_block();		// ���ο� ���� ����ϴ�.
		Score_Board();		//���ھ� �������

		for (int i = 0; i < 5; i++)
		{
			Key = Check_key();    // �ʴ� 5���� �Է��� �ް� ����� �����մϴ�.

			if (Key == ESC) { break; }
			if (Space_flag == True) { // �����̽��ٸ� ������ �ٷ� ���� ���� �����մϴ�.
				Space_flag = False;
				break;
			}

			Draw_Board();	 // ���带 �׸��ϴ�.
			Sleep(Speed);
		}
		Drop_block();       // 1���Ŀ� ���� �����ϴ�.
		C = Check_line();		 // ������ üũ�մϴ�.(���� ���� �Ǻ�, ���� ���ٿϼ� �Ǻ�)
		if (C == True) { break; }
		if (Key == ESC) { break; }
	}
}

//���� ���� �ϴ� �Լ�
void Game_Reset() {

	// �� ������ �ʱ�ȭ
	srand((unsigned)time(NULL));  // ���� ����

	Score = 0;
	B_type = 0;
	B_rotation = 0;
	B_type_next = 0;
	Bx = (BOARD_WIDTH / 2) - 1;
	By = 0;

	New_Board();		// ���ο� ���带 ����ϴ�.
	New_block();		// ���ο� ���� ����ϴ�.

	
}

// ���� ����
void New_Board() {

	////////////////////// ���ο� ������ ���� ////////////////////

	//memset(����, �ʱ�ȭ��, ����ũ��)
	memset(board, EMPTY, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //���� �޸� �ʱ�ȭ   [������ ��簪�� EMPTY = 0(�����) ���� ����ϴ�]
	memset(board_cpy, 100, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //ī�Ǻ��� �޸� �ʱ�ȭ

																	  // �� �� �����//
	for (int y = 0; y < BOARD_HEIGHT; y++) {
		for (int x = 0; x < BOARD_WIDTH; x++) {

			if (x == 0) { board[y][x] = WALL; }                              //������ ������ ���� ����ϴ�(��)

			if (x == BOARD_WIDTH - 1) { board[y][x] = WALL; }                //������ ���� ���� ����ϴ�(��)

			if (y == BOARD_HEIGHT - 1) { board[y][x] = WALL; }				  //������ �Ʒ��� ���� ����ϴ�(��)
		}
	}
	system("cls");

	///////////////////////////////////////////////////////////
}

// �� ����
void New_block() {

	/////////////// NEW BLOCK ///////////////
	srand((unsigned)time(NULL));  // ���� ����

	if (Block_flag == True) {		// ���ο� ���� �ʿ��Ҷ�,

		Bx = (BOARD_WIDTH / 2) - 1;		// ������ ���� x ��ǥ
		By = 0;							// ������ ���� y ��ǥ

		B_type = B_type_next; //���������� ������ 
		B_type_next = (rand() % 7); //���� ���� ����
		B_rotation = 0;  //ȸ���� 0������ ������ 

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

// ���κ��� �׸���
void Draw_Board() {
	int i, j, x, y;

	// õ�� �����//
	for (j = 1; j<BOARD_WIDTH - 1; j++) { //y���� 3�� ��ġ�� õ���� ���� 
		if (board[3][j] == EMPTY) board[3][j] = CEILLING;
	}

	// �� �׸���
	for (y = 0; y < BOARD_HEIGHT; y++) {
		for (x = 0; x < BOARD_WIDTH; x++) {
			if (board_cpy[y][x] != board[y][x]) {
				gotoxy(6 + (x * 2), 2 + y);
				switch (board[y][x]) {
				case EMPTY: // ����
					printf("  ");
					break;
				case CEILLING: // õ��
					printf(". ");
					break;
				case WALL: // ��
					printf("��");
					break;
				case INACTIVE_BLOCK:
					printf("��");
					break;
				case ACTIVE_BLOCK: //�����̰��ִ� �� ���  
					printf("��");
					break;
				}
			}
		}
	}
	// ���κ����� �迭 ���¸� �����մϴ�.
	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			board_cpy[i][j] = board[i][j];
		}
	}
}

// ���ھ�� ����
void Score_Board() {
	Draw_Score();		//���ھ�� �׸���
	////////////////// ���� ���� �׸��ϴ�./////////////
	for (int i = 0; i < 4; i++) {
		gotoxy(39, 6 + i);
		for (int j = 0; j < 4; j++) {

			if (blocks[B_type_next][0][i][j] == 1)
			{
				printf("��");
			}
			else
			{
				printf("  ");
			}
		}
	}
	/////////////////////////////////////////////////////

}

// Ű�Է��� �ִ��� Ȯ�δ� �Լ�
int Check_key() {
	int key = 0; //Ű�� �ʱ�ȭ

	if (_kbhit()) {				//Ű ���� �ִ� ���
		key = _getch();

		if (key == 224) {		// ����Ű �� ���
			do { key = _getch(); } while (key == 224);

			switch (key) {
			case LEFT:  // ����
				if (Crush_check(Bx - 1, By, B_rotation) == True) {
					Move_block(LEFT);
					break;
				}
				break;
			case RIGHT: // ������
				if (Crush_check(Bx + 1, By, B_rotation) == True) {
					Move_block(RIGHT);
					break;
				}
				break;
			case  DOWN:  // �Ʒ���
				if (Crush_check(Bx, By + 1, B_rotation) == True) {
					Move_block(DOWN);
					break;
				}
				break;
			case UP:  // ����
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
			case SPACE: //�����̽� Ű�� ��������
				Space_flag = False;  //�����̽� flag �۵�
				while (Crush_check(Bx, By + 1, B_rotation) == True) {
					Drop_block();
					Score = Score + 2;
				}
				Space_flag = True;
				break;

			case P: //P(�빮��) �������� 
			case p: //p(�ҹ���) �������� 
				key = Pause(); //�Ͻ����� 
				if (key == 1) { return ESC; }
				memset(board_cpy, 100, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //ī�Ǻ��� �޸� �ʱ�ȭ
				PlaySound("Tetris_background_music.wav", NULL, SND_ASYNC | SND_LOOP);  // ��Ʈ���� ���� ���
				break;
			case ESC: //ESC�������� 
				PlaySound(NULL, NULL, 0); //���� ����.
				return ESC;
			}
		}
	}
	while (_kbhit()) _getch(); //Ű���۸� ���
	return 0;
}

// �浹�� Ȯ���ϴ� �Լ� (True  , False)
int Crush_check(int Bx, int By, int B_rotation) {
	int i, j;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) { //������ ��ġ�� �����ǰ� ������� ���ؼ� �浹�ϸ� false�� ���� 
			if (blocks[B_type][B_rotation][i][j] == 1 && board[By + i][Bx + j]>0)
				return False;
		}
	}
	return True; //�ϳ��� ���浹�ϸ� true���� 
}

// ���� �̵���Ű�� �Լ�
void Move_block(int Dir) {
	int i, j;

	switch (Dir) {
	case LEFT: //���ʹ��� 
		for (i = 0; i<4; i++) {
			for (j = 0; j<4; j++) {
				if (blocks[B_type][B_rotation][i][j] == 1) {
					board[By + i][Bx + j] = EMPTY; //������ǥ�� ���� ����
					board[By + i][Bx + j - 1] = ACTIVE_BLOCK; //�������� ��ĭ���� active block�� ���� 
				}
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

// ���� ��ĭ ������ �Լ�
void Drop_block() {
	int i, j, a = 0;

	if (Crush_flag && Crush_check(Bx, By + 1, B_rotation) == False) // ���� ������� ������ 
	{
		///////////////////////////////////////////          // �������� ���� ����.
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
	if (Crush_flag && Crush_check(Bx, By + 1, B_rotation) == True) { Move_block(DOWN); }  // ���� ��������� ���� ��ĭ �Ʒ��� �̵���Ŵ
	if (Crush_flag && Crush_check(Bx, By + 1, B_rotation) == False) { Crush_flag = True; }  // ������ �̵��� �ȵǸ� Crush_flag �� ��.
}

// ������ üũ�ϴ� �Լ�
int Check_line() {
	int i, j, k, l;

	int block_amount; //������ ��ϰ����� �����ϴ� ���� 
	int combo = 0; //�޺����� �����ϴ� ���� ������ �ʱ�ȭ 

				   ///////////////////////   ���� üũ   ///////////////////////////////
	for (i = BOARD_HEIGHT - 2; i>3;) { //BOARD_HEIGHT - 2 : ���ʺ��� ��ĭ����,  i>3 : õ��(3)�Ʒ����� �˻� 
		block_amount = 0; //��ϰ��� ���� ���� �ʱ�ȭ 
		for (j = 1; j<BOARD_WIDTH - 1; j++) { //���� �������� ��ϰ��縦 �� 
			if (board[i][j]>0) block_amount++;
		}
		if (block_amount == BOARD_WIDTH - 2) { //����� ���� �� ��� 

			combo++;

			for (k = i; k>1; k--) { //������ ��ĭ�� ��� ����(������ õ���� �ƴ� ��쿡��) 
				for (l = 1; l<BOARD_WIDTH - 1; l++) {
					if (board[k - 1][l] != CEILLING) board[k][l] = board[k - 1][l];
					if (board[k - 1][l] == CEILLING) board[k][l] = EMPTY;
					//������ õ���� ��쿡�� õ���� ��ĭ ������ �ȵǴϱ� ��ĭ�� ���� 
				}
			}
			Score += 100;
		}
		else i--;
	}

	//////////////////////  �޺� üũ  ////////////////////////////////

	if (combo) { //�� ������ �ִ� ��� ������ ���� ��ǥ�� ���� ǥ����  
		if (combo > 1) { //2�޺��̻��� ��� ��� ���ʽ��� �޼����� �����ǿ� ����ٰ� ���� 
			Draw_Board();
			gotoxy(6 + (BOARD_HEIGHT / 2), 7); printf("%d COMBO!", combo);
			Sleep(1000);
			Score += (combo * Level * 100);

			memset(board_cpy, 100, sizeof(int)*(BOARD_HEIGHT)*(BOARD_WIDTH));	//�ؽ�Ʈ�� ����� ���� main_cpy�� �ʱ�ȭ.
																				//(main_cpy�� main_org�� ���� �ٸ��Ƿ� ������ draw()ȣ��� ������ ��ü�� ���� �׸��� ��) 
		}
	}

	/////////////////////////// ���� ���� üũ ///////////////////////////////////////
	for (j = 1; j<BOARD_WIDTH - 1; j++) { //���� �������� ��ϰ��縦 �� 
		if (board[3][j] > 0) {
			Draw_Gameover();

			gotoxy(25, 11); printf("   YOUR SCORE : %2d", Score);
			getc(stdin);
			PlaySound(NULL, NULL, 0); //���� ����.

			return True;
		}
	}
	return False;
}

// ������ �Ͻ����� �ϴ� �Լ�
int Pause() {
	int KeyBoard = 0, count = 0;
	while (1) {
		PlaySound(NULL, NULL, 0); //���� ����.

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