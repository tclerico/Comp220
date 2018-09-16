//
// Created by Tim on 9/5/2017.
//

#include <cstdlib>
#include "ArrayLib.h"



using namespace std;

//this function will generate a random number between given min and max value
//if the min value is greater than the max value it will return the min
int genRandInt(int min, int max, int* numLinesRun){
    if(min>=max){
        *numLinesRun+=2;
        return min;
    }
    //ensure that random # is between min and max values
    int random_int = (rand() %(max-min+1)+min);
    *numLinesRun+=3;
    return random_int;
}

/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @return a pointer to the array, which must be deleted by the user
 */
int* genRandArray(int size, int min, int max, int* numLinesRun){
    int temp;
    *numLinesRun += 1;
    if(min>max){
        temp=max;
        max=min;
        min=temp;
        *numLinesRun+=4;
    }
    int* randArray = new int [size];
    *numLinesRun+=3;
    for(int x=0;x<size;x++){
        randArray[x]=genRandInt(min,max,numLinesRun);
        *numLinesRun+=3;
    }
    *numLinesRun+=1;
    return randArray;
}

/**
 * generates an array with values 1 through size, shuffled in random order
 * example: genShuffledArray(5) might yield {2, 1, 4, 5, 3}
 * @pre srand must be called once before this function is used the first time
 * @return a pointer to the array, which must be deleted by the user,
 *          returns nullptr if size < 1
 */
int* genShuffledArray(int size,int* numLinesRun){
    //Checks to see if size is less then 1
    //returns nulllptr
    if (size<1) {
        *numLinesRun+=2;
        return nullptr;
    }
    //initialize array on heap
    int* shufArr = new int [size];
    *numLinesRun+=3;
    //populate array with 0's
    for(int x=0;x<size;x++){
        shufArr[x]=0;
        *numLinesRun+=3;
    }
    //use a temp to store the random # which will correlate to the index that a value will be stored in
    //inciment with x, and store value of x in random index to avoid duplicates
    int randNum;
    *numLinesRun+=3;
    for(int x=1;x<=size;x++){
        ///gen random num
        randNum=genRandInt(1,size,numLinesRun);
        *numLinesRun+=3;
        //check to see if a value already exists in random index
        if(shufArr[randNum-1]!=0){
            //if there is a value take away from x to make sure the number being added to the array stays consistent
            x--;
            *numLinesRun+=2;
        }else{
            //add value into array at random index
            shufArr[randNum-1]=x;
            *numLinesRun+=2;
        }
    }
    *numLinesRun+=1;
    return shufArr;
}

/**
 * creates a string version of an int array for easy printing
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
std::string toString(int const* arrayPtr, int size){
    std::string STR = "{";
    for(int x=0;x<size;x++){
        std::string y = std::to_string(arrayPtr[x]);
        if(x==size-1){
            STR = STR + y;
        }else{
            STR = STR + y + ", ";
        }
    }
    STR = STR + "}";
    return STR;

}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int find(const int* arrayPtr, int size, int numToFind,int* numLinesRun){
    *numLinesRun+=2;
    for(int x=0;x<size;x++){
        *numLinesRun+=2;
        if(numToFind==arrayPtr[x]){
            *numLinesRun+=2;
            return x;
        }
    }
    *numLinesRun+=1;
    return -1;
}

/**
 * Searches an int array for a certain value
 * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
 */
int findLast(const int* arrayPtr, int size, int numToFind, int* numLinesRun){
    int temp=-1;
    *numLinesRun+=3;
    for(int x=0;x<size;x++){
        *numLinesRun+=2;
        if(numToFind==arrayPtr[x]){
            temp=x;
            *numLinesRun+=2;
        }
    }
    *numLinesRun+=1;
    return temp;
}

/*
 * loops through array searching for the max value
 * @return the index of the first occurance of the max value in the array
 */
int findMaxIndex(const int* arrayPtr, int size, int* numLinesRun){
    int index;
    int temp=0;
    index = arrayPtr[0];
    *numLinesRun+=5;
    for(int x=0;x<size;x++){
        *numLinesRun+=2;
        if(index<arrayPtr[x]){
            index=arrayPtr[x];
            temp=x;
            *numLinesRun+=3;
        }
    }
    *numLinesRun+=1;
    return temp;
}
/*
 * Switches the values in an index and the index to the right of it
 * */
void switchValue(int* array, int index, int* numLinesRun){
    int temp = array[index];
    int temp2 = array[index+1];
    array[index]=temp2;
    array[index+1]=temp;
    *numLinesRun+=4;
}

/*
 * Loops through an array sorting the values numerically using the bubble sort method
 * @returns the pointer to the array
 */
void sort(int* arrayToSort, int size, int* numLinesRun){
    *numLinesRun+=2;
    for (int x = 0; x < size - 1; x++) {
        *numLinesRun += 4;
        for (int y = 0; y < size - 1; y++) {
            *numLinesRun += 2;
            if (arrayToSort[y] > arrayToSort[y + 1]) {
                *numLinesRun += 2;
                switchValue(arrayToSort, y, numLinesRun);
            }
        }
    }
}


/**
 * generates a copy of a given array
 * @return a pointer to the copy array, which must be deleted by the user
 */
int* copyArray(int const* arrayToCopy, const int size, int* numLinesRun){
    int* cArray = new int [size];
    *numLinesRun+=3;
    for(int x=0;x<size;x++){
        cArray[x] = arrayToCopy[x];
        *numLinesRun+=3;
    }
    *numLinesRun+=1;
    return cArray;
}