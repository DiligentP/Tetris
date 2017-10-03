#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

void textColor(int color_number);  // 인터페이스의 글자 색깔 바꾸는 함수
void gotoxy(int x, int y);	// 인터페이스의 위치를 정하는 함수

#define LEFT 75 //좌로 이동    //키보드값들 
#define RIGHT 77 //우로 이동 
#define UP 72 //회전 
#define DOWN 80 //soft drop
#define SPACE 32 //hard drop
#define p 112 //일시정지 
#define P 80 //일시정지
#define ESC 27 //게임종료

void T_MAP();  //테트리스 맵 생성

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