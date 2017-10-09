#include "Header.h"

// 테트리스 맨 처음 시작 화면 
void T_START_Display() {
	int KeyBoard = 0; int count = 0; //  KeyBoard : 키보드 값을 받는 변수 , count : UP(72) = +1, DOWN(80) = -1

	system("title ●T E T R I S●");

	int i = 0;

	///////////////////// 테트리스 로고 ///////////////////////
	/*
	printf("\t ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("\tㅣ■■■■■ ■■■■ ■■■■■ ■■■■  ■■■ ■■■■ㅣ\n");
	printf("\tㅣ    ■     ■           ■     ■     ■   ■   ■      ㅣ\n");
	printf("\tㅣ    ■     ■■■■     ■     ■■■■    ■   ■■■■ㅣ\n");
	printf("\tㅣ    ■     ■           ■     ■     ■   ■         ■ㅣ\n");
	printf("\tㅣ    ■     ■■■■     ■     ■     ■ ■■■ ■■■■ㅣ\n");

	printf("\t ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n\n\t");
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
				textColor(12); printf("■");
			}
			else if (TETRIS_LOGO[i] == 2) {
				textColor(10); printf("■");
			}
			else if (TETRIS_LOGO[i] == 3) {
				textColor(14); printf("■");
			}
			else if (TETRIS_LOGO[i] == 4) {
				textColor(9); printf("■");
			}
			else if (TETRIS_LOGO[i] == 5) {
				textColor(11); printf("■");
			}
			else if (TETRIS_LOGO[i] == 6) {
				textColor(13); printf("■");
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

		///////////////////// 테트리스 메뉴 ///////////////////////

		if (KeyBoard == DOWN && count != 4) {
			count++;
		}
		else if (KeyBoard == UP && count != 1) {
			count--;
		}
		else if (KeyBoard == ESC) {
			exit(0);
		}

		//textColor(240);  흰색 배경
		//textColor(7);		기본

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

// 텍스트 색깔 변경
void textColor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

// 커서 위치 변경
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}