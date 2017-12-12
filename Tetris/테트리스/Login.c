#include "Header.h"

info Palyer[100];		// 최대 100명까지 데이터를 생성가능함.

char Id_s[20], Ps_s[20];	// 입력받은 아이디와 패스워드를 저장할 임시 공간 , 저장되어있는 플레이어의 데이터와 비교함.

char Id[20] = "1234", Ps[20] = "1234";

void Login_main(int Count) {
	while (1) 
	{
		enum login_menu { INFO = 5, LOGIN, SIGNIN, EXIT };

		switch (Count) 
		{
		case INFO:
			system("cls");
			printf("내 정보");
			break;
		case LOGIN:
			Login();
			break;
		case SIGNIN:
			printf("회원가입");
			break;
		case EXIT:
			system("cls");
			exit(0);
		}
		break;
	}
}

void Login() {
	int KeyBoard = 0; int count = 1;
	int T=0;
	int Succes = 0;
	
	system("cls");

	Draw_input_Login();

	Cursor(1);
	T = input_Login(1);
	T = input_Login(T);
	Cursor(0);

	if (T == True) {
		Succes = check_Login();

		if (Succes == True) {
			system("cls");
			printf("로그인 완료");
			while (_getch() != '\r') {}   // 바로 넘어가는 경우를 방지하기위함임
		}
		else {
			system("cls");
			printf("아이디와 패스워드가 맞지 않습니다!");
			while (_getch() != '\r') {}   // 바로 넘어가는 경우를 방지하기위함임
		}
	}
	else if (T == False) {
		system("cls");
		printf("로그인 실패 !");
		while (_getch() != '\r') {  }   // 바로 넘어가는 경우를 방지하기위함임
	}
	else if (T == 3){
		system("cls");
		printf("아이디 패스워드는 15자 내외입니다.");
		while (_getch() != '\r') {}   // 바로 넘어가는 경우를 방지하기위함임
	}
}


int input_Login(int dir) {			// (dir )	1 = 아이디 2 = 패스워드
	int Key = 0;
	int i = 0 , j = 0;

	if (dir == 1) // 아이디
	{
		gotoxy(30,7);
		while ((Id_s[i] = _getch()) != '\t')
		{
			if (Id_s[i] == '\b') {    // 또 받으면 안 됨
				if (i == 0) { continue; }
				printf("\b \b");    // 왼쪽으로 이동하여 별을 지우고 다시 커서를 그 자리로
				i--;            // 배열의 첨자를 앞에서 받은 글자 위치로 이동
				Id_s[i] = '\0';    // 이동한 위치의 글자를 지움
			}
			else if (Id_s[i] == ESC) { return 4; }	// 나가기

			else if (Id_s[i] == '\r') { break; }	// 아이디 입력후 엔터를 누르면 비밀번호를 입력할수 있음.

			else if (i > 15) { return 3; }		// 입력값이 15자를 넘으면 에러발생

			else {
				printf("%c", Id_s[i]);
				i++;
			}
		}
		Id_s[i] = '\0';
		return 2;
	}

	else if (dir == 2) // 패스워드
	{
		gotoxy(30,11);
		while ((Ps_s[j] = _getch()) != '\r')
		{
			if (Ps_s[j] == '\b') {    // 또 받으면 안 됨
				if (j == 0) { continue; }
				printf("\b \b");    // 왼쪽으로 이동하여 별을 지우고 다시 커서를 그 자리로
				j--;            // 배열의 첨자를 앞에서 받은 글자 위치로 이동
				Ps_s[j] = '\0';    // 이동한 위치의 글자를 지움
			}
			else if (Ps_s[j] == ESC) { return 4; }	//나가기

			else if (j > 15) { return 3; }		// 입력값이 15자를 넘으면 에러발생

			else {
				_putch('*');
				j++;
			}
		}
		Ps_s[j] = '\0';
		return True;
	}

	else if (dir == 3) { //입력 초과 에러
		return 3;
	}

	else if (dir == 4) {
		return 4;
	}

	return False;
}

int check_Login() {
	if (!strcmp(Id_s, Id) && (!strcmp(Ps_s, Ps)))
	{
		return True;
	}
	else
	{
		return False;
	}
}