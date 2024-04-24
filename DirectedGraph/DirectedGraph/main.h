#pragma once

#include "iostream"
#include<stdlib.h>  
#include<math.h>  
#include<string.h>  
#include <string>

using namespace std;

#define MAX_VERTEX_SIZE 5
#define STACKSIZE 1000

class Vertex
{
public:
	string data;
	int visited; // Have you visited
};

class Stack
{
private:
	int top;
	int elements[STACKSIZE];

public:

	Stack()
	{
		top = -1;
	}

	void push(int element)
	{
		top++;
		elements[top] = element;
	}

	int pop()
	{
		if(top == -1)
		{
			return -1;
		}
		return false;
	}

	int peek()
	{
		if (top == -1)
		{
			return -1;
		}

		int data = elements[top];
		return data;
	}

	bool isEmpty()
	{
		if (top <= -1)
		{
			return true;
		}
		return false;
	}
};

class Graph
{
private:
	int size;
	Vertex vertexs[MAX_VERTEX_SIZE];
	int adjacencyMatrix[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];
	Stack stack;

public:
	Graph()
	{
		size = 0;
		memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));
	}

	void addVertex(string data)
	{
		Vertex vertex;
		vertex.data = data;
		vertex.visited = false;

		vertexs[size] = vertex;
		size++;
	}

	void addEdge(int from, int to)
	{
		// A -> B != B -> A
		adjacencyMatrix[from][to] = 1;
	}

	int findAdjacencyUnVisitedVertex(int row)
	{
		for (int col = 0; col < size; col++)
		{
			if (adjacencyMatrix[row][col] == 1 && !vertexs[col].visited)
			{
				return col;
			}
		}
		return -1;
	}

	void depthFirstSearch()
	{
		vertexs[0].visited = true;
		cout << vertexs[0].data;
		stack.push(0);

		while (!stack.isEmpty())
		{
			int row = stack.peek();
			int col = findAdjacencyUnVisitedVertex(row);
			
			if (col == -1)
			{
				stack.pop();
			}
			else
			{
				vertexs[col].visited = true;
				cout << "->" << vertexs[col].data;
				stack.push(col);
			}
		}
		clear();
	}

	void clear()
	{
		for (int i = 0; i < size; i++)
		{
			vertexs[i].visited = false;
		}
	}

	void printGraph()
	{
		for (int i = 0; i < MAX_VERTEX_SIZE; i++)
		{
			cout << vertexs[i].data << " ";
		}
		cout <<" \n";

		for (int i = 0; i < MAX_VERTEX_SIZE; i++)
		{
			cout << vertexs[i].data << "";
			for (int j = 0; j < MAX_VERTEX_SIZE; j++)
			{
				cout << adjacencyMatrix[i][j] << " ";
			}
			cout <<" \n";
		}
	}
};
