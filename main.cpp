#include <iostream>
#include "headers/tree.h"

#include "libs/Graph.h"
#include "libs/hashtable.h"
#include "libs/minheap.h"
#include "libs/maxheap.h"
using namespace std;

int main() {
    Graph graph;
    graph.addEdge(2, 2);
    graph.print();
    return 0;
}