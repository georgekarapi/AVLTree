#ifndef HASHTABLE_H
#define HASHTABLE_H


class hashtable {
public:
    hashtable();

    virtual ~hashtable();

    int getCapacity() { return cap; }

    int setsize() { return n; }

    void insert(int);

    int hash(int);

    int searchkey(int);

    void deletekey(int);

protected:

private:
    int *data;
    bool *a; //availability
    int cap, n;

    void doublec(); // double capacity
};

#endif // HASHTABLE_H
