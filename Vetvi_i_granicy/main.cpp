// Vetvi_i_granici.cpp : 
//
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;
void Output(int **A, int *C);
int Rise(int **A, int *C);
int **FormMatrix();
int *FormVector();
int Tree(int y, int *g);
int N = 3;
int maxim = 10;
int main()
{
	Output(FormMatrix(), FormVector());
	Tree(Rise(FormMatrix(), FormVector()), FormVector());
	return 0;
}

int **FormMatrix()//???????? ??????? ??????
{
	ifstream fin("C:\\Users\\Evil Spirit\\Desktop\\???????.txt");
	int **A = new int*[N];
	for (size_t i = 0; i < N; i++)
	{
		A[i] = new int[N];
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			fin >> A[i][j];
		}
	}
	return A;
}

int *FormVector()
{
	ifstream fin("C:\\Users\\Evil Spirit\\Desktop\\??????.txt");
	int *C = new int[N];
	for (size_t i = 0; i < N; i++)
	{
		fin >> C[i];
	}
	return C;
}

int Rise(int **A, int *C)
{
	int y = 0;
	int *flag = new int[N];
	int *minim = new int[N];
	int *arg = new int[N];
	int *max = new int[N];
	int *diff = new int[N];
	int error = 0, exit = 0;
	while (exit != 1)
	{
		for (size_t j = 0; j < N; j++)
		{
			minim[j] = A[0][j];
			arg[j] = 0;
			for (size_t i = 0; i < N; i++)
			{
				if (A[i][j] < minim[j] && A[i][j] != minim[j])
				{
					minim[j] = A[i][j];
					arg[j] = i;
				}
			}
		}
		for (size_t j = 0; j < N; j++)
		{
			max[j] = A[0][j];
			for (size_t i = 0; i < N; i++)
			{
				if (A[i][j] > max[j] && A[i][j] != max[j])
				{
					max[j] = A[i][j];
				}
			}
		}
		for (size_t j = 0; j < N; j++)
		{
			flag[j] = A[0][j];
			for (size_t i = 0; i < N; i++)
			{
				if ((A[i][j] > minim[j]) && (A[i][j] != minim[j]))
				{
					flag[j] = A[i][j];
					if ((A[i][j] < flag[j]) && (A[i][j] != flag[j]))
					{	
					flag[j] = A[i][j];
					}
				}
			}
		}
		cout << "Minim \tand \tmax " << endl;
		for (size_t i = 0; i < N; i++)
		{
			cout << minim[i] << " ";
		}
		cout << "\t\t";
		for (size_t i = 0; i < N; i++)
		{
			cout << max[i] << " ";
		}
		cout << "\nFlag \tand \t place\n";
		for (size_t i = 0; i < N; i++)
		{
			cout << flag[i] << " ";
		}
		cout << "\t\t ";
		for (size_t i = 0; i < N; i++)
		{
			cout << arg[i] + 1<< " ";
		}
		cout << "\nDiffenece ";
		for (size_t i = 0; i < N; i++)
		{
			diff[i] = flag[i] - minim[i];
			cout << diff[i] << " ";
		}
		for (size_t i = 0; i < N; i++)
		{
			if ((C[arg[i]] - diff[i]) > 0)
			{
				C[arg[i]] -= diff[i];
				A[arg[i]][i] += diff[i];
			}
			else error++;
			if(diff[i] == 0)error++;
		}
		if (error > 0)
		{
			exit = 1;
		}
	Output(A, C);
	}
	for (size_t j = 0; j < N; j++)
	{
		minim[j] = A[0][j];
		arg[j] = 0;
		for (size_t i = 0; i < N; i++)
		{
			if (A[i][j] < minim[j] && A[i][j] != minim[j])
			{
				minim[j] = A[i][j];
				arg[j] = i;
			}
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		y += minim[i];
	}
	cout << "Out " << y;
	return y;
}

int Tree(int c, int *g)
{
	int opt, flag = 0, i = N - 1, sum = 0, rec = 0;
	vector<int> Y(N);
	for (size_t j = 0; j < N - 1; j++)
	{
		Y.push_back(1);
	}
	Y.push_back(1);
	for (size_t i = 0; i < Y.size(); i++)
		{
			sum += (g[i] * Y[i]);
		}
		opt = c + sum;
		flag = Y.size() - 1;
		while (true)
	{
		Y[i] = 0;
		for (size_t i = 0; i < Y.size(); i++)
		{
			sum += (g[i] * Y[i]);
		}
		
		if(c + sum > opt && c + sum != opt)
		{
			if(Y[i] != 0)
			{
				Y[i] = 0;
			}
			else 
			{
				for(size_t j = i; j > flag; j--)
				{
					Y.erase(Y.begin() + j);
				}
				i = flag;
				Y[i] = 0;
				for(int j = 1; j < N; j++)
				{
					Y.push_back(1);
				}
			}
		}
		else
		{
			opt = c + sum;
			i = flag;
		}
	}
}
void Output(int **A, int *C)
{
	cout << "\nNew iteration" << endl;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << "\t" << C[i] << endl;
	}
}

