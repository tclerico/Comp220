#include <iostream>
#include "ListTests.h"
#include "IntList.h"
#include "ArrayList.h"
#include "IntLinkedList.h"

void testAllForList(IntList* list1, IntList* list2){
    rangeErrorTests(list1);

    int a1[] {3, 5, 7, 9};
    insertAtFrontAndEndIsEmptyClearTester(list1, list2, a1, 4);
    list1->clearList();
    list2->clearList();

    int a2[] {-1, -3, -43, -654, -3, 0, -2, -24};
    insertAtFrontAndEndIsEmptyClearTester(list1, list2, a2,8);
    list1->clearList();
    list2->clearList();

    insertAtTester(list1);
    list1->clearList();

    findTester(list1);
    list1->clearList();
}

int main() {
    IntList* testList1 = new ArrayList();
    IntList* testList2 = new ArrayList();
    printf("\n*************************\nTESTING WITH ARRAY LIST:\n*************************\n");
    testAllForList(testList1, testList2);
    delete testList1;
    delete testList2;


    testList1 = new IntLinkedList();
    testList2 = new IntLinkedList();
    printf("\n*************************\nTESTING WITH LINKED LIST:\n*************************\n");
    testAllForList(testList1, testList2);
    delete testList1;
    delete testList2;

    return 0;
}