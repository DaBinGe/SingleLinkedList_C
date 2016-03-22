//
//  SingleLinkedList.c
//  SingleLinkTableDemo
//
//  Created by DaDa on 16/3/21.
//  Copyright © 2016年 DaDa. All rights reserved.
//

#include "SingleLinkedList.h"
#include <stdlib.h>

#pragma mark tool method
static const char *MallocFailedMsg = "Memory exhausted or can not get enough continous memory.\n";

void printMallocFailedMsg() {
    printf("%s",MallocFailedMsg);
}

/**
 *  Print the node data
 *
 *  @param headNode
 */
void printLinkedNode(LinkedList_Long headNode) {
    if (headNode == NULL) {
        printf("The node is NULL.\n");
        return;
    }
    printf("The node data is %lld.\n",headNode->data);
}

/**
 *  Print the whole link data
 *
 *  @param headNode the header of link
 */
void printLinkedList(LinkedList_Long headNode) {
    LinkedList_Long pNext = headNode->next;
    printf("The linked list has %lld nodes,it is : \n",headNode->data);
    
    while (pNext != NULL) {
        printf("%lld, ",pNext->data);
        pNext = pNext->next;
    }
    printf("\n");
}

LongNodeData countOfLinkedList(LinkedList_Long head) {
    return head->data;
}

/**
 *  Judging the index is beyond the link or not
 *
 *  @param index
 *  @param head
 *
 *  @return
 */
bool isIndexInsideLinkedList(LongNodeData index,LinkedList_Long head) {
    if (index >= head->data) {
        printf("Index %lld beyond bounds [0...%lld].\n",index,head->data - 1);
        return 0;
    }
    return 1;
}

#pragma mark create method
/**
 *  Create a node without data and without next node
 *
 *  @return a non-data node
 */
LinkedNode_Long *createHeadNode() {
    LinkedNode_Long *headNode = (LinkedNode_Long*)malloc(sizeof(LinkedNode_Long));
    if (headNode == NULL) {
        printMallocFailedMsg();
        return NULL;
    }
    headNode->data = 0;//save the amount of node
    headNode->next = NULL;
    return headNode;
}

/**
 *  Create one node with data and appending next node
 *
 *  @param data
 *  @param next
 *
 *  @return current node pointer
 */
LinkedNode_Long *createOneNode(LongNodeData data,LinkedNode_Long *next) {
    LinkedNode_Long *node = createHeadNode();
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = next;
    return node;
}

/**
 *  Create one link list while inserting the new node into link's front.
 *
 *  @param count number of nodes
 *
 *  @return link list header node pointer
 */
LinkedList_Long createLinkedListAtHeader(int count) {
    LinkedList_Long head = createHeadNode();
    if (head == NULL) {
        return NULL;
    }
    if (count < 1) {
        printf("Please enter a positive integer.\n");
        return NULL;
    }
    
    LinkedList_Long pLast = NULL;
    LongNodeData amount = 0;//number of nodes
    
    for (int index = 0; index < count; index++) {
        LinkedList_Long pNext = createHeadNode();
        if (pNext == NULL) {
            printf("Create node failed\n");//return NULL if neccessory
            break;
        }
        
        printf("Enter a integer,%d integer will be entered later.\n",count - index);
        scanf("%lld",&pNext->data);
        
        if (amount == 0) {//the first node
            pLast = pNext;
            amount++;
            continue;
        }
        
        //add the node to the link "head"
        pNext->next = pLast;
        pLast = pNext;
        amount++;
    }
    
    head->next = pLast;
    head->data = amount;
    
    return head;
}

/**
 *  Create a link list while inserting the new node into the link's rear.
 *
 *  @param count amount of link node
 *
 *  @return link header node pointer
 */
LinkedList_Long createLinkedListAtTail(int count) {
    LinkedList_Long head = createHeadNode();
    if (head == NULL) {
        return NULL;
    }
    if (count < 1) {
        printf("Please enter a positive integer.\n");
        return NULL;
    }
    
    LinkedList_Long pLast = head;
    LongNodeData nodeNum = 0;
    for (int index = 0; index < count; index++) {
        LinkedList_Long pNext = createHeadNode();
        if (pNext == NULL) {
            printf("create node failed.");
            break;
        }
        printf("Enter a integer,%d integer will be entered later.\n",count - index);
        scanf("%lld",&pNext->data);
        
        //append the node to the link "head"
        pLast->next = pNext;
        pLast = pNext;
        nodeNum++;
    }
    
    head->data = nodeNum;
    return head;
}

/**
 *  Create link continously unless entering the exitData to stop
 *
 *  @param exitData   receive it to stop inputing
 *  @param isAtHeader add new node to link header or tail
 *
 *  @return link header node pointer
 */
