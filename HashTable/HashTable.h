/*
 ============================================================================
 Name        : HashTable.h
 Author      : Brandon A. Reid - Bar0191
 Version     : v1
 Copyright   : 2016
 Course      : CSCE2110
 Description : HashTable class definitions
 Notes       : this program is a barebones HashTable that was required for
 CSCE2110, the assignment did not require eror checking and user input, this
 is simply a hardcoded hashTable with basic student info.
 ============================================================================
 */
// cites
//http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html
//http://www.cplusplus.com/forum/beginner/92538/
//http://www.cplusplus.com/reference/list/list/
//http://www.cs.uregina.ca/Links/class-info/210/STLList/
//http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
//https://www.coursera.org/learn/data-structures/lecture/mW2wn/hashing-integers

#include "Node.h"

// class oject for HashTable
class HashTable
{
private:
	// private variables
	int hashLength;									// size of hash table
	int hashFunction(int hashKey);	// return the hash value

public:
	// declare array of linked lists for hash table
	list<Node> LinkedList[500];

	// constructor will create class object with the above array
	HashTable(int hashTableLength = 500);

	// function prototypes
	void insert(Node *newNode);			// hash insert
	void remove(int NodeKey);				// hash delete
	void printList(int hashKey);		// print IDs in linked list
	void lookUp(int NodeKey);				// hash lookup
	int getNumberOfNodes();					// return number of student nodes
	void printBucketValues();				// detailed print of the hash table
	void printHistogram();					// higher-level view of the table
};
