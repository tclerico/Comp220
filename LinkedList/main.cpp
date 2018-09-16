#include <iostream>
#include "IntLinkedList.h"



void copyConstructorTest(){
    //This relies on a working insertAtEnd()
    std::cout<<"COPY CONSTRUCTOR TEST"<<std::endl;

    IntLinkedList orig;
    for(int x=0;x<4;x++){
        orig.insertAtEnd(x);
    }

    IntLinkedList nlist = IntLinkedList(orig);
    int error=0;

    LinkedNode* original = orig.getFront();
    LinkedNode* newL = nlist.getFront();
    for(int x=0;x<4;x++){
        if(newL->getItem()!=original->getItem()){
            error++;
        }
        newL = newL->getNext();
        original = original->getNext();
    }

    if(error==0){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"Fail with Errors: " + error<<std::endl;
    }

    original=nullptr;
    newL=nullptr;

}


void insertTest(){
    //tests all 'insert' functions
    std::cout<<"INSERT AT End TEST"<<std::endl;

    IntLinkedList tester;
    for (int x=0;x<5;x++){
        tester.insertAtEnd(x);
    }
    LinkedNode* ptr = tester.getFront();
    int error = 0;
    for(int x=0;x<5;x++){
        if(x!=ptr->getItem()){
            error++;
        }
        ptr=ptr->getNext();
    }
    if(error==0){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"Fail with Errors: " + error<<std::endl;
    }

    std::cout<<"\n"<<std::endl;
    std::cout<<"INSERT AT FRONT TEST"<<std::endl;

    IntLinkedList ftest;
    for(int x=0;x<5;x++){
        ftest.insertAtEnd(x);
    }
    ftest.insertAtFront(99);
    ptr = ftest.getFront();

    if(ptr->getItem()!=99){
        std::cout<<"ERROR INCORRECT VALUE"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }
    std::cout<<"\n"<<std::endl;
    std::cout<<"INSERT AT TEST"<<std::endl;

    IntLinkedList iaTest;
    for(int x=0;x<5;x++){
        iaTest.insertAtEnd(x);
    }
    //list = 0,1,2,3,4
    int a [] = {5,6,7,8};
    iaTest.insertAt(a[0],1);
    iaTest.insertAt(a[1],3);
    iaTest.insertAt(a[2],5);
    iaTest.insertAt(a[3],7);

    ptr = iaTest.getFront();
    error=0;
    int ans [] = {0,5,1,6,2,7,3,8,4};
    for(int x=0;x<9;x++){
        if(ptr->getItem()!=ans[x]){
            error++;
        }
        ptr=ptr->getNext();
    }

    if(error==0){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"Fail with Errors: " + error<<std::endl;
    }

    std::cout<<"\n"<<std::endl;
    std::cout<<"INSERT AT OUT OF RANGE TEST"<<std::endl;

    try{
        iaTest.insertAt(99,99);
    }catch(std::out_of_range& e){
        std::cout<<"PASS"<<std::endl;
    }

    ptr=nullptr;
}

void itemCountTest(){
    std::cout<<"ITEM COUNT TEST"<<std::endl;
    IntLinkedList test;
    for(int x=0;x<5;x++){
        test.insertAtEnd(x);
    }
    int z = test.itemCount();
    if(z!=5){
        std::cout<<"ERROR INCORRECT COUNT"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }

}

void getValueAtTest(){
    std::cout<<"GET VALUE AT TEST"<<std::endl;
    IntLinkedList test;
    for(int x=0;x<5;x++){
        test.insertAtEnd(x);
    }
    int error =0;
    LinkedNode* ptr = test.getFront();
    for(int x=0;x<5;x++){
        int z = test.getValueAt(x);
        if(z!=ptr->getItem()){
            error++;
        }
        ptr=ptr->getNext();
    }

    if(error==0){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"FAIL WITH ERRORS: " + error<<std::endl;
    }
    ptr=nullptr;
}

