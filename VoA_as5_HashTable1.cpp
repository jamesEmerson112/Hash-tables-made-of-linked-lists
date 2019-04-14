
//  HashTable.cpp


#include "VoA_as5_HashTable.h"

// Constructs the empty Hash Table object.
// Array length is set to 17 by default.
HashTable::HashTable(int tableLength)
{
	if (tableLength <= 0) tableLength = 17;
	array = new linkedList[tableLength];
	length = tableLength;
}

// Returns an array location
int HashTable::hash(int itemValue)
{
	return itemValue % length;
}

// Adds an item to the Hash Table.
void HashTable::insertValue( int itemValue )
{
	int index = hash(itemValue);
	array[index].insertItem(itemValue);
}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
bool HashTable::removeItem( int itemValue )
{
	int index = hash(itemValue);
	// cout << "index = " << index << endl;
	return array[index].removeItem(itemValue);
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
/*
item * HashTable::getItemByValue(int itemValue)
{
	int index = hash(itemValue);
	return array[index].getItem(itemValue);
}
*/

// Display the contents of the Hash Table to console window.
void HashTable::printTable(ofstream & outfile)
{
	for (int i = 0; i < length; i++)
	{
		outfile << i << ": ";
		array[i].printList(outfile);
	}
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
	return length;
}

// Returns the number of Items in the Hash Table.
int HashTable::getNumberOfItems()
{
	int itemCount = 0;
	for (int i = 0; i < length; i++)
	{
		itemCount += array[i].getLength();
	}
	return itemCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
	delete[] array;
}

// Search the item to verify it is "would be deleted" or "not found"
bool HashTable::searchItem( int itemValue )
{
	int index = hash(itemValue);
	return array[index].searchItem(itemValue);
}

//*****************************************************************
// End of File
//*****************************************************************