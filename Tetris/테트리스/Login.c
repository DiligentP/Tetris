#include "Header.h"

info Palyer[100];		// 최대 100명까지 데이터를 생성가능함.

char Id_s[20], Ps_s[20];	// 입력받은 아이디와 패스워드를 저장할 임시 공간 , 저장되어있는 플레이어의 데이터와 비교함.

char Id[20] = "1234", Ps[20] = "1234";

void Login_main(int Count) {
	
	while (1) 
	{
		enum login_menu { INFO = 1, LOGIN, SIGNIN, EXIT };

		switch (Count) 
		{
		case INFO:
			break;
		case LOGIN:
			system("cls");
			Login();
			break;
		case SIGNIN:
			break;
		case EXIT:
			system("cls");
			exit(0);
		}
	}
}

int Login() {
	int KeyBoard = 0; int count = 1;
	int T=0;
	
	//Draw_Login(count);

	while (1) {
		if (_kbhit()) {
			KeyBoard = _getch();
		}
		if (KeyBoard == Enter) {
			break;
		}
		if (KeyBoard == 49 || KeyBoard == 97) {
			KeyBoard = _getch();
			T = input_Login(1);
			gotoxy(30, 11); 
			input_Login(T);
		}

		if (KeyBoard == 224) {	// 방향키 인 경우
			KeyBoard = _getch();
			if ((KeyBoard == DOWN || KeyBoard == RIGHT) && count != 4) {
				PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
				count++;
			}
			else if ((KeyBoard == UP || KeyBoard == LEFT) && count != 1) {
				PlaySound("Tetris_tic.wav", NULL, SND_ASYNC);
				count--;
			}
			//Draw_Login(count);
			
		}
	}

	if (count == 3) {
		system("cls");
		printf("회원가입은 준비중입니다. ");
		_getch();
	}
	if (count == 4) {
		system("cls");
		printf("로그인 기능은 준비중입니다.");
		_getch();
	}
	system("cls");
	printf("로그인 실패");
	_getch();
}


int input_Login(int dir) {			// (dir )	1 = 아이디 2 = 패스워드

	int Key = 0;
	int i = 0;

	if (dir == 1) // 아이디
	{
		while ((Id_s[i] = _getch()) != '\t')
		{
			if (Id_s[i] == '\b') {    // 또 받으면 안 됨
				if (i == 0) { continue; }
				printf("\b \b");    // 왼쪽으로 이동하여 별을 지우고 다시 커서를 그 자리로
				i--;            // 배열의 첨자를 앞에서 받은 글자 위치로 이동
				Id_s[i] = '\0';    // 이동한 위치의 글자를 지움
			}

			else {
				printf("%c", Id_s[i]);
				i++;
			}
		}
		Id_s[i] = '\0';
		return True;
	}

	else if (dir == 2) // 패스워드
	{
		while ((Ps_s[i] = _getch()) != '\r')
		{
			if (Ps_s[i] == '\b') {    // 또 받으면 안 됨
				printf("\b \b");    // 왼쪽으로 이동하여 별을 지우고 다시 커서를 그 자리로
				i--;            // 배열의 첨자를 앞에서 받은 글자 위치로 이동
				Ps_s[i] = '\0';    // 이동한 위치의 글자를 지움
			}

			else {
				_putch('*');
				i++;
			}
		}
		Ps_s[i] = '\0';
		return True;
	}

	return False;
}