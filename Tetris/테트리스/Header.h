#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>

#pragma comment(lib,"winmm")// PlaySound �Լ��� ȣ���ϱ� ���� ��ó����

//////////////// ��ũ�� ���� ////////////////////
#define LEFT 75			//�·� �̵�
#define RIGHT 77		//��� �̵� 
#define UP 72			//ȸ�� 
#define DOWN 80			//soft drop
#define SPACE 32		//hard drop
#define p 112			//�Ͻ����� 
#define P 80			//�Ͻ�����
#define ESC 27			//��������
#define Enter 13		//����

#define ACTIVE_BLOCK -2		// �����ǹ迭�� ����� �̵������� ����� ���µ� 
#define CEILLING -1			// ����� �̵��� �� �ִ� ������ 0 �Ǵ� ���� ������ ǥ�� 
#define EMPTY 0				// ����� �̵��� �� ���� ������ ����� ǥ�� 
#define WALL 1				// ����� �̵��� �� ���� ��
#define INACTIVE_BLOCK 2	// �̵��� �Ϸ�� ��ϰ�

#define False 0
#define True 1

#define BOARD_HEIGHT 20 // ������ (����)  //������
#define BOARD_WIDTH 13	// ������ (����)  



////////////////   INTERFACE.C   /////////////////////////
int START_Display();	 // ��Ʈ���� ó�� ���� ȭ��

void Score_Board();		 // ��Ʈ���� ���ھ� ȭ�� (����, ������, ���ӹ���Ű ��.)

void Game_over();		 // ���� ���� ȭ��

////////////////  SYSTEM.C   /////////////////////////
void New_Board(int board[][BOARD_WIDTH]);									// ���ο� ���带 �����ϴ� �ϴ��Լ�

void Draw_Board(int board[][BOARD_WIDTH]);									// ���� ���带 �׸��� �Լ�

void Draw_Score(int board[][BOARD_WIDTH]);									// ���ھ� ���带 �׸��� �Լ�

void New_block(int board[][BOARD_WIDTH]);									// ���ο� ���� �����ϴ� �Լ�

void Move_block(int board[][BOARD_WIDTH], int Dir);							// ���� �����̴� �Լ�

void Drop_block(int board[][BOARD_WIDTH]);									// ���� ��ĭ ������ �Լ�

int Crush_check(int board[][BOARD_WIDTH], int Bx, int By, int B_rotation);	// ���� ���� �浹�ϴ��� Ȯ�� �ϴ� �Լ�

int Check_line(int board[][BOARD_WIDTH]);									// ������ �ϼ� ����� Ȯ���ϴ� �Լ�

void Check_key(int board[][BOARD_WIDTH]);									// Ű �Է��� �ִ��� Ȯ���ϴ� �Լ�

////////////////  UTILE.C   /////////////////////////
void textColor(int color_number);	// ���� ���� �ٲٴ� �Լ�

void gotoxy(int x, int y);			// Ŀ�� ��ġ�� ���ϴ� �Լ�

void Cursor(int n);					// Ŀ�� ����� �Լ