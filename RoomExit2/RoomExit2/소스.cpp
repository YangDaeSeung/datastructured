#include <stdio.h>
#include <Windows.h>

int main()
{
	enum Place {
		DESK = 1,
		BOOK,
		BED,
		DOOR,
	};

	int Slect;
	int Key;
	bool b_Desk = false;

	while (true)
	{
		printf("��Ż�����~~~\n");
		printf("�������� 3����ƶ�~~\n");
		printf("���� ���� : %d", Key);
		printf("1.å�� 2.å 3.ħ�� 4.��");
		scanf("%d", &select);
		switch (Slect)
		{
		case DESK:
			if (b_Desk == false)
			{
				system("cls");
				printf("å�� ���� �߰��߾�~");
				system("pause");
				Key = Key + 1;
				b_Desk = true;
				break;
			}
			if (b_Desk == true)
			{
				system("cls");
				printf("�� �������ʿ䰡����");
				break;
			}


		default:
			break;
		}
	}
}