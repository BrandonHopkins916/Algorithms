// SingleLink.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Node.h"

using namespace std;

int main()
{
    SingleLink* singleLink = new SingleLink();

    singleLink->remove(2);

    singleLink->output();

    delete singleLink;

    return 0;
}
