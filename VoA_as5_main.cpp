//**************************************************************
//  An Thien Vo	
// 	CS 302 - 1001, Dr. Larmore
//  Assignment #5
//
// Hash table and linked list
//
//**************************************************************

#include "VoA_as5_HashTable.h"
#include <string>
#include <iomanip>

const int MAX = 499;

void outputSmallData(ofstream &);

void outputBigData(ofstream &);

int main()
{
	/* Program plan:
	 * 1. Read the first file
	 * 2. Insert those items
	 * 3. close that input file
	 * 4. Read the second input file
	 * 5. Delete the items listed in that file
	 * 6. Re-print the hash table
	 */

	ofstream outfile;
	string outputFile;
	cout << "An T. Vo, CS 302 - 1001, Dr. Larmore, Assignment 5" << endl;
	cout << "Please enter the desired name for you output: " << endl;
	cin >> outputFile;

	outfile.open(outputFile.c_str());

	outputSmallData(outfile);

	outputBigData(outfile);

	outfile.close();

	system("pause");
	return 0;
}

//**********************************************************************
void outputSmallData(ofstream & outfile)
{
	HashTable table1;

	string inputFileName;
	ifstream infile;
	int data = 0;
	int index = 0;
	int deletedData[MAX], countDeletedData = 0;
	for (int i = 0; i < MAX; ++i)
	{
		deletedData[i] = 0;
	}

	int notFoundData[MAX], countNotFoundData = 0;
	for (int i = 0; i < MAX; ++i)
	{
		notFoundData[i] = 0;
	}

	outfile << "Printing the output for the small data. \n\n";
	outfile << "Inserting items from: " << "middata" << endl;	

		// 1
	infile.open("middata.txt");

	if (!infile)
	{
		outfile << "This is the wrong file" << endl;
		system("pause");
		return;
	}

		// 2
	while (infile >> data)
	{
		table1.insertValue(data);
	}

		// 3
	infile.close();

	table1.printTable(outfile);

	//******************************************************************
	// delete item

	outfile << "Deleting items from: deletedata" << endl;

		// 4
	infile.open("deletedata.txt");

	if (!infile)
	{
		outfile << "This is the wrong file" << endl;
		system("pause");
		return;
	}	

	 	// 5
	while (infile >> data)
	{
		if(table1.searchItem(data))
		{
			deletedData[countDeletedData] = data;
			countDeletedData++;
		}
		else if (!table1.searchItem(data))
		{
			notFoundData[countNotFoundData] = data;
			countNotFoundData++;
		}
		table1.removeItem(data);
	}

	infile.close();

		// printing the deleted and not-found data
	for (int i = countDeletedData-1; i >= 0; --i)
	{
		outfile << deletedData[i] << " deleted" << endl;
	}
	for (int i = countNotFoundData-1; i >= 0; --i)
	{
		outfile << notFoundData[i] << " not found" << endl;
	}

	outfile << "Items remaining in hash table: " << endl;

	table1.printTable(outfile);

	outfile << endl;
	outfile << setw(20) << setfill('*') << endl;
	outfile << endl;
}

//*************************************************************************

void outputBigData(ofstream & outfile)
{
	HashTable table2;

	string inputFileName;
	ifstream infile;
	int data = 0;
	int index = 0;
	int deletedData[MAX], countDeletedData = 0;
	for (int i = 0; i < MAX; ++i)
	{
		deletedData[i] = 0;
	}

	int notFoundData[MAX], countNotFoundData = 0;
	for (int i = 0; i < MAX; ++i)
	{
		notFoundData[i] = 0;
	}

	cout << "Please enter the input file (with .txt): " << endl;
	cin >> inputFileName;
	outfile << "Printing the output for the big data. \n\n";
	outfile << "Inserting items from: " << inputFileName << endl;	

		// 1
	infile.open(inputFileName.c_str());

	if (!infile)
	{
		cout << "This is the wrong file" << endl;
		system("pause");
		return;
	}

		// 2
	while (infile >> data)
	{
		table2.insertValue(data);
	}

		// 3
	infile.close();

	table2.printTable(outfile);

	//******************************************************************
	// delete item

	cout << "Please enter the deleted data file (with .txt): " << endl;
	cin >> inputFileName;
	outfile << "Deleting items from: " << inputFileName << endl;

		// 4
	infile.open(inputFileName.c_str());

	if (!infile)
	{
		cout << "This is the wrong file" << endl;
		system("pause");
		return;
	}	

	 	// 5
	while (infile >> data)
	{
		if(table2.searchItem(data))
		{
			deletedData[countDeletedData] = data;
			countDeletedData++;
		}
		else if (!table2.searchItem(data))
		{
			notFoundData[countNotFoundData] = data;
			countNotFoundData++;
		}
		table2.removeItem(data);
	}

	infile.close();

		// printing the deleted and not-found data
	for (int i = countDeletedData-1; i >= 0; --i)
	{
		outfile << deletedData[i] << " deleted" << endl;
	}
	for (int i = countNotFoundData-1; i >= 0; --i)
	{
		outfile << notFoundData[i] << " not found" << endl;
	}

	outfile << "Items remaining in hash table: " << endl;
	table2.printTable(outfile);

	outfile << endl;
	outfile << setw(20) << setfill('*') << endl;
	outfile << endl;
}

