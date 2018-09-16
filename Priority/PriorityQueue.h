#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>

class PriorityQueue {
public:

    virtual ~PriorityQueue(){}

    /*
     * Adds an item to the priority queue
     * @param priority - a float representing the priority (large numbers are higher priority)
     * @post - the item is included in the priority queue to be removed later
     */
    virtual void addItem(std::string itemToAdd, float priority)=0;

    /*
     * removes and returns the item with the highest priority (large numbers are higher priority).
     * If the priorities are equal, it acts as a normal queue (FIFO)
     * @post - the item is removed from the priority queue
     * @returns a copy of the item
     * @throws std::out_of_range exception if empty
     */
    virtual std::string dequeueHighestPriorityItem()=0;

    /*
     * @returns true if queue is empty, false if there are any items
     */
    virtual bool isEmpty()=0;

};
#endif //PRIORITY_QUEUE_H