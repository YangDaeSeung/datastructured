#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	printf("\n\n\n          =============================================================\n\n\n\n\n");
	printf("\n                                     방탈출                   \n\n");
	printf("\n                                            Made : YDS         \n\n\n\n");
	printf("\n\n          =============================================================\n\n\n\n\n");
	printf("\n(1) 게임시작 (2) 나가기\n");
	int user;
	int a = 1; // 1층
	int b = 1;
	int c = 1;
	int key = 1;
	int password1 = 216;
	int anwser;
	scanf("%d", &a);

	switch (a)
	{
	case 1:
	{
		system("cls");
		printf("게임시작");
		while (a)
		{
			printf("\n\n\n============================================================\n\n\n");
			printf("\n\n\n                              Room                          \n\n\n");
			printf("\n\n\n============================================================\n\n\n");
			printf("(1) 침대 (2) 옷장 (3) 책상 (4) 방문"); // Room
			scanf("%d", &b); system("cls");

			switch (b)
			{
			case 1:
			{
				printf("\n\n\n============================================================\n\n\n");
				printf("\n\n\n                            침대에는 아무것도없었다.                       \n\n\n");
				printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");
			} break;
			case 2:
			{	printf("\n\n\n============================================================\n\n\n");
			printf("\n\n\n                옷장 조사중...                                             \n\n\n"); printf("\n\n\n============================================================\n\n\n");
			system("pause"); system("cls");  printf("\n\n\n============================================================\n\n\n");
			printf("\n\n\n                            옷장에서 열쇠가 발견하였다                       \n\n\n");      printf("\n\n\n============================================================\n\n\n");  system("pause"); system("cls");
			a = 0;;
			} break;
			case 3:
			{
				printf("\n\n\n ============================================================\n\n\n\n\n");
				printf("\n\n\n                          책상서랍에 자물쇠가있다.                          \n\n\n");
				printf("\n\n\n ============================================================\n\n\n\n\n");
				system("pause"); system("cls");    printf("\n\n\n============================================================\n\n\n");
				printf("\n\n\n                           하지만 열쇠가없다..                        \n\n\n");      printf("\n\n\n============================================================\n\n\n");
				system("pause"); system("cls");
			} break;
			case 4:
			{
				printf("\n\n\n============================================================\n\n\n");
				printf("\n\n\n                              비밀번호를 입력하세요.                          \n\n\n");     printf("\n\n\n============================================================\n\n\n");
				printf("(1)비밀번호를 입력한다. (2)몸으로 부순다.(3)더 둘러본다.\n");
				scanf("%d", &c); system("pause"); system("cls");
				switch (c)
				{
				case 1:
				{
					printf("password : ___\b\b\b");
					scanf("%d", &anwser);
					system("cls");
					for (int j = 0; j <1; j++)
					{
						if (password1 == anwser)
						{
							printf("clear");
							return 0;
						}
						else
						{
							printf("No password");
							system("pause"); system("cls");
						}
					}
				} break;
				case 2:
				{
					printf("\n\n\n============================================================\n\n\n");
					printf("\n\n\n                              쾅쾅쾅!!!                        \n\n\n");       printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");
					printf("\n\n\n============================================================\n\n\n");
					printf("\n\n\n                              꺼내주세요!!!!!                       \n\n\n");      printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");         printf("\n\n\n============================================================\n\n\n");
					printf("\n\n\n                        살인자에게 적발되여 죽임을 당했습니다.                       \n\n\n");    printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");
					return 0;
				}
				case 3:
				{
				}break;
				}
			}
			}
		}
	}
	}
	// end
	while (key)
	{
		printf("\n\n\n============================================================\n\n\n");
		printf("\n소지품 \n\n    key                          Room                          \n\n\n");        printf("\n\n\n============================================================\n\n\n");
		printf("(1) 침대 (2) 옷장 (3) 책상 (4) 방문"); // Room
		scanf("%d", &b); system("cls");
		switch (b)
		{
		case 1:
		{
			printf("\n\n\n============================================================\n\n\n");
			printf("\n\n\n                            침대에는 아무것도없었다.                       \n\n\n");
			printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");
		} break;
		case 2:
		{	printf("\n\n\n============================================================\n\n\n");
		printf("\n\n\n        옷장에는 더이상 조사안하는게 좋을꺼같다.                                                   \n\n\n");
		printf("\n\n\n ============================================================\n\n\n\n\n");
		system("pause"); system("cls");
		} break;
		case 3:
		{
			printf("\n\n\n ============================================================\n\n\n\n\n");
			printf("\n\n\n                          책상서랍에 자물쇠가있다.                          \n\n\n");
			printf("\n\n\n ============================================================\n\n\n\n\n");
			system("pause"); system("cls");    printf("\n\n\n============================================================\n\n\n");
			printf("\n\n\n                           열쇠를 사용했다                     \n\n\n");      printf("\n\n\n============================================================\n\n\n");
			system("pause"); system("cls"); printf("\n\n\n============================================================\n\n\n");
			printf("\n\n\n        쪽지내용 :  2명이죽고 1명이살고 6명이 도망쳤다                                  \n\n\n");     printf("\n\n\n============================================================\n\n\n");
			system("pause"); system("cls");
		} break;
		case 4:
		{
			printf("\n\n\n============================================================\n\n\n");
			printf("\n\n\n                              비밀번호를 입력하세요.                          \n\n\n");     printf("\n\n\n============================================================\n\n\n");
			printf("(1)비밀번호를 입력한다. (2)몸으로 부순다.(3)더 둘러본다.\n");
			scanf("%d", &c); system("pause"); system("cls");
			switch (c)
			{
			case 1:
			{
				printf("password : ___\b\b\b");
				scanf("%d", &anwser);
				system("cls");
				for (int j = 0; j <1; j++)
				{
					if (password1 == anwser)
					{
						printf("clear");
						return 0;
					}
					else
					{
						printf("No password");
						system("pause"); system("cls");
					}
				}
			} break;
			case 2:
			{
				printf("\n\n\n============================================================\n\n\n");
				printf("\n\n\n                              쾅쾅쾅!!!                        \n\n\n");       printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");
				printf("\n\n\n============================================================\n\n\n");
				printf("\n\n\n                              꺼내주세요!!!!!                       \n\n\n");      printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");         printf("\n\n\n============================================================\n\n\n");
				printf("\n\n\n                        살인자에게 적발되여 죽임을 당했습니다.                       \n\n\n");    printf("\n\n\n============================================================\n\n\n"); system("pause"); system("cls");
				return 0;
			}
			case 3:
			{
			}break;
			}
		}
		}
	}
}