#include "SinglyLinkedList.hpp"

// Konstruktor - inicjalizacja pustej listy jednokierunkowej
SinglyLinkedList::SinglyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destruktor - zwolnienie pamieci wszystkich wezlow
SinglyLinkedList::~SinglyLinkedList() {
    clear();
}

// Dodanie elementu na poczatek listy - O(1)
void SinglyLinkedList::addFront(int value) {
    SLLNode* newNode = new SLLNode(value);
    if (!head) {
        head = tail = newNode; // Lista pusta - nowy wezel jest jednoczesnie head i tail
    } else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

// Dodanie elementu na koniec listy - O(1) dzieki wskaznikowi tail
void SinglyLinkedList::addBack(int value) {
    SLLNode* newNode = new SLLNode(value);
    if (!tail) {
        head = tail = newNode; // Lista pusta
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// Dodanie elementu na wskazana pozycje - O(n) traversal do pozycji
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
    // Przejscie do wezla poprzedzajacego wskazana pozycje
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;
}

// Usuniecie elementu z poczatku listy - O(1)
void SinglyLinkedList::removeFront() {
    if (!head) return;
    SLLNode* temp = head;
    head = head->next;
    if (!head) {
        tail = nullptr; // Lista stala sie pusta
    }
    delete temp;
    size--;
}

// Usuniecie elementu z konca listy - O(n) wymaga traversal do przedostatniego wezla
void SinglyLinkedList::removeBack() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size--;
        return;
    }
    // Przejscie do przedostatniego wezla
    SLLNode* current = head;
    while (current->next != tail) {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = nullptr;
    size--;
}

// Usuniecie elementu z wskazanej pozycji - O(n) traversal do pozycji
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
    // Przejscie do wezla poprzedzajacego usuwany
    for (int i = 0; i < index - 1; ++i) {
        current = current->next;
    }
    SLLNode* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
}

// Wyszukiwanie elementu w liscie - przeszukiwanie liniowe O(n)
bool SinglyLinkedList::find(int value) const {
    SLLNode* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

// Wyswietlenie wszystkich elementow listy
void SinglyLinkedList::display() const {
    SLLNode* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Wyczyszczenie listy - usuniecie wszystkich wezlow i zwolnienie pamieci
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

// Zwrocenie aktualnego rozmiaru listy
int SinglyLinkedList::getSize() const {
    return size;
}

// Pobranie elementu o wskazanym indeksie - O(n)
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
