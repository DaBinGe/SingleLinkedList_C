//
//  SingleLinkedList.h
//  SingleLinkTableDemo
//
//  Created by DaDa on 16/3/21.
//  Copyright © 2016年 DaDa. All rights reserved.
//

#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>
#include <stdbool.h>

typedef  long long LongNodeData;

/**
 *  Struct LinkedNode_longLong is the definition of element of single link list.
 *
 *  @param data The data of the link header save the amount of the link,else,
 *              save the data of each element.
 *
 *  @param next The next is the pointer of next element of current element.
 */
typedef struct LinkedNode_longLong {
    LongNodeData data;
    struct LinkedNode_longLong *next;
} LinkedNode_Long,*LinkedList_Long;


#pragma mark tool method
/**
 *  Print the node data
 *
 *  @param headNode
 */
void printLinkedNode(LinkedList_Long headNode);

/**
 *  Print the whole link data
 *
 *  @param headNode the header of link
 */
void printLinkedList(LinkedList_Long headNode);

LongNodeData countOfLinkedList(LinkedList_Long head);

/**
 *  Judging the index is beyond the link or not
 *
 *  @param index
 *  @param head
 *
 *  @return
 */
bool isIndexInsideLinkedList(LongNodeData index,LinkedList_Long head);


#pragma mark create method
/**
 *  Create a node without data and without next node
 *
 *  @return a non-data node
 */
LinkedNode_Long *createHeadNode();

/**
 *  Create one node with data and appending next node
 *
 *  @param data
 *  @param next
 *
 *  @return current node pointer
 */
LinkedNode_Long *createOneNode(LongNodeData data,LinkedNode_Long *next);

/**
 *  Create one link list while inserting the new node into link's front.
 *
 *  @param count number of nodes
 *
 *  @return link list header node pointer
 */
LinkedList_Long createLinkedListAtHeader(int count);

/**
 *  Create a link list while inserting the new node into the link's rear.
 *
 *  @param count amount of link node
 *
 *  @return link header node pointer
 */
LinkedList_Long createLinkedListAtTail(int count);

/**
 *  Create link continously unless entering the exitData to stop
 *
 *  @param exitData   receive it to stop inputing
 *  @param isAtHeader add new node to link header or tail
 *
 *  @return link header node pointer
 */
LinkedList_Long createLinkedListWithExitData(LongNodeData exitData,bool isAtHeader);

/**
 *  Create a link with local data [0...7]
 *
 *  @return link
 */
LinkedList_Long createLinked();

#pragma mark query
/**
 *  Query the lastest node of the link
 *
 *  @param head link header node
 *
 *  @return the lastest node pointer
 */
LinkedList_Long lastNodeOfLinkedList(LinkedList_Long head);

/**
 *  Query the node at index of the link
 *
 *  @param head  link header node
 *  @param index index
 *
 *  @return the found node pointer
 */
LinkedList_Long nodeAtIndex(LinkedList_Long head,LongNodeData index);


#pragma mark add
/**
 *  Insert a new node,inputed instantly, at index of the link
 *
 *  @param head link header node
 *
 *  @return link header node
 */
LinkedList_Long insertOneNodeAtIndex(LinkedList_Long head);

/**
 *  Insert the node into the link at index of the link
 *
 *  @param head  link header node
 *  @param node  node
 *  @param index index
 *
 *  @return link header node
 */
LinkedList_Long insertNodeIntoListAtIndex(LinkedList_Long head,
                                          LinkedList_Long node,
                                          LongNodeData index);


#pragma mark modify
/**
 *  Exchage two data of two node
 *
 *  @param nodeLeft  node one
 *  @param nodeRight node two
 */
void exchangeTwoNodeData(LinkedList_Long nodeLeft,LinkedList_Long nodeRight);

/**
 *  Exchage two node data with two index
 *
 *  @param head       link header node
 *  @param indexLeft  index one
 *  @param indexRight index two
 *
 *  @return link header node
 */
LinkedList_Long exchageTwoNode (LinkedList_Long head,
                                LongNodeData indexLeft,
                                LongNodeData indexRight);

/**
 *  Revert the link by operating its datas
 *
 *  @param head link
 */
void revertLinkedList (LinkedList_Long head);


#pragma mark sort
/**
 *  sort the link's datas
 *
 *  @param head      link header node
 *  @param accending sort by accending or decending
 *
 *  @return the origin link header node
 */
LinkedList_Long sortLinkedList(LinkedList_Long head,bool accending);


#pragma mark delete
/**
 *  Delete one node at index of the link
 *
 *  @param head  link header node
 *  @param index index of the link
 *
 *  @return link header node
 */
LinkedList_Long deleteNodeAtIndex (LinkedList_Long head,LongNodeData index);

/**
 *  Delete the whole link and release the memory,release the header node if
 *  neccessary
 *
 *  @param head link
 *
 *  @return link header node
 */
LinkedList_Long deleteLinkedList (LinkedList_Long head);


#endif /* SingleLinkedList_h */
