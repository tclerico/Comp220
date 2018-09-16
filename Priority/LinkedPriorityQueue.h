//
// Created by Toby Dragon on 11/3/17.
//

#ifndef INC_220_27_PRIORITYQUEUE_LINKEDPRIORITYQUEUE_H
#define INC_220_27_PRIORITYQUEUE_LINKEDPRIORITYQUEUE_H

#include "PriorityQueue.h"
#include "PriorityLinkedNode.h"

class LinkedPriorityQueue : public PriorityQueue{
private:
    PriorityLinkedNode* front;

public:
    LinkedPriorityQueue();


    void addItem(std::string itemToAdd, float priority);

    //most time-sensitive operation, should operate in O(1)
    std::string dequeueHighestPriorityItem();

    bool isEmpty();

};


#endif //INC_220_27_PRIORITYQUEUE_LINKEDPRIORITYQUEUE_H
