#ifndef LINKED_LIST
#define LINKED_LIST

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;
    
    SinglyLinkedListNode(int node_data);
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList();

    void insert_node(int node_data);
};

void free_singly_linked_list(SinglyLinkedListNode* node);

#endif