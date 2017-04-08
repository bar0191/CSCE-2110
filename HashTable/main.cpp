/*
 ============================================================================
 Name        : main.cpp
 Author      : Brandon A. Reid - Bar0191
 Version     : v1
 Copyright   : 2016
 Course      : CSCE2110
 Description : main - hardcoded student data
 Notes       : this program is a barebones HashTable that was required for
 CSCE2110, the assignment did not require eror checking and user input, this
 is simply a hardcoded hashTable with basic student info.
 ============================================================================
 */

#include "HashTable.h"

int main()
{	

	ifstream fin;
	ofstream fout;

	int uid;
	double gpa;
	string major;
	string suid;
	string sgpa;
	
	// create a new empty hash table
	HashTable table;

	fin.open("input.txt");

	while (getline(fin, suid, ',') && 
	       getline(fin, sgpa, ',') && 
	       getline(fin, major))
	{
		uid = stoi(suid); gpa = stod(sgpa);
	
		Node *student = new Node(uid, gpa, major);
		table.insert(student);
	}

	// show update
	table.printBucketValues();
	table.printHistogram();

	fout.close();
	return 0;
}
