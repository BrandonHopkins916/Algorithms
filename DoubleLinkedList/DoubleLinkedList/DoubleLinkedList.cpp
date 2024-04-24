// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Node.h"

using namespace std;

int main()
{
    DoubleLink* doubleLink = new DoubleLink();

    doubleLink->add("E");

    doubleLink->output();
    
    delete doubleLink;
    
    return 0;
}
