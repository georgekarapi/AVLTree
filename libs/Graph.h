//
// Created by giorgos on 21/6/2019.
//

#ifndef BINARYTREE_GRAPH_H
#define BINARYTREE_GRAPH_H

#endif //BINARYTREE_GRAPH_H

#include <vector>

using namespace std;

struct Edge{
    int value;
    vector<Edge *> neighbors;
};

class Graph{
private:
    vector<Edge *> edges;

    int search(vector<int> arr, int value);

    int search(vector<Edge *> arr, int value);

    bool exists(vector<Edge *> path, Edge *el);
public:
    int addEdge(int x, int y);
    int removeEdge(int x, int y);
    void print();
    void getSize();

    void mst();
};