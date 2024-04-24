// HeapSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include "SortHeap.h"

using namespace std;

int main()
{
	int inputValue;
	int* scores;
	printf("How many input value do you want to have?\n");
	cin >> inputValue;

	scores = (int*)malloc(inputValue * sizeof(int));

	if (scores == NULL)
	{
		cout << "Memory is not allocated, exiting applications\n";
		exit(0);
	}

	for (int i = 0; i < inputValue; i++)
	{
		scanf_s("%d", &scores[i]);
	}

	cout << "\n\n";

	cout << "Before building the heap: \n";

	for (int j = 0; j < inputValue; j++)
	{
		cout << scores[j] << ",";
	}
	cout << "\n\n";

	printf("After building a heap: \n");

	createHeap(scores, inputValue);

	for (int j = 0; j < inputValue; j++)
	{
		cout << scores[j] << ",";
	}
	cout << "\n\n";

	printf("After heap sorting: ");

	heapSort(scores, inputValue);

	for (int j = 0; j < inputValue; j++)
	{
		cout << scores[j] << ",";
	}
	cout << "\n\n";

	delete scores;
}
