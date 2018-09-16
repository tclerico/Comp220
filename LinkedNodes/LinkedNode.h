//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H

#include <string>

class LinkedNode {

private:
    std::string item;
    LinkedNode* next;

public:
    LinkedNode(std::string item);
    LinkedNode(const LinkedNode& nodeToCopy); //only copies item, next is set to nullptr
    std::string getItem();
    LinkedNode* getNext();
    void setItem(std::string newItem);
    void setNext(LinkedNode* newNext);
};


#endif //LINKEDNODE_H
