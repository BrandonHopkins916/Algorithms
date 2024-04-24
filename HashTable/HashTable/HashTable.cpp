// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

#include "CallFunction.h"

using namespace std;

int main()
{
    HashTable* hashTable = new HashTable();

    hashTable->put("David", "Good Boy Keep Going");
    hashTable->put("grace", "Cute Girl Keep Going");

    cout << "David => " << hashTable->get("David") << endl;
    cout << "grace => " << hashTable->get("grace") << endl;

    delete hashTable;

    return 0;

}
