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
		printf("방탈출시작~~~\n");
		printf("열쇠조각 3개모아라~~\n");
		printf("열쇠 조각 : %d\n", Key);
		printf("1.책상 2.책 3.침대 4.문\n");
		scanf("%d", &Slect);

		switch (Slect)
		{
		case DESK:
			if (b_Desk == false)
			{
				system("cls");
				printf("책상에 열쇠 발견했어~");
				system("pause");
				Key = Key + 1;
				b_Desk = true;
				break;
			}
			if (b_Desk == true)
			{
				system("cls");
				printf("음 조사할필요가없어");
				system("pause");
				break;
			}
		case BOOK:
			if (n_Book == 0)
			{
				system("cls");
				printf("한번더 찾아봐야겠어!!");
				system("pause");
				n_Book = n_Book + 1;
				break;
				
			}
			if (n_Book == 1)
			{
				system("cls");
				printf("역시!! 찾았어!!");
				system("pause");
				Key = Key + 1;
				n_Book = n_Book + 1;
				break;
			}
			if (n_Book == 2)
			{
				system("cls");
				printf("음 이제 침대가봐도 될꺼같아");
				system("pause");
				n_Bed = n_Bed + 1;
				break;
			}
		case BED:
			if (n_Bed == 0)
			{
				system("cls");
				printf("일단 책부터 찾아볼래!!");
				system("pause");
			}
			if (n_Bed == 1)
			{
				system("cls");
				printf("열쇠 발견");
				system("pause");
				Key = Key + 1;
				break;
			}
		case DOOR:
			if (Key == 3)
			{
				system("cls");
				printf("아싸 탈출!!\n");
				printf("간닸!!");
				system("pause");
				return;
			}
			if (Key == 1 )
			{
				system("cls");
				printf("열쇠 찾아봐");
				system("pause");
				break;
			}
			system("cls");
			printf("열쇠 내놔");
			system("pause");
			break;
		default:
			break;
		}
	}

}