#include "Header.h"

// ��Ʈ���� �� ó�� ���� ȭ�� 
void T_START_Display() {
	int KeyBoard = 0; int count = 0; //  KeyBoard : Ű���� ���� �޴� ���� , count : UP(72) = +1, DOWN(80) = -1

	system("title ��T E T R I S��");

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

// �ؽ�Ʈ ���� ����
void textColor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

// Ŀ�� ��ġ ����
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}