LinkedList_Long createLinkedListWithExitData(LongNodeData exitData,bool isAtHeader) {
    LinkedList_Long head = createHeadNode();
    if (head == NULL) {
        return NULL;
    }
    LongNodeData amount = 0;
    LinkedList_Long pLast = isAtHeader ? NULL : head;
    
    while (1) {
        LinkedList_Long pNext = createHeadNode();
        if (pNext == NULL) {
            break;
        }
        printf("Enter an integer data,enter %lld to exit the creating.\n",exitData);
        scanf("%lld",&pNext->data);
        if (pNext->data == exitData) {
            break;
        }
        if (isAtHeader) {//add to header
            if (amount != 0) {//is not the first node
                pNext->next = pLast;
            }
        }else {//add to tail
            pLast->next = pNext;
        }
        pLast = pNext;
        amount++;
    }
    head->data = amount;
    if (isAtHeader) {
        head->next = pLast;
    }
    return head;
}

/**
 *  Create a link with local data [0...7]
 *
 *  @return link
 */
LinkedList_Long createLinked() {
    LinkedList_Long head = createHeadNode();
    if (head == NULL) {
        return NULL;
    }
    LongNodeData amount = 0;
    LinkedList_Long pLast = NULL;
    for (LongNodeData index = 0; index < 8; index++) {
        LinkedList_Long pNext = createHeadNode();
        if (pNext == NULL) {
            return head;
        }
        if (!index) {//append the first node to header
            pLast = pNext;
            head->next = pLast;
        }else {//appending the node to last node
            pLast->next = pNext;
            pLast = pNext;
        }
        pNext->data = index;
        amount++;
    }
    head->data = amount;
    
    return head;
}

#pragma mark query
/**
 *  Query the lastest node of the link
 *
 *  @param head link header node
 *
 *  @return the lastest node pointer
 */
LinkedList_Long lastNodeOfLinkedList(LinkedList_Long head) {
    if (head == NULL) {
        return NULL;
    }
    LinkedList_Long pNext = head->next;
    if (pNext == NULL) {
        return NULL;
    }
    while (pNext->next) {
        pNext = pNext->next;
    }
    return pNext;
}

/**
 *  Query the node at index of the link
 *
 *  @param head  link header node
 *  @param index index
 *
 *  @return the found node pointer
 */
LinkedList_Long nodeAtIndex(LinkedList_Long head,LongNodeData index) {
    if (head == NULL) {
        return NULL;
    }
    if (index < 0) {
        printf("Please enter an non-negative integer.\n");
        return NULL;
    }
    if (index >= head->data) {
        printf("The index %lld beyond bounds [0...%lld],and \n"
               "please be sure the index is counted from 0.\n",index,head->data - 1);
        return NULL;
    }
    
    LinkedList_Long pNext = head->next;
    LongNodeData num = 0;
    while (pNext && num < index) {
        pNext = pNext->next;
        num++;
    }
    return pNext;
}

#pragma mark add
/**
 *  Insert a new node,inputed instantly, at index of the link
 *
 *  @param head link header node
 *
 *  @return link header node
 */
LinkedList_Long insertOneNodeAtIndex(LinkedList_Long head) {
    if (head == NULL) {
        printf("Insert failed,as the linked list is NULL.");
        return head;
    }
    LinkedList_Long node = createHeadNode();
    if (node == NULL) {
        printf("Insert failed for the sake of memory error.\n");
        return head;
    }
    LongNodeData index = 0;
    printf("Enter the index,a non-negative integer,as the insert location.\n");
    scanf("%lld",&index);
    while (!isIndexInsideLinkedList(index, head)) {
        printf("please enter agan.\n");
        index = 0;
        scanf("%lld",&index);
    }
    printf("please enter the data.\n");
    scanf("%lld",&node->data);
    
    if (index < 0) {
        index = 0;
    }
    return insertNodeIntoListAtIndex(head, node, index);
}

/**
 *  Insert the node into the link at index of the link
 *
 *  @param head  link header node
 *  @param node  node
 *  @param index index
 *
 *  @return link header node
 */
LinkedList_Long insertNodeIntoListAtIndex(LinkedList_Long head,LinkedList_Long node,LongNodeData index) {
    if (head == NULL) {
        return NULL;
    }
    if (node == NULL) {
        printf("Insert failed,because the node is NULL.\n");
        return head;
    }
    if ((*head).next == NULL) {//node count is 0
        (*head).next = node;
        return head;
    }
    if (index > (*head).data - 1) {
        LinkedList_Long tailNode = lastNodeOfLinkedList(head);
        (*tailNode).next = node;

    }else {
        if (index == 0) {
            (*node).next = (*head).next;
            (*head).next = node;
        }else {
            LinkedList_Long lastNode = nodeAtIndex(head, index - 1);
            if (lastNode == NULL) {
                printf("Got node at index failed!\n");
                return head;
            }
            (*node).next = (*lastNode).next;
            (*lastNode).next = node;
        }
    }
    
    return head;
}

#pragma mark modify
/**
 *  Exchage two data of two node
 *
 *  @param nodeLeft  node one
 *  @param nodeRight node two
 */
void exchangeTwoNodeData(LinkedList_Long nodeLeft,LinkedList_Long nodeRight) {
    LongNodeData data = nodeLeft->data;
    nodeLeft->data = nodeRight->data;
    nodeRight->data = data;
}

