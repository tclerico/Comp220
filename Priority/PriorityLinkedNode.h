//
// Created by Toby Dragon on 11/3/17.
//

#ifndef INC_220_27_PRIORITYQUEUE_PRIORITYLINKEDNODE_H
#define INC_220_27_PRIORITYQUEUE_PRIORITYLINKEDNODE_H

#include <string>

class PriorityLinkedNode {
private:
    std::string item;
    PriorityLinkedNode* next;
    float priority;

public:
    PriorityLinkedNode(std::string item, float priority);
    PriorityLinkedNode(const PriorityLinkedNode& nodeToCopy); //only copies item and priority, next is set to nullptr
    std::string getItem();
    PriorityLinkedNode* getNext();
    float getPriority();
    void setItem(std::string newItem);
    void setNext(PriorityLinkedNode* newNext);
};

#endif //INC_220_27_PRIORITYQUEUE_PRIORITYLINKEDNODE_H
