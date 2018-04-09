#include <stdio.h>

void main()
{
	int Arr[10] = { 9,7,1,5,8,2,6,3,4,0 };

	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10 - 1; i++) 
		{
			if (Arr[i] > Arr[i + 1]) // 9>7
			{
				int Temp;
				Temp = Arr[i];  //Temp 9 Arr[0] = 9
				Arr[i] = Arr[i + 1]; // Arr[1] = 7 / Arr[i+1] = 7
				Arr[i + 1] = Temp; // Arr[1] = 9 
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", Arr[i]);
	}
}