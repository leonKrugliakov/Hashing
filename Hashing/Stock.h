//****************************************************************************************************
//
//      File:                Stock.h
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
//			3.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

class Stock
{
private:
	string name,
		symbol;
	double price;
public:
	Stock(const string& name = "", const string& symbol = "", double price = 0);
	Stock(const Stock& s);
	void display() const;
	string getName() const;
	string getSymbol() const;
	double getPrice() const;
	bool operator==(const Stock& right) const;
	bool operator!=(const Stock& right) const;
	int hash(int size);

	friend ostream& operator<<(ostream& os, const Stock& s);
};

//****************************************************************************************************

Stock::Stock(const string& name, const string& symbol, double price) 
{
	this->name = name;
	this->symbol = symbol;
	this->price = price;
}

//****************************************************************************************************

Stock::Stock(const Stock& s)
{
	this->name = s.name;
	this->symbol = s.symbol;
	this->price = s.price;
}

//****************************************************************************************************

void Stock::display() const
{
	cout << "Company Name: " << name << endl 
		<< "Symbol:" << symbol << endl 
		<< "Price:" << price << endl << endl;
}

//****************************************************************************************************

string Stock::getName() const
{
	return name;
}

//****************************************************************************************************

string Stock::getSymbol() const
{
	return symbol;
}

//****************************************************************************************************

double Stock::getPrice() const
{
	return price;
}

//****************************************************************************************************

bool Stock::operator==(const Stock& right) const
{
	bool equal = false;

	if (this->name == right.name && 
		this->symbol == right.symbol && 
		this->price == right.price)
	{
		equal = true;
	}

	return equal;
}

//****************************************************************************************************

bool Stock::operator!=(const Stock& right) const
{
	bool equal = false;

	if (this->name != right.name ||
		this->symbol != right.symbol ||
		this->price != right.price)
	{
		equal = true;
	}

	return equal;
}

//****************************************************************************************************

int Stock::hash(int size)
{
	int key = 0;

	string stringKey = symbol + name + to_string(price);

	for (size_t i = 0; i < stringKey.length(); i++)
	{
		key += (int)stringKey[i];
	}

	return (key % (size - 1));
}

//****************************************************************************************************

ostream& operator<<(ostream& os, const Stock& s)
{
	os << "Company Name: " << s.getName() << endl <<
		"Symbol:" << s.getSymbol() << endl <<
		"Price:" << s.getPrice() << endl;

	return os;
}

//****************************************************************************************************

#endif STOCK_H