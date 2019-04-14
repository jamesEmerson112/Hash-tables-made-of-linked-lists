/*
 * HashTable.h
 * 
 * This header file contains the Hash Table class declaration
 * Hash Table array elements consist of Linked List objects
 */

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "VoA_as5_LinkedList.h"

class HashTable
{
private:
	linkedList *array;

	//ofstream & outfile;

	// :ength is the size
	int length;

	// Returns an array location for a given item key.
	int hash( int itemValue );
public:
	// Construct the empty Hash Table object.
	HashTable( int tableLength = 17 );

	// Add an item to the Hash table
	void insertValue( int value );

	// Delete an Item
	bool removeItem( int itemValue );

	// Search the item to verify it is "would be deleted" or "not found"
	bool searchItem( int itemValue );

	// Display the contents of the Hash Table to the console
	void printTable(ofstream &);

	// Return the number of locations in the Hash Table
	int getLength();

	// Return the number of items in the Hash Table.
	int getNumberOfItems();

	// De-allocate all memory used for the Hash Table;
	~HashTable();

};

#endif