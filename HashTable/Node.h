/*
 ============================================================================
 Name        : Node.h
 Author      : Brandon A. Reid - Bar0191
 Version     : v1
 Copyright   : 2016
 Course      : CSCE2110
 Description : Node class definition for student info
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

// allowed includes
#include <iostream>
#include <string>
#include <list>
#include <fstream>

// allowed standard libraries
using std::cout;
using std::string;
using std::list;
using std::ofstream;
using std::ifstream;

// Node class to hold object for each student
class Node
{
public:

	// student info
	int ID;
	double GPA;
	string major;

	// funcion prototypes
	// constructors and De-constructors
	Node();
	~Node();
	Node(int stuID, double stuGPA, string stuMajor);

	// overloaded operators for stl list
	int operator == (const Node& rhs);
	int operator != (const Node& rhs);
};
