//
// Created by Haya on 11/27/2023.
//

#ifndef ASSIGNMENT_5_NODE_H
#define ASSIGNMENT_5_NODE_H

#include <iostream>
using namespace std;

class Node{
public:
    string getDate(){return date;}
    double getRate(){return rate;}

    void setDate(string d){date = d;}
    void setRate(double r){rate = r;}

private:
    string date;
    double rate;
};

#endif //ASSIGNMENT_5_NODE_H
