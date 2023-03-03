// Fibonacci_Sequence.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

class Fib
{
public:

	int Fibsequence(int userInput)
	{
		if (userInput > 15|| userInput < 0)
		{
			printf("Value is outside the scope\n");
			return 0;
		}
		else
		{
			int  t1 = 0, t2 = 1, nextTerm = 0;
			for (int i = 0; i <= userInput; i++)
			{
				if ( i == 1 )
				{
					printf("%i ", t1 );
					continue;
				}
				if ( i == 2 )
				{
					printf("%i ", t2);
					continue;
				}

				nextTerm = t1 + t2;
				t1 = t2;
				t2 = nextTerm;

				printf("%d ", nextTerm);
			}
		}
		return 0;
	}
};

int main()
{
    int a = 0;

    printf("What number did you want to start with?\n");
    scanf_s("%d", &a);

    Fib fibsequence;

    fibsequence.Fibsequence(a);

}

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
