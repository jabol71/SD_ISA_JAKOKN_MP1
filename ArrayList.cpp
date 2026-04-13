#include "ArrayList.hpp"

// Konstruktor - inicjalizacja tablicy dynamicznej o poczatkowej pojemnosci 1
ArrayList::ArrayList() {
    capacity = 1;
    size = 0;
    data = new int[capacity];
}

// Destruktor - zwolnienie pamieci zaalokowanej na tablice
ArrayList::~ArrayList() {
    delete[] data;
}

// Zmiana rozmiaru tablicy - alokacja nowej tablicy i skopiowanie danych
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

// Dodanie elementu na poczatek tablicy - delegacja do addAt z indeksem 0
void ArrayList::addFront(int value) {
    addAt(0, value);
}

// Dodanie elementu na koniec tablicy - podwojenie pojemnosci jesli brak miejsca
void ArrayList::addBack(int value) {
    if (size == capacity) {
        resize(capacity * 2); // Podwojenie rozmiaru tablicy
    }
    data[size] = value;
    size++;
}

// Dodanie elementu na wskazana pozycje - przesuniecie elementow w prawo
void ArrayList::addAt(int index, int value) {
    if (index < 0 || index > size) {
        return; // Indeks poza zakresem
    }
    if (size == capacity) {
        resize(capacity * 2); // Podwojenie rozmiaru tablicy
    }
    // Przesuniecie elementow o jedna pozycje w prawo
    for (int i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

// Usuniecie elementu z poczatku tablicy
void ArrayList::removeFront() {
    removeAt(0);
}

// Usuniecie elementu z konca tablicy
void ArrayList::removeBack() {
    if (size == 0) return;
    removeAt(size - 1);
}

// Usuniecie elementu z wskazanej pozycji - przesuniecie elementow w lewo
void ArrayList::removeAt(int index) {
    if (index < 0 || index >= size) {
        return; // Indeks poza zakresem
    }
    // Przesuniecie elementow o jedna pozycje w lewo
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
    // Zmniejszenie tablicy gdy zajmuje tylko 1/4 pojemnosci
    if (size > 0 && size == capacity / 4) {
        resize(capacity / 2);
    }
}

// Wyszukiwanie elementu w tablicy - przeszukiwanie liniowe
bool ArrayList::find(int value) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

// Wyswietlenie wszystkich elementow tablicy
void ArrayList::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

// Wyczyszczenie tablicy - zwolnienie pamieci i reset do stanu poczatkowego
void ArrayList::clear() {
    delete[] data;
    capacity = 1;
    size = 0;
    data = new int[capacity];
}

// Zwrocenie aktualnego rozmiaru tablicy
int ArrayList::getSize() const {
    return size;
}

// Pobranie elementu o wskazanym indeksie
int ArrayList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}
