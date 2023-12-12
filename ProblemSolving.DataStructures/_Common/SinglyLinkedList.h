#ifndef LINKED_LIST
#define LINKED_LIST
#include <string>
#include <vector>

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

void print_singly_linked_list(const SinglyLinkedListNode* node, const std::string& sep, std::vector<int>& fOut);
void free_singly_linked_list(SinglyLinkedListNode* node);

#endif