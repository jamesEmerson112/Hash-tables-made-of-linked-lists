/* 
 * LinkedList.h
 *
 * This header file contains the Linked List class declaration.
 * Hash Table array elements consist of Linked List objects.
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>

using namespace std;


//*********************************************************
// List items are keys with pointers to the next item.
//*********************************************************
struct item
{
	int value;
	item *next;
};

//*****************************************************************
// Linked lists
//*****************************************************************
class linkedList
{
private:
	//ofstream & outfile;

	item *head;

	// Length is the number of data nodes
	int length;

public:
	// Construct an empty linked list object.
	// Create the head node and set the length to zero.
	linkedList();

	// Insert an item into the end of the list.
	void insertItem(int itemValue);

	// Remove an item from the list
	// Return true if it is successful
	bool removeItem(int itemValue);

	// search for an item
	// Return a reference to the first math.
	// Else return a NULL pointer 
	bool searchItem(int itemValue);

	// Display list contents
	void printList(ofstream &);

	// Return the length of the list
	int getLength();

	// De-allocate list memory when the program terminates
	~linkedList();
};

#endif

//*****************************************************************
// End of File
//*****************************************************************