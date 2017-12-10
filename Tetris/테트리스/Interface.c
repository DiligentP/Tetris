#include "Header.h"

extern int Score;

// ��Ʈ���� �� ó�� ���� ȭ�� 
int START_Display() {
	int KeyBoard = 0; int count = 0; //  KeyBoard : Ű���� ���� �޴� ���� , count : UP(72) = +1, DOWN(80) = -1

	system("title T E T R I S");

	int i = 0;
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
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
			count++;
		}
		else if (KeyBoard == UP && count != 1) {
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
			count--;
		}
		else if (KeyBoard == ESC) {
			exit(0);
		}
		else if (KeyBoard == Enter || KeyBoard == SPACE) {
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

// ���ھ�� ȭ��
void Score_Board() {
	int x = BOARD_WIDTH * 2 + 10, y = 3;
	gotoxy(x, y); printf(" SCORE : %d", Score);
	gotoxy(x, y + 2); printf("+- N E X T -+ ");
	gotoxy(x, y + 3); printf("|           | ");
	gotoxy(x, y + 4); printf("|           | ");
	gotoxy(x, y + 5); printf("|           | ");
	gotoxy(x, y + 6); printf("|           | ");
	gotoxy(x, y + 7); printf("+-- -   - --+ ");

	gotoxy(x - 2, y + 14); printf("   ��    : Change       | SPACE : Hard Drop");
	gotoxy(x - 2, y + 16); printf("��    �� : Left / Right | P   : Pause");
	gotoxy(x - 2, y + 18); printf("   ��    : Soft Drop    | ESC  : Quit");
}

// ���� ���� ȭ��
void Game_over() {

	PlaySound(NULL, NULL, 0); //���� ����.

	PlaySound("Tetris_Arcade_Music_Loginska.wav", NULL, SND_ASYNC);

	system("cls");

	gotoxy(23, 5); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�"); //���ӿ��� �޼��� 
	gotoxy(23, 6); printf("��                              ��");
	gotoxy(23, 7); printf("��  +-----------------------+   ��");
	gotoxy(23, 8); printf("��  |   G A M E  O V E R    |   ��");
	gotoxy(23, 9); printf("��  +-----------------------+   ��");
	gotoxy(23, 10); printf("��                              ��");
	gotoxy(23, 11); printf("��                              ��");
	gotoxy(23, 12); printf("��                              ��");
	gotoxy(23, 13); printf("��                              ��");
	gotoxy(23, 14); printf("�ǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢǢ�");

	gotoxy(25, 11); printf("   YOUR SCORE : %2d", Score);
	getc(stdin);
	PlaySound(NULL, NULL, 0); //���� ����.
}

//���� �Ͻ����� ȭ��
int Pause() {
	int x = 9, y = 5;
	int KeyBoard = 0, count = 0;
	while (1) {

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

		gotoxy(x, y + 1); printf("                     ");
		gotoxy(x, y + 2); printf("+-------------------+");
		gotoxy(x, y + 3); printf("|     P A U S E     |");
		gotoxy(x, y + 4); printf("+-------------------+");
		gotoxy(x, y + 5); printf("                     ");
		if (count == 1) { textColor(240); }
		gotoxy(x + 5, y + 6); printf("[ Resuem ]");
		if (count == 1) { textColor(7); }
		if (count == 2) { textColor(240); }
		gotoxy(x + 5, y + 7); printf("[  Exit  ]");
		if (count == 2) { textColor(7); }
		gotoxy(x, y + 8); printf("                     ");
		KeyBoard = _getch();
	}
	return 0;
}

// ��ŷ ȭ��
void Ranking() {
	FILE *Ranking = fopen("Rankin.txt", "r+");

	system("cls");
	gotoxy(10, 3); printf("[1��]		������		5000		2017-12-10");
	gotoxy(10, 5); printf("[2��]		������		15000		2017-12-10");
}