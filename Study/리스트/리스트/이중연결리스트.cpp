#include <iostream>

class Node {
public:
	int Data;
	Node* pNext;
	Node* pPre;
};

class List {
	Node* Head;
	Node* Tail;
	int l_Size = 0;
public:
	List()
	{
		Head = NULL;
		Tail = NULL;
	}
	void Add(int Data)
	{
		Node* pTemp;
		pTemp = new Node;
		pTemp->Data = Data;
		pTemp->pNext = NULL;
		pTemp->pPre = NULL;
		if (Head)
		{
			pTemp->pPre = Tail;
			Tail->pNext = pTemp;
			Tail = pTemp;
		}
		else
		{
			Tail = pTemp;
			Head = Tail;
		}
		l_Size = l_Size + 1;
	}


	void print()
	{
		Node *pNode = Head;
		while (pNode != NULL)
		{
			printf("%d", pNode->Data);
			pNode = pNode->pNext;

		}
	}
	void Size()
	{
		printf("사이즈 : %d",l_Size);
	}
	bool Empty()
	{
		Node *pNode = Head;
		if (pNode != NULL)
		{
			printf("비어있지않음");
			return true;
		}
		else
		{
			printf("비었음");
			return false;
		}
	}
	void Begin()
	{
		Node* pNode = Head;
		if (pNode != NULL)
		{
			printf("%d", pNode->Data);
		}
		else
		{
			printf("-1");
		}
	}
	void End()
	{
		Node* pNode = Tail;
		if (pNode != NULL)
		{
			printf("%d", pNode->Data);
		}
		else
		{
			printf("-1");
		}
	}
	void insert(int Data, int insert)
	{
		Node* pNode = Head;
		Node* pTemp = NULL;
		pTemp = new Node;
		pTemp->Data = insert;
		pTemp->pNext = NULL;
		pTemp->pPre = NULL;
		while (pNode != NULL)
		{
			
			if (pNode->Data == Data)  //  3->5->4
			{
				pTemp->pNext = pNode->pNext; // 5->4
				pTemp->pPre = pNode; //  3<-5
				pNode->pPre = pTemp; // 5 <- 4
				pNode->pNext = pTemp; // 3->5
				break;
			}
			pNode = pNode->pNext;
		}
	}

};

void main()
{
	List L;
	L.Add(1);
	L.Add(2);
	L.Add(3);
	L.Add(4);
	L.insert(3, 5);
	L.print();


}