//
// Created by Tim on 9/26/2017.
//

#include <cstdlib>
#include "ArrayLib.h"
#include <iostream>

using namespace std;


std::string recToString(int const* arrPtr, const int size, const int index,const std::string STR){

    if(index<size){
        if(index!=size-1){
            std::string x = std::to_string(arrPtr[index])+", ";
            const std::string temp = recToString(arrPtr,size,index+1,STR+x);
            return temp;
        }else{
            std::string x = std::to_string(arrPtr[index]);
            const std::string temp = recToString(arrPtr,size,index+1,STR+x);
            return temp;
        }
    }
    else{
        return STR+"}" ;
    }
}


std::string toString(int const* arrayPtr, const int size) {
    std::string final = recToString(arrayPtr,size,0,"{");
    return final;
}

//tail recursion
int recFind(const int* arrayPtr, const int size, const int numToFind, const int index, int& numLinesRun){
    int temp = arrayPtr[index];
    numLinesRun+=2;
    if(temp!=numToFind){
        numLinesRun+=1;
        if(index==size){
            numLinesRun+=1;
            return -1;
        }else {
            numLinesRun+=2;
            temp = recFind(arrayPtr, size, numToFind, index + 1, numLinesRun);
            return temp;
        }
    }else{
        numLinesRun+=1;
        return index;
    }
}


//calls the recFind Function to recursively loop through array
//@Returns the index value
int find(const int* arrayPtr, const int size, const int numToFind, int& numLinesRun){
    if(size==0){
        numLinesRun+=2;
        return -1;
    }
    numLinesRun+=1;
    int final = recFind(arrayPtr,size,numToFind,0, numLinesRun);
    numLinesRun+=1;
    return final;
}


//non-tail recursion
int recFindLast(const int* arrayPtr, const int size,const int numToFind, const int index, int&numLinesRun){
    int temp = 0;
    numLinesRun+=2;
    if(index<size){
        numLinesRun+=1;
        temp = recFindLast(arrayPtr,size,numToFind,index+1, numLinesRun);
        if(temp!=-1){
            numLinesRun+=2;
            return temp;
        }
        int temp2 = arrayPtr[index];
        numLinesRun+=1;
        if (temp2==numToFind){
            numLinesRun+=2;
            return index;
        }else{
            numLinesRun+=2;
            return -1;
        }
    }else{
        numLinesRun+=2;
        return -1;
    }

}

//calls recFindLast function to recursively loop through array looking for num
//@returns index value
int findLast(const int* arrayPtr,const int size,const int numToFind, int& numLinesRun){
    int final = recFindLast(arrayPtr,size,numToFind,0,numLinesRun);
    numLinesRun+=2;
    return final;
}

//Tail recursion
int recFindMaxIndex(const int* arrayPtr, const int size, const int index,const int mIndex, int& numLinesRun){
    int temp;
    numLinesRun+=1;
    if(index<size) {
        numLinesRun+=1;
        if(arrayPtr[mIndex]<arrayPtr[index]){
            numLinesRun+=2;
            temp = recFindMaxIndex(arrayPtr,size,index+1,index,numLinesRun);
            return temp;
        }else{
            numLinesRun+=2;
            temp = recFindMaxIndex(arrayPtr,size,index+1,mIndex,numLinesRun);
            return temp;
        }

    }else{
        numLinesRun+=1;
        return mIndex;
    }
}


