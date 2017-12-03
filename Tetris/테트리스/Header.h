#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>

//////////////// ��ũ�� ���� ////////////////////
#define LEFT 75 //�·� �̵�    //Ű���尪�� 
#define RIGHT 77 //��� �̵� 
#define UP 72 //ȸ�� 
#define DOWN 80 //soft drop
#define SPACE 32 //hard drop
#define p 112 //�Ͻ����� 
#define P 80 //�Ͻ�����
#define ESC 27 //��������
#define Enter 13 //����

#define False 0
#define True 1

#define BOARD_HEIGHT 20 // ������ (����)  //������
#define BOARD_WIDTH 13	// ������ (����)  

#define ACTIVE_BLOCK -2 // �����ǹ迭�� ����� �̵������� ����� ���µ� 
#define CEILLING -1     // ����� �̵��� �� �ִ� ������ 0 �Ǵ� ���� ������ ǥ�� 
#define EMPTY 0         // ����� �̵��� �� ���� ������ ����� ǥ�� 
#define WALL 1          // ����� �̵��� �� ���� ��
#define INACTIVE_BLOCK 2 // �̵��� �Ϸ�� ��ϰ�

////////////////  SYSTEM.C   /////////////////////////
int T_START_Display();  //��Ʈ���� ó�� ���� ȭ��

void T_reset();   // ��Ʈ���� ����

void New_Board(int board[][BOARD_WIDTH]);

void Draw_Board(int board[][BOARD_WIDTH]);

void New_block(int board[][BOARD_WIDTH]);

void Game_over();

void Move_block(int board[][BOARD_WIDTH], int Dir);

void Drop_block(int board[][BOARD_WIDTH]);

void board_Check(int board[][BOARD_WIDTH]);

int Crush_check(int board[][BOARD_WIDTH], int Bx, int By, int B_rotation);

void Check_line(int board[][BOARD_WIDTH]);

////////////////  UTILE.C   /////////////////////////
void textColor(int color_number); // ���� ���� �ٲٴ� �Լ�

void gotoxy(int x, int y); // Ŀ�� ��ġ�� ���ϴ� �Լ�

void Cursor(int n); //Ŀ�� ����� �Լ