//
// Created by Haya on 11/27/2023.
//

// File:MinHeap.cpp
// Heape Class implementation file (Minimum heap for graph edges)


// Member Functions

// Constructor with argument. max size is mVal elements
// not including a[0] which will receive a weight -32767
// The constructor creates the heap array, initializes
// the end of the heap to N=0,and itmMin

#include "MinHeap.h"
#include <iostream>
#include <queue>

using namespace std;

MinHeap::MinHeap(int mVal)
{
    a = new Edge[mVal+1]; 	N=0;
    MaxSize = mVal; itemMin = -32767; // Minimum Heap
    a[0].w = itemMin ;
}
// Class Destructor
MinHeap::~MinHeap()
{ delete [] a;}

// Heap Adjustment Functions
// upheap element at location (k) in the heap
// as long as it is less than the parent

void MinHeap::upheap(int k)
{
    Edge e = a[k]  ;
    while ( e <= a[k/2])
    { a[k] = a[k/2] ;   k = k/2 ; }
    a[k] = e ;
}

// downheap element at (k) in the heap
void MinHeap::downheap(int k)
{
    int j = 2 * k ;     Edge e = a[k] ;
    while (j <= N) {
        if ((j < N) && (a[j+1] < a[j])) j++ ;
        if ( e <= a[j] ) break;
        a[j/2] = a[j] ;     j *= 2 ;   }
    a[j/2] = e ;
}

// Insert (e) in a heap and adjust heap
void MinHeap::insert(Edge e)
{
    a[++N] = e ;    upheap(N) ;
}


// remove and return top of the heap, then adjust heap
Edge MinHeap::remove()
{
    Edge e = a[1] ;
    a[1] = a[N--] ; downheap(1) ;
    return e;
}
