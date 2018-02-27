//
// Created by teodor on 12/13/17.
//

#ifndef SUPERQUICKSORT_SQSORT_H
#define SUPERQUICKSORT_SQSORT_H

#include <iostream>
#include "CmpUnit.h"

template <class S_Type> class SqSort {
public:
    // Passing pointer to function is too slow :(
    //explicit SqSort(int (*f)(const void * a, const void * b)): userFunc(f){};
    void sqSort(S_Type* data, int size);
    void printArray(const S_Type* array, int count);
    //int (*userFunc)(const void *, const void *);
    void heapSort(S_Type* arr, int n);
    void insertionSort(S_Type* arr, int left, int right);

private:
    void mergeSort(S_Type* data, int l, int r);
    void merge(S_Type* data, int l, int m, int r);
    void heapify(S_Type* arr, int n, int i);
};


#endif //SUPERQUICKSORT_SQSORT_H
