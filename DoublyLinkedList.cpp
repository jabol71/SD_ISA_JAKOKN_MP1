#include "DoublyLinkedList.hpp"

// Konstruktor - inicjalizacja pustej listy dwukierunkowej
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destruktor - zwolnienie pamieci wszystkich wezlow
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

// Dodanie elementu na poczatek listy - O(1)
void DoublyLinkedList::addFront(int value) {
    DLLNode* newNode = new DLLNode(value);
    if (!head) {
        head = tail = newNode; // Lista pusta - nowy wezel jest jednoczesnie head i tail
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

// Dodanie elementu na koniec listy - O(1) dzieki wskaznikowi tail
void DoublyLinkedList::addBack(int value) {
    DLLNode* newNode = new DLLNode(value);
    if (!tail) {
        head = tail = newNode; // Lista pusta
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// Dodanie elementu na wskazana pozycje - O(n) traversal do pozycji
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
    // Przejscie do wezla na wskazanej pozycji
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    // Wstawienie nowego wezla przed current
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}

// Usuniecie elementu z poczatku listy - O(1)
void DoublyLinkedList::removeFront() {
    if (!head) return;
    DLLNode* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr; // Lista stala sie pusta
    }
    delete temp;
    size--;
}

// Usuniecie elementu z konca listy - O(1) dzieki wskaznikowi prev w tail
void DoublyLinkedList::removeBack() {
    if (!tail) return;
    DLLNode* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr; // Lista stala sie pusta
    }
    delete temp;
    size--;
}

// Usuniecie elementu z wskazanej pozycji - O(n) traversal do pozycji
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
    // Przejscie do wezla na wskazanej pozycji
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    // Przepiecie wskaznikow sasiadow i usuniecie wezla
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

// Wyszukiwanie elementu w liscie - przeszukiwanie liniowe O(n)
bool DoublyLinkedList::find(int value) const {
    DLLNode* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

// Wyswietlenie wszystkich elementow listy od poczatku
void DoublyLinkedList::display() const {
    DLLNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Wyswietlenie wszystkich elementow listy od konca (w odwrotnej kolejnosci)
void DoublyLinkedList::displayReverse() const {
    DLLNode* current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

// Wyczyszczenie listy - usuniecie wszystkich wezlow i zwolnienie pamieci
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

// Zwrocenie aktualnego rozmiaru listy
int DoublyLinkedList::getSize() const {
    return size;
}

// Pobranie elementu o wskazanym indeksie - optymalizacja: szukanie od blizszego konca
int DoublyLinkedList::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    DLLNode* current;
    if (index < size / 2) {
        // Indeks blizej poczatku - szukanie od head
        current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        // Indeks blizej konca - szukanie od tail
        current = tail;
        for (int i = size - 1; i > index; --i) {
            current = current->prev;
        }
    }
    return current->data;
}
