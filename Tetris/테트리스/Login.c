#include "Header.h"

info Palyer[100];		// �ִ� 100����� �����͸� ����������.

char Id_s[20], Ps_s[20];	// �Է¹��� ���̵�� �н����带 ������ �ӽ� ���� , ����Ǿ��ִ� �÷��̾��� �����Ϳ� ����.

char Id[20] = "1234", Ps[20] = "1234";

void Login_main(int Count) {
	while (1) 
	{
		enum login_menu { INFO = 5, LOGIN, SIGNIN, EXIT };

		switch (Count) 
		{
		case INFO:
			system("cls");
			printf("�� ����");
			break;
		case LOGIN:
			Login();
			break;
		case SIGNIN:
			printf("ȸ������");
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
			printf("�α��� �Ϸ�");
			while (_getch() != '\r') {}   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
		}
		else {
			system("cls");
			printf("���̵�� �н����尡 ���� �ʽ��ϴ�!");
			while (_getch() != '\r') {}   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
		}
	}
	else if (T == False) {
		system("cls");
		printf("�α��� ���� !");
		while (_getch() != '\r') {  }   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
	}
	else if (T == 3){
		system("cls");
		printf("���̵� �н������ 15�� �����Դϴ�.");
		while (_getch() != '\r') {}   // �ٷ� �Ѿ�� ��츦 �����ϱ�������
	}
}


int input_Login(int dir) {			// (dir )	1 = ���̵� 2 = �н�����
	int Key = 0;
	int i = 0 , j = 0;

	if (dir == 1) // ���̵�
	{
		gotoxy(30,7);
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
		gotoxy(30,11);
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