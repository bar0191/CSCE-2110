/*
 ============================================================================
 Name        : HashTable.cpp
 Author      : Brandon A. Reid - Bar0191
 Version     : v1
 Copyright   : 2016
 Course      : CSCE2110
 Description : HashTable class functions
 Notes       : this program is a barebones HashTable that was required for
 CSCE2110, the assignment did not require eror checking and user input, this
 is simply a hardcoded hashTable with basic student info.
 ============================================================================
 */

#include "HashTable.h"

/*
 ============================================================================
 Function    : HashFunction()
 Parameters  : int hashKey
 Return      : nothing
 Description : Lemma hashing algorithm currently being used as hashing key
 Citation    : https://www.coursera.org/learn/data-structures/lecture/mW2wn/hashing-integers
 ============================================================================
*/
int HashTable::hashFunction(int hashKey)
{
  // default hash function
     return (hashKey) % hashLength;

  // Lemma hash function
  // 1<a<p, 1<b<p, p=10^length of keys (prime #)
  // universal family A is a memeber of [1,p-1] and B is a member of [0,p-1]
    
  //int a = 13;
  //int b = 52;
  //int p = 1000000069;
    
  //int Lemma = (a * (hashKey) + b) % p;
  //return (Lemma % hashLength);
}

/*
 ============================================================================
 Function    : HashTable()
 Parameters  : int hashTabLength
 Return      : nothing
 Description : Constructor
 Citation    : N/A - Function was given
 ============================================================================
*/
HashTable::HashTable(int hashTableLength)
{
  // class Constructor
  if (hashTableLength <= 0) hashTableLength = 500;
  hashLength = hashTableLength;
}

/*
 ============================================================================
 Function    : insert()
 Parameters  : Node newNode
 Return      : nothing
 Description : insert new node, hard coded from main, hashes ID # as the key
 Citation    : http://www.cplusplus.com/reference/list/list/push_back/
 ============================================================================
*/
void HashTable::insert(Node *newNode)
{
  // hash a new key (bucket location) determined by newNode's ID number
  int bucket = hashFunction(newNode->ID);

  // push newNode to the back of the list
  LinkedList[bucket].push_back(*newNode);
}

/*
 ============================================================================
 Function    : insert()
 Parameters  : Node newNode
 Return      : nothing
 Description : insert new node, hard coded from main, hashes ID # as the key
 Citation    : http://www.cplusplus.com/reference/list/list/remove/
 ============================================================================
*/
void HashTable::remove(int NodeKey)
{
  int bucket = hashFunction(NodeKey); // hash the key for bucket location
  list<Node>::iterator Node;          // create iterator for stl list

  // iterate through list starting from beginning, until end is reached
  for (Node = LinkedList[bucket].begin(); Node != LinkedList[bucket].end(); Node++)
  {
    // if NodeKey matches a Nodes->ID value
    if ((*Node).ID == NodeKey)
    {
      // remove indicated Node from stl list at hashed bucket value
      LinkedList[bucket].remove(*Node);
      return;
    }
  }
}

/*
 ============================================================================
 Function    : printList()
 Parameters  : int hashKey
 Return      : nothing
 Description : prints list of IDs in each bucket table
 Citation    : N/A
 ============================================================================
*/
void HashTable::printList(int hashKey)
{
  // if list is empty
  if (LinkedList[hashKey].size() == 0)
  {
    cout << "\n{ }\n";
    return;
  }

  // create iterator to start at beginning of list
  list<Node>::iterator Node = LinkedList[hashKey].begin();
  // loop through existing IDs for each list
  cout << "\n{ \n";
  while(Node != LinkedList[hashKey].end())
  {
    cout << "\t" << (*Node).ID << ", " << (*Node).GPA << ", " << (*Node).major << "\n";
    Node++;
  }
  cout << "}\n";
}


/*
 ============================================================================
 Function    : lookUp()
 Parameters  : int NodeKey
 Return      : nothing
 Description : look up NodeKey, dependent upon ID number, ID = Key
 Citation    : N/A
 ============================================================================
*/
void HashTable::lookUp(int NodeKey)
{
  int bucket = hashFunction(NodeKey);   // hash the key for bucket location
  list<Node>::iterator Node;            // create iterator for stl list

  // iterate through beginning to end of the list
  for (Node = LinkedList[bucket].begin(); Node != LinkedList[bucket].end(); Node++)
  {
    // if a Nodes ID matches the NodeKey value
    if ((*Node).ID == NodeKey)
    {
      // output lookUp Student information
      cout << "Student " << (*Node).ID    << " FOUND! Printing out student "
           << (*Node).ID << " data: \n";
      cout << "   ID: "  << (*Node).ID    << "\n"
           << "  GPA: "  << (*Node).GPA   << "\n"
           << "Major: "  << (*Node).major << "\n";
      return;
    }
  }
}

/*
 ============================================================================
 Function    : getNumberOfNodes()
 Parameters  : nothing
 Return      : nothing
 Description : get number of nodes in each linked list in the hash table
 Citation    : http://www.cplusplus.com/reference/list/list/size/
 ============================================================================
*/
int HashTable::getNumberOfNodes()
{
  int NodeCount = 0;  // declare number of Nodes at 0

  // iterate through buckets
  for (int bucket = 0; bucket < hashLength; bucket++)
  {
      // check count of Nodes in each linked list
      NodeCount += LinkedList[bucket].size();
  }
  return NodeCount;
}

/*
 ============================================================================
 Function    : printBucketValues()
 Parameters  : nothing
 Return      : nothing
 Description : print all the keys within each bucket
 Citation    : N/A - Function was given
 ============================================================================
*/
void HashTable::printBucketValues()
{
  // print ID values in HashTable
  cout << "\n\nHash Table Bucket Values:\n";
  for (int bucket = 0; bucket < hashLength; bucket++)
  {
      cout << "Bucket " << bucket + 1 << ": ";
      printList(bucket);
  }
}

/*
 ============================================================================
 Function    : printHistogram()
 Parameters  : nothing
 Return      : nothing
 Description : displays each node is a histogram style table, helps visualize
 Citation    : http://www.cplusplus.com/reference/list/list/size/
 ============================================================================
*/
void HashTable::printHistogram()
{
    // print detailed histogram of HashTable
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfNodes() << " Nodes total\n";
    for (int bucket = 0; bucket < hashLength; bucket++)
    {
        cout << bucket + 1 << ":\t";
        for (int node = 0; node < LinkedList[bucket].size(); node++)
            cout << " O";
        cout << "\n";
    }
}
