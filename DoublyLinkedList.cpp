#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

void DoublyLinkedList::addFront(int value) {
    DLLNode* newNode = new DLLNode(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::addBack(int value) {
    DLLNode* newNode = new DLLNode(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::addAt(int index, int value) {
    if (index < 0 || index > size) return;
    if (index == 0) {
        addFront(value);
        return;
    }
    if (index == size) {
        addBack(value);
        return;
    }

    DLLNode* newNode = new DLLNode(value);
    DLLNode* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}

void DoublyLinkedList::removeFront() {
    if (!head) return;
    DLLNode* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    size--;
}

void DoublyLinkedList::removeBack() {
    if (!tail) return;
    DLLNode* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    size--;
}

void DoublyLinkedList::removeAt(int index) {
    if (index < 0 || index >= size) return;
    if (index == 0) {
        removeFront();
        return;
    }
    if (index == size - 1) {
        removeBack();
        return;
    }

    DLLNode* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

bool DoublyLinkedList::find(int value) const {
    DLLNode* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::display() const {
    DLLNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::displayReverse() const {
    DLLNode* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::clear() {
    DLLNode* current = head;
    while (current) {
        DLLNode* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = tail = nullptr;
    size = 0;
}

int DoublyLinkedList::getSize() const {
    return size;
}

int DoublyLinkedList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    DLLNode* current;
    if (index < size / 2) {
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        current = tail;
        for (int i = size - 1; i > index; --i) {
            current = current->prev;
        }
    }
    return current->data;
}
