#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <locale.h>
using namespace std;

struct Object
{
	int weigh;
	int point;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int p, w, x;
	cout << "Введите количество предметов\n";
	cin >> p;
	cout << "Введите вместимость рюкзака\n";
	cin >> w;
	Object *it = new Object[p];
	int **Value = new int*[p] {0};
	for (int i = 0; i < p; i++)
	{
		Value[i] = new int[w] {0};
	}
	ofstream fout("C:\\Users\\1\\Desktop\\Parasha.txt");
	for (int i = 0; i < p; i++)
	{

		cout << "Введите вес " << i+1 << "-го предмета\n";
		cin >> it[i].weigh;
	}
	for (int i = 0; i < p; i++)
	{
		cout << "Введите ценность " << i+1 << "-го предмета\n";
		cin >> it[i].point;
	}
	fout.close();
	for (int i = 1; i < p; i++)
	{
		for (int j = 1; j < w; j++)
		{
			x = w / it[i].weigh;
			if (it[i].weigh < x)
			{
				Value[i][j] = max(Value[i - 1][j]*x,Value[i - 1][j - it[i].weigh]*x + it[i].point);
			}
			else Value[i][j] = Value[i - 1][j]*x;
		}
	}
	for (int i = 0; i < p; i++)
	{
		cout << "\n";
		for (int j = 0; j < w; j++)
		{
			cout << Value[i][j] << " ";
		}
	}
	for (int i = 0; i < p; i++)
	{
		delete[] Value[i];
	}
	delete[] Value;
	delete[] it;
	return 0;
}