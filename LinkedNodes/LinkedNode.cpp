//
// Created by Toby Dragon on 10/17/17.
//
#include "LinkedNode.h"

LinkedNode::LinkedNode(std::string item){
    this->item = item;
    next = nullptr;
}

LinkedNode::LinkedNode(const LinkedNode& nodeToCopy){
    item = nodeToCopy.item;
    next = nullptr;
}

std::string LinkedNode::getItem(){
    return item;
}

LinkedNode* LinkedNode::getNext(){
    return next;
}

void LinkedNode::setItem(std::string newItem){
    item = newItem;
}

void LinkedNode::setNext(LinkedNode* newNext){
    next = newNext;
}