/**
 *  Exchage two node data with two index
 *
 *  @param head       link header node
 *  @param indexLeft  index one
 *  @param indexRight index two
 *
 *  @return link header node
 */
LinkedList_Long exchageTwoNode (LinkedList_Long head,LongNodeData indexLeft,LongNodeData indexRight) {
    if (head == NULL) {
        printf("Exchaged failed.The linkedList is NULL\n");
        return head;
    }
    if (head->data < 1) {
        printf("Exchaged failed.The linkedList has nodes less than 2.\n");
        return head;
    }
    if (indexRight == indexLeft) {
        return head;
    }
    if (!isIndexInsideLinkedList(indexLeft, head) || !isIndexInsideLinkedList(indexRight, head)) {
        return head;
    }
    
    printf("Begin exchaging two node.\n");
    LinkedList_Long nodeLeft = nodeAtIndex(head, indexLeft);
    LinkedList_Long nodeRight = nodeAtIndex(head, indexRight);
    exchangeTwoNodeData(nodeLeft, nodeRight);
    return head;
}

/**
 *  Revert the link by operating its datas
 *
 *  @param head link
 */
void revertLinkedList (LinkedList_Long head) {
    if (head == NULL) {
        printf("Revert failed,the linkedList is NULL.\n");
        return;
    }
    LongNodeData count = head->data - 1;
    if (count < 2) {
        return;
    }
    for (LongNodeData index = 0; index < count; index++,count--) {
        exchageTwoNode(head, index, count);
    }
}

#pragma mark sort
/**
 *  sort the link's datas
 *
 *  @param head      link header node
 *  @param accending sort by accending or decending
 *
 *  @return the origin link header node
 */
LinkedList_Long sortLinkedList(LinkedList_Long head,bool accending) {
    //mode 1,using node count
    if (head->data < 1) {
        return head;
    }
    LinkedList_Long node = head->next;
    for (LongNodeData row = 0; row < head->data - 1; row++) {
        LinkedList_Long pNext = node->next;
        if (pNext == NULL || node == NULL) {
            break;
        }
        for (LongNodeData coloum = 0; coloum < head->data; coloum++) {
            if (accending) {
                if (node->data > pNext->data) {
                    exchangeTwoNodeData(node, pNext);
                }
            }else {
                if (node->data < pNext->data) {
                    exchangeTwoNodeData(node, pNext);
                }
            }
            pNext = pNext->next;
            if (pNext == NULL) {
                break;
            }
        }
        node = node->next;
    }
    
    return head;
    
    //mode 2,using pointer
    if (head->next == NULL) {
        return head;
    }
    LinkedList_Long qNode = head->next;
    while (qNode) {
        LinkedList_Long qNext = qNode->next;
        while (qNext) {
            if (accending) {
                if (qNode->data > qNext->data) {
                    exchangeTwoNodeData(qNode, qNext);
                }
            }else {
                if (qNode->data < qNext->data) {
                    exchangeTwoNodeData(qNode, qNext);
                }
            }
            qNext = qNext->next;
        }
        qNode = qNode->next;
    }
    return head;
}

#pragma mark delete
/**
 *  Delete one node at index of the link
 *
 *  @param head  link header node
 *  @param index index of the link
 *
 *  @return link header node
 */
LinkedList_Long deleteNodeAtIndex (LinkedList_Long head,LongNodeData index) {
    if (head == NULL) {
        printf("Delete failed,the linked list is NULL.\n");
        return head;
    }
    if (head->next == NULL) {
        printf("Delete failed,the linked list's node count is 0.\n");
        return head;
    }
    if (index >= head->data) {
        printf("Delete failed,index %lld beyond bounds [0...%lld].\n",index,head->data);
        return head;
    }
    if (index == 0) {
        LinkedList_Long node = nodeAtIndex(head, 0);
        head->next = node->next;
        node->next = NULL;
        free(node);
        
    }else {
        LinkedList_Long node = nodeAtIndex(head, index - 1);
        LinkedList_Long nodeDelete = node->next;
        node->next = nodeDelete->next;
        nodeDelete = NULL;
        free(nodeDelete);
        
    }
    head->data--;
    return head;
}

/**
 *  Delete the whole link and release the memory,release the header node if
 *  neccessary
 *
 *  @param head link
 *
 *  @return link header node
 */
LinkedList_Long deleteLinkedList (LinkedList_Long head) {
    if (head == NULL) {
        printf("The linkedList is NULL.\n");
        return NULL;
    }
    LinkedList_Long list = head->next;
    if (list == NULL) {
        printf("The LinkedList has no node.\n");
        return head;
    }
    LongNodeData index = 0;
    while (list) {
        LinkedList_Long node = list;
        list = list->next;
        printf("delete node %lld at index %lld.\n",node->data,index++);
        node->next = NULL;
        node = NULL;
        free(node);
        head->data--;
    }
    head->next = NULL;
    free(head->next);
    
    return head;
}





