//
// Created by giorgos on 21/6/2019.
//

#ifndef BINARYTREE_GRAPH_H
#define BINARYTREE_GRAPH_H

#endif //BINARYTREE_GRAPH_H

#include <vector>

struct Edge{
    int value;
    std::vector<int> links;
};

class Graph{
private:
    std::vector<Edge> graphTable;
    int searchEdge(int edge);
    int searchLink(int edge, int link);
public:
    int addEdge(int x, int y);
    int removeEdge(int x, int y);
    void print();
    void getSize();
};