//
//  main.c
//  SingleLinkedList_C
//
//  Created by DaDa on 16/3/22.
//  Copyright © 2016年 DaDa. All rights reserved.
//

#include <stdio.h>
#include "SingleLinkedList.h"

void testSingleLinkedList();
void testCreateMethods();
void testQueryMethod();
void testAddMethod(LinkedList_Long head);
void testModifyMethod(LinkedList_Long head);
void testSortMethod(LinkedList_Long head);
void testDeleteMethod(LinkedList_Long head);

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    
    testSingleLinkedList();
    
    return 0;
}

void testSingleLinkedList() {
//    testCreateMethods();
    
//    testQueryMethod();
    
    LinkedList_Long head = createLinked();
    
//    testModifyMethod(head);
    
//    testSortMethod(head);
    
    testDeleteMethod(head);
    
}

void testCreateMethods() {
//    LinkedList_Long head = createLinkedListAtHeader(6);
//    printLinkedList(head);

//    LinkedList_Long head = createLinkedListAtTail(6);
//    printLinkedList(head);

//    LinkedList_Long head = createLinkedListWithExitData(EOF, 0);
//    printLinkedList(head);
    
    LinkedList_Long head = createLinked();
    printLinkedList(head);

}

void testQueryMethod() {
    LinkedList_Long head = createLinkedListWithExitData(EOF, 0);
    printLinkedList(head);

//    LinkedList_Long lastNode = lastNodeOfLinkedList(head);
//    printLinkedNode(lastNode);
    
    LongNodeData index = 3;
    LinkedList_Long node = nodeAtIndex(head, index);
    printf("The index is %lld.",index);
    printLinkedNode(node);

}

void testAddMethod(LinkedList_Long head) {
    printLinkedList(head);

//    head = insertOneNodeAtIndex(head);
//    printLinkedList(head);
    
    head = insertNodeIntoListAtIndex(head, createOneNode(100, NULL), 0);
    printLinkedList(head);

}

void testModifyMethod(LinkedList_Long head) {
    printLinkedList(head);
    
//    head = exchageTwoNode(head, 0, head->data - 1);
//    printLinkedList(head);

    revertLinkedList(head);
    printLinkedList(head);

}

void testSortMethod(LinkedList_Long head) {
    printLinkedList(head);
    head = sortLinkedList(head, 1);
    printf("*******  Sort results  *****\n");
    printLinkedList(head);

}

void testDeleteMethod(LinkedList_Long head) {
    printLinkedList(head);
    
//    head = deleteNodeAtIndex(head, 0.5);
//    printLinkedList(head);
    
    head = deleteLinkedList(head);
    printLinkedList(head);

}
