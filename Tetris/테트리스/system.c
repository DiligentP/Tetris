#include "Header.h"

int MAP_X = 15;
int MAP_Y = 20;

void T_START() {
	int i, j;
	printf("\n\n    ");
	///////////// Y //////////////////
	for (i = 0; i < MAP_Y; i++) {

		printf("\n    ¢Ì");
		for (j = 0; j < (MAP_X - 2); j++) {
			printf("  ");
		}
		printf("¢Ì");
	}
	///////////// X //////////////////
	printf("\n    ");
	for (i = 0; i < MAP_X; i++) {
		printf("¢Ì");
	}
	//////////////////////////////////
	printf("\n    ");
}

void textColor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}