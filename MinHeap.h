//
// Created by Haya on 11/27/2023.
//

#ifndef ASSIGNMENT_5_MINHEAP_H
#define ASSIGNMENT_5_MINHEAP_H

// File: MinHeap.h
// Heap Class header file (Minimum Heap for graph edges)
/* ________________________________________________________________________________________________
The following is a definition of a class for a Minimum Heap "MinHeap". The elements of the heap are
structs that model an edge in a non-directed weighted graph. Each edge is characterized by three
integers: (u,v,w). u is the index of a node, v is the index of the second node, and w is the weight
of the edge between u and v. The top of the heap will contain the edge with the minimum weight. The
heap condition is that a parent is always less than or equal to the children. The heap is implemented
as a dynamic array a[] with a size specified by the class constructor. Location a[0] is reserved to
contain a weight value "itemMin" smaller than any possible weight value (e.g. a negative number)
___________________________________________________________________________________________________
*/

#include "Edge.h"
using namespace std;

class MinHeap
{
public:

    // Member Functions
    // Class Constructor with input size parameter
    MinHeap(int );
    // Class Destructor
    ~MinHeap();
    // Functions Prototype Definitions
    void insert(Edge e);			// insert edge into heap
    Edge remove(); // remove the top of the heap
    int getN() const {return N;}

private:
    // Pointer to Storage Array
    Edge *a;
    // Maximum Size (not including a[0])
    int MaxSize;
    int N;							// index of last element in the heap
    weightType itemMin;				// itemMin to be stored in a[0]
    // Heap Adjustment Functions
    void upheap(int k);
    void downheap(int k);

};



#endif //ASSIGNMENT_5_MINHEAP_H
//#include "MinHeap.cpp"