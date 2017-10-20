#include "Header.h"

// 테트리스 맨 처음 시작 화면 
int T_START_Display() {
	int KeyBoard = 0; int count = 0; //  KeyBoard : 키보드 값을 받는 변수 , count : UP(72) = +1, DOWN(80) = -1

	system("title T E T R I S");

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
		else if (KeyBoard == Enter) {
			return count;									//  카운트를 반환하고 함수를 종료.
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

void showBoard()
{
	int x, y;
	int board[BOARD_HEIGHT + 1][BOARD_WIDTH + 2] = { 0, };

	system("cls");   // 화면 클리어

	//중앙보드라인
	for (x = 1; x <= BOARD_WIDTH + 1; x++)
	{
		board[BOARD_HEIGHT][x] = 1; //board 배열중앙1인식
		gotoxy((BOARD_X)+x * 2, BOARD_Y + BOARD_HEIGHT);  //콘솔좌표
		printf("━");
	}
	//왼쪽보드라인
	for (y = 0; y<BOARD_HEIGHT + 1; y++)
	{
		board[y][0] = 1; //board 배열왼쪽1인식
		gotoxy(BOARD_X, BOARD_Y + y);
		if (y == BOARD_HEIGHT)
			printf("┗");
		else
				printf("┃");
	}
	//오른쪽보드라인
	for (y = 0; y<BOARD_HEIGHT + 1; y++)
	{
		board[y][BOARD_WIDTH + 1] = 1; //board 배열오른쪽1인식
		gotoxy(BOARD_X + (BOARD_WIDTH + 2) * 2, BOARD_Y + y);
		if (y == BOARD_HEIGHT)
			printf("┛");
		else
				printf("┃");
	}

	//모서리값값변경
	board[20][0] = 1;
	board[20][11] = 1;



	//보드판숫자보기
	/*
	gotoxy(6,2);
	for(y=0; y<=BOARD_HEIGHT; y++){
	      for(x=0; x<=BOARD_WIDTH+1; x++){
	              gotoxy(4+(x*2),2+y);
	              printf("%d ",board[y][x]);
	      }
	      printf("\n");
	}
	*/
	gotoxy(36,2); 	printf("Best: 1000");
	gotoxy(36,3); 	printf("Score: 100");

	gotoxy(36,6);	printf(" NEXT ");
	gotoxy(36,7);	printf("┌━━━━━━┐");
	gotoxy(36,8);	printf("┃            ┃");
	gotoxy(36,9);	printf("┃            ┃");
	gotoxy(36,10);	printf("┃            ┃");
	gotoxy(36,11);	printf("┗━━━━━━┘");

	gotoxy(36,14);	printf("KEY");
	gotoxy(36,15);	printf("    ESC (P) : 나가기(메뉴)");
	gotoxy(36,17);	printf("    ↑상 ↓하 ←좌 →우");
	gotoxy(36,19);	printf("    SPACE : 맨밑으로내리기");

	getc(stdin);

	system("cls");

	gotoxy(23, 5); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤"); //게임오버 메세지 
	gotoxy(23, 6); printf("▤                              ▤");
	gotoxy(23, 7); printf("▤  +-----------------------+   ▤");
	gotoxy(23, 8); printf("▤  |   G A M E  O V E R    |   ▤");
	gotoxy(23, 9); printf("▤  +-----------------------+   ▤");
	gotoxy(23,10); printf("▤                              ▤");
	gotoxy(23,11); printf("▤    YOUR SCORE: ...           ▤");
	gotoxy(23,12); printf("▤                              ▤");
	gotoxy(23,13); printf("▤                              ▤");
	gotoxy(23,14); printf("▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤▤");
	
	getc(stdin);


	printf("\n");
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

// 커서 보이기 & 숨기기
void cursor(int n) 
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}