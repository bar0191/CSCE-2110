/*
 ============================================================================
 Name        : Node.cpp
 Author      : Brandon A. Reid - Bar0191
 Version     : v1
 Copyright   : 2016
 Course      : CSCE2110
 Description : function definitions for Node Class
 Notes       : this program is a barebones HashTable that was required for
 CSCE2110, the assignment did not require eror checking and user input, this
 is simply a hardcoded hashTable with basic student info.
 ============================================================================
 */

#include "Node.h"

/*
 ============================================================================
 Function    : Node()
 Parameters  : nothing
 Return      : nothing
 Description : Constructor
 Citation    : N/A
 ============================================================================
*/
Node::Node()
{
  //Constructor
  ID = 0;
  GPA = 0.00;
  major = "";
}

/*
 ============================================================================
 Function    : ~Node()
 Parameters  : nothing
 Return      : nothing
 Description : De-constructor
 Citation    : N/A
 ============================================================================
*/
Node::~Node()
{
  //De-constructor
}

/*
 ============================================================================
 Function    : Node() (overloaded) Constructor
 Parameters  : nothing
 Return      : nothing
 Description : overloaded function to take in parameters as a function
 Citation    : N/A
 ============================================================================
*/
Node::Node(int stuID, double stuGPA, string stuMajor)
{
  //Co-Constructor
  ID = stuID;
  GPA = stuGPA;
  major = stuMajor;
}

/*
 ============================================================================
 Function    : operator ==
 Parameters  : right hand side of comparison
 Return      : 1 (success)
 Description : overloaded operator for STL list comparisons with class objects
              this has to be done in order to use the stl linked list class
 Citation    : http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html
 ============================================================================
*/
int Node::operator == (const Node& rhs)
{
  if (this->ID != rhs.ID) return 0;
  if (this->GPA != rhs.GPA) return 0;
  if (this->major != rhs.major) return 0;
  return 1;
}

/*
 ============================================================================
 Function    : operator !=
 Parameters  : right hand side of comparison
 Return      : 1 (success)
 Description : overloaded operator for STL list comparisons with class objects
              this has to be done in order to use the stl linked list class
 Citation    : http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html
 ============================================================================
*/
int Node::operator != (const Node& rhs)
{
  if (this->ID == rhs.ID) return 0;
  if (this->GPA == rhs.GPA) return 0;
  if (this->major == rhs.major) return 0;
  return 1;
}
