#include "stdafx.h"
#include <algorithm>
#include <locale>
#include <iostream>
#include<fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int N = 10;
	int buf1 = 0, buf2 = 0, buff = 0;
	int buf, i = 0, l = 1, j = 1;
	int **mas = new int*[N] {0};
	for (int i = 0; i < N; i++)
	{
		mas[i] = new int[N] {0};
	}
	int **answer = new int*[N] {0};
	for (int i = 0; i < N; i++)
	{
		answer[i] = new int[3]{ 0 };
	}
	ifstream fin("A:\\Laborators\\ASY\\Neighbor.txt");
	for (int i = 0; i < N; i++)
	{
		fin >> buf;
		mas[0][i] = buf;
	}
	fin.close();
	for (int i = 1; i < N; i++)
	{
		j = i;
		l = 1;
		while (l != (N - i + 1))
		{
			mas[i][j] = (mas[i - 1][j - 1] - l);

			l++;
			j++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		for (int j = 0; j < N; j++)
		{
			cout << mas[i][j] << "\t";
		}
	}
	ofstream fout("A:\\Laborators\\ASY\\Conclusion.txt");
	for (int i = 0; i < N; i++)
	{
		fout << "\n";
		for (int j = 0; j < N; j++)
		{
			if (mas[i][j] != 0)
			{
				fout << mas[i][j] << "\t";
			}
			else fout << "\t";
		}
	}
	fout.close();
	ofstream fout1("A:\\Laborators\\ASY\\Answer.txt");
	for (int j = 0; j < N; j++)
	{
		while (mas[i][j] != 0 && i <=j-1)
		{
			l = 1;
			if (j < 2)
			{
				if (j == 0)
				{
					answer[j][0] = j + 1;
					answer[j][1] = mas[0][j];
					answer[j][2] = 0;
				}
				if (j == 1)
				{
					answer[j][0] = j + 1;
					answer[j][1] = min(mas[0][j], mas[1][j] + mas[0][j - 1]);
					if (answer[j][1] == mas[0][j])
						answer[j][2] = 0;
					if (answer[j][1] == mas[1][j] + mas[0][j - 1])
						answer[j][2] = 1;
				}
			}
			else
			{
				while (l <i)
				{
					answer[j][0] = j + 1;
					buf1 = mas[0][l] + mas[l+1][j];
					buff = mas[0][l - 1] + mas[l][j];
					buf2 = min(buf1, buf2);
					answer[j][1] = min(buff, mas[0][j]);
					if (answer[j][1] == mas[0][j])
						answer[j][2] = 0;
					if (answer[j][1] == buff)
						answer[j][2] = l + 1;
					l++;
				}
			}
			i++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		for (int j = 0; j < 3; j++)
		{
			cout << answer[i][j] << "\t";
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fout1 << answer[i][j] << "\t";
		}
		fout1 << "\n";
	}
	for (int i = 0; i < N; i++)
	{
			fout1 <<"\nx*"<<i+1<<" = " <<answer[i][2];
	}

	fout1.close();
	return 0;
}