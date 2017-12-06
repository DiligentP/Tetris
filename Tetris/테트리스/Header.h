#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>

#pragma comment(lib,"winmm")// PlaySound 함수를 호출하기 위한 전처리기

//////////////// 매크로 정의 ////////////////////
#define LEFT 75			//좌로 이동
#define RIGHT 77		//우로 이동 
#define UP 72			//회전 
#define DOWN 80			//soft drop
#define SPACE 32		//hard drop
#define p 112			//일시정지 
#define P 80			//일시정지
#define ESC 27			//게임종료
#define Enter 13		//엔터

#define ACTIVE_BLOCK -2		// 게임판배열에 저장될 이동가능한 블록의 상태들 
#define CEILLING -1			// 블록이 이동할 수 있는 공간은 0 또는 음의 정수로 표현 
#define EMPTY 0				// 블록이 이동할 수 없는 공간은 양수로 표현 
#define WALL 1				// 블록이 이동할 수 없는 벽
#define INACTIVE_BLOCK 2	// 이동이 완료된 블록값

#define False 0
#define True 1

#define BOARD_HEIGHT 20 // ┃개수 (세로)  //보드판
#define BOARD_WIDTH 13	// ━개수 (가로)  



////////////////   INTERFACE.C   /////////////////////////
int START_Display();	 // 테트리스 처음 시작 화면

void Score_Board();		 // 테트리스 스코어 화면 (점수, 다음블럭, 게임방향키 등.)

void Game_over();		 // 게임 오버 화면

////////////////  SYSTEM.C   /////////////////////////
void New_Board(int board[][BOARD_WIDTH]);									// 새로운 보드를 생성하는 하는함수

void Draw_Board(int board[][BOARD_WIDTH]);									// 메인 보드를 그리는 함수

void Draw_Score(int board[][BOARD_WIDTH]);									// 스코어 보드를 그리는 함수

void New_block(int board[][BOARD_WIDTH]);									// 새로운 블럭을 생성하는 함수

void Move_block(int board[][BOARD_WIDTH], int Dir);							// 블럭을 움직이는 함수

void Drop_block(int board[][BOARD_WIDTH]);									// 블럭을 한칸 내리는 함수

int Crush_check(int board[][BOARD_WIDTH], int Bx, int By, int B_rotation);	// 블럭이 벽과 충돌하는지 확인 하는 함수

int Check_line(int board[][BOARD_WIDTH]);									// 라인이 완성 됬는지 확인하는 함수

void Check_key(int board[][BOARD_WIDTH]);									// 키 입력이 있는지 확인하는 함수

////////////////  UTILE.C   /////////////////////////
void textColor(int color_number);	// 글자 색깔 바꾸는 함수

void gotoxy(int x, int y);			// 커서 위치를 정하는 함수

void Cursor(int n);					// 커서 숨기는 함수