#pragma once
#include<iostream>
using namespace std;

struct NODE
{
	int info;
	NODE* next;
};
typedef NODE* TList;

class QUEUE
{
public:
	TList head, tail;
	QUEUE();
	bool Empty();
	void Enqueue(int elem);
	int Dequeue();
	int Head();
	void View();
	void Print();
};