int findMaxIndex(const int* arrayPtr, const int size, int& numLinesRun){
    if(size==0){
        numLinesRun+=2;
        return -1;
    }else{
        numLinesRun+=1;
        int final = recFindMaxIndex(arrayPtr,size,0,0, numLinesRun);
        numLinesRun+=1;
        return final;
    }

}
//Non-Tail I think??
int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    if(size==1 && numToFind==arrayPtr[0]){
        numLinesRun+=2;
        return 0;
    }else if(size<1 ||(size==1 && numToFind!=arrayPtr[0])){
        numLinesRun+=3;
        return -1;
    }
    int midIndex = (size-1)/2;
    int index;
    numLinesRun+=2;
    if(numToFind==arrayPtr[midIndex]){
        numLinesRun+=2;
        return midIndex;

    }else if (numToFind>arrayPtr[midIndex]){ //split into right half
        numLinesRun+=2;
        //for odd
        if(size%2==0){
            numLinesRun+=2;
            index = binFind(arrayPtr+midIndex+1,(size)/2,numToFind,numLinesRun);
        }else{//for even
            numLinesRun+=2;
            index = binFind(arrayPtr+midIndex+1,(size-1)/2,numToFind,numLinesRun);
        }
        if(index==-1){
            numLinesRun+=2;
            return -1;
        }else{
            numLinesRun+=2;
            return index+midIndex+1;
        }

    } else if (numToFind<arrayPtr[midIndex]){ //split into left half
        numLinesRun+=5;
        index = binFind(arrayPtr,(size-1)/2,numToFind,numLinesRun);
        return index;
    }
}


//this function will generate a random number between given min and max value
//if the min value is greater than the max value it will return the min
int genRandInt(int min, int max, int& numLinesRun){
    if(min>=max){
        numLinesRun+=2;
        return min;
    }
    //ensure that random # is between min and max values
    int random_int = (rand() %(max-min+1)+min);
    numLinesRun+=3;
    return random_int;
}

/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @return a pointer to the array, which must be deleted by the user
 */
int* genRandArray(int size, int min, int max, int& numLinesRun){
    int temp;
    numLinesRun += 1;
    if(min>max){
        numLinesRun+=4;
        temp=max;
        max=min;
        min=temp;
    }
    int* randArray = new int [size];
    numLinesRun+=3;
    for(int x=0;x<size;x++){
        randArray[x]=genRandInt(min,max,numLinesRun);
        numLinesRun+=3;
    }
    numLinesRun+=1;
    return randArray;
}

/**
 * generates an array with values 1 through size, shuffled in random order
 * example: genShuffledArray(5) might yield {2, 1, 4, 5, 3}
 * @pre srand must be called once before this function is used the first time
 * @return a pointer to the array, which must be deleted by the user,
 *          returns nullptr if size < 1
 */
int* genShuffledArray(int size,int& numLinesRun){
    //Checks to see if size is less then 1
    //returns nulllptr
    if (size<1) {
        numLinesRun+=2;
        return nullptr;
    }
    //initialize array on heap
    int* shufArr = new int [size];
    numLinesRun+=3;
    //populate array with 0's
    for(int x=0;x<size;x++){
        shufArr[x]=0;
        numLinesRun+=3;
    }
    //use a temp to store the random # which will correlate to the index that a value will be stored in
    //inciment with x, and store value of x in random index to avoid duplicates
    int randNum;
    numLinesRun+=3;
    for(int x=1;x<=size;x++){
        ///gen random num
        randNum=genRandInt(1,size,numLinesRun);
        numLinesRun+=3;
        //check to see if a value already exists in random index
        if(shufArr[randNum-1]!=0){
            //if there is a value take away from x to make sure the number being added to the array stays consistent
            x--;
            numLinesRun+=2;
        }else{
            //add value into array at random index
            shufArr[randNum-1]=x;
            numLinesRun+=2;
        }
    }
    numLinesRun+=1;
    return shufArr;
}
/*
 * Switches the values in an index and the index to the right of it
 * */
void switchValue(int* array, int index, int& numLinesRun){
    int temp = array[index];
    int temp2 = array[index+1];
    array[index]=temp2;
    array[index+1]=temp;
    numLinesRun+=4;
}

/*
 * Loops through an array sorting the values numerically using the bubble sort method
 * if a value is greater than the value in the next index, calls switchValue to
 * switch the values in the indices.
 * @returns the pointer to the array
 */
