#include "DeleteNodeLinkedList.h"

#include <iostream>

using namespace std;

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position)
{
    if (!llist || position < 0) return llist;

    if (position == 0)
    {
        SinglyLinkedListNode* nodeToDelete = llist;
        llist = llist->next;
        delete nodeToDelete;  // Use 'delete' for memory allocated with 'new'
        return llist;
    }

    SinglyLinkedListNode* currentNode = llist;
    for (int i = 0; i < position-1; ++i)
    {
        if (currentNode->next == nullptr) return llist;  // Position out of range, do nothing
        currentNode = currentNode->next;
    }
    SinglyLinkedListNode* nodeToDelete = currentNode->next;
    currentNode->next = currentNode->next->next;
    delete nodeToDelete;
    return llist;
}

int deleteNodeLinkedList()
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

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);

    vector<int> output;
    print_singly_linked_list(llist1, " ", output);
    cout << "\n";

    free_singly_linked_list(llist1);

    return 0;
}