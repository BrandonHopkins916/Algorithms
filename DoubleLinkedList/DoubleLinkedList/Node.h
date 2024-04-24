#pragma once

#include <iostream>

using namespace std;

class Node
{
	public:
		string data;
		Node* prev;
		Node* next;
};

class DoubleLink
{

	public:
		Node* head;
		Node* tail;

		DoubleLink()
		{
			head = new Node();
			head->data = "A";
			head->prev = NULL;
			head->next = NULL;

			Node* nodeB = new Node();
			nodeB->data = "B";
			nodeB->prev = head;
			nodeB->next = NULL;
			head->next  = nodeB;

			Node* nodeC = new Node();
			nodeC->data = "C";
			nodeC->prev = nodeB;
			nodeC->next = NULL;
			nodeB->next = nodeC;

			tail = new Node();
			tail->data = "D";
			tail->prev = nodeC;
			tail->next = NULL;
			nodeC->next = tail;
		}

		void output()
		{
			Node* p = head;
			Node* end = NULL;
			while (p != NULL)
			{
				cout << p->data << "->";
				end = p;
				p = p->next;
			}
			cout << "End\n";

			p = end;
			while (p != NULL)
			{
				cout << p->data << "->";
				p = p->prev;
			}
			cout << "Start\n\n";
		}

		void add(string data)
		{
			Node *newNode = new Node();
			newNode->data = data;
			newNode->next = NULL;

			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}

		~DoubleLink()
		{
			Node* p = head;
			Node* temp = p;
			while (p != NULL)
			{
				temp = p;
				p = p->next;
				delete temp;
			}
		}
};

