#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<mmsystem.h>

#pragma comment(lib,"winmm")// PlaySound �Լ��� ȣ���ϱ� ���� ��ó����

typedef struct information {
	char Id[20];		//���̵�
	char Password[20];	//�н�����
	char Name[20];		// �̸�
	char Time[20];		// �÷��� �ð�
	char Score[20];		// ����
	char Date[20];		// �÷��� ��¥
}info;

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
#define Teb 9			//��

#define ACTIVE_BLOCK -2				// �����ǹ迭�� ����� �̵������� ����� ���µ� 
#define CEILLING -1					// ����� �̵��� �� �ִ� ������ 0 �Ǵ� ���� ������ ǥ�� 
#define EMPTY 0						// ����� �̵��� �� ���� ������ ����� ǥ�� 
#define WALL 1						// ����� �̵��� �� ���� ��
#define INACTIVE_BLOCK 2			// �̵��� �Ϸ�� ��ϰ�

#define False 0
#define True 1

#define BOARD_HEIGHT 20 // ������ (����)  //������
#define BOARD_WIDTH 13	// ������ (����)

///////////////////  Login.c        ///////////////////
void Login_main(int Count);								// �α��� ���� �Լ�

int Login();											// �α��� �Լ�

int input_Login(int dir);								// ���̵� �н����� �Է��Լ�

//////////////////   Interface.c   ///////////////////
void START_Display();									// ��Ʈ���� ó�� ���� Ÿ��Ʋ ȭ��

int Draw_Login_menu();									// ��Ʈ���� �α��� ȭ��

void Draw_Score();										// ��Ʈ���� ���ھ� ȭ�� (����, ������, ���ӹ���Ű ��.)

void Draw_Pause(int count);								// ���� �Ͻ����� ȭ��

void Draw_Gameover();									// ���� ���� ȭ��

void Draw_Rank();										// ���� ��ŷ ȭ��

int Main_Menu();										// ���� ���� �޴� ȭ��

///////////////////  Game.c        ///////////////////
void Game_main();										// ���� ���� �Լ�

void Game_Reset();										// ���� ���� �Լ�

void New_block();										// ���ο� ���� �����ϴ� �Լ�

void Score_Board();										// ���ھ� ���带 �����ϴ� �Լ�

void Draw_Board();										// ���� ���带 �׸��� �Լ�

void Move_block(int Dir);								// ���� �����̴� �Լ�

void Drop_block();										// ���� ��ĭ ������ �Լ�

void New_Board();										// ���ο� ���带 ����� �Լ�

int Check_line();										// ������ �ϼ� ����� Ȯ���ϴ� �Լ�

int Check_key();										// Ű �Է��� �ִ��� Ȯ���ϴ� �Լ�

int Crush_check(int Bx, int By, int B_rotation);		// ���� ���� �浹�ϴ��� Ȯ�� �ϴ� �Լ�

int Pause();											// ������ �Ͻ� �����ϴ� �Լ�

///////////////////  Rank.c        ///////////////////
void Rank_main();										// ��ŷ ���� �Լ�

///////////////////  System.c      ///////////////////
void System_main();										// �ý��� ���� �Լ�

///////////////////  Utile.c       ///////////////////
void textColor(int color_number);						// ���� ���� �ٲٴ� �Լ�

void gotoxy(int x, int y);								// Ŀ�� ��ġ�� ���ϴ� �Լ�

void Cursor(int n);										// Ŀ�� ����� �Լ