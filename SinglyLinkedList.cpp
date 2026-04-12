#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

void SinglyLinkedList::addFront(int value) {
    SLLNode* newNode = new SLLNode(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void SinglyLinkedList::addBack(int value) {
    SLLNode* newNode = new SLLNode(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void SinglyLinkedList::addAt(int index, int value) {
    if (index < 0 || index > size) return;
    if (index == 0) {
        addFront(value);
        return;
    }
    if (index == size) {
        addBack(value);
        return;
    }

    SLLNode* newNode = new SLLNode(value);
    SLLNode* current = head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

void SinglyLinkedList::removeFront() {
    if (!head) return;
    SLLNode* temp = head;
    head = head->next;
    if (!head) {
        tail = nullptr;
    }
    delete temp;
    size--;
}

void SinglyLinkedList::removeBack() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size--;
        return;
    }
    SLLNode* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    size--;
}

void SinglyLinkedList::removeAt(int index) {
    if (index < 0 || index >= size) return;
    if (index == 0) {
        removeFront();
        return;
    }
    if (index == size - 1) {
        removeBack();
        return;
    }

    SLLNode* current = head;
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    SLLNode* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
}

bool SinglyLinkedList::find(int value) const {
    SLLNode* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void SinglyLinkedList::display() const {
    SLLNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void SinglyLinkedList::clear() {
    SLLNode* current = head;
    while (current) {
        SLLNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
    size = 0;
}

int SinglyLinkedList::getSize() const {
    return size;
}

int SinglyLinkedList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    SLLNode* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}
