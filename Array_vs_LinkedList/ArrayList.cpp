//
// Created by Tim on 10/10/2017.
//

#include "ArrayList.h"
#include <iostream>
#include "ArrayLib.h"

ArrayList::ArrayList(int initialCapacity) {
    this->currCapacity = initialCapacity;
    this->array = new int [initialCapacity];
    this->currItemCount = 0;
}

//Destructor
//BIG-O: O(1)
ArrayList:: ~ArrayList(){
    delete [] array;
}

//copy constructor
//BIG-O: O(N)
ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    currCapacity=arrayListToCopy.currCapacity;
    currItemCount=arrayListToCopy.currItemCount;

    array = new int [currCapacity];
    for(int x=0;x<currItemCount;x++){
        array[x]=arrayListToCopy.array[x];
    }
}
//asignment operator
//BIG-O: O(N)
ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
    if(this!=&arrayListToCopy){
        delete [] array;

        currCapacity=arrayListToCopy.currCapacity;
        currItemCount=arrayListToCopy.currItemCount;

        array = new int [currCapacity];
        for(int x=0;x<currItemCount;x++){
            array[x]=arrayListToCopy.array[x];
        }
    }
    return *this;
}



/**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
//BIG-O: O(N)
void ArrayList::doubleCapacity(){
    currCapacity=currCapacity*2;
    int* doubleArray = new int [currCapacity];
    for(int x=0;x<currCapacity/2;x++){
        doubleArray[x]=array[x];
    }
    delete [] array;
    array = doubleArray;
}

/**
     * appends the new item to the end of the list
     * @param itemToAdd the item to add to the end of the array
     * @post the list has an additional value in it, at the end
     */
//BIG-O: O(1) or O(N)
void ArrayList::insertAtEnd(int itemToAdd){
    if(currItemCount<currCapacity){
        array[currItemCount] = itemToAdd;
        currItemCount+=1;
    }else{
        doubleCapacity();
        array[currItemCount]=itemToAdd;
        currItemCount+=1;
    }

}


/**
     * appends the new item to the beginning of the list
     * @param itemToAdd the item to add to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
//BIG-O: O(N)
void ArrayList::insertAtFront(int itemToAdd){
    if(currItemCount<currCapacity){
        for(int x=currItemCount;x>=0;x--){
           array[x+1]=array[x];
        }
        array[0]=itemToAdd;
        currItemCount+=1;
    }else{
        doubleCapacity();
        for(int x=currItemCount;x>=0;x--){
           array[x+1]=array[x];
        }
        array[0]=itemToAdd;
        currItemCount+=1;

    }

}

/**
     * inserts the item into the list so that it can be found with get(index)
     * @param itemToAdd the item to add
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or >currItemCount)
     */
//BIG-O: O(N)
void ArrayList::insertAt(int itemToAdd, int index){
    if (index<0 || index>currItemCount){
        throw std::out_of_range("invalid index");

    }else if(currItemCount<currCapacity){
        for(int x=currItemCount;x>index;x--){
            array[x]=array[x-1];
        }
        array[index]=itemToAdd;
        currItemCount+=1;
    }else{
        doubleCapacity();
        for(int x=currItemCount;x>index;x--){
            array[x]=array[x-1];
        }
        array[index]=itemToAdd;
        currItemCount+=1;
    }
}

/**
     * gets a value from the list
     * @param index the location from which to get the value
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
//BIG-O: O(1)
int ArrayList::getValueAt(int index){
    if(index>currItemCount || index<0){
        throw std::out_of_range("invalid index");
    }else{
        return array[index];
    }
}

/**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @returns a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
//BIG-O: O(1) or O(N)
int ArrayList::removeValueAt(int index){
    if(index>currItemCount || index<0){
        throw std::out_of_range("invalid index");
    }else if(index==currItemCount){
        int x = array[index];
        currItemCount-=1;
        return x;
    }else{
        int x = array[index];
        currItemCount-=1;
        for(int x = index;x<currItemCount;x++){
            array[x]=array[x+1];
        }
        return x;
    }
}

/**
     * checks if there are any valid items in the list
     * @returns true if there are no valid items in the list, false otherwise
     */
//BIG-O: O(1)
bool ArrayList::isEmpty(){
    if(currItemCount==0){
        return true;
    }else{
        return false;
    }
}


/**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
//BIG-O: O(1)
int ArrayList::itemCount(){
    return currItemCount;
}

/**
     * removes all valid items from the list
     * @post the list is completely clear of valid items
     */
//BIG-O: O(1)
void ArrayList::clearList(){
    currItemCount=0;
}

/**
     * gives a string representation of the current list
     * @returns a string representing the given list in the exact format shown below
     * {1, 2, 3, 4, 5}
     */
//BIG-O: O(N)
std::string ArrayList::toString(){
   return ::toString(array,currItemCount);
}

/**
     * finds the largest value in the array
     * @post numLinesRun is updated to include lines run by this function
     * @return the first index of the maximum value, or -1 if size < 1
     */
//BIG-O: O(N)
int ArrayList::findMaxIndex(){
    int garbo = 0;
    return ::findMaxIndex(array,currItemCount,garbo);
}

/**
     * Searches an int array for a certain value
     * @post numLinesRun is updated to include lines run by this function
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
//BIG-O: O(N)
int ArrayList::find(int numToFind){
    int garbo =0;
    return ::find(array,currItemCount,numToFind,garbo);
}

/**
     * Searches an int array for a certain value
     * @post numLinesRun is updated to include lines run by this function
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
//BIG-O: O(N)
int ArrayList::findLast(int numToFind){
    int garbo = 0;
    return ::findLast(array,currItemCount,numToFind,garbo);
}

