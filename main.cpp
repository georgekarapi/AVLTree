#include <iostream>
#include "headers/tree.h"
using namespace std;

int main() {
    Tree tree;
    tree.insert(12);
    tree.insert(8);
    tree.insert(20);
    tree.insert(3);
    tree.insert(9);
    tree.insert(7);
    tree.insert(9);
    tree.print();
    cout  << "new" << endl;
    tree.del(10);
    tree.del(20);
    tree.print();
    return 0;
}