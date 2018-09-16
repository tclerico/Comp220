//
// Created by Toby Dragon on 11/3/17.
//

#include "PriorityLinkedNode.h"

PriorityLinkedNode::PriorityLinkedNode(std::string item, float priority){
    this->item = item;
    this->priority = priority;
    next = nullptr;
}

PriorityLinkedNode::PriorityLinkedNode(const PriorityLinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    this->priority = nodeToCopy.priority;
    next = nullptr;
}

std::string PriorityLinkedNode::getItem(){
    return item;
}

PriorityLinkedNode* PriorityLinkedNode::getNext(){
    return next;
}

float PriorityLinkedNode::getPriority(){
    return priority;
}

void PriorityLinkedNode::setItem(std::string newItem){
    item = newItem;
}

void PriorityLinkedNode::setNext(PriorityLinkedNode* newNext){
    next = newNext;
}