#include <iostream>
#include "headers/tree.h"

#include "libs/Graph.h"
using namespace std;

int main() {
    Graph graph;
    graph.addEdge(1,2);
    graph.addEdge(2,0);

    graph.addEdge(2,1);
    graph.addEdge(2,1);
    graph.addEdge(2,1);
    graph.addEdge(2,1);
    graph.addEdge(2,0);
    graph.addEdge(0,1);
    graph.print();
    return 0;
}