//
// Created by Toby Dragon on 10/24/17.
//

#include "LinkedStack.h"

//Creates an empty stack
LinkedStack::LinkedStack(){
    top = nullptr;
}

void LinkedRecursion(LinkedNode* ptr, LinkedStack* nStack){
    if(ptr->getNext() == nullptr){
        nStack->push(ptr->getItem());
    }
    else{
        LinkedRecursion(ptr->getNext(),nStack);
        nStack->push(ptr->getItem());
    }
}


//copy constructor
LinkedStack::LinkedStack(const LinkedStack& stackToCopy){
    //TODO
    top = nullptr;
    if(stackToCopy.top != nullptr){
        LinkedRecursion(stackToCopy.top, this);
    }


}

//destructor
LinkedStack::~LinkedStack(){
    while(!isEmpty()){
        LinkedNode* ptr = top->getNext();
        delete top;
        top = ptr;
        ptr = nullptr;
    }
}

//Assignment Operator
//LinkedStack& LinkedStack::operator=(const LinkedStack& stackToCopy){
//    if(this!=&stackToCopy){
//        while(!isEmpty()){
//            LinkedNode* ptr = top->getNext();
//            delete top;
//            top = ptr;
//            ptr = nullptr;
//        }
//
//        LinkedRecursion(stackToCopy.top, this);
//    }else{
//        return *this;
//    }
//}


//puts an item onto the top of the stack
void LinkedStack::push (std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    newNode->setNext(top);
    top = newNode;
}

//takes the item off the top of the stack and returns it
//throws out_of_range exception if the stack is empty
std::string LinkedStack::pop(){
    //TODO
    if(top == nullptr){
        throw std::out_of_range("Stack Is Empty!");
    }
    //if there are multiple items in stack
    else{
        std::string item = top->getItem();
        LinkedNode* ptr = top->getNext();
        delete top;
        top = ptr;
        ptr = nullptr;
        return item;
    }
}

//returns true if the stack has no items, false otherwise
bool LinkedStack::isEmpty(){
    return top == nullptr;
}
