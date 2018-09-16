//
//  BST.cpp
//  TreeProject
//
//  Created by Toby Dragon on 11/13/14.
//  Copyright (c) 2014 Toby Dragon. All rights reserved.
//
//Submitted by TIM CLERICO

#include <iostream>
#include "BST.h"

BST::BST(){
    root = nullptr;
}

void deleteSubTree(BTNode* current){
    if (current != nullptr) {
        deleteSubTree(current->getLeft());
        deleteSubTree(current->getRight());
        delete current;
    }
}


BTNode* copy(BTNode* current){
    if(current!=nullptr){
        BTNode* cNode = new BTNode(current->getItem());

        BTNode* left = copy(current->getLeft());
        cNode->setLeft(left);

        BTNode* right = copy(current->getRight());
        cNode->setRight(right);

        return cNode;
    }else{
        return nullptr;
    }

}

//copy constructor
//BIG O: O(N)
BST::BST(const BST& treeToCopy){
    if(root==nullptr){
        throw std::out_of_range("EMPTY TREE");
    }else{
       this->root = copy(treeToCopy.root);
    }


}

//Assignment Operator
//BIG O: O(N)
BST& BST::operator=(const BST& treeToCopy){
    if(this!=&treeToCopy){
        if (this->root==nullptr){
            throw std::out_of_range("EMPTY TREE");
        }else{
            deleteSubTree(this->root);
            this->root = copy(treeToCopy.root);
        }
    }
    return *this;
}

//destructor
//BIG O: O(N)
BST::~BST(){
    deleteSubTree(root);
}

void add(BTNode* current,  int newValue){
    if (newValue == current->getItem()){
        throw DuplicateValueException();
    }
    else if (newValue < current->getItem()){
        BTNode* child = current->getLeft();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setLeft(new BTNode(newValue));
        }
    }
    else { //newValue > current->getItem()
        BTNode* child = current->getRight();
        if (child != nullptr){
            add(child, newValue);
        }
        else {
            current->setRight(new BTNode(newValue));
        }
    }
}

//Big O: O(H)
void BST::add(int newValue){
    if (root == nullptr){
        root = new BTNode(newValue);
    }
    else {
        ::add(root, newValue);
    }
}

bool find(BTNode *current, int itemToFind) {
    if (current == nullptr){
        return false;
    }
    else {
        if (current->getItem() == itemToFind) {
            return true;
        } else if (current->getItem() > itemToFind) {
            return find(current->getLeft(), itemToFind);
        } else {
            return find(current->getRight(), itemToFind);
        }
    }
}

//BIG O: O(H)
bool BST::find(int itemToFind) {
    return ::find(root, itemToFind);
}

void printInOrder(BTNode* current){
    if(current!=nullptr){
        printInOrder(current->getLeft());
        std::cout<< current->getItem() << std::endl;
        printInOrder(current->getRight());
    }
}
//Big O: O(N)
void BST::printInOrder(){
    ::printInOrder(root);
}

int itemCount(BTNode* current){
    if(current!=nullptr){
        int countLeft = itemCount(current->getLeft());
        int countRight = itemCount(current->getRight());
        int count = countLeft + countRight + 1;
        return count;

    }else{
        return 0;
    }
}
//BIG O: O(N)
int BST::itemCount(){
    return ::itemCount(root);
}

int height(BTNode* current){
    if(current!=nullptr){
        int countLeft = height(current->getLeft());
        int countRight = height(current->getRight());
        if(countLeft>countRight){
            return countLeft+1;
        }else{
            return countRight+1;
        }

    }else{
        return -1;
    }
}

//BIG O: O(N)
int BST::height(){
    return ::height(root);
}

int max(BTNode* current){
    if(current->getRight() != nullptr){
        int great = max(current->getRight());
        return great;
    }else{
        return current->getItem();
    }
}

//BIG O: O(H)
int BST::max(){
   //max value in a tree is the bottom right corner (go all the way down the right branch)
    if(root == nullptr){
        throw std::out_of_range("TREE IS EMPTY");
    }else{
        return ::max(root);
    }


}







