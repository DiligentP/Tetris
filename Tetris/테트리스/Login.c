#include "Header.h"

info Palyer[100];		// �ִ� 100����� �����͸� ����������.

char Id_s[20], Ps_s[20];	// �Է¹��� ���̵�� �н����带 ������ �ӽ� ���� , ����Ǿ��ִ� �÷��̾��� �����Ϳ� ����.

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

		if (KeyBoard == 224) {	// ����Ű �� ���
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
		printf("ȸ�������� �غ����Դϴ�. ");
		_getch();
	}
	if (count == 4) {
		system("cls");
		printf("�α��� ����� �غ����Դϴ�.");
		_getch();
	}
	system("cls");
	printf("�α��� ����");
	_getch();
}


int input_Login(int dir) {			// (dir )	1 = ���̵� 2 = �н�����

	int Key = 0;
	int i = 0;

	if (dir == 1) // ���̵�
	{
		while ((Id_s[i] = _getch()) != '\t')
		{
			if (Id_s[i] == '\b') {    // �� ������ �� ��
				if (i == 0) { continue; }
				printf("\b \b");    // �������� �̵��Ͽ� ���� ����� �ٽ� Ŀ���� �� �ڸ���
				i--;            // �迭�� ÷�ڸ� �տ��� ���� ���� ��ġ�� �̵�
				Id_s[i] = '\0';    // �̵��� ��ġ�� ���ڸ� ����
			}

			else {
				printf("%c", Id_s[i]);
				i++;
			}
		}
		Id_s[i] = '\0';
		return True;
	}

	else if (dir == 2) // �н�����
	{
		while ((Ps_s[i] = _getch()) != '\r')
		{
			if (Ps_s[i] == '\b') {    // �� ������ �� ��
				printf("\b \b");    // �������� �̵��Ͽ� ���� ����� �ٽ� Ŀ���� �� �ڸ���
				i--;            // �迭�� ÷�ڸ� �տ��� ���� ���� ��ġ�� �̵�
				Ps_s[i] = '\0';    // �̵��� ��ġ�� ���ڸ� ����
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