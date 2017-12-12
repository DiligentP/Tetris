#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>

#pragma comment(lib,"winmm")// PlaySound 함수를 호출하기 위한 전처리기

typedef struct information {
	char Id[20];		//아이디
	char Password[20];	//패스워드
	char Name[20];		// 이름
	char Time[20];		// 플레이 시간
	char Score[20];		// 점수
	char Date[20];		// 플레이 날짜
}info;

//////////////// Macro ////////////////////
#define LEFT 75			//좌로 이동
#define RIGHT 77		//우로 이동 
#define UP 72			//회전 
#define DOWN 80			//soft drop
#define SPACE 32		//hard drop
#define p 112			//일시정지 
#define P 80			//일시정지
#define ESC 27			//게임종료
#define Enter 13		//엔터
#define Teb 9			//탭

#define ACTIVE_BLOCK -2				// 게임판배열에 저장될 이동가능한 블록의 상태들 
#define CEILLING -1					// 블록이 이동할 수 있는 공간은 0 또는 음의 정수로 표현 
#define EMPTY 0						// 블록이 이동할 수 없는 공간은 양수로 표현 
#define WALL 1						// 블록이 이동할 수 없는 벽
#define INACTIVE_BLOCK 2			// 이동이 완료된 블록값

#define False 0
#define True 1

#define BOARD_HEIGHT 20 // ┃개수 (세로)  //보드판
#define BOARD_WIDTH 13	// ━개수 (가로)

///////////////////  Login.c        ///////////////////
void Login_main(int Count);								// 로그인 메인 함수

int Login();											// 로그인 함수

int input_Login(int dir);								// 아이디 패스워드 입력함수

//////////////////   Interface.c   ///////////////////
void START_Display();									// 테트리스 처음 시작 타이틀 화면

int Draw_Login_menu();									// 테트리스 로그인 화면

void Draw_Score();										// 테트리스 스코어 화면 (점수, 다음블럭, 게임방향키 등.)

void Draw_Pause(int count);								// 게임 일시정지 화면

void Draw_Gameover();									// 게임 오버 화면

void Draw_Rank();										// 게임 랭킹 화면

int Main_Menu();										// 게임 메인 메뉴 화면

///////////////////  Game.c        ///////////////////
void Game_main();										// 게임 메인 함수

void Game_Reset();										// 게임 리셋 함수

void New_block();										// 새로운 블럭을 생성하는 함수

void Score_Board();										// 스코어 보드를 생성하는 함수

void Draw_Board();										// 메인 보드를 그리는 함수

void Move_block(int Dir);								// 블럭을 움직이는 함수

void Drop_block();										// 블럭을 한칸 내리는 함수

void New_Board();										// 새로운 보드를 만드는 함수

int Check_line();										// 라인이 완성 됬는지 확인하는 함수

int Check_key();										// 키 입력이 있는지 확인하는 함수

int Crush_check(int Bx, int By, int B_rotation);		// 블럭이 벽과 충돌하는지 확인 하는 함수

int Pause();											// 게임을 일시 정지하는 함수

///////////////////  Rank.c        ///////////////////
void Rank_main();										// 랭킹 메인 함수

///////////////////  System.c      ///////////////////
void System_main();										// 시스템 메인 함수

///////////////////  Utile.c       ///////////////////
void textColor(int color_number);						// 글자 색깔 바꾸는 함수

void gotoxy(int x, int y);								// 커서 위치를 정하는 함수

void Cursor(int n);										// 커서 숨기는 함수