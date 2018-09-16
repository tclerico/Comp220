//
// Created by Toby Dragon on 10/24/17.
//
#include <iostream>
#include "LinkedStack.h"
#include "LinkedQueue.h"

void queueCopyConstructorTest(){
    //TODO
    std::cout<<"TESTING QUEUE COPY CONSTRUCTOR"<<std::endl;
    LinkedQueue original = LinkedQueue();
    for(int x=0;x<4;x++){
        original.enqueue(std::to_string(x+1));
    }

    LinkedQueue nQueue = LinkedQueue(original);
    int errors = 0;
    for(int x=0;x<4;x++){
        if(original.dequeue()!=nQueue.dequeue()){
            errors++;
        }
    }
    if(errors!=0){
        std::cout<<"ERRORS: " + errors<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }

}
void stackCopyConstructorTest(){
    //TODO
    std::cout<<"TESTIN STACK COPY CONSTRUCTOR"<<std::endl;
    LinkedStack original = LinkedStack();
    for(int x=0;x<4;x++){
        original.push(std::to_string(x+1));
    }

    LinkedStack nStack = LinkedStack(original);
    int errors =0;
    for(int x=0;x<4;x++) {
        if (original.pop() != nStack.pop()) {
            errors++;
        }
    }
    if(errors==0){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"Errors: "+ errors<<std::endl;
    }

}

void simpleStackQueueTest(){
    std::cout << "simpleStackQueueTest" << std::endl;
    LinkedQueue testQueue;
    LinkedStack testStack;

    for (int i=0; i<4; i++){
        std::string personToAdd = "person" + std::to_string(i+1);
        testQueue.enqueue(personToAdd);
        testStack.push(personToAdd);
    }
    std::cout << "Queue:" << std::endl;
    int count=1;
    while( ! testQueue.isEmpty()){
        std::cout << count << ":" << testQueue.dequeue()<< std::endl;
        count++;
    }
    std::cout << "\nStack:" << std::endl;
    count=1;
    while( ! testStack.isEmpty()){
        std::cout << count << ":" << testStack.pop()<< std::endl;
        count++;
    }
    try {
        testStack.pop();
        std::cout << "FAIL: should have thrown exception from pop"<< std::endl;
    }
    catch(std::out_of_range& e){
        std::cout << "pass: caught exception: "<< e.what() << std::endl;
    }
    try {
        testQueue.dequeue();
        std::cout << "FAIL: should have thrown exception from dequeue"<< std::endl;
    }
    catch(std::out_of_range& e){
        std::cout << "pass: caught exception: "<< e.what() << std::endl;
    }
    testStack.push("Maria");
    testStack.push("Janice");
    testStack.pop();
    testStack.push("Paul");
    testStack.push("Johan");
    testStack.pop();
    std::cout << testStack.pop()<< std::endl;

    testQueue.enqueue("Maria");
    testQueue.enqueue("Janice");
    testQueue.dequeue();
    testQueue.enqueue("Paul");
    testQueue.enqueue("Johan");
    testQueue.dequeue();
    std::cout << testQueue.dequeue()<< std::endl;
}

int main(){
    simpleStackQueueTest();
    stackCopyConstructorTest();
    queueCopyConstructorTest();
    return 0;
}

