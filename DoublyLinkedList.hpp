#pragma once

#include <iostream>
#include <stdexcept>

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    DLLNode* head;
    DLLNode* tail;
    int size;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addFront(int value);
    void addBack(int value);
    void addAt(int index, int value);

    void removeFront();
    void removeBack();
    void removeAt(int index);

    bool find(int value) const;
    void display() const;
    void displayReverse() const;
    void clear();
    int getSize() const;
    int get(int index) const;
};
