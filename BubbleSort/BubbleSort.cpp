// BubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BubbleSort.h"
#include <iostream>
#include <utility>

int main()
{
	int array[6] = { 8 , 1, 88, 9, 5, 50};

	int A = sizeof(array) / sizeof(array[0]);

	bubbleSort(array, A);

	printf("Sorted Array\n");

	printArray( array, A);

	return 0;

}
