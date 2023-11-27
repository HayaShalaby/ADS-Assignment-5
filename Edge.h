//
// Created by Haya on 11/27/2023.
//

#ifndef ASSIGNMENT_5_EDGE_H
#define ASSIGNMENT_5_EDGE_H

// File: Edge.h
// Definition of Edge class
/* _______________________________________________________________
An edge (u,v,w) existing between nodes (u) and (v) with weight (w)
is modeled as a class (Edge).
__________________________________________________________________
*/

#include "Node.h"
typedef int weightType;		// weights are positive integers

class Edge
{
public:
    Node u;
    Node v;
    weightType w;
    bool operator < (const Edge &e)
    { return (w < e.w); }
    bool operator <= (const Edge &e)
    { return (w <= e.w); }
    // Overload the > operator
    bool operator>(const Edge &e) const
    {return (w > e.w);}
    // Overload the >= operator
    bool operator>=(const Edge &e) const
    {return (w >= e.w);}

}; // end of class Edge declaration


#endif //ASSIGNMENT_5_EDGE_H
