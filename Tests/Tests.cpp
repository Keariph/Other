// Tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("A:\\Laborators\\ASY\\hnyaVsykaya.txt");
	int buff;
	while (fin.peek() != EOF)
	{
	    fin >> buff;
	    cout << buff << endl;
	}
    return 0;
}

