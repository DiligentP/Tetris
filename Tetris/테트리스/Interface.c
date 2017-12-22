#include "Header.h"

extern int Score;
extern info Player[100];
extern int Player_num;
extern info Player_Top[10];

// ��Ʈ���� �� ó�� ���� Ÿ��Ʋ ȭ�� 
void START_Display() {
	system("title T E T R I S");

	int i = 0;
	int TETRIS_LOGO[] =
	{	9, 8, 0, 1, 1, 1, 0, 2, 2, 2, 0, 3, 3, 3, 0, 4, 4, 4, 0, 5, 0, 6, 6, 6, 0, 10,
		8, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 4, 0, 4, 0, 5, 0, 6, 0, 0, 0,10,
		8, 0, 0, 1, 0, 0, 2, 2, 2, 0, 0, 3, 0, 0, 4, 4, 4, 0, 5, 0, 6, 6, 6, 0,10,
		8, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 4, 4, 0, 0, 5, 0, 0, 0, 6, 0,10,
		8, 0, 0, 1, 0, 0, 2, 2, 2, 0, 0, 3, 0, 0, 4, 0, 4, 0, 5, 0, 6, 6, 6, 0, 7		};
		for (int i = 0; ; i++) {
			if (TETRIS_LOGO[i] == 10) {	printf("\n");	}
			if (TETRIS_LOGO[i] == 9) {	printf("\n\n\n\n\n");	}
			if (TETRIS_LOGO[i] == 8) {	printf("\t    ");		}

			else if (TETRIS_LOGO[i] == 1) {	textColor(12); printf("��");	}
			else if (TETRIS_LOGO[i] == 2) {	textColor(10); printf("��");	}
			else if (TETRIS_LOGO[i] == 3) {	textColor(14); printf("��");	}
			else if (TETRIS_LOGO[i] == 4) {	textColor(9); printf("��");	}
			else if (TETRIS_LOGO[i] == 5) {	textColor(11); printf("��");	}
			else if (TETRIS_LOGO[i] == 6) {	textColor(13); printf("��");	}
			
			else if (TETRIS_LOGO[i] == 7) {	
				textColor(8); printf(" by JH");
				break;
			}
			else {	printf("  ");	}
		}
		printf("\n"); textColor(7); printf("\n\n\n       ");
}

// �α��� �޴� ȭ��
int Draw_Login_menu(int count) {
	int KeyBoard = 0;

	system("cls");

	START_Display();

	while (1) {
		if (KeyBoard == RIGHT) 
		{ 
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
			count = 1;
			return count;
		}

		if (KeyBoard == DOWN && count != 8) {
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
			count++;
		}
		else if (KeyBoard == UP && count != 5) {
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
			count--;
		}
		
		if (KeyBoard == Enter || KeyBoard == SPACE) {
			return count;
		}

		gotoxy(36, 11);  printf("�� ��\n\n");
		printf("\t\t\t    ");
		if (count == 5) { textColor(240); }
		printf(">>     MY INFO    <<\n\n");
		if (count == 5) { textColor(7); }
		printf("\t\t\t    ");
		if (count == 6) { textColor(240); }
		printf(">>    L O G I N   <<\n\n");
		if (count == 6) { textColor(7); }
		printf("\t\t\t    ");
		if (count == 7) { textColor(240); }
		printf(">>   S I G N U P  <<\n\n");
		if (count == 7) { textColor(7); }
		printf("\t\t\t    ");
		if (count == 8) { textColor(240); }
		printf(">>     E X I T    <<\n");
		if (count == 8) { textColor(7); }

		KeyBoard = _getch();
	}
	
}

// �α��� �Է� ȭ��
void Draw_input_Login() {
	printf("\n\n\n\n\n\n\n\t\t ");
	printf("[ID      ] :");

	printf("\n\t\t��------------------------------------��");
	printf("\n\n\n\t\t ");
	printf("[Password] :");

	printf("\n\t\t��------------------------------------��");

	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t[Teb] ĭ�̵�  [ESC] ����ȭ��");
}

// ��Ʈ���� ���� �޴� ȭ��
int Main_Menu() {
	int KeyBoard = 0; int count = 0; //  KeyBoard : Ű���� ���� �޴� ���� , count : UP(72) = +1, DOWN(80) = -1

	///////////////////// ��Ʈ���� �޴� ///////////////////////
	system("cls");

	START_Display();

	while (1) 
	{	
		if (KeyBoard == LEFT) {
			PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
			count = 5;
			count = Draw_Login_menu(count);
			if (count > 4) {
				return count;
			}
		}

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
		gotoxy(36, 11); printf("�� ��\n\n");
		printf("\t\t\t    ");
		if (count == 1) { textColor(240); }
		printf(">>   GAME START   <<\n\n");
		if (count == 1) { textColor(7); }
		printf("\t\t\t    ");
		if (count == 2) { textColor(240); }
		printf(">>     R A N K    <<\n\n");
		if (count == 2) { textColor(7); }
		printf("\t\t\t    ");
		if (count == 3) { textColor(240); }
		printf(">>   S Y S T E M  <<\n\n");
		if (count == 3) { textColor(7); }
		printf("\t\t\t    ");
		if (count == 4) { textColor(240); }
		printf(">>     E X I T    <<\n");
		if (count == 4) { textColor(7); }
		KeyBoard = _getch();
	}
}

// ���ھ�� ȭ��
void Draw_Score() {
	int x = BOARD_WIDTH * 2 + 10, y = 3;
	gotoxy(x, y); printf(" BEST SCORE : %d", Player[Player_num].Score);
	gotoxy(x, y+1); printf(" SCORE : %d", Score);
	gotoxy(x, y + 3); printf("+- N E X T -+ ");
	gotoxy(x, y + 4); printf("|           | ");
	gotoxy(x, y + 5); printf("|           | ");
	gotoxy(x, y + 6); printf("|           | ");
	gotoxy(x, y + 7); printf("|           | ");
	gotoxy(x, y + 8); printf("+-- -   - --+ ");

	gotoxy(x - 2, y + 14); printf("   ��    : Change       | SPACE : Hard Drop");
	gotoxy(x - 2, y + 16); printf("��    �� : Left / Right | P   : Pause");
	gotoxy(x - 2, y + 18); printf("   ��    : Soft Drop    | ESC  : Quit");
}

// ���� ���� ȭ��
void Draw_Gameover() {

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
}

//���� �Ͻ����� ȭ��
void Draw_Pause(int count) {
	int x = 9, y = 5;

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
}

// ��ŷ ȭ��
void Draw_Rank() {
	system("cls");
	
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("\n\n\t[ %d  st ]\t Name: %s      Score: %d",i+1, Player_Top[i].Name, Player_Top[i].Score);
	}
	_getch();
}

void Draw_myinfo() {
	if (Player_num == -1) {
		system("cls");
		printf("\n\n\n\t �α����� ���ּ���.\n");
		return;
	}
	system("cls");
	printf("\n\n\n");
	printf("\t\t�̸� : %s\n\n", Player[Player_num].Name);
	printf("\t\t���̵� : %s\n\n", Player[Player_num].Id);
	printf("\t\t��й�ȣ : %s\n\n",Player[Player_num].Password);
	printf("\t\t����Ʈ ���ھ� : %d\n\n",Player[Player_num].Score);
}