void removeTest(){
    std::cout<<"REMOVE AT TEST"<<std::endl;

    IntLinkedList test;
    for(int x=0;x<5;x++){
        test.insertAtEnd(x);
    }

    //remove last item
    int x = test.removeValueAt(4);
    if(x!=4){
        std::cout<<"Fail"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }

    //remove first
    x=test.removeValueAt(0);
    if(x!=0){
        std::cout<<"Fail"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }

    test.clearList();
    for(int x=0;x<5;x++){
        test.insertAtEnd(x);
    }
    test.insertAt(99,3);
    std::cout<<"EXPECT OUT OF RANGE:"<<std::endl;
    try{
        test.removeValueAt(99);
    }catch(std::out_of_range& e){
        std::cout<<"PASS"<<std::endl;
    }

    test.removeValueAt(3);
    int error=0;
    for(int x=0;x<5;x++){
        if(test.getValueAt(x)!=x){
            error++;
        }
    }
    if(error==0){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"Fail with errors: "+error<<std::endl;
    }

    std::cout<<"REMOVING FROM FRONT"<<std::endl;
    test.removeValueAt(0);
    error=0;
    for(int x=1;x<5;x++){
        if(test.getValueAt(x-1)!=x){
            error++;
        }
    }
    if(error==0){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"Fail with errors: "+error<<std::endl;
    }

}

void clearListTest(){
    std::cout<<"TESTING CLEAR LIST"<<std::endl;
    IntLinkedList test;
    for(int x=0;x<2;x++){
        test.insertAtEnd(x);
    }
    test.clearList();
    if(test.isEmpty()){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"FAIL"<<std::endl;
    }
    IntLinkedList test2;
    for(int x=0;x<3;x++){
        test2.insertAtEnd(x);
    }
    test2.clearList();
    if(test2.isEmpty()){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"FAIL"<<std::endl;
    }
    std::cout<<"TESTING EMPTY LIST"<<std::endl;
    IntLinkedList ntest;
    try{
        ntest.clearList();
    }catch(std::out_of_range& e ){
        std::cout<<"PASS"<<std::endl;
    }

}


void toStringTest(){
    IntLinkedList test;
    for(int x=0;x<5;x++){
        test.insertAtEnd(x);
    }
    std::string x = test.toString();
    std::string real = "{0, 1, 2, 3, 4}";
    if(x!=real){
        std::cout<<"YOURE PARENTS THINK YOURE A FAILURE"<<std::endl;
    }else{
        std::cout<<"YOU PREFORMED AS EXPECTED"<<std::endl;
    }

    std::cout<<"TESTING EMPTY LIST"<<std::endl;
    IntLinkedList b;
    x = b.toString();
    std::string doodoo = "{}";
    if(x!=doodoo){
        std::cout<<"YOURE PARENTS THINK YOURE A FAILURE"<<std::endl;
    }else{
        std::cout<<"YOU PREFORMED AS EXPECTED"<<std::endl;
    }
}


void findMaxTest(){
    std::cout<<"FIND MAX TEST"<<std::endl;

    IntLinkedList test;
    for(int x=0;x<5;x++){
        test.insertAtEnd(x*2);
    }

    int end = test.findMaxIndex();

    if(end!=4){
        std::cout<<"FAIL INCCORECT INDEX"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }

    test.insertAt(99,2);
    end = test.findMaxIndex();
    if(end!=2){
        std::cout<<"FAIL INCCORECT INDEX"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }

}

void findTest(){
    std::cout<<"FIND TEST"<<std::endl;
    IntLinkedList test;
    for(int x=0;x<10;x++){
        test.insertAtEnd(x);
    }

    for(int x=0;x<10;x++){
        if(test.find(x)!=x){
            std::cout<<"FIND FAIL"<<std::endl;
        }else{
            std::cout<<"PASS"<<std::endl;
        }
    }

    int nope = test.find(99);
    if(nope==-1){
        std::cout<<"PASS"<<std::endl;
    }else{
        std::cout<<"Fail"<<std::endl;
    }
}


void findLastTEst(){
    std::cout<<"FIND LAST TEST"<<std::endl;

    IntLinkedList poopy;

    for(int x=0;x<5;x++){
        poopy.insertAtEnd(x);
    }

    poopy.insertAt(0,3);
    int pls = poopy.findLast(0);
    if(pls != 3){
        std::cout<<"fail"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }

    if(poopy.findLast(99)!=-1){
        std::cout<<"fail"<<std::endl;
    }else{
        std::cout<<"PASS"<<std::endl;
    }
}



int main() {
    copyConstructorTest();
    insertTest();
    itemCountTest();
    getValueAtTest();
    removeTest();
    clearListTest();
    toStringTest();
    findMaxTest();
    findTest();
    findLastTEst();
    std::cout<<"All Tests Complete"<<std::endl;

}