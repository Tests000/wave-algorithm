#include "QUEUE.h"

QUEUE::QUEUE()
{
	head = NULL;
}
bool QUEUE::Empty()
{
	return head == NULL;
}
void QUEUE::Enqueue(int elem)
{
	TList p = new NODE;
	p->info = elem;
	p->next = NULL;
	if (Empty()) head = p;
	else tail->next = p;
	tail = p;
}
int QUEUE::Dequeue()
{
	TList p = head;
	head = head->next;
	int elem = p->info;
	p->next = NULL;
	delete p;
	return elem;
}
int QUEUE::Head()
{
	return head->info;
}
void QUEUE::View()
{
	TList p = head;
	while (p != NULL)
	{
		cout << p->info<<' ';
		p = p->next;
	}
	cout << endl;
}
void QUEUE::Print()
{
	while (!Empty())
		cout << Dequeue();
	cout << endl;
}

