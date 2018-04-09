#include <iostream>

class Node {
public:
	int Data;
	Node* pNext;
};

class Stack {
	Node* Top;
	Node* Bottom;
	int count = 0;
public:
	Stack()
	{
		Top = NULL; // 탑이 받아야한다
		Bottom = NULL; // 
	}
	void Push(int Data)
	{
		Node* pTemp;
		pTemp = new Node;
		pTemp->Data = Data;
		pTemp->pNext = NULL;

		if (Bottom)
		{
			Top->pNext = pTemp;
			Top = pTemp;
		}
		else
		{
			Top = pTemp; // 탑이 값을 받아야한다.
			Bottom = Top; // 바텀이 탑의 값을받는다.

		}
		count = count + 1;
	}

	void Print()
	{
		Node* pNode = Bottom;

		while (pNode != NULL)
		{
			printf("%d", pNode->Data);
			pNode =  pNode->pNext;
			if (pNode)
			{
				printf(",");
			}
		}
	}
	void Top_p()
	{
		if (Top)
		{
			printf("Top : %d", Top->Data);
		}
		else
		{
			printf("-1");
		}
	}
	bool Empty()
	{
		if (Bottom)
		{
			printf("1");
				return true;
		}
		else
		{
			printf("0");
			return false;
		}
	}
	void Size()
	{
		printf("Count : %d", count);
	}
	void Pop() // 뒷부분삭제
	{
		Node* pNode = Bottom;
		Node* pPre = NULL;
		while (pNode != Top)
		{
			pPre = pNode; // pPre = 40
			pNode = pNode->pNext; // pNod = 40  ==  Top = 40

		}

		Top = pPre;
		Top->pNext = NULL;
		delete pNode;
	}
};

void main()
{
	Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	//s.Print();
	//s.Top_p();
	s.Pop();
	s.Pop();
	s.Print();
}