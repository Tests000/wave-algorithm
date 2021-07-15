#include"QUEUE.h"
#include <stack>
#include<sstream>

void Matrix(int**& Matr, int size);
void Print(int** arr, int size);
void Task(int** Matr, int size, int start, int finish);

int main()
{
	int size;
	cin >> size;
	int** Matr;
	Matrix(Matr, size);
	Task(Matr, size, 1, 4);
	return 0;
}

void Matrix(int**& Matr, int size)
{
	Matr = new int* [size];

	for (int i = 0; i < size; i++)
		Matr[i] = new int[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			cin >> Matr[i][j];
}

void Print(int** arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << i + 1 << " - " << arr[i][i] << endl;
}

void Task(int** Matr, int size, int start, int finish)
{
	QUEUE queue;
	int city;
	stack <int>st;
	for (int i = 0; i < size; i++)
		Matr[i][i] = -1; //В данном случае не будем создавать доп. массив, а используем главную диагональ для хранения кратчайшего расстояния
	Matr[start-1][start-1] = 0; //установим точку старта
	queue.Enqueue(start-1);
	while(!queue.Empty()) //волновой обход матрицы
	{
		city = queue.Dequeue();
		for (int j = 0; j < size; j++)
			if (Matr[city][j] > 0 && (Matr[city][city] + Matr[city][j] < Matr[j][j] || Matr[j][j] < 0))
			{
				queue.Enqueue(j);
				Matr[j][j] = Matr[city][city] + Matr[city][j];
			}
	}
	if (Matr[finish - 1][finish - 1] == -1)
		cout<< "Way not found";
	else //если существует, то восстановим
	{
		st.push(finish);
		city = finish - 1;
		while (city != start - 1)
			for (int j = 0; j < size&& city != start - 1; j++)
				if (Matr[city][city] - Matr[city][j]==Matr[j][j])
				{
					city = j;
					j = -1;
					st.push(city + 1);
				}
		while (!st.empty())
		{
			cout << st.top()<<' ';
			st.pop();
		}
		cout<< "\nlength of way = "<<Matr[finish-1][finish-1];
	}
}