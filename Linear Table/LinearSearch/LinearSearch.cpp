// LinearSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "FunctionStore.h"
#include <iostream>

int main()
{
	int array[] = { 90, 70, 50, 80, 60, 85 };

	int length = (sizeof(array) / sizeof(array[0]));

	int* tempArray = new int[length + 1];

	for (int i = 0; i < length; i++)
	{
		tempArray[i] = array[i];
	}

	tempArray[length] = 75;

	memcpy_s(tempArray, sizeof(tempArray), array, sizeof(tempArray));

	for (int j = 0; j < length + 1; j++)
	{
		printf("%d\n", tempArray[j]);
	}

	printf("Releasing tempArray\n");
	delete[] tempArray;
	printf("Release tempArray\n");

}
