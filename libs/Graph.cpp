//
// Created by giorgos on 21/6/2019.
//
#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;

int Graph::searchEdge(int edge) {
    for(int i = 0; i < graphTable.size(); i++) {
        if(graphTable[i].value == edge) {
            return i;
        }
    }
    return -1;
}

int Graph::searchLink(int edge, int link) {
    for(int i = 0; i < graphTable[edge].links.size(); i++) {
        if(graphTable[edge].links[i] == link) {
            return i;
        }
    }
    return -1;
}

int Graph::addEdge(int x, int y) {
    int edgeLink =  searchEdge(x);
    if(edgeLink == -1) {
        Edge newEdge,newEdge2;
        newEdge.value = x;
        newEdge.links.push_back(y);
        graphTable.push_back(newEdge);
        newEdge2.value = y;
        newEdge2.links.push_back(x);
        graphTable.push_back(newEdge2);
        return 1;
    }
    if(searchLink(edgeLink, y) == -1) {
        graphTable[edgeLink].links.push_back(y);
        if(searchEdge(y) == -1) {
            Edge edg;
            edg.value = y;
            edg.links.push_back(x);
            graphTable.push_back(edg);
        }
        return 1;
    }
    return 0;
}

int Graph::removeEdge(int x, int y) {
    int edgeLink =  searchEdge(x);
    if(edgeLink != -1) {
        int link = searchLink(edgeLink, y);
        if(link != -1) {
            graphTable[edgeLink].links.erase(graphTable[edgeLink].links.begin() + link);
            if(graphTable[edgeLink].links.size() <= 0) {
                graphTable.erase(graphTable.begin() + edgeLink);
            }
        }
    }
}

void Graph::print() {
    for(int i = 0; i < graphTable.size(); i++) {
        for(int j = 0; j < graphTable[i].links.size(); j++) {
            cout << "X: " << graphTable[i].value << " Y: " << graphTable[i].links[j] << endl;
        }
    }
}

void Graph::getSize() {
//    for(int i = 0; i < graphTable.size(); i++) {
//        cout << ": " << graphTable[i].value << " Y: " << graphTable[i].links[j] << endl;
//    }
}