//
// Created by teodor on 12/13/17.
//

#include "SqSort.h"
#include "CmpUnit.h"
using namespace std;

template <class S_Type>
void SqSort<S_Type>::insertionSort(S_Type* arr, int left, int right)
{
    int i, j;
    S_Type key;
    for (i = left; i < right; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

template <class S_Type>
void SqSort<S_Type>::heapify(S_Type* arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <class S_Type>
void SqSort<S_Type>::heapSort(S_Type* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template <class S_Type>
void SqSort<S_Type>::merge(S_Type* arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    S_Type L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        //if (userFunc(&L[i], &R[j]) < 0)
        //cout << "CMP " << L[i]->count << endl;
        /*if (*L[i] < *L[0]){

        }*/
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


template <class S_Type>
void SqSort<S_Type>::mergeSort(S_Type* arr, int l, int r)
{
    if (l < r)
    {
        // Just to avoid overflow l+(r-l)
        int m = l+(r-l)/2;

        /*if (m - l < 50){
            heapSort(arr, m - l);
        } else {
            mergeSort(arr, l, m);
        }*/

        /*if (m - l < 50){
            insertionSort(arr, l, m);
        } else {
            mergeSort(arr, l, m);
        }*/
        mergeSort(arr, l, m);

        /*if (r - m < 5000){
            heapSort(arr, m+1);
        } else {
            mergeSort(arr, m+1, r);
        }*/

        /*if (r - m < 50){
            insertionSort(arr, m+1, r);
        } else {
            mergeSort(arr, m+1, r);
        }*/
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

template <class S_Type>
void SqSort<S_Type>::sqSort (S_Type* array, int count)
{
    mergeSort(array, 0, count-1);
}

template <class S_Type>
void SqSort<S_Type>::printArray(const S_Type* array, const int count){
    /*for (int i = 0; i < count; i++)
        cout << array[i] << ", ";
    cout << endl;*/
}

template class SqSort<int>;
template class SqSort<float>;
template class SqSort<long>;
template class SqSort<const char*>;
template class SqSort<double>;
template class SqSort<long long>;
template class SqSort<CmpUnit>;
