#include "hashtable.h"

hashtable::hashtable() {
    n = 0;
    cap = 100;
    data = new int[cap];
    a = new bool[cap];
    int i;
    for (i = 0; i < cap; i++) a[i] = true;
}

hashtable::~hashtable() {
    delete[] data;
    delete[] a;
}

int hashtable::hash(int val) {
    return ((cap - 50) * val + cap - 30) % cap;
}

void hashtable::doublec() {
    cap *= 2;
    bool *b = new bool[cap];
    int *d = new int[cap];
    int i;
    for (i = 0; i < cap; i++) b[i] = true;
    for (i = 0; i < cap / 2; i++) {
        if (!a[i]) {
            int h = hash(data[i]);
            while (!b[h]) {
                h++;
                if (h == cap) h = 0;
            }
            d[h] = data[i];
            b[h] = false;
        }
    }
    delete[] data;
    delete[] a;
    data = d;
    a = b;
}

void hashtable::insert(int val) {
    int h = hash(val);
    while (!a[h]) {
        h++;
        if (h == cap) h = 0; // cycles
    }
    data[h] = val;
    n++;
    a[h] = false;
    if (n > cap / 2) doublec();
}

int hashtable::searchkey(int key) {
    int h = hash(key);
    do {
        if (data[h] == key) return h;
        h++;
        if (h == cap) h = 0;
    } while (!a[h]);
    return -1;
}

void hashtable::deletekey(int key) {
    int x = searchkey(key);
    if (x != -1) a[x] = true;
}
