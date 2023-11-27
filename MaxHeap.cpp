//
// Created by Haya on 11/27/2023.
//

// File: MaxHeap.cpp
// Heap Class implementation file (Maximum heap for graph edges)

#include "MaxHeap.h"

// Class Constructor with argument. max size is mVal elements
// not including a[0] which will receive a weight 32767
// The constructor creates the heap array, initializes
// the end of the heap to N=0, and itemMax

MaxHeap::MaxHeap(int mVal)
{
    a = new Edge[mVal + 1];  // Dynamic array for heap
    N = 0;
    MaxSize = mVal;
    itemMax = 32767; // Maximum Heap
    a[0].w = itemMax;
}

// Class Destructor
MaxHeap::~MaxHeap()
{
    delete[] a;
}

// Heap Adjustment Functions

// upheap element at location (k) in the heap
// as long as it is greater than the parent
void MaxHeap::upheap(int k)
{
    Edge e = a[k];
    while (e >= a[k / 2])
    {
        a[k] = a[k / 2];
        k = k / 2;
    }
    a[k] = e;
}

// downheap element at (k) in the heap
void MaxHeap::downheap(int k)
{
    int j = 2 * k;
    Edge e = a[k];
    while (j <= N)
    {
        if ((j < N) && (a[j + 1] > a[j]))
            j++;
        if (e >= a[j])
            break;
        a[j / 2] = a[j];
        j *= 2;
    }
    a[j / 2] = e;
}

// Insert (e) into a heap and adjust heap
void MaxHeap::insert(Edge e)
{
    a[++N] = e;
    upheap(N);
}

// Remove and return the top of the heap, then adjust the heap
Edge MaxHeap::remove()
{
    Edge e = a[1];
    a[1] = a[N--];
    downheap(1);
    return e;
}