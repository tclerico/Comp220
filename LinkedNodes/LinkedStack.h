//
// Created by Toby Dragon on 10/22/17.
//

#ifndef STACKSANDQUEUES_STACK_H
#define STACKSANDQUEUES_STACK_H

#include <string>
#include <stdexcept>
#include "LinkedNode.h"

/**
 * Represents a LIFO data structure (Last In First Out). Picture a pile (stack)
 * where when you put something on top, you have to take it off to reach anything else
 * (last stone on the top of the pile comes off before any other)
 */
class LinkedStack {
private:
    LinkedNode* top;



public:

    //Creates an empty stack
    LinkedStack();

    //Copy Constructor
    LinkedStack(const LinkedStack& stackToCopy);

    //Destructor
    ~LinkedStack();

    //Assignment Operator
    LinkedStack& operator=(const LinkedStack& stackToCopy);

    //puts an item onto the top of the stack
    void push (std::string item);

    //takes the item off the top of the stack and returns it
    //throws out_of_range exception if the stack is empty
    std::string pop();

    //returns true if the stack has no items, false otherwise
    bool isEmpty();
};

#endif //STACKSANDQUEUES_STACK_H
