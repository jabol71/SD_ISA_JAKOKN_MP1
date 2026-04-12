#pragma once

#include <iostream>
#include <stdexcept>

class ArrayList {
private:
    int* data;
    int capacity;
    int size;

    void resize(int newCapacity);

public:
    ArrayList();
    ~ArrayList();

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
