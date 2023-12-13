#include "InsertNodeLinkedList.h"

#include <iostream>

using namespace std;

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position)
{
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    if (!llist || position == 0) {
        newNode->next = llist;
        return newNode;
    }
    
    SinglyLinkedListNode* currentNode = llist;
    for (int i = 0; i < position - 1; ++i)
    {
        if (currentNode->next)
            currentNode = currentNode->next;
        else
            break;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    return llist;
    
}

int insertNodePositionLinkedList()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    vector<int> output;
    print_singly_linked_list(llist_head, " ", output);
    
    free_singly_linked_list(llist_head);

    return 0;
}
