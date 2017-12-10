#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>

#pragma comment(lib,"winmm")// PlaySound �Լ��� ȣ���ϱ� ���� ��ó����

//////////////// Macro ////////////////////
#define LEFT 75			//�·� �̵�
#define RIGHT 77		//��� �̵� 
#define UP 72			//ȸ�� 
#define DOWN 80			//soft drop
#define SPACE 32		//hard drop
#define p 112			//�Ͻ����� 
#define P 80			//�Ͻ�����
#define ESC 27			//��������
#define Enter 13		//����

#define ACTIVE_BLOCK -2				// �����ǹ迭�� ����� �̵������� ����� ���µ� 
#define CEILLING -1					// ����� �̵��� �� �ִ� ������ 0 �Ǵ� ���� ������ ǥ�� 
#define EMPTY 0						// ����� �̵��� �� ���� ������ ����� ǥ�� 
#define WALL 1						// ����� �̵��� �� ���� ��
#define INACTIVE_BLOCK 2			// �̵��� �Ϸ�� ��ϰ�

#define False 0
#define True 1

#define BOARD_HEIGHT 20 // ������ (����)  //������
#define BOARD_WIDTH 13	// ������ (����)


//////////////////   Interface.c   ///////////////////
int START_Display();									// ��Ʈ���� ó�� ���� ȭ��

void Score_Board();										// ��Ʈ���� ���ھ� ȭ�� (����, ������, ���ӹ���Ű ��.)

int Pause();											// �Ͻ����� �Լ�

void Game_over();										// ���� ���� ȭ��

void Ranking();											// ���� ��ŷ ȭ��

///////////////////  Game.c        ///////////////////
void Game_main();										// ���� ���� �Լ�

void Game_Reset();										// ���� ���� �Լ�

void New_block();										// ���ο� ���� ����� �Լ�

void Draw_Score();										// ���ھ� ���带 �׸��� �Լ�

void Draw_Board();										// ���� ���带 �׸��� �Լ�

void Move_block(int Dir);								// ���� �����̴� �Լ�

void Drop_block();										// ���� ��ĭ ������ �Լ�

void New_Board();										// ���ο� ���带 ����� �Լ�

int Check_line();										// ������ �ϼ� ����� Ȯ���ϴ� �Լ�

int Check_key();										// Ű �Է��� �ִ��� Ȯ���ϴ� �Լ�

int Crush_check(int Bx, int By, int B_rotation);		// ���� ���� �浹�ϴ��� Ȯ�� �ϴ� �Լ�

///////////////////  Rank.c        ///////////////////
void Rank_main();										// ��ŷ ���� �Լ�

///////////////////  System.c      ///////////////////
void System_main();										// �ý��� ���� �Լ�

///////////////////  Utile.c       ///////////////////
void textColor(int color_number);						// ���� ���� �ٲٴ� �Լ�

void gotoxy(int x, int y);								// Ŀ�� ��ġ�� ���ϴ� �Լ�

void Cursor(int n);										// Ŀ�� ����� �Լ