#pragma once

#include <iostream>
#include <string>

using namespace std;

// Adjust the heap
void adjustHeap( int arr[], int currentIndex, int maxLength)
{
	int noLeafValue = arr[currentIndex];

	int j = 2 * currentIndex + 1;
	for (; j <= maxLength; j = currentIndex * 2 + 1)
	{
		if (j < maxLength && arr[j] < arr[j + 1])
		{
			j++;
		}

		if (noLeafValue >= arr[j])
		{
			break;
		}

		arr[currentIndex] = arr[j];
		currentIndex = j;
	}
	
	arr[currentIndex] = noLeafValue;
}

// Create the heap
void createHeap( int arr[], int length )
{
	int i = ((length - 1) / 2); 
	for( ; i >= 0; i-- )
	{
		adjustHeap(arr, i, length - 1);
	}
}

// Sort the heap
void heapSort( int arr[] , int length )
{
	int i = length - 1;

	for (; i > 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		adjustHeap(arr, 0, i - 1);
	}
}