#include "ArrayList.hpp"

ArrayList::ArrayList() {
    capacity = 1;
    size = 0;
    data = new int[capacity];
}

ArrayList::~ArrayList() {
    delete[] data;
}

void ArrayList::resize(int newCapacity) {
    if (newCapacity < 1) newCapacity = 1;
    int* newData = new int[newCapacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void ArrayList::addFront(int value) {
    addAt(0, value);
}

void ArrayList::addBack(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[size] = value;
    size++;
}

void ArrayList::addAt(int index, int value) {
    if (index < 0 || index > size) {
        return; // out of bounds
    }
    if (size == capacity) {
        resize(capacity * 2);
    }
    for (int i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

void ArrayList::removeFront() {
    removeAt(0);
}

void ArrayList::removeBack() {
    if (size == 0) return;
    removeAt(size - 1);
}

void ArrayList::removeAt(int index) {
    if (index < 0 || index >= size) {
        return; // out of bounds
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
    if (size > 0 && size == capacity / 4) {
        resize(capacity / 2);
    }
}

bool ArrayList::find(int value) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

void ArrayList::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void ArrayList::clear() {
    delete[] data;
    capacity = 1;
    size = 0;
    data = new int[capacity];
}

int ArrayList::getSize() const {
    return size;
}

int ArrayList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}
