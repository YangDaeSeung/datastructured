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
		printf("방탈출시작~~~\n");
		printf("열쇠조각 3개모아라~~\n");
		printf("열쇠 조각 : %d", Key);
		printf("1.책상 2.책 3.침대 4.문");
		scanf("%d", &select);
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
				break;
			}


		default:
			break;
		}
	}
}