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

/////////////////// ����ü ////////////////////
typedef struct tetris {

	int level;       //����
	int gmaeover;    //���� ����
	int score;       // ����
	int rotation;    // ������ ��ġ
	int absX, absY;  // ������ ������ǥ
	int curX, curY;  // ������ ������ǥ
	int curblock;    // �����
	int nextblock;   // ������

} Tetris;
/////////////////////////////////////////////////


void textColor(int color_number); // ���� ���� �ٲٴ� �Լ�

void gotoxy(int x, int y); // Ŀ�� ��ġ�� ���ϴ� �Լ�

void T_START_Display();  //��Ʈ���� ó�� ���� ȭ��

