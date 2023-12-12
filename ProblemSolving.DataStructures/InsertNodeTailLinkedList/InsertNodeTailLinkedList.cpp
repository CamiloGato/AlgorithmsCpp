#include "InsertNodeTailLinkedList.h"

#include <iostream>
#include <vector>

#include "../_Common/SinglyLinkedList.h"

using namespace std;

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data)
{
    
}

int insertNodeTailLinkedList()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
        SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
        llist->head = llist_head;
    }

    vector<int> output;
    print_singly_linked_list(llist->head, "\n", output);
    cout << "\n";

    free_singly_linked_list(llist->head);

    return 0;
}