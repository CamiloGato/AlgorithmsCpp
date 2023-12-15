#include "PrintNodeReverseLinkedList.h"

#include <iostream>

using namespace std;

void reversePrint(SinglyLinkedListNode* llist)
{
    if (llist == nullptr) return;
    reversePrint(llist->next);
    cout << llist->data << '\n';
}

int printNodeReverseLinkedList()
{
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
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

        reversePrint(llist->head);
    }

    return 0;
}