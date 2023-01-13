//****************************************************************************************************
//
//      File:                Hashing.cpp
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
//		    1.    HashTable.h - contains the HashTable class
//			2.	  Stock.h - Contains the Stock structure
//			3.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#include <iostream>

#include "Stock.h"
#include "HashTable.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

int main()
{
	bool complete = false;
	char answer;
	string symbolInput;

	Stock aapl = { "Apple", "aapl", 115.31 };
	Stock tsla = { "Tesla", "tsla", 410.83 };
	Stock fb = { "Facebook", "fb", 280.83 };
	Stock googl = { "Google", "googl", 1613.83 };
	Stock msft = { "Microsoft", "msft", 201.83 };
	Stock amzn = { "Amazon", "amzn", 3031.23 };

	HashTable<Stock> ht(5);

	ht.insert(aapl);
	ht.insert(tsla);
	ht.insert(fb);
	ht.insert(googl);
	ht.insert(msft);
	ht.insert(amzn);

	while (!complete)
	{
		cout << string(50, '-') << endl;
		cout << "Please select what you would like to do:" << endl
			<< "A. Display all the stocks in the list." << endl
			<< "B. Remove a stock in the list." << endl
			<< "C. Search information about a stock in the list." << endl 
			<< "Q. To Quit." << endl << endl;
		cin >> answer;

		switch (tolower(answer))
		{
		case 'a':
			ht.display();
			break;
		case 'b':
			cout << "Please enter the symbol for the stock you would like to remove:" << endl;
			cin >> symbolInput;
			if (symbolInput == "aapl")
			{
				ht.remove(aapl);
			}
			else if (symbolInput == "tsla")
			{
				ht.remove(tsla);
			}
			else if (symbolInput == "fb")
			{
				ht.remove(fb);
			}
			else if (symbolInput == "googl")
			{
				ht.remove(googl);
			}
			else if (symbolInput == "msft")
			{
				ht.remove(msft);
			}
			else if (symbolInput == "amzn")
			{
				ht.remove(amzn);
			}
			else
			{
				cout << "There was no item found, please try again!";
			}
			break;
		case 'c':
			cout << "Please enter the symbol for the stock you would like to search:" << endl;
			cin >> symbolInput;
			if (symbolInput == "aapl")
			{
				cout << *ht.search(aapl);
			}
			else if (symbolInput == "tsla")
			{
				cout << *ht.search(tsla);
			}
			else if (symbolInput == "fb")
			{
				cout << *ht.search(fb);
			}
			else if (symbolInput == "googl")
			{
				cout << *ht.search(googl);
			}
			else if (symbolInput == "msft")
			{
				cout << *ht.search(msft);
			}
			else if (symbolInput == "amzn")
			{
				cout << *ht.search(amzn);
			}
			else
			{
				cout << "There was no item found, please try again!";
			}
			break;
		case 'q':
			cout << "Quitting..." << endl;
			complete = true;
			break;
		default:
			cout << "You have entered an invalid input. Please try again." << endl;
		}

	}

}

//****************************************************************************************************

/*
Please select what you would like to do:
A. Display all the stocks in the list.
B. Remove a stock in the list.
C. Search information about a stock in the list.
Q. To Quit.

a
Company Name: Google
Symbol:googl
Price:1613.83

------------------

Company Name: Apple
Symbol:aapl
Price:115.31

------------------

Company Name: Facebook
Symbol:fb
Price:280.83

------------------

Company Name: Tesla
Symbol:tsla
Price:410.83

------------------

Company Name: Microsoft
Symbol:msft
Price:201.83

------------------

--------------------------------------------------
Please select what you would like to do:
A. Display all the stocks in the list.
B. Remove a stock in the list.
C. Search information about a stock in the list.
Q. To Quit.

c
Please enter the symbol for the stock you would like to search:
fb
Company Name: Facebook
Symbol:fb
Price:280.83
--------------------------------------------------
Please select what you would like to do:
A. Display all the stocks in the list.
B. Remove a stock in the list.
C. Search information about a stock in the list.
Q. To Quit.

b
Please enter the symbol for the stock you would like to remove:
googl
--------------------------------------------------
Please select what you would like to do:
A. Display all the stocks in the list.
B. Remove a stock in the list.
C. Search information about a stock in the list.
Q. To Quit.

a
Company Name: Apple
Symbol:aapl
Price:115.31

------------------

Company Name: Facebook
Symbol:fb
Price:280.83

------------------

Company Name: Tesla
Symbol:tsla
Price:410.83

------------------

Company Name: Microsoft
Symbol:msft
Price:201.83

------------------

--------------------------------------------------
Please select what you would like to do:
A. Display all the stocks in the list.
B. Remove a stock in the list.
C. Search information about a stock in the list.
Q. To Quit.

q
Quitting...
*/