void sort(int* arrayToSort, int size, int& numLinesRun){
    numLinesRun+=2;
    for (int x = 0; x < size - 1; x++) {
        numLinesRun += 4;
        for (int y = 0; y < size - 1; y++) {
            numLinesRun += 2;
            if (arrayToSort[y] > arrayToSort[y + 1]) {
                numLinesRun += 2;
                switchValue(arrayToSort, y, numLinesRun);
            }
        }
    }
}


/**
 * generates a copy of a given array
 * @return a pointer to the copy array, which must be deleted by the user
 */
int* copyArray(int const* arrayToCopy, const int size, int& numLinesRun) {
    int *cArray = new int[size];
    numLinesRun += 3;
    for (int x = 0; x < size; x++) {
        cArray[x] = arrayToCopy[x];
        numLinesRun += 3;
    }
    numLinesRun += 1;
    return cArray;
}

/**
 * returns an array that is a sorted, merged copy of arrays a1 and a2
 * Operates in O(n), linear time
 * @pre both a1 and a2 must be sorted
 * @post numLinesRun is updated to include lines run by this function
 * @return an array of size (size1+size2) that is an in-order (sorted) copy of all values from a1 and a2,
 * or nullptr if (size1+size2) < 1
 */
int* merge(const int* a1, const int size1, const int* a2, const int size2, int& numLinesRun){
    numLinesRun+=5;
    int count=0;
    int count1=0;
    int count2=0;
    //int cSize;
    int* temp = new int [size1+size2];

    //want to use the size of the smaller array
//    if(size1>=size2){
//        cSize=size2;
//        numLinesRun+=2;
//    }else{
//        cSize=size1;
//        numLinesRun+=2;
//    }

    //iterates through the arrays comparing values and populating new array.
    while(count1<size1 && count2<size2){
        numLinesRun+=1;
        if(a1[count1]<a2[count2]){
            temp[count]=a1[count1];
            count++;
            count1++;
            numLinesRun+=4;
        }else{
            temp[count]=a2[count2];
            count++;
            count2++;
            numLinesRun+=4;
        }
    }

    //fill the array with the remaining values
    if(count2<size2){
        numLinesRun+=3;
        for(int x=count2;x<size2;x++){
            numLinesRun+=4;
            temp[count]=a2[x];
            count++;
        }
    }else{
        numLinesRun+=3;
        for(int x=count1;x<size1;x++){
            numLinesRun+=4;
            temp[count]=a1[x];
            count++;
        }
    }
    numLinesRun+=1;
    return temp;

}

/**
 * returns a sorted copy of the array using merge sort
 * @post numLinesRun is updated to include lines run by this function
 * @return a copy of the array sorted from min to max values, or nullptr if size < 1
 */
int* mergeSort(const int* arrayToSort, int size, int& numLinesRun){
    if(size<1){
        numLinesRun+=2;
        return nullptr;
    }
    else if(size==1){
        numLinesRun+=3;
        int* arr = copyArray(arrayToSort,1,numLinesRun);

        numLinesRun+=1;
        return arr;
    }
    else if(size>1 && size%2==0){
        numLinesRun+=4;

        int mid = size/2;
        numLinesRun+=1;

        int* a1 = mergeSort(arrayToSort, mid, numLinesRun);
        numLinesRun+=1;

        int* a2 = mergeSort(arrayToSort+mid, mid, numLinesRun);
        numLinesRun+=1;

        int* fin = merge(a1, mid, a2, mid, numLinesRun);
        numLinesRun+=1;

        delete []a1;
        delete []a2;
        return fin;
    }
    else if(size>1 && size%2!=0){
        numLinesRun+=5;

        int mid = size/2;
        numLinesRun+=1;

        int* a1 = mergeSort(arrayToSort, mid+1, numLinesRun);
        numLinesRun+=1;

        int* a2 = mergeSort(arrayToSort+mid+1, mid, numLinesRun);
        numLinesRun+=1;

        int* fin = merge(a1,mid+1,a2,mid,numLinesRun);
        numLinesRun+=1;

        delete []a1;
        delete []a2;
        return fin;
    }


}















