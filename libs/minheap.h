#ifndef MINHEAP_H
#define MINHEAP_H


class minheap {
public:
    minheap();

    virtual ~minheap();

    unsigned int Getnofelements() { return nofelements; }

    void Setnofelements(unsigned int val) { nofelements = val; }

    void SetHeight(int val) { height = val; }

    int GetHeight() { return height; }

    void IncNoe(); //Increases the number of elements
    void DecNoe(); //Decreases the number of elements
    int min() { return A[0]; }

    void insert(int x);

    void deletemin();

    int *A;

protected:

private:

    int height;
    unsigned int nofelements;
};

#endif // MINHEAP_H
