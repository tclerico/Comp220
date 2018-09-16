//
// Created by Toby Dragon on 8/26/17.
//
#include <iostream>
#include "TestLib.h"
#include "ArrayLib.h"

void printAssertEquals(int expected, int actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}

void printAssertCloseToEqual(float expected, float actual, float errorMargin ){
    float diff = expected - actual;
    if ( diff <= errorMargin && diff >= -errorMargin){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\t not close to actual: " << actual << std::endl;
    }
}

void printAssertArrayEqual(int* a1, int *a2, int size){
    int failCount = 0;
    for (int i=0; i<size; i++){
        if (a1[i] != a2[i]) {
            failCount++;
        }
    }
    if (failCount <=0){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, failCount: " << failCount << std::endl;
    }
}

void printAssertStringEqual(std::string expected, std::string actual){
    if (expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "actual: " << actual << std::endl;
    }
}

bool checkSorted(int* a, int size){
    int failCount = 0;
    for (int i=0; i<size-1; i++){
        if (a[i] > a[i+1]) {
            failCount++;
        }
    }
    return failCount == 0;
}

int countOccurrences(const int* a1, int size, int itemToCount){
    //return the number of times itemToCount occurs in a1
    int total = 0;
    for (int i=0; i< size; i++) {
        if (a1[i] == itemToCount) {
            total++;
        }
    }
    return total;
}

bool checkForSameElements(const int* a1, const int *a2, int size){
    //check that the same number of each element exists using countOccurrences on every element from one array on the other
    //check everything in a1 exists in a2
    for (int i=0; i<size; i++) {
        if ((countOccurrences(a1, size, a1[i])) != countOccurrences(a2, size, a1[i])) {
            std::cout << "Error: element: " << a1[i] << " not found in both lists\n";
            return false;
        }
    }
    //edge case: a2 may contain things that are not in a1
    //so check everything in a2
    for (int i=0; i<size; i++) {
        if ((countOccurrences(a1, size, a2[i])) != countOccurrences(a2, size, a2[i])) {
            std::cout << "Error: element: " << a1[i] << " not found in both lists\n";
            return false;
        }
    }
    return true;
}

void sortTest(){
    std::cout << "mergeSortTest" << std::endl;
    int timer = 0;
    int junkTimer = 0;
    //loop several times to get different lengths
    for (int i = 1; i < 100; i++) {
        //generate random array of length i
        int* arr1 = genRandArray(i,0,i,timer);
        //copy it
        int* arr2 = copyArray(arr1,i, junkTimer);
        //sort it
        int* merged = mergeSort(arr2,i,timer);
        //call checkSorted on it
        if (checkSorted(merged, i)) {
            if (checkForSameElements(arr1, merged, i)) {
                std::cout << "Pass\n";
            }
            else {
                std::cout <<"Fail, Arrays contain different elements! Size = " << i << toString(arr1, i) << toString(merged, i)<<  std::endl;
            }
        }
        else {
            std::cout <<"Failed: Not sorted for size = " << i << toString(merged, i)<<  std::endl;
        }
        delete[] arr1;
        delete[] arr2;
    }
}

int main(){
    srand(time(NULL));
    sortTest();

}