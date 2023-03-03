#include <iostream>
#include "Insert.h"

struct node
{
    int data;
    struct node* next;
};

int main()
{
    int i;
    printf(" What would you like to do:\n" );
    printf(" 1. Insert\n, 2. Delete\n, 3. Traverse\n, 4. Search\n ");
    scanf_s("%d", &i);

    switch ( i )
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}

