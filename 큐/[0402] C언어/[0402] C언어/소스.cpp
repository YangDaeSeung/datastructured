#include <iostream>

/* 큐 클래스로 구현하기*/
class Node {
public:
	int Data;
	Node *pNext;
};

class Queue {
	Node * Head;
	Node * Tail;
public:
	Queue()
	{
		Head = NULL;
		Tail = NULL;
	}

	void Push(int Data) //추가 
	{
		Node * pTemp;
		pTemp = new Node;
		pTemp->Data = Data;
		pTemp->pNext = NULL;
		if (Head != NULL) // 헤드가 널이아니라면
		{
			// 10 -> 20 -> NULL
			Tail->pNext = pTemp;
			Tail = pTemp; // 이걸빼면 10,40만 연걸이된다.
		}
		else // 헤드가 널이라면 
		{
			Tail = pTemp; // Tail 10  Temp 10
			Head = Tail; //  Head 10  Tail 10
		}
	}

	void PrintNode() // 출력
	{
		Node* pTemp = Head;
		while (pTemp != NULL)
		{
			
			printf("%d", pTemp->Data);
			pTemp = pTemp->pNext;
			if (pTemp)
			{
				printf(",");
			}
		}
	}
	void Pop()  // 앞에부분삭제
	{
		Node* pHead = Head;
		Head = Head->pNext;
		delete pHead;
	}
	void Back() // 마지막숫자 체크
	{
		Node* pEnd = Tail;
		if (pEnd != NULL)
		{
			printf("마지막 숫자 : %d ", pEnd->Data);
		}
		else
		{
			printf("-1");
		}
	}
	void front() // 첫번째 숫자 체크
	{
		Node* pFirst = Head;
		if (pFirst != NULL)
		{
			printf("첫번째 숫자 : %d", pFirst->Data);
		}
		else
		{
			printf("-1");
		}
	}
	void Size()
	{
		Node* pNode = Head;
		int Size = 0;
		if (pNode != NULL)
		{
			for (Size = 1; pNode != Tail; Size++) 
			{
				pNode = pNode->pNext;
			}
			printf("크기 : %d", Size);
		}
		else
		{
			printf("-1");
		}
	}
	bool Empty()
	{
		Node*pNode = Head;
		if (pNode != NULL)
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
};

void main()
{
	Queue Q;
	/*Q.Push(1);
	Q.Push(2);
	Q.Push(3);
	Q.Push(4);*/
	//Q.PrintNode();
	//Q.Pop();
	//Q.PrintNode();
	//Q.Pop();
	//Q.PrintNode();
	//Q.Back();
	//Q.front();
	//Q.Size();
	//Q.Empty();

}