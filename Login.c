#include "Header.h"

info Player[100];		// �ִ� 100������ �����͸� ����������.
int Player_count;		// ���Ϸ� ���� �÷��̾��� ���� ��� ����
int Player_num=-1;			// �α����� �÷��̾��� ����ü �迭 �ѹ��� ������.  Player[Player_num] == �α����� ȸ���� ����

char Id_s[20], Ps_s[20];	// �Է¹��� ���̵�� �н����带 ������ �ӽ� ���� , ����Ǿ��ִ� �÷��̾��� �����Ϳ� ����.

void Login_main(int Count) {

	Info_data_read();

	while (1) 
	{
		enum login_menu { INFO = 5, LOGIN, SIGNUP, EXIT };

		switch (Count) 
		{
		case INFO:
			system("cls");
			Draw_myinfo();
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


// ���� �����  -  �����͸� �ҷ����� �����ϴ� ����� �ϴ� �Լ�.
void Info_data_read() {

	int i = 0;

	FILE *data = fopen("Info_data.txt", "r+");

	if (data == NULL)
	{
		system("cls");
		printf("\n\n\t\t������������ �����ϴ� ���Դϴ�.");
		for (int i = 0; i < 3; i++) { Sleep(500); printf("."); }
		FILE *re = fopen("Info_data.txt", "w");							// ������������ ������.
		fclose(re);
		return;
	}

	while(!feof(data)){  //�����Ͱ� ������ ���� �����ҋ� ����.  *feof ��ȯ�� : ���ϳ�O [1~] ���ϳ�X [0]
		
		fscanf(data, "%s%s%s%d\n", Player[i].Name, Player[i].Id, Player[i].Password, &Player[i].Score);
		i++;
	}

	Player_count = i;

	fclose(data);
}
void Info_data_save() {
	FILE *data = fopen("Info_data.txt", "w+");

	for (int j = 0; j < Player_count; j++) {
		fprintf(data, "%s %s %s %d\n", Player[j].Name, Player[j].Id, Player[j].Password, Player[j].Score);
	}

	fclose(data);
}

// �α����� ��� �� �ϴ� �Լ�.
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
			printf("\n\n\t�α��� �Ϸ�");
			while (_getch() != '\r') {}   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
		}
		else {
			system("cls");
			printf("\n\n\t���̵�� �н����尡 ���� �ʽ��ϴ�!");
			while (_getch() != '\r') {}   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
		}
	}
	else if (T == False) {
		system("cls");
		printf("\n\n\t�α��� ���� !");
		while (_getch() != '\r') {  }   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
	}
	else if (T == 3){
		system("cls");
		printf("\n\n\t���̵� �н������ 15�� �����Դϴ�.");
		while (_getch() != '\r') {}   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
	}
}

// �α����� ��� �κ�
int input_Login(int dir) {			// (dir )	1 = ���̵� 2 = �н�����
	int Key = 0;
	int i = 0, j = 0;

	if (dir == 1) // ���̵�
	{
		gotoxy(30, 7);
		while ((Id_s[i] = _getch()) != '\t')
		{
			if (Id_s[i] == '\b') {    // �� ������ �� ��
				if (i == 0) { continue; }
				printf("\b \b");    // �������� �̵��Ͽ� ���� ����� �ٽ� Ŀ���� �� �ڸ���
				i--;            // �迭�� ÷�ڸ� �տ��� ���� ���� ��ġ�� �̵�
				Id_s[i] = '\0';    // �̵��� ��ġ�� ���ڸ� ����
			}
			else if (Id_s[i] == ESC) { return 4; }	// ������

			else if (Id_s[i] == '\r') { break; }	// ���̵� �Է��� ���͸� ������ ��й�ȣ�� �Է��Ҽ� ����.

			else if (i > 15) { return 3; }		// �Է°��� 15�ڸ� ������ �����߻�

			else {
				printf("%c", Id_s[i]);
				i++;
			}
		}
		Id_s[i] = '\0';
		return 2;
	}

	else if (dir == 2) // �н�����
	{
		gotoxy(30, 11);
		while ((Ps_s[j] = _getch()) != '\r')
		{
			if (Ps_s[j] == '\b') {    // �� ������ �� ��
				if (j == 0) { continue; }
				printf("\b \b");    // �������� �̵��Ͽ� ���� ����� �ٽ� Ŀ���� �� �ڸ���
				j--;            // �迭�� ÷�ڸ� �տ��� ���� ���� ��ġ�� �̵�
				Ps_s[j] = '\0';    // �̵��� ��ġ�� ���ڸ� ����
			}
			else if (Ps_s[j] == ESC) { return 4; }	//������

			else if (j > 15) { return 3; }		// �Է°��� 15�ڸ� ������ �����߻�

			else {
				_putch('*');
				j++;
			}
		}
		Ps_s[j] = '\0';
		return True;
	}

	else if (dir == 3) { //�Է� �ʰ� ����
		return 3;
	}

	else if (dir == 4) {
		return 4;
	}

	return False;
}

// ȸ������ ����� �ϴ� �Լ�.
void SignUp() {
	
	system("cls");

	input_signUp();

	printf("\n\t\tȸ�� ������ �Ǿ����ϴ�.");

	_getch();
}

// ȸ�������� ��ºκ�
void input_signUp() {
	int i = 0;
	i = Player_count;

	printf("\n\n\n\n\t\tSIGN UP\n\n");
	printf("\t\tID �Է� : ");
	scanf("%s", Player[i].Id);
	printf("\n\n\t\tPASSWORD �Է� : ");
	scanf("%s", Player[i].Password);
	printf("\n\n\t\t�̸� �Է� :");
	scanf("%s", Player[i].Name);
	Player[i].Score = 0;
	i++;

	Player_count = i;
}

// �α��� �Ҷ�, ȸ���� ���̵�� �н����带 �˻��ϴ� �Լ�.
int check_Login() {

	for (int i = 0; i < Player_count; i++) {

		if (!strcmp(Id_s, Player[i].Id) && (!strcmp(Ps_s, Player[i].Password)))
		{
			Player_num = i;   // �÷��̾� �迭�� �ѹ��� ������.
			return True;
		}
	}
	return False;
}

// ȸ�� ���
void list() {
	for (int j = 0; j < Player_count; j++) {
		printf("%s %s %s %d\n", Player[j].Name, Player[j].Id, Player[j].Password, Player[j].Score);
	}
}