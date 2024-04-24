#pragma once

#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

#define CAPACITY 16

class Node
{
public:
	string key;
	string value;
	int hash;
	Node* next;
};

class HashTable 
{
public:
	Node* table[CAPACITY];
	int size;

	bool isEmpty()
	{
		return size == 0 ? true : false;
	}

	void put(string key, string value)
	{
		int hash = hashCode(key);
		Node *newNode = new Node();
		newNode->key = key;
		newNode->value = value;
		newNode->hash = hash;
		newNode->next = NULL;

		Node* node = table[hash];
		while (node != NULL)
		{
			if (node->key == key)
			{
				node->value = value;
				return;
			}
			node = node->next;
		}

		newNode->next = table[hash];
		table[hash] = newNode;
		size++;
	}

	string get(string key)
	{
		int hash = hashCode(key);
		Node* node = table[hash];

		while (node != NULL)
		{
			if (node->key == key)
			{
				return node->value;
			}
			node = node->next;
		}
		return NULL;
	}

	int hashCode(string key)
	{
		int num = 0;
		//int i;
		for (char ch : key)
		{
			num += (int)ch;
		}

		double avg = num * (pow(5, 0.5) - 1) / 2;
		double numneric = avg - floor(avg);
		return (int)floor(numneric * CAPACITY);
	}

	~HashTable()
	{
		for (int i = 0; i < CAPACITY; i++)
		{
			Node* node = table[i];
			while (node != NULL)
			{
				Node* temp = node->next;
				node = node->next;
				delete temp;
			}
			delete node;
		}
	};
};