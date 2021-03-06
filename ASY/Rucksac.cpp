#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <locale>
using namespace std;

struct Object
{
	int weigh;
	int point;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	int p, w, x, x1, x3;
	cout << "Введите количество предметов\n";
	cin >> p;
	cout << "Введите вместимость рюкзака\n";
	cin >> w;
	int buf;
	int buf1 = 0, buf2 = 0, buf3 = 0, buff = 0;
	Object *it = new Object[p];
	int **Value = new int*[p] {0};
	for (int i = 0; i < p; i++)
	{
		Value[i] = new int[w] {0};
	}
	ifstream weight("A:\\Laborators\\ASY\\Weight.txt");
	for (int i = 0; i < p; i++)
	{
		weight >> buf;
		//cout << "Введите вес " << i + 1 << "-го предмета\n";
		it[i].weigh = buf;
	}
	weight.close();
	ifstream point("A:\\Laborators\\ASY\\Point.txt");
	for (int i = 0; i < p; i++)
	{
		point >> buf;
		//cout << "Введите ценность " << i + 1 << "-го предмета\n";
		it[i].point = buf;
	}
	point.close();
	ofstream fout("A:\\Laborators\\ASY\\Rucksac.txt");
	for (int i = 1; i < p; i++)
	{
		for (int j = 1; j < w; j++)
		{
			x = j / it[i].weigh;
			x1 = (j - 1 )/ it[i].weigh;
			x3 = j - (x*it[i].weigh) / it[i - 1].weigh;
			buf1 = (it[i-1].weigh *x) + it[i-1].point;
			buf2 = (it[i-1].weigh *x1) + it[i-1].point;
			buf3 = (it[i-1].weigh*(x - 1) +it[i-1].point) + (it[i-1].weigh*x3 +it[i-1].point);
			buff = max(buf1, buf2);
			Value[i][j] = max(buff, Value[i][j]);
		}
	}
	for (int i = 0; i < p; i++)
	{
		fout << "\n";
		for (int j = 0; j < w; j++)
		{
			fout << Value[i][j] << " ";
		}
	}
	fout.close();
	for (int i = 0; i < p; i++)
	{
		delete[] Value[i];
	}
	delete[] Value;
	delete[] it;
	return 0;
}
