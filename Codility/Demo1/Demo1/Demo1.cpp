// Demo1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int solution(vector<int>& A)
{
	sort(A.begin(), A.end());

	int size = A.size();
	int missingIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != A[i] - 1)
		{
			missingIndex = i + 1;
		}
	}
	cout << missingIndex;
	return missingIndex;
}

int main()
{
	int inputNumber;
	int numbers;
	vector<int> A;

	cout << "How many elements will you need \n";

	cin >> inputNumber;

	for (int i = 0; i < inputNumber; i++)
	{
		cin >> numbers;
		A.push_back(numbers);
	}

	solution(A);
	
}

