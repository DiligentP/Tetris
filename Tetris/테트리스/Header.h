#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

//////////////// 매크로 정의 ////////////////////
#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //회전 
#define DOWN 80 //soft drop
#define SPACE 32 //hard drop
#define p 112 //일시정지 
#define P 80 //일시정지
#define ESC 27 //게임종료
#define Enter 13 //엔터

#define BOARD_HEIGHT 20 // ┃개수   //보드판
#define BOARD_WIDTH 12  // ━개수
#define BOARD_X 4 //보드열x좌표
#define BOARD_Y 2 //보드행y좌표


/////////////////// 구조체 ////////////////////
typedef struct tetris {

	int level;       //레벨
	int gmaeover;    //게임 오버
	int score;       // 점수
	int rotation;    // 도형의 위치
	int absX, absY;  // 도형의 절대좌표
	int curX, curY;  // 도형의 현재좌표
	int curblock;    // 현재블럭
	int nextblock;   // 다음블럭

} Tetris; 
/////////////////////////////////////////////////

////////////////  SYSTEM.C   /////////////////////////
void textColor(int color_number); // 글자 색깔 바꾸는 함수

void gotoxy(int x, int y); // 커서 위치를 정하는 함수

void cursor(int n); //커서 숨기는 함수

int T_START_Display();  //테트리스 처음 시작 화면

void showBoard();
/////////////////////////////////////////////////////