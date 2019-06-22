#include "maxheap.h"

maxheap::maxheap() {
    Setnofelements(0);
    SetHeight(0);
}

maxheap::~maxheap() {
    //dtor
}

void maxheap::IncNoe() {
    Setnofelements(Getnofelements() + 1);
}

void maxheap::DecNoe() {
    Setnofelements(Getnofelements() - 1);
}

void maxheap::insert(int val) {

    int i, cap = 2;
    for (i = 0; i < GetHeight(); i++) {
        cap *= 2;
    }
    cap--;
    if (Getnofelements() < cap) {
        A[Getnofelements()] = val;
        i = Getnofelements();
        int parent = (i - 1) / 2;
        bool flag = A[parent] < A[i];
        while (flag) {
            int temp = A[i];
            A[i] = A[parent];
            A[parent] = temp;
            i = parent;
            parent = (i - 1) / 2;
            flag = A[parent] < A[i];
        }
    } else {
        SetHeight(GetHeight() + 1);
        int *B;
        B = new int[cap * 2];
        for (i = 0; i < Getnofelements(); i++) {
            B[i] = A[i];
        }
        B[i] = val;
        delete[] A;
        A = B;
        int parent = (i - 1) / 2;
        bool flag = A[parent] < A[i];
        while (flag) {
            int temp = A[i];
            A[i] = A[parent];
            A[parent] = temp;
            i = parent;
            parent = (i - 1) / 2;
            flag = A[parent] < A[i];
        }
    }
    IncNoe();
}

void maxheap::deletemax() {
    int i, key = 0;
    for (i = 0; i < GetHeight(); i++) {
        A[key] = A[2 * key + 1] > A[2 * key + 2] ? A[2 * key + 1] : A[2 * key + 2];
        key = A[2 * key + 1] > A[2 * key + 2] ? 2 * key + 1 : 2 * key + 2;
    }
    A[key] = A[Getnofelements() - 1];
    DecNoe();
}
