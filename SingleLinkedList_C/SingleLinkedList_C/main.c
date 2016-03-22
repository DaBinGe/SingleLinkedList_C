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

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    
    testSingleLinkedList();
    
    return 0;
}

void testSingleLinkedList() {
//    LinkedList_Long head = createLinkedListAtHeader(6);
//    printLinkedList(head);

//    LinkedList_Long head = createLinkedListAtTail(6);
//    printLinkedList(head);
    
    LinkedList_Long head = createLinkedListWithExitData(EOF, 0);
    printLinkedList(head);
    
//    LinkedList_Long lastNode = lastNodeOfLinkedList(head);
//    printLinkedNode(lastNode);

//    LinkedList_Long node = nodeAtIndex(head, 3);
//    printLinkedNode(node);

//    head = insertOneNodeAtIndex(head);
//    printLinkedList(head);

//    head = insertNodeIntoListAtIndex(head, createOneNode(100, NULL), 0);
//    printLinkedList(head);

//    head = sortLinkedList(head, YES);
//    printLinkedList(head);

//    head = deleteNodeAtIndex(head, 0.5);
//    printLinkedList(head);

//    head = deleteLinkedList(head);
//    printLinkedList(head);

//    head = exchageTwoNode(head, 0, head->data - 1);
//    printLinkedList(head);
    
    revertLinkedList(head);
    printLinkedList(head);
}
