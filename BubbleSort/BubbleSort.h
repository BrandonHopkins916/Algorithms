#pragma once

#include <algorithm>
#include <iostream>


void bubbleSort( int arr[], int size)
{
	int i, j;

	for( i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void printArray( int arr[], int size )
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d\n", arr[i]);
}

void Insert( int arr[], int size )
{

}