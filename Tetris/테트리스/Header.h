#include <stdio.h>

void T_MAP();  //��Ʈ���� �� ����

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