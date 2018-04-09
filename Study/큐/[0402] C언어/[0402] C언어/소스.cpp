#include <iostream>

/* ť Ŭ������ �����ϱ�*/
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

	void Push(int Data) //�߰� 
	{
		Node * pTemp;
		pTemp = new Node;
		pTemp->Data = Data;
		pTemp->pNext = NULL;
		if (Head != NULL) // ��尡 ���̾ƴ϶��
		{
			// 10 -> 20 -> NULL
			Tail->pNext = pTemp;
			Tail = pTemp; // �̰ɻ��� 10,40�� �����̵ȴ�.
		}
		else // ��尡 ���̶�� 
		{
			Tail = pTemp; // Tail 10  Temp 10
			Head = Tail; //  Head 10  Tail 10
		}
	}

	void PrintNode() // ���
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
	void Pop()  // �տ��κл���
	{
		Node* pHead = Head;
		Head = Head->pNext;
		delete pHead;
	}
	void Back() // ���������� üũ
	{
		Node* pEnd = Tail;
		if (pEnd != NULL)
		{
			printf("������ ���� : %d ", pEnd->Data);
		}
		else
		{
			printf("-1");
		}
	}
	void front() // ù��° ���� üũ
	{
		Node* pFirst = Head;
		if (pFirst != NULL)
		{
			printf("ù��° ���� : %d", pFirst->Data);
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
			printf("ũ�� : %d", Size);
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