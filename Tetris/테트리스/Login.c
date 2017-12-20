#include "Header.h"

info Player[100];		// 최대 100명까지 데이터를 생성가능함.
int Player_count;		// 파일로 받은 플레이어의 수를 담는 변수
int Player_num;			// 로그인한 플레이어의 구조체 배열 넘버를 저장함.  Player[Player_num] == 로그인한 회원의 정보

char Id_s[20], Ps_s[20], Name_s[20];	// 입력받은 아이디와 패스워드를 저장할 임시 공간 , 저장되어있는 플레이어의 데이터와 비교함.

void Login_main(int Count) {

	Info_data_read();

	while (1) 
	{
		enum login_menu { INFO = 5, LOGIN, SIGNUP, EXIT };

		switch (Count) 
		{
		case INFO:
			system("cls");
			list();
			_getch();
			break;
		case LOGIN:
			Login();
			break;
		case SIGNUP:
			SignUp();
			break;
		case EXIT:
			system("cls");
			Exit();
		}
		break;
	}

	Info_data_save();
}


// 파일 입출력  -  데이터를 불러오고 저장하는 기능을 하는 함수.
void Info_data_read() {

	int i = 0;

	FILE *data = fopen("Info_data.txt", "r+");

	if (data == NULL)
	{
		system("cls");
		printf("\n\n\t\t데이터파일을 생성하는 중입니다.");
		for (int i = 0; i < 3; i++) { Sleep(500); printf("."); }
		FILE *re = fopen("Info_data.txt", "w");							// 데이터파일을 생성함.
		fclose(re);
		return;
	}

	while(!feof(data)){  //데이터가 파일의 끝에 도달할떄 까지.  *feof 반환값 : 파일끝O [1~] 파일끝X [0]
		
		fscanf(data, "%s%s%s%s\n", Player[i].Name, Player[i].Id, Player[i].Password, Player[i].Score);
		i++;
	}

	Player_count = i;

	fclose(data);
}
void Info_data_save() {
	FILE *data = fopen("Info_data.txt", "w+");

	for (int j = 0; j < Player_count; j++) {
		fprintf(data, "%s %s %s %s\n", Player[j].Name, Player[j].Id, Player[j].Password, Player[j].Score);
	}

	fclose(data);
}

// 로그인의 기능 을 하는 함수.
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

// 로그인의 출력 부분
int input_Login(int dir) {			// (dir )	1 = 아이디 2 = 패스워드
	int Key = 0;
	int i = 0, j = 0;

	if (dir == 1) // 아이디
	{
		gotoxy(30, 7);
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
		gotoxy(30, 11);
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

// 회원가입 기능을 하는 함수.
void SignUp() {
	
	system("cls");

	input_signUp();

	printf("\n\t\t회원 가입이 되었습니다.");

	_getch();
}

// 회원가입의 출력부분
void input_signUp() {
	int i = 0;
	i = Player_count;

	printf("\n\n\n\n\t\tSIGN UP\n\n");
	printf("\t\tID 입력 : ");
	scanf("%s", Player[i].Id);
	printf("\n\n\t\tPASSWORD 입력 : ");
	scanf("%s", Player[i].Password);
	printf("\n\n\t\t이름 입력 :");
	scanf("%s", Player[i].Name);
	strcpy(Player[i].Score, "0");
	i++;

	Player_count = i;
}

// 로그인 할때, 회원의 아이디와 패스워드를 검사하는 함수.
int check_Login() {

	for (int i = 0; i < Player_count; i++) {

		if (!strcmp(Id_s, Player[i].Id) && (!strcmp(Ps_s, Player[i].Password)))
		{
			Player_num = i;   // 플레이어 배열의 넘버를 저장함.
			return True;
		}
	}
	return False;
}

// 회원 목록
void list() {
	for (int j = 0; j < Player_count; j++) {
		printf("%s %s %s %s\n", Player[j].Name, Player[j].Id, Player[j].Password, Player[j].Score);
	}
}