#include "ReverseLinkedList.h"

#include <iostream>

using namespace std;

SinglyLinkedListNode* reverse(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* current = head;
    SinglyLinkedListNode* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int reverseLinkedList()
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

        SinglyLinkedListNode* llist1 = reverse(llist->head);

        vector<int> output;
        print_singly_linked_list(llist1, " ", output);
        cout << "\n";

        free_singly_linked_list(llist1);
    }

    return 0;
}
