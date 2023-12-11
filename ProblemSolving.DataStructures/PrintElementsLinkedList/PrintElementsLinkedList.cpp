#include "PrintElementsLinkedList.h"
#include "../_Common/SinglyLinkedList.h"
#include <iostream>

using namespace std;

void printLinkedList(SinglyLinkedListNode* head)
{
    cout << head->data << endl;
    if (head->next != nullptr)
        printLinkedList(head->next);
}

int printElementsLinkedList()
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

    printLinkedList(llist->head);

    return 0;
}
