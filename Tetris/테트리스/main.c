#include "Header.h"

///////////////////// ���� ���� ���� ///////////////////
int board[BOARD_HEIGHT + 1][BOARD_WIDTH + 2] = { EMPTY, };   //// ���� ������� ������   EMPTY = 0  //�ʱⰪ


int main() {

	int Count;         // T_START_Display(); �Լ����� ��ȯ�� ��ȯ��

	Cursor(0);         // Ŀ�� ����� : 0 ����� 1 ���̱�

	while (1)
	{
		Count = T_START_Display();       // 1 : GAME START  2 : RANK  3 : SYSTEM  4 : EXIT 

		switch (Count)
		{
		case 1:
			Update_Board(board);   // ������ ����
			board_Check(board);
			
			break;
		case 2:
			printf("\t\t\t��ŷ�� ���� �غ����Դϴ�.\n\n");
			getc(stdin);
			break;
		case 3:
			printf("\t\t\t�ý����� ���� �غ����Դϴ�.\n\n");
			getc(stdin);
			break;
		case 4:
			exit(0);
		}
	}

	return 0;
}