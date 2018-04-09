#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum Menu {SEARCH =1,Inbentory,Exit};
enum Location {Bad = 1,Desk,BookStock,CloseCase,Door};
int UInbentory();
int ItemGet(int ID,int ON);



void main()
{

	int select = 0;
	int play = 1;
	int ItemGet = 0;
	while (play != 3)
	{
		printf("방에 갇혔다. 다음에 할 행동을 선택하세요\n");
		printf("%d)찾기 %d)가방 %d)종료", SEARCH, Inbentory, Exit);
		scanf("%d", &select);
		switch (select)
		{
		case SEARCH:
			//printf("%d)침대 %d)책상 %d)책장 %d)옷장 %d)문\n", Bad, Desk, BookStock, CloseCase, Door);
			//printf("Input : ");
			//scanf("%d", &select);
			ItemGet = UInbentory();
			break;
		case Inbentory:
			UInbentory();
			break;
		case Exit:
			play = 3;
			break;
		}
		//테스트용 구문
		printf("%d", ItemGet);
		scanf("%d", &select);

	}
	
}
int UInbentory()
{
	int ItemID;
	ItemID = 2;
	return ItemID;


}
int ItemGet(int ID,int ON)
{
	
	return 0;
}
