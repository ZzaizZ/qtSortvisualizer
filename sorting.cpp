#include "sorting.h"
#include "sorts.cpp"

Sorting::Sorting(int *array, uint64_t len)
{
    init(array, len);
}

Sorting::~Sorting()
{}

bool Sorting::sorted()
{
    return finished;
}

void Sorting::init(int *array, uint64_t len)
{
    this->array = array;
    length = len;
    finished = false;
}

BubbleSort::BubbleSort(int *array, uint64_t len):
    Sorting(array, len)
{
    I = 0; J = 0;
}

BubbleSort::~BubbleSort()
{}

void BubbleSort::sort()
{
    bubble_sort(array, length);
}

void BubbleSort::step()
{
    if (finished)
        return;
    if (array[J] > array[J+1])
        swaP(array[J], array[J+1]);
    J++;
    if (J >= length - 1 - I)
    {
        J = 0;
        I++;
    }
    if (I >= length)
        finished = true;
}

InsertionSort::InsertionSort(int *array, uint64_t len):
    Sorting (array, len)
{
    I = 1; J = I;
    finished = false;
}

InsertionSort::~InsertionSort()
{}

void InsertionSort::sort()
{
    insertion_sort(array, length);
}

void InsertionSort::step()
{
    if (finished)
        return;
    if (I < length)
    {
        if (J > 0 && array[J-1] > array[J])
        {
            swaP(array[J], array[J-1]);
            J--;
        }
        else
        {
            I++;
            J = I;
        }
    }
    else
        finished = true;
}

SelectionSort::SelectionSort(int *array, uint64_t len):
    Sorting (array, len)
{
    I = 0;
    J = I + 1;
    min = I;
    finished = false;
}

SelectionSort::~SelectionSort()
{}

void SelectionSort::sort()
{
    selection_sort(array, length);
}

void SelectionSort::step()
{
    if (finished)
        return;
    if (array[J] < array[min])
        min = J;
    J++;
    if (J >= length)
    {
        swaP(array[I], array[min]);
        I++;
        min = I;
        J = I;
    }
    if (I >= length - 1)
        finished = true;
}

