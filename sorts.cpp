#include <stdio.h>
#include <stdint.h>

#include "mainwidget.h"

template <class T>
void copy(T target[], T source[], uint64_t source_len)
{
    for (uint64_t i = 0; i < source_len; i++)
        target[i] = source[i];
}

template <class T>
void swaP(T &a, T &b)
{
    T c;
    c = a;
    a = b;
    b = c;
}

template <class T>
void shuffle_array(T array[], uint64_t len)
{
    srand(time(0));
    for (uint64_t i = 0; i < len; i++)
    {
        uint64_t rand_index_1 = static_cast<uint64_t>(rand()) % len;
        uint64_t rand_index_2 = static_cast<uint64_t>(rand()) % len;
        swaP(array[rand_index_1], array[rand_index_2]);
    }
}

template <class T>
void bubble_sort(T array[], uint64_t len)
{
    for (uint64_t i = 0; i < len; i++)
        for (uint64_t j = 0; j < len - 1 - i; j++)
            if (array[j] > array[j+1])
                swaP(array[j], array[j+1]);
}

template <class T>
void insertion_sort(T array[], uint64_t len)
{
    for (uint64_t i = 1; i < len; i++)
        for (uint64_t j = i; j > 0 && array[j-1] > array[j]; j--)
            swaP(array[j-1], array[j]);
}

template <class T>
void selection_sort(T array[], uint64_t len)
{
    for (uint64_t i = 0; i < len - 1; i++)
    {
        uint64_t min = i;
        for (uint64_t j = i+1; j < len; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        swaP(array[i], array[min]);
    }
}

// TODO: quicksort и merge sort

