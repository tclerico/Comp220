//
// Created by Toby Dragon on 11/3/17.
//

#include "LinkedPriorityQueue.h"

LinkedPriorityQueue::LinkedPriorityQueue(){
    front = nullptr;
}

/*
 * Adds an item to the priority queue
 * @param priority - a float representing the priority (large numbers are higher priority)
 * @post - the item is included in the priority queue to be removed later
 */
void LinkedPriorityQueue::addItem(std::string itemToAdd, float priority){
    //TODO
}

/*
 * removes and returns the item with the highest priority (large numbers are higher priority).
 * If the priorities are equal, it acts as a normal queue (FIFO)
 *
 * *** most time-sensitive operation, should operate in O(1) ***
 *
 * @post - the item is removed from the priority queue
 * @returns a copy of the item
 * @throws std::out_of_range exception if empty
 */
std::string LinkedPriorityQueue::dequeueHighestPriorityItem(){
    if (isEmpty()){
        throw std::out_of_range("Can't dequeue from empty priority queue");
    }
    else {
        std::string item = front->getItem();
        PriorityLinkedNode* toDelete = front;
        front = front->getNext();
        delete toDelete;
        return item;
    }
}

/*
 * @returns true if queue is empty, false if there are any items
 */
bool LinkedPriorityQueue::isEmpty(){
    return front == nullptr;
}