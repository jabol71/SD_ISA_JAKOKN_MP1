#pragma once

#include <iostream>
#include <stdexcept>

struct SLLNode {
    int data;
    SLLNode* next;
    SLLNode(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
private:
    SLLNode* head;
    SLLNode* tail;
    int size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void addFront(int value);
    void addBack(int value);
    void addAt(int index, int value);

    void removeFront();
    void removeBack();
    void removeAt(int index);

    bool find(int value) const;
    void display() const;
    void clear();
    int getSize() const;
    int get(int index) const;
};
