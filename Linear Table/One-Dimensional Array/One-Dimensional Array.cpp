// One-Dimensional Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int array[] = { 90, 70, 50, 80, 60, 85 };

    int length = ( sizeof(array) / sizeof(array[0]) );

    for (int i = 0; i < length; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
