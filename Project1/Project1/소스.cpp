#include <stdio.h>
#include <Windows.h>
void main()
{
	enum Place {
		DESK = 1,
		BOOK,
		BED,
		DOOR,
	};

	int Slect;
	int Key = 0;
	bool b_Desk = false;
	int n_Book = 0;
	int n_Bed = 0;

	while (1)
	{
		system("cls");
		printf("��Ż�����~~~\n");
		printf("�������� 3����ƶ�~~\n");
		printf("���� ���� : %d\n", Key);
		printf("1.å�� 2.å 3.ħ�� 4.��\n");
		scanf("%d", &Slect);

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
				system("pause");
				break;
			}
		case BOOK:
			if (n_Book == 0)
			{
				system("cls");
				printf("�ѹ��� ã�ƺ��߰ھ�!!");
				system("pause");
				n_Book = n_Book + 1;
				break;
				
			}
			if (n_Book == 1)
			{
				system("cls");
				printf("����!! ã�Ҿ�!!");
				system("pause");
				Key = Key + 1;
				n_Book = n_Book + 1;
				break;
			}
			if (n_Book == 2)
			{
				system("cls");
				printf("�� ���� ħ�밡���� �ɲ�����");
				system("pause");
				n_Bed = n_Bed + 1;
				break;
			}
		case BED:
			if (n_Bed == 0)
			{
				system("cls");
				printf("�ϴ� å���� ã�ƺ���!!");
				system("pause");
			}
			if (n_Bed == 1)
			{
				system("cls");
				printf("���� �߰�");
				system("pause");
				Key = Key + 1;
				break;
			}
		case DOOR:
			if (Key == 3)
			{
				system("cls");
				printf("�ƽ� Ż��!!\n");
				printf("����!!");
				system("pause");
				return;
			}
			if (Key == 1 )
			{
				system("cls");
				printf("���� ã�ƺ�");
				system("pause");
				break;
			}
			system("cls");
			printf("���� ����");
			system("pause");
			break;
		default:
			break;
		}
	}

}