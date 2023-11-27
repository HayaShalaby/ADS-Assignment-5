//
// Created by Haya on 11/27/2023.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

const double M = 1.2345;

//read the file into a max heap
//for N most positive loop for N using level order traversal on max heap
//read the file into a min heap
//for N most negative loop for N using level order traversal on min heap
//change rate to rate change because it is the change from M, if greater than M then +ve, otherwise -ve (multiply rate by -1)

//level order traversal for both min and max heaps
template <typename T>
vector<Node> levelOrderTraversal(const T* heap, int limit) {
    vector<Node> traversedNodes;  // Container to store nodes
    if (heap->getN() == 0 || limit <= 0) {
        cout << "Invalid limit or heap is empty." << endl;
        return traversedNodes;
    }

    queue<int> indices;
    indices.push(1);  // Start from the root (index 1 in the array)
    int nodesProcessed = 0;  // Counter for the number of nodes processed

    while (!indices.empty() && nodesProcessed < limit) {
        int currentIndex = indices.front();
        indices.pop();

        // Process the current element
        traversedNodes.push_back(heap->a[currentIndex]);

        // Increment the counter
        nodesProcessed++;

        // Calculate indices of left and right children
        int leftChildIndex = 2 * currentIndex;
        int rightChildIndex = 2 * currentIndex + 1;

        // Enqueue left child if it exists
        if (leftChildIndex <= heap->getN()) {
            indices.push(leftChildIndex);
        }

        // Enqueue right child if it exists
        if (rightChildIndex <= heap->getN()) {
            indices.push(rightChildIndex);
        }
    }

    return traversedNodes;
}

int main() {
    int N;
    string line;

    cout << "Enter the amount of exchange rate changes (positive or negative) that you'd like to get the dates for:"
         << endl;
    cin >> N;

    ifstream file("exchange rates.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    MinHeap minHeap(INT_MAX); //creating minimum heap
    MaxHeap maxHeap(INT_MAX); //creating maximum heap
    while (!file.eof()) { //reading the rates & dates into the heap
        getline(file, line);
        stringstream ss(line);
        string date, eRate;

        getline(ss, date, ',');
        getline(ss, eRate, ',');

        double rate = stod(eRate);
        if (rate < M) //negative change
            rate = rate * -1.0;

        Edge e;
        e.u.setDate(date);
        e.u.setRate(rate);

        getline(file, line);
        stringstream ss2(line);
        string date2, eRate2;

        getline(ss2, date2, ',');
        getline(ss2, eRate2, ',');

        double rate2 = stod(eRate2);
        if (rate2 < M) //negative change
            rate2 = rate2 * -1.0;

        e.v.setDate(date2);
        e.v.setRate(rate2);

        minHeap.insert(e);
        maxHeap.insert(e);
    }

    vector<Node> nodesTraversed = levelOrderTraversal(&minHeap, N);

    return 0;
}