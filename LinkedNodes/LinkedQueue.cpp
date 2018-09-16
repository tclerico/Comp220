//
// Created by Toby Dragon on 10/24/17.
//
#include "LinkedQueue.h"

//Creates an empty queue
LinkedQueue::LinkedQueue(){
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
LinkedQueue::LinkedQueue(const LinkedQueue& queueToCopy){
    front = nullptr;
    end = nullptr;
    LinkedNode* ptr = queueToCopy.front;
    while(ptr!= nullptr){
        this->enqueue(ptr->getItem());
        ptr = ptr->getNext();
    }
}

//Destructor
LinkedQueue::~LinkedQueue(){
   while(!isEmpty()){
       LinkedNode* ptr = front->getNext();
       delete front;
       front = ptr;
       ptr = nullptr;
   }
    end=nullptr;
}

//LinkedQueue& LinkedQueue::operator=(const LinkedQueue& queueToCopy){
//    if (this!=&queueToCopy){
//        while(!isEmpty()){
//            LinkedNode* ptr = front->getNext();
//            delete front;
//            front = ptr;
//            ptr = nullptr;
//        }
//
//        front = nullptr;
//        end = nullptr;
//        LinkedNode* ptr = queueToCopy.front;
//        while(ptr!= nullptr){
//            this->enqueue(ptr->getItem());
//            ptr = ptr->getNext();
//        }
//    }else{
//        return *this;
//    }
//}


//adds an item to the end of the queue
void LinkedQueue::enqueue(std::string item){
    LinkedNode* newNode = new LinkedNode(item);
    //if front is nullptr, end should be nullptr too
    if (front == nullptr){
        front = newNode;
        end = newNode;
    }
    else {
        end->setNext(newNode);
        end = newNode;
    }
}

//takes an item off the front of the queue and returns it
//throws out_of_range exception if the queue is empty
std::string LinkedQueue::dequeue(){
    //TODO, consider cases where:
    // the queue is empty - return null
    if(front == nullptr && end == nullptr){
        throw std::out_of_range("Que is Empty!");
    }
    // the queue has one item -
    else if(front == end){
        std::string item = front->getItem();
        delete front;
        front = nullptr;
        end = nullptr;
        return item;
    }
    // the queue has many items
    else{
        std::string item = front->getItem();
        LinkedNode* ptr = front->getNext();
        delete front;
        front = ptr;
        ptr = nullptr;
        return item;
    }



}

//returns true if the queue has no items, false otherwise
bool LinkedQueue::isEmpty(){
    return front == nullptr;
}
