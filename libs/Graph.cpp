//
// Created by giorgos on 21/6/2019.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "Graph.h"
using namespace std;

int Graph::search(vector<int> arr, int value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int Graph::search(vector<Edge *> arr, int value) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]->value == value) {
            return i;
        }
    }
    return -1;
}

int Graph::addEdge(int x, int y) {
    Edge *edgeX, *edgeY;
    int linkX = search(edges, x);
    int linkY = search(edges, y);

    // X Edge does not exist
    if (linkX == -1) {
        edgeX = new Edge;
        edgeX->value = x;
        edges.push_back(edgeX);
    } else {
        edgeX = edges[linkX];
    }

    // Y Edge does not exist
    if (linkY == -1) {
        edgeY = new Edge;
        edgeY->value = y;
        edges.push_back(edgeY);
    } else {
        edgeY = edges[linkY];
    }

    linkY = search(edgeX->neighbors, y);
    if (linkY == -1) {
        edgeX->neighbors.push_back(edgeY);
    }

    if (x == y) {
        return 0;
    }

    linkX = search(edgeY->neighbors, x);
    if (linkX == -1) {
        edgeY->neighbors.push_back(edgeX);
    }
}

int Graph::removeEdge(int x, int y) {
    Edge *edgeX, *edgeY;
    int linkX = search(edges, x);
    int linkY = search(edges, y);
    int temp;

    // X Edge exists
    if (linkX != -1) {
        edgeX = edges[linkX];

        temp = search(edgeX->neighbors, y);
        if (temp != -1) {
            edgeX->neighbors.erase(edgeX->neighbors.begin() + temp);
        }
    }

    // Y Edge exists
    if (linkY != -1) {
        edgeY = edges[linkY];

        temp = search(edgeY->neighbors, x);
        if (temp != -1) {
            edgeY->neighbors.erase(edgeY->neighbors.begin() + temp);
        }
    }
}

bool Graph::exists(vector<Edge *> path, Edge *el) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == el) {
            return true;
        }
    }
    return false;
}

void Graph::mst() {
    bool flag = false;
    vector<Edge *> path;
    int index = 0;
    while (index < edges.size()) {
        for (int i = 0; i < edges[index]->neighbors.size(); i++) {
            if (!exists(path, edges[index]->neighbors[i])) {
                path.push_back(edges[index]->neighbors[i]);
            }
        }
        index++;
    }
}

void Graph::print() {
    for (int i = 0; i < edges.size(); i++) {
        for (int j = 0; j < edges[i]->neighbors.size(); j++) {
            cout << "X: " << edges[i]->value << " Y: " << edges[i]->neighbors[j]->value << endl;
        }
    }
}