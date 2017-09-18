#include <stdio.h>

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