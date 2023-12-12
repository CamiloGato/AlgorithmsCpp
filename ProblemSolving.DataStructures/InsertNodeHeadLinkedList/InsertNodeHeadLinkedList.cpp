#include "InsertNodeHeadLinkedList.h"

#include <iostream>

#include "../_Common/SinglyLinkedList.h"

using namespace std;

SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data)
{
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    if (llist == nullptr) {
        return newNode;
    }
    
    newNode->next = llist;
    return newNode;
}

int insertNodeHeadLinkedList()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        SinglyLinkedListNode* llist_head = insertNodeAtHead(llist->head, llist_item);
        llist->head = llist_head;
    }

    vector<int> output;
    print_singly_linked_list(llist->head, "\n", output);
    cout << "\n";

    free_singly_linked_list(llist->head);

    return 0;
}