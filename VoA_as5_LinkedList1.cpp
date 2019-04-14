/*
 * LinkedList.cpp
 * HashTable
 *
 * This header file contains the Linked List class declaration
 */

#include "VoA_as5_LinkedList.h"

// Construct the empty linked list object.
// Create the head node and set the length to zero.
linkedList::linkedList()
{
	head = new item; // creating a new struct pointer type
	head->next = nullptr; // pointing to an empty space
	length = 0;
}

// Insert an item at the end of the list
void linkedList::insertItem( int value )
{
	item *newItem = new item;
	newItem->value = value;
	newItem->next = nullptr;
	if(!head->next) 			// if the list is empty
	{
		head->next = newItem;
		length++;
		return;
	} // end if(!head->next)
	// else
	item *p = head; 			// so I'm inserting the item from the head 
	item *q = head->next; 		// instead of the tail
	p->next = newItem;
	newItem->next = q;
	length++;
}

// Remove an item from the list by item key.
// Return true if it's sucessful
bool linkedList::removeItem(int itemValue)
{
	if (!head->next)  		// if there is nothing here in head
							// then there is nothing to remove
	{
		return false;
	}

	item * p = head; 		
	item * q = head;
 
	while (q) 				// aka q->next
	{
		if (q->value == itemValue) 	// if it matches, delete it and return true
		{
			p->next = q->next;
			delete q; 
			length--;
			return true;
		}
		p = q;
		q = p->next;
	} // end while (q)
	return false;
} // end remove item

// search for an item by its value
bool linkedList::searchItem(int itemValue)
{
	if (!head->next)  		// if there is nothing here in head
							// then there is nothing to remove
	{
		return false;
	}

	item * p = head; 		
	item * q = head;
 
	while (q) 				// aka q->next
	{
		if (q->value == itemValue) 	// if it matches, delete it and return true
		{
			return true;
		}
		p = q;
		q = p->next;
	} // end while (q)
	return false;
}

// Display list contents to the console window.
void linkedList::printList(ofstream & outfile)
{
	if (length == 0)
	{
		outfile << "\n";
		return;
	}

	item * p = head;
	item * q = head;

	while (q)
	{
		p = q;
		if (p != head)
		{
			outfile << p->value;
			if (p->value)
				outfile << " ";
			else
				outfile << " ";
		}
		q = p->next;
	}
	outfile << "\n";
}

// Return the length of the list
int linkedList::getLength()
{
	return length;
}

// De-allocate list memory when the program terminates.
linkedList::~linkedList()
{
	item * p = head;
	item * q = head;
	while(q)
	{
		p = q;
		q = p->next;
		if (q)
			delete p;
	}
}

// End of file

