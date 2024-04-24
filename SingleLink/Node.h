#pragma once

#include <iostream>

using namespace std;

class Node
{
	
	public:
		string	data;
		Node* next = NULL;
};

class SingleLink
{

	public:
		Node* head;
		Node* tail;

		SingleLink()
		{
			head = new Node();
			head->data = "A";
			head->next = NULL;

			Node* nodeB = new Node();
			nodeB->data = "B";
			nodeB->next = NULL;
			head->next = nodeB;

			Node* nodeC = new Node();
			nodeC->data = "C";
			nodeC->next = NULL;
			nodeB->next = nodeC;

			tail = new Node();
			tail->data = "D";
			tail->next = NULL;
			nodeC->next = tail;
		}

		void output()
		{
			Node* p = head;

			while (p != NULL)
			{
				cout << p->data << "->";
				p = p->next;
			}
			cout << "END";
		}

		/*void add(string data)
		{
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = NULL;

			tail->next = newNode;
			tail = newNode;
		}*/

		void insert( int insertPosition, string data )
		{
			Node* p = head;
			int i = 0;

			while (p->next != NULL && i < insertPosition - 1)
			{
				p = p->next;
				i++;
			}

			Node* newNode = new Node();
			newNode->data = data;

			newNode->next = p->next;
			p->next = newNode;

		}

		void remove(int removePosition)
		{
			Node* p = head;
			int i = 0;

			while (p->next != NULL && i < removePosition - 1)
			{
				p = p->next;
				i++;
			}

			Node* temp = p->next;
			p->next = p->next->next;
			temp->next = NULL;

			delete temp;
		}

		~SingleLink()
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