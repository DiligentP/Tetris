#include "Header.h"

int main() 
{
	int Count;

	Cursor(0);					// Ŀ�� ����� : 0 ����� 1 ���̱�

	while (1) 
	{
		Count = Main_Menu();
		
		enum menu { GAME = 1, RANK, SYSTEM, EXIT };

		switch (Count)
		{
		case GAME:
			Game_main();							// ���� ���� �Լ�
			break;

		case RANK:
			Rank_main();							// ��ũ ���� �Լ�
			break;
			
		case SYSTEM:
			System_main();							// �ý��� ���� �Լ�
			break;

		case EXIT:
			system("cls");							// ���� ����
			return 0;

		default:
			Login_main(Count);						// ��ȯ�� ī��Ʈ �Լ��� 5�̻��̸� �α��� �Լ��� �����մϴ�.
			break;
		}
	}
}