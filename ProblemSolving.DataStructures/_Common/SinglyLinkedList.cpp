#include "SinglyLinkedList.h"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

SinglyLinkedListNode::SinglyLinkedListNode(const int node_data) {
    this->data = node_data;
    this->next = nullptr;
}

SinglyLinkedList::SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void print_singly_linked_list(const SinglyLinkedListNode* node, const std::string& sep, std::vector<int>& fOut) {
    while (node) {
        fOut.emplace_back(node->data);
        std::cout << node->data << std::endl; 
        node = node->next;
    }
}

void SinglyLinkedList::insert_node(const int node_data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!this->head) {
        this->head = node;
    } else {
        this->tail->next = node;
    }

    this->tail = node;
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}
