#include "Header.h"

///////////////////// ���� ���� ���� ///////////////////
int board[BOARD_HEIGHT][BOARD_WIDTH] = { EMPTY, };   //// ���� ������� ������   EMPTY = 0  //�ʱⰪ


int main() {

	int Count;         // T_START_Display(); �Լ����� ��ȯ�� ��ȯ��
	int Key,i,j,c=0;

	Cursor(0);         // Ŀ�� ����� : 0 ����� 1 ���̱�

	while (1)
	{
		Count = T_START_Display();       // 1 : GAME START  2 : RANK  3 : SYSTEM  4 : EXIT 

		enum menu {GAMESTART=1,RANK,SYSTEM,EXIT};

		switch (Count)
		{
		case GAMESTART:
			PlaySound("tetris_background_music.wav", NULL, SND_ASYNC | SND_LOOP);  // ��Ʈ���� ���� ���

			New_Board(board);   // ���ο� ���带 ����ϴ�.

			while (1) {
				New_block(board);		// ���ο� ���� ����ϴ�.
  				for (i = 0; i < 5; i++) {
					Key = Check_key(board);    // �ʴ� 5���� �Է��� �ް� ����� �����մϴ�.
					Draw_Board(board);	 // ���带 �׸��ϴ�.
					Sleep(SPEED());
				}
				Drop_block(board);       // 1���Ŀ� ���� �����ϴ�.
				c = Check_line(board);		 // ������ üũ�մϴ�.
				if (c == 1) { break; }
			}
			PlaySound(NULL, NULL, NULL); //���� ����.
			break;

		case RANK:
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