//
// Created by Toby Dragon on 9/2/16.
//

#include <iostream>
#include "ArrayLib.h"
#include "TestLib.h"

void toStringTest(){
    std::cout << "toStringTest" << std::endl;
    int a1[] = {1, 2, 3, 4};
    printAssertStringEqual("{1, 2, 3, 4}", toString(a1, 4));
    int a2[] = {1};
    printAssertStringEqual("{1}", toString(a2, 1));
    int a3[] = {121, 432, 53, 4, 96, 3684};
    printAssertStringEqual("{121, 432, 53, 4, 96, 3684}", toString(a3, 6));
    printAssertStringEqual("{}", toString(a3, 0));
}

void findTest(){
    std::cout << "findTest" << std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (i != find(a1, 10, a1[i])){
            failCount++;
        }
    }
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }

    int a2[]={10, 20, 3, 22, 2, 33, 3, 9, 3, 2};
    printAssertEquals(2, find(a2, 10, 3));
    printAssertEquals(-1, find(a2, 10, 500));
    printAssertEquals(-1, find(a2, 0, 10));
}

void findLastTest(){
    std::cout << "findLastTest" << std::endl;
    int a1[]={1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int failCount = 0;
    for (int i=0; i< 10; i++){
        if (i != findLast(a1, 10, a1[i])){
            failCount++;
        }
    }
    if (failCount <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, fail count:" << failCount << std::endl;
    }

    int a2[]={10, 20, 3, 22, 2, 33, 3, 9, 3, 2};
    printAssertEquals(8, findLast(a2, 10, 3));
    printAssertEquals(-1, findLast(a2, 10, 500));
    printAssertEquals(-1, findLast(a2, 0, 10));
}

void genRandArrayTest(int low, int high){
    int countSize = high-low+1;
    int* randCounts = new int [countSize]{};
    int outCount=0;
    int linesRun = 0;

    int* randArray = genRandArray(countSize*100, low, high, &linesRun);
    for (int i=0; i<countSize*100; i++){
        int num = randArray[i];
        num = num - low;
        if (num >= countSize){
            outCount++;
        }
        else {
            randCounts[num]++;
        }
    }
    delete[] randArray;
    randArray = nullptr;

    bool allPresent = true;
    for (int i=0; i<countSize; i++){
        if (randCounts[i]<=0){
            allPresent = false;
        }
    }
    delete[] randCounts;
    randCounts = nullptr;

    if (allPresent && outCount == 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, allPresent:" << allPresent << ", outCount:" << outCount << std::endl;
    }
}

void genRandArrayTest(){
    std::cout << "genRandArrayTest" << std::endl;
    int linesRun = 0;
    //print some random arrays to make sure they look right
    int* rands = genRandArray(15, 20, 25, &linesRun);
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = genRandArray(15, -3, 3, &linesRun);
    std::cout << toString(rands, 15) << std::endl;
    delete[] rands;
    rands = nullptr;

    genRandArrayTest(0, 10);
    genRandArrayTest(1, 5);
    genRandArrayTest(50, 60);
    genRandArrayTest(-10, 10);
    genRandArrayTest(-10, -5);
}

//relies on a working find function!!!
void genShuffledArrayTest(int size){
    int linesRun = 0;
    int* shuffled = genShuffledArray(size, &linesRun);
    int missing=0;
    for (int i=1; i<= size; i++){
        if (find(shuffled, size, i) == -1){
            missing++;
        }
    }

    delete[] shuffled;
    shuffled = nullptr;
    if (missing <= 0){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, missing count:" << missing << std::endl;
    }

}

void genShuffledArrayTest(){
    int linesRun = 0;
    std::cout << "shuffledArrayTest" << std::endl;
    //print some shuffled arrays to make sure they look right
    int* shuffled = genShuffledArray(10, &linesRun);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = genShuffledArray(10, &linesRun);
    std::cout << toString(shuffled, 10) << std::endl;
    delete[] shuffled;
    shuffled = nullptr;

    genShuffledArrayTest(12);
    genShuffledArrayTest(5);
    genShuffledArrayTest(1);
    int* array = genShuffledArray(0, &linesRun);
    if (array == nullptr){
        std::cout << "pass\n";
    }
    else {
        std::cout << "FAIL, array:" << array << std::endl;
    }
}

void copyArrayTest(){
    int linesRun = 0;
    std::cout << "copyArrayTest" << std::endl;
    int a1[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a2[] = {1, 2, 3, 22, 64, 33, 24, 9, 865, 23};
    int a3[] = {10, 20, 30, 220, 640, 330, 240, 90, 8650, 230};

    int* copy = copyArray(a1, 10, &linesRun);
    printAssertArrayEqual(copy, a1, 10);
    for (int i=0; i< 10; i++){
        copy[i] = copy[i]*10;
    }
    printAssertArrayEqual(copy, a3, 10);
    printAssertArrayEqual(a1, a2, 10);

    delete[] copy;
    copy = nullptr;
}

std::string findMaxIndexTest(int* arr, int expected, int size) {
    int index = findMaxIndex(arr, size);
    if (index == expected) {
        return "pass";
    } else {
        return "FAIL";
    }
}

void findMaxIndexTest(){
    std::cout << "findMaxIndexTest\n";
    //make some arrays. turns out i skipped a5
    int a1[] = {1,2,3,5,3,5,1};
    int a2[] = {400,1,0,15};
    int a3[] = {1,2,3,4,5};
    int a4[] = {-3,-4,-6,-2};
    int a6[] = {1};
    int a7[] = {};
    //make bools print as true/false instead of binary
    std::cout << std::boolalpha;
    //run some tests
    std::cout << "Testing multiple occurrences of max number: ";
    std::cout << findMaxIndexTest(a1, 3, 7) << std::endl;
    std::cout << "Testing max number at array start: ";
    std::cout << findMaxIndexTest(a2, 0, 4) << std::endl;
    std::cout << "Testing max number at array end: ";
    std::cout << findMaxIndexTest(a3, 4, 5) << std::endl;
    std::cout << "Testing all negative numbers: ";
    std::cout << findMaxIndexTest(a4, 3, 4) << std::endl;
    std::cout << "Testing array of size 1: ";
    std::cout << findMaxIndexTest(a6, 0, 1) << std::endl;
    std::cout << "Testing array of size 0. ";
    std::cout << findMaxIndexTest(a7, -1, 0) << std::endl;
}

void sortTest(){
    std::cout << "sortTest" << std::endl;
    int timer = 0;
    int junkTimer = 0;
    //loop several times to get different lengths
    for (int i = 10; i < 100; i+=11) {
        //generate random array of length i
        int* arr1 = genRandArray(i,0,i,&timer);
        //copy it
        int* arr2 = copyArray(arr1,i, &junkTimer);
        //sort it
        sort(arr2,i,&timer);
        //call checkSorted on it
        if (checkSorted(arr2, i)) {
            if (checkForSameElements(arr1, arr2, i)) {
                std::cout << "Pass\n";
            }
            else {
                std::cout <<"Fail, Arrays contain different elements! Size = " << i << toString(arr1, i) << toString(arr2, i)<<  std::endl;
            }
        }
        else {
            std::cout <<"Failed: Not sorted for size = " << i << toString(arr2, i)<<  std::endl;
        }
        delete[] arr1;
        delete[] arr2;
    }
}

void binSearchTest(int* a, int size, int* notInVals, int sizeNotIn){
    if (checkSorted(a, size)){
        bool allGood = true;
        for (int i=0; i<size; i++){
            int answer = binFind(a, size, a[i]);
            if ( answer != i){
                std::cout << "FAIL: Did not find " << a[i] << " in " << toString(a, size) << ", got: " << answer <<  std::endl;
                allGood = false;
            }
        }
        for (int i=0; i<sizeNotIn; i++){
            int ans = binFind(a, size, notInVals[i]);
            if (ans != -1){
                std::cout << "FAIL: gave " << ans <<" instead of -1 for " << notInVals[i] << " in " << toString(a, size) << std::endl;
                allGood = false;
            }
        }
        if (allGood){
            std::cout << "pass" << std::endl;
        }
    }
    else {
        std::cout << "ERROR IN TEST: can't binSearch an unsorted Array" << std::endl;
    }
}

void binSearchTest(){
    //simplest case
    std::cout << "binSearchTest" << std::endl;
    int a1[] {5, 6, 7};
    int a2[] {2, 8, 10};
    std::cout << "1 - only  3 elements" <<  std::endl;
    binSearchTest(a1, 3, a2, 3);
    std::cout << "2 - only  3 elements" <<  std::endl;
    binSearchTest(a2, 3, a1, 3);

    //odd number of elements
    int a3[] {10, 20, 30, 40, 50, 60, 70};
    int a4[] {5, 15, 25, 35, 45, 55, 65, 75, 85};
    std::cout << "3 - odd number of elements" <<  std::endl;
    binSearchTest(a3, 7, a4, 9);
    std::cout << "4 - odd number of elements" <<  std::endl;
    binSearchTest(a4, 9, a3, 7);

    //even number of elements
    int a5[] {2, 5, 9, 11};
    int a6[] {0, 1, 3, 6, 10, 12, 22, 367};
    std::cout << "5 - even number of elements" <<  std::endl;
    binSearchTest(a5, 4, a6, 8);
    std::cout << "6 - even number of elements" <<  std::endl;
    binSearchTest(a6, 8, a5, 4);

    //test arrays with negative values
    int a7[] {-11, -10, -8, -5, -1};
    int a8[] {-400, -300, -200, -100, -99, -98};
    std::cout << "7 - negative values\n";
    binSearchTest(a7, 5, a8, 6);
    std::cout << "8 - negative values\n";
    binSearchTest(a8, 6, a7, 5);

    //test for arrays of size 1
    int a9[] {3};
    int a10[] {4};
    std::cout << "9 - size 1\n";
    binSearchTest(a9,1,a10,1);
    std::cout << "10 - size 1\n";
    binSearchTest(a10,1,a9,1);

    // and 0
    std::cout << "11 - array size 0\n";
    printAssertEquals(-1, binFind(a9, 0, 100));

}

int main(){

    std::cout << "\nREGRESSION TESTS\n" << std::endl;
    genRandArrayTest();
    std::cout << std::endl;
    genShuffledArrayTest();
    std::cout << std::endl;
    copyArrayTest();
    std::cout << std::endl;
    std::cout << std::endl;
    sortTest();


    std::cout << "\n\nNEW IMPLEMENTATION TESTS\n" << std::endl;
    toStringTest();
    std::cout << std::endl;
    findTest();
    std::cout << std::endl;
    findLastTest();
    std::cout << std::endl;
    findMaxIndexTest();
    std::cout << std::endl;
    binSearchTest();
    return 0;
}
