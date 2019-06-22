#ifndef MAXHEAP_H
#define MAXHEAP_H


class maxheap {
public:
    maxheap();

    virtual ~maxheap();

    unsigned int Getnofelements() { return nofelements; }

    void Setnofelements(unsigned int val) { nofelements = val; }

    void SetHeight(int val) { height = val; }

    int GetHeight() { return height; }

    void IncNoe(); //Increases the number of elements
    void DecNoe(); //Decreases the number of elements
    int max() { return A[0]; }

    void insert(int);

    void deletemax();

    int *A;

protected:

private:
    int height;
    unsigned int nofelements;
};

#endif // MAXHEAP_H
