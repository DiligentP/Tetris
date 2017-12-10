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
}; //��ϸ�� ���� 4*4������ ����� ǥ�� blocks[b_type][b_rotation][i][j]�� ��� 
//////////////////////////////////////////////////////////////////////////////
int board_cpy[BOARD_HEIGHT][BOARD_WIDTH] = { 100, };

int Block_flag = True;		// ���ο� ���� �ʿ����� �˸��� FLAG
int Crush_flag = True;		// ���� �浹 ������ �Ǵ��ϴ� FLAG
int Space_flag = False;		// �����̽� Ű�� ���ȴ��� �Ǵ��ϴ� FLAG

int Speed = 100;   // �ʴ� 5���� �Է��� �ޱ⶧���� 100 ������ �����δ� 500��.
int Score = 0;
int Level = 1;

int Bx, By;			//���� ������ġ
int B_type;			//��� ������ ���� 
int B_rotation;		//��� ȸ���� ���� 
int B_type_next;	//���� ��ϰ� ���� 

// ���� ����
void New_Board(int board[][BOARD_WIDTH]) {

	////////////////////// ���ο� ������ ���� ////////////////////
		
		//memset(����, �ʱ�ȭ��, ����ũ��)
		memset(board, EMPTY, sizeof(board)*(BOARD_HEIGHT)*(BOARD_WIDTH)); //���� �޸� �ʱ�ȭ   [������ ��簪�� EMPTY = 0(�����) ���� ����ϴ�]
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
void New_block(int board[][BOARD_WIDTH]) {

	/////////////// NEW BLOCK ///////////////
	srand((unsigned)time(NULL));  // ���� ����
	

	if (Block_flag == True) {

		Bx = (BOARD_WIDTH / 2) - 1;
		By = 0;
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
	Draw_Score(board);  //���ھ� �������
}

// ���κ��� �׸���
void Draw_Board(int board[][BOARD_WIDTH]) {
	int i,j,x,y;

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

// ���ھ�� �׸���
void Draw_Score(int board[][BOARD_WIDTH]) {
	Score_Board();
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

// �浹�� Ȯ���ϴ� �Լ� (True  , False)
int Crush_check(int board[][BOARD_WIDTH], int Bx, int By, int B_rotation) {
	int i, j;
	for (i = 0; i<4; i++) {
		for (j = 0; j<4; j++) { //������ ��ġ�� �����ǰ� ������� ���ؼ� �浹�ϸ� false�� ���� 
			if (blocks[B_type][B_rotation][i][j] == 1 && board[By + i][Bx + j]>0)
				return False;
		}
	}
	return True; //�ϳ��� ���浹�ϸ� true���� 
}

// Ű�Է��� �ִ��� Ȯ�δ� �Լ�
int Check_key(int board[][BOARD_WIDTH]) {
	int key = 0; //Ű�� �ʱ�ȭ
	
	if (_kbhit()) {				//Ű ���� �ִ� ���
 		key = _getch();

		if (key == 224) {		// ����Ű �� ���
			/**/do { key = _getch(); } while (key == 224);

			switch (key) {
			case LEFT:  // ����
				if (Crush_check(board, Bx - 1, By, B_rotation) == True) {
					Move_block(board, LEFT);
					break;
				}
				break;
			case RIGHT: // ������
				if (Crush_check(board, Bx + 1, By, B_rotation) == True) {
					Move_block(board, RIGHT);
					break;
				}
				break;
			case  DOWN:  // �Ʒ���
				if (Crush_check(board, Bx, By + 1, B_rotation) == True) {
					Move_block(board, DOWN);
					break;
				}
				break;
			case UP:  // ����
				if (Crush_check(board, Bx, By, (B_rotation + 1) % 4) == True) {
					Move_block(board, UP);
				}
				else if (Crush_flag == 1 && Crush_check(board, Bx, By - 1, (B_rotation + 1) % 4) == True) {
					Move_block(board, 100);
				}
				break;
			}
		}
		else {
			switch (key) {
			case SPACE: //�����̽� Ű�� ��������
				Space_flag = False;  //�����̽� flag �۵�
				while (Crush_check(board, Bx, By + 1, B_rotation) == True) {
					Drop_block(board);
					Score = Score + 2;
				}
				Space_flag = True;
				break;

			case P: //P(�빮��) �������� 
			case p: //p(�ҹ���) �������� 
				Pause(); //�Ͻ����� 
				_getch();
				break;
			case ESC: //ESC�������� 
				PlaySound(NULL, NULL, 0); //���� ����.
				return ESC;
			}
		}
	}
	while (_kbhit()) _getch(); //Ű���۸� ���
}

// ���� �̵���Ű�� �Լ�
void Move_block(int board[][BOARD_WIDTH] ,int Dir) {
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
void Drop_block(int board[][BOARD_WIDTH]) {
	int i, j,a=0;

	//if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == True) { Crush_flag = False; }  // ���� ��������� Crush_flag �� ��.

	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == False) // ���� ������� ������ 
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
	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == True) { Move_block(board, DOWN); }  // ���� ��������� ���� ��ĭ �Ʒ��� �̵���Ŵ
	if (Crush_flag && Crush_check(board, Bx, By + 1, B_rotation) == False) { Crush_flag = True;}  // ������ �̵��� �ȵǸ� Crush_flag �� ��.
}

// ������ üũ�ϴ� �Լ�
int Check_line(int board[][BOARD_WIDTH]) {
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
			Draw_Board(board);
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
			Game_over();
			_getch();
			return True;
		}
	}
	return False;
}