# SingleLinkedList_C
Basic operations of single linked list,such as create,modify,query,delete,sort,revert,etc. in C language.

IDE:  Mac OS EI Capitan 10.11.3,Xcode 7.2 (7C68)

# Usage
Opening main.c by Xcode or another IDE in your PC,there are five parts of test method:
Create,query,add,modify,sort,delete.
Then,making the **comment selections** avalible or unavalible you need of the methods or functions.
Lastly,run.

If you want to test sort Method,you should make testSortMethod(head); avalible.

```
void testSingleLinkedList() {
//    testCreateMethods();
    
//    testQueryMethod();
    
    LinkedList_Long head = createLinked();
    
//    testAddMethod(head);
    
//    testModifyMethod(head);
    
    testSortMethod(head);
    
//    testDeleteMethod(head);
    
}

```

If you want to exchage two node,but not revert linked:

```
void testModifyMethod(LinkedList_Long head) {
    printLinkedList(head);
    
    head = exchageTwoNode(head, 0, head->data - 1);
    printLinkedList(head);

//    revertLinkedList(head);
//    printLinkedList(head);

}
```
