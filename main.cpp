#include <iostream>
#include "headers/tree.h"
using namespace std;

int main() {
    Tree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    tree.insert(7);
    tree.del(20);
    cout << tree.root->value << endl;
    //tree.print();
    return 0;
}