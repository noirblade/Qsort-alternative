#include <iostream>
#include <cstring>
#include "SqSort.h"
#include "CmpUnit.h"
#include <random>
#include <iomanip>
#include <chrono>
using namespace std;

#define INT_TEST_NUMBERS 50000

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
default_random_engine generator(seed);

int getRandomInt(){
    uniform_int_distribution<int> distribution(-500,500);
    return distribution(generator);
}

float getRandomFloat(){
    uniform_real_distribution<float> distribution(-500,500);
    return distribution(generator);
}

// Comparing functions
//int countCmpInt = 0;
int compareInt (const void * a, const void * b)
{
    //countCmpInt++;
    return ( *(int*)a - *(int*)b );
}

int compareFloat (const void * a, const void * b)
{
    float fa = *(const float*) a;
    float fb = *(const float*) b;
    return (fa > fb) - (fa < fb);
}

int compareString (const void * a, const void * b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
}

int compareObject (const void * a, const void * b)
{
    //const CmpUnit *ca = reinterpret_cast<const CmpUnit *>(a);
    //const CmpUnit *cb = reinterpret_cast<const CmpUnit *>(b);

    const CmpUnit *ca = (CmpUnit*) a;
    const CmpUnit *cb = (CmpUnit*) b;

    cout << "Cmp obj " << ca->count << endl;
    return ca->count - cb->count;
}
//////

// Integer test
void intTest(int numbers[]){

    //SqSort <int>sqSort(compareInt);
    SqSort <int>sqSort;

    cout << "_________________________" << endl;
    cout << "Integer test start" << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

    auto t0 = chrono::high_resolution_clock::now();
    sqSort.sqSort(numbers, INT_TEST_NUMBERS);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

}

void intHeapTest(int numbers[]){

    //SqSort <int>sqSort(compareInt);
    SqSort <int>sqSort;

    cout << "_________________________" << endl;
    cout << "Integer heap test start" << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

    auto t0 = chrono::high_resolution_clock::now();
    sqSort.heapSort(numbers, INT_TEST_NUMBERS);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

}

void insertionSortTest(int numbers[]){

    //SqSort <int>sqSort(compareInt);
    SqSort <int>sqSort;

    cout << "_________________________" << endl;
    cout << "Integer insertion test start" << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

    auto t0 = chrono::high_resolution_clock::now();
    sqSort.insertionSort(numbers, 0, INT_TEST_NUMBERS);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

}

void intTestQsort(int numbers []){

    cout << "SQ: Integer test start" << endl;
    auto t0 = chrono::high_resolution_clock::now();
    qsort(numbers, INT_TEST_NUMBERS, sizeof(int), compareInt);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;

    //SqSort <int> sqSort(compareInt);
    SqSort <int> sqSort;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);
    cout << "_________________________" << endl;
}

////


// Char test
void charTest(){
    const char *charData[6] = {
            "cbb",
            "aba",
            "cccccc",
            "bbbbbb",
            "ffffff",
            "aaaaaa"
    };

    //SqSort <const char*>sqSort(compareString);
    SqSort <const char*>sqSort;

    cout << "String test start" << endl;
    sqSort.printArray(charData, 6);
    sqSort.sqSort(charData, 6);
    sqSort.printArray(charData, 6);
    cout << "_________________________" << endl;
}

void charTestQsort(){
    const char *charData[6] = {
            "cbb",
            "aba",
            "cccccc",
            "bbbbbb",
            "ffffff",
            "aaaaaa"
    };

    //SqSort <const char*>sqSort(compareString);
    SqSort <const char*>sqSort;

    cout << "SQ: String test start" << endl;
    qsort(charData, 6, sizeof(char*), compareString);
    sqSort.printArray(charData, 6);
    cout << "_________________________" << endl;

}
////

// Float test
void floatTest(float numbers[]){
    //SqSort <float>sqSort(compareFloat);
    SqSort <float>sqSort;
    cout << "_________________________" << endl;
    cout << "Float test start" << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

    auto t0 = chrono::high_resolution_clock::now();
    sqSort.sqSort(numbers, INT_TEST_NUMBERS);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

}

void floatHeapTest(float numbers[]){
    //SqSort <float>sqSort(compareFloat);
    SqSort <float>sqSort;
    cout << "_________________________" << endl;
    cout << "Float heap sort test start" << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

    auto t0 = chrono::high_resolution_clock::now();
    sqSort.heapSort(numbers, INT_TEST_NUMBERS);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

}

void floatInsertionTest(float numbers[]){
    //SqSort <float>sqSort(compareFloat);
    SqSort <float>sqSort;
    cout << "_________________________" << endl;
    cout << "Float insertion sort test start" << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

    auto t0 = chrono::high_resolution_clock::now();
    sqSort.insertionSort(numbers, 0, INT_TEST_NUMBERS);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);

}

void floatTestQsort(float numbers[]){
    auto t0 = chrono::high_resolution_clock::now();
    qsort(numbers, INT_TEST_NUMBERS, sizeof(float), compareFloat);
    auto t1 = chrono::high_resolution_clock::now();
    cout << "Time: " << chrono::duration_cast<chrono::microseconds>(t1 - t0).count() << endl;
    //SqSort <float> sqSort(compareFloat);
    SqSort <float> sqSort;
    cout << "SQ: Float test start" << endl;
    sqSort.printArray(numbers, INT_TEST_NUMBERS);
    cout << "_________________________" << endl;

}
////

