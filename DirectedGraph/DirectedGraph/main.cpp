// Visual Studio 2022

#include "pch.h"
#include "main.h"
#include "iostream"
#include<stdlib.h>  
#include<math.h>  
#include<string.h>  
#include <string>

using namespace std;

#define MAX_VERTEX_SIZE 5
#define STACKSIZE 1000

int main()
{
	Graph* graph = new Graph();

	graph->addVertex("A");
	graph->addVertex("B");
	graph->addVertex("C");
	graph->addVertex("D");
	graph->addVertex("E");

	graph->addEdge(0, 1);
	graph->addEdge(0, 2);
	graph->addEdge(0, 3);
	graph->addEdge(1, 2);
	graph->addEdge(1, 3);
	graph->addEdge(2, 3);
	graph->addEdge(3, 4);

	graph->printGraph();

	cout << "\nDepth-first search traversal output:\n";

	graph->depthFirstSearch();

	delete graph;

	return 0;
}
