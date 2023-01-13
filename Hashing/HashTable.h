//****************************************************************************************************
//
//      File:                HashTable.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #2
//
//      Course Name:         Data Structures II
//
//      Course Number:       COSC 3100 - 11
//
//      Due:                 November 3, 2020
//
//
//      This program creates a few stocks and then stores them into a has table.
//		The simulation then asks the user if they would like to display, search,
//		or remove stocks. The program uses quadratic probing.
//
//      Other files required:
//		    1.    Hashing.cpp - contains the main function
//			2.	  Stock.h - Contains the Stock structure
//			3.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

template <typename T>
class HashTable
{
private:
	Node<T>* table;
	int size;
public:
	HashTable(int s = 10);
	~HashTable();
	void insert(T& item);
	void remove(T& item);
	T* search(T& item) const;
	void display() const;
};

//****************************************************************************************************

template <typename T>
HashTable<T>::HashTable(int s)
{
	size = s;
	table = new Node<T>[size];
}

//****************************************************************************************************

template <typename T>
HashTable<T>::~HashTable()
{
	delete[] table;
}

//****************************************************************************************************

template <typename T>
void HashTable<T>::insert(T& item)
{
	int hash = item.hash(size);
	bool inserted = false;

	if (table[hash].status == -1 || table[hash].status == 0)
	{
		table[hash].element = &item;
		table[hash].status = 1;
	}
	else 
	{
		for (int i = 0; i < size && !inserted; i++)
		{
			int newHash = (hash + i * i) % size;

			if (table[newHash].status == -1 || table[newHash].status == 0)
			{
				table[newHash].element = &item;
				table[newHash].status = 1;
				inserted = true;
			}
		}
	}
}

//****************************************************************************************************

template <typename T>
void HashTable<T>::remove(T& item)
{
	int hash = item.hash(size);
	bool removed = false;

	if (table[hash].element == &item)
	{
		table[hash].element = nullptr;
		table[hash].status = 0;
	}
	else
	{
		for (int i = 0; i < size && !removed; i++)
		{
			int newHash = (hash + i * i) % size;

			if (table[newHash].element == &item)
			{
				table[newHash].element = nullptr;
				table[newHash].status = 0;
				removed = true;
			}
		}
	}
}

//****************************************************************************************************

template <typename T>
T* HashTable<T>::search(T& item) const
{
	int hash = item.hash(size);
	bool found = false;
	T* returned = nullptr;

	if (table[hash].element == &item)
	{
		returned = table[hash].element;
	}
	else
	{
		for (int i = 0; i < size && !found; i++)
		{
			int newHash = (hash + i * i) % size;

			if (table[newHash].element == &item)
			{
				returned = table[newHash].element;
				found = true;
			}
		}
	}

	return returned;
}

//****************************************************************************************************

template <typename T>
void HashTable<T>::display() const
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].status == 1) 
		{
			cout << *table[i].element << endl;
			cout << "------------------" << endl << endl;
		}
	}
}

//****************************************************************************************************

#endif