/// Object test
void objectTest(){
    CmpUnit units[6] = {
             CmpUnit(),
             CmpUnit(),
             CmpUnit(),
             CmpUnit(),
             CmpUnit(),
             CmpUnit()
    };

    for (int i = 0; i < 6; i++){
        units[i].count = getRandomInt();
    }

    //SqSort <CmpUnit*>sqSort(compareObject);
    SqSort <CmpUnit>sqSort;
    sqSort.printArray(units, 6);
    cout << "Object test start" << endl;
    sqSort.sqSort(units, 6);

    sqSort.printArray(units, 6);
    //delete [] units;
    cout << "_________________________" << endl;
}

void objectHeapTest(){
    CmpUnit units[6] = {
            CmpUnit(),
            CmpUnit(),
            CmpUnit(),
            CmpUnit(),
            CmpUnit(),
            CmpUnit()
    };

    for (int i = 0; i < 6; i++){
        units[i].count = getRandomInt();
    }

    //SqSort <CmpUnit*>sqSort(compareObject);
    SqSort <CmpUnit>sqSort;
    sqSort.printArray(units, 6);
    cout << "Object heap test start" << endl;
    sqSort.heapSort(units, 6);

    sqSort.printArray(units, 6);
    //delete [] units;
    cout << "_________________________" << endl;
}

void objectInsertionTest(){
    CmpUnit units[6] = {
            CmpUnit(),
            CmpUnit(),
            CmpUnit(),
            CmpUnit(),
            CmpUnit(),
            CmpUnit()
    };

    for (int i = 0; i < 6; i++){
        units[i].count = getRandomInt();
    }

    //SqSort <CmpUnit*>sqSort(compareObject);
    SqSort <CmpUnit>sqSort;

    sqSort.printArray(units, 6);

    cout << "Object insertion test start" << endl;
    sqSort.insertionSort(units, 0, 6);

    sqSort.printArray(units, 6);
    //delete [] units;
    cout << "_________________________" << endl;
}

////

int main() {

    int numbers[INT_TEST_NUMBERS];
    for (int i = 0; i < INT_TEST_NUMBERS; i++){
        numbers[i] = getRandomInt();
    }
    int qNumbers[INT_TEST_NUMBERS];
    copy(begin(numbers), end(numbers), begin(qNumbers));
    int hNumbers[INT_TEST_NUMBERS];
    copy(begin(numbers), end(numbers), begin(hNumbers));
    int iNumbers[INT_TEST_NUMBERS];
    copy(begin(numbers), end(numbers), begin(iNumbers));

    // For unsorted numbers heap sort looks like fastest without optimization [50000 items ~ 24684ms] with -O2 [50000 items ~ 4751ms]
    intHeapTest(hNumbers);
    // For unsorted numbers insertionSort is veeeery bad [50000 items ~ 1945644ms] with -O2 [50000 items ~ 414903ms]
    insertionSortTest(iNumbers);

    // For unsorted numbers mergeSort is [50000 items ~ 10326ms] with -O2 [50000 items ~ 4768ms]
    // Merge sort combined with insertion sort when the array become smaller doesn't give me a better results. See SqSort::mergeSort() line 121
    intTest(numbers);
    //cout << "cmp int calls " << countCmpInt << endl;
    //countCmpInt = 0;
    // For unsorted numbers std::qsort is [50000 items ~ 6316ms] with -O2 [50000 items ~ 5262ms]
    intTestQsort(qNumbers);
    //cout << "cmp int calls " << countCmpInt << endl;


    // Test sorted
    // Sorted heap test is [50000 items ~ 18154ms] with -O2 [50000 items ~ 4110ms]
    intHeapTest(numbers);

    // For sorted numbers insertionSort rocks
    // Sorted insertion test is [50000 items ~ 253ms] with -O2 [50000 items ~ 114ms]
    insertionSortTest(numbers);

    // Sorted merge test is [50000 items ~ 6899ms] with -O2 [50000 items ~ 1686ms]
    intTest(numbers);

    // Sorted std::qsort test is [50000 items ~ 1585ms] with -O2 [50000 items ~ 1541ms]
    intTestQsort(qNumbers);

    // Floats tests follow the same rates as integers
    float numbersFloat[INT_TEST_NUMBERS];
    for (int i = 0; i < INT_TEST_NUMBERS; i++){
        numbersFloat[i] = getRandomFloat();
    }
    float qlNumbers[INT_TEST_NUMBERS];
    copy(begin(numbersFloat), end(numbersFloat), begin(qlNumbers));
    float hlNumbers[INT_TEST_NUMBERS];
    copy(begin(numbersFloat), end(numbersFloat), begin(hlNumbers));
    float ilNumbers[INT_TEST_NUMBERS];
    copy(begin(numbersFloat), end(numbersFloat), begin(ilNumbers));

    floatHeapTest(hlNumbers);
    floatInsertionTest(ilNumbers);
    floatTest(numbersFloat);
    floatTestQsort(qlNumbers);

    // Test sorted
    floatHeapTest(numbersFloat);
    floatInsertionTest(numbersFloat);
    floatTest(numbersFloat);
    floatTestQsort(numbersFloat);

    /*
     * How to overload < operator for char * !!?
    charTest();
    charTestQsort();
     */

    objectTest();
    objectHeapTest();
    objectInsertionTest();
    return 0;
}