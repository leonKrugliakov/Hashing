//****************************************************************************************************
//
//      File:                Node.h
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
//			2.	  HashTable.h - Contains the HashTable class
//			3.	  Stock.h - Contains the Stock structure
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename T>
struct Node
{
	T* element;
	int status;
	Node();
	Node(T* element, int status);
};

//****************************************************************************************************

template <typename T>
Node<T>::Node()
{
	element = nullptr;
	status = 0;
}

//****************************************************************************************************

template <typename T>
Node<T>::Node(T* element, int status)
{
	this->element = element;
	this->status = status;
}

//****************************************************************************************************

#endif