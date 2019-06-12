#include <iostream>
#include "headers/tree.h"
using namespace std;

int main() {
    Tree tree;
    tree.insert(14);
    tree.insert(16);
    tree.insert(20);
    tree.insert(9);
    tree.insert(15);
    tree.insert(19);
    cout << tree.root->value << endl;
    //tree.print();
    return 0;
}