#ifndef SORTING_H
#define SORTING_H

#include <QObject>

class Sorting
{
public:
    Sorting(int *array, uint64_t len);
    virtual ~Sorting();
    void init(int *array, uint64_t len);
    bool sorted();
    virtual void step() = 0;
    virtual void sort() = 0;
protected:
    int *array;
    uint64_t length;
    bool finished;
    uint64_t I, J;
};

class BubbleSort : public Sorting
{
public:
    BubbleSort(int *array, uint64_t len);
    ~BubbleSort();
    void step();
    void sort();
};

class InsertionSort : public Sorting
{
public:
    InsertionSort(int *array, uint64_t len);
    ~InsertionSort();
    void step();
    void sort();
};

class SelectionSort : public Sorting
{
public:
    SelectionSort(int *array, uint64_t len);
    ~SelectionSort();
    void step();
    void sort();
private:
    uint64_t min;
};

#endif // SORTING_H
