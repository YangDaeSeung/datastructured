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
		printf("�濡 ������. ������ �� �ൿ�� �����ϼ���\n");
		printf("%d)ã�� %d)���� %d)����", SEARCH, Inbentory, Exit);
		scanf("%d", &select);
		switch (select)
		{
		case SEARCH:
			//printf("%d)ħ�� %d)å�� %d)å�� %d)���� %d)��\n", Bad, Desk, BookStock, CloseCase, Door);
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
		//�׽�Ʈ�� ����
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
