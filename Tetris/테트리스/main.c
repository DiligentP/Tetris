#include "Header.h"

///////////////////// ���� ���� ���� ///////////////////
int board[BOARD_HEIGHT][BOARD_WIDTH] = { EMPTY, };   //// ���� ������� ������   EMPTY = 0  //�ʱⰪ


int main() {

	int Count,C;         // T_START_Display(); �Լ����� ��ȯ�� ��ȯ��
	extern int Speed, Space_flag;

	Cursor(0);         // Ŀ�� ����� : 0 ����� 1 ���̱�

	while (1)
	{
		Count = START_Display();       // 1 : GAME START  2 : RANK  3 : SYSTEM  4 : EXIT 

		enum menu {GAMESTART=1,RANK,SYSTEM,EXIT};

		switch (Count)
		{
		case GAMESTART:
			PlaySound("Tetris_background_music.wav", NULL, SND_ASYNC | SND_LOOP);  // ��Ʈ���� ���� ���

			New_Board(board);   // ���ο� ���带 ����ϴ�.

			while (1) {
				New_block(board);		// ���ο� ���� ����ϴ�.

				for (int i = 0; i < 5; i++) {
					Check_key(board);    // �ʴ� 5���� �Է��� �ް� ����� �����մϴ�.
					
					if (Space_flag == True) { // �����̽��ٸ� ������ �ٷ� ���� ���� �����մϴ�.
						Space_flag = False;
						break; 
					}  
					Draw_Board(board);	 // ���带 �׸��ϴ�.
					Sleep(Speed);
				}

				Drop_block(board);       // 1���Ŀ� ���� �����ϴ�.
				C = Check_line(board);		 // ������ üũ�մϴ�.(���� ���� �Ǻ�, ���� ���ٿϼ� �Ǻ�)

				if (C == True) { break; }
			}
			break;

		case RANK:
			gotoxy(3 + (BOARD_HEIGHT / 2) - 1, 7); printf("COMBO!");
			printf("\t\t\t��ŷ�� ���� �غ����Դϴ�.\n\n");
			getc(stdin);
			break;
		
		case SYSTEM:
			printf("\t\t\t�ý����� ���� �غ����Դϴ�.\n\n");
			getc(stdin);
			break;
		
		case EXIT:
			return 0;
		}
	}
}