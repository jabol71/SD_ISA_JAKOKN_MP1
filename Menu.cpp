#include "Menu.hpp"
#include "ArrayList.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "Benchmark.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

int Menu::getRandomNumber(int min, int max) {
    return min + std::rand() % ((max + 1) - min);
}

template<typename T>
void runMenuForStructure(T& ds, const std::string& name) {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n--- Menu: " << name << " ---\n";
        std::cout << "1. Zbuduj z pliku (data.txt)\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Dodaj element\n";
        std::cout << "4. Znajdz element\n";
        std::cout << "5. Utworz losowo\n";
        std::cout << "6. Wyswietl\n";
        std::cout << "0. Powrot\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string filename;
            std::cout << "Podaj nazwe pliku (np. data.txt): ";
            std::cin >> filename;
            std::ifstream file(filename);
            if (file.is_open()) {
                int count;
                if (file >> count) {
                    ds.clear();
                    for (int i = 0; i < count; ++i) {
                        int val;
                        file >> val;
                        ds.addBack(val);
                    }
                    std::cout << "Wczytano z pliku.\n";
                } else {
                    std::cout << "Blad odczytu z pliku (pusty lub zly format).\n";
                }
                file.close();
            } else {
                std::cout << "Nie mozna otworzyc pliku!\n";
            }
        } else if (choice == 2) {
            std::cout << "1. Usun z poczatku\n";
            std::cout << "2. Usun z konca\n";
            std::cout << "3. Usun z wybranej pozycji\n";
            int subchoice;
            std::cin >> subchoice;
            if (subchoice == 1) ds.removeFront();
            else if (subchoice == 2) ds.removeBack();
            else if (subchoice == 3) {
                int idx;
                std::cout << "Podaj indeks: ";
                std::cin >> idx;
                ds.removeAt(idx);
            }
        } else if (choice == 3) {
            int val;
            std::cout << "Podaj wartosc: ";
            std::cin >> val;
            std::cout << "1. Dodaj na poczatek\n";
            std::cout << "2. Dodaj na koniec\n";
            std::cout << "3. Dodaj na wybrana pozycje\n";
            int subchoice;
            std::cin >> subchoice;
            if (subchoice == 1) ds.addFront(val);
            else if (subchoice == 2) ds.addBack(val);
            else if (subchoice == 3) {
                int idx;
                std::cout << "Podaj indeks: ";
                std::cin >> idx;
                ds.addAt(idx, val);
            }
        } else if (choice == 4) {
            int val;
            std::cout << "Podaj wartosc do znalezienia: ";
            std::cin >> val;
            if (ds.find(val)) {
                std::cout << "Element " << val << " znajduje sie w strukturze.\n";
            } else {
                std::cout << "Element " << val << " nie zostal znaleziony.\n";
            }
        } else if (choice == 5) {
            int size;
            std::cout << "Podaj wielkosc struktury: ";
            std::cin >> size;
            ds.clear();
            for (int i = 0; i < size; ++i) {
                ds.addBack(std::rand() % 1000); // random values 0-999
            }
            std::cout << "Wypelniono losowymi danymi.\n";
        } else if (choice == 6) {
            ds.display();
        }
    }
}

void Menu::structureMenu(const std::string& structName) {
    if (structName == "ArrayList") {
        ArrayList arr;
        runMenuForStructure(arr, structName);
    } else if (structName == "SinglyLinkedList") {
        SinglyLinkedList sll;
        runMenuForStructure(sll, structName);
    } else if (structName == "DoublyLinkedList") {
        DoublyLinkedList dll;
        runMenuForStructure(dll, structName);
    }
}

void Menu::runBenchmark() {
    Benchmark bench;
    bench.runAllBenchmarks();
}

void Menu::showMainMenu() {
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== MENU GLOWNE ===\n";
        std::cout << "1. Tablica dynamiczna (ArrayList)\n";
        std::cout << "2. Lista jednokierunkowa (Singly Linked List)\n";
        std::cout << "3. Lista dwukierunkowa (Doubly Linked List)\n";
        std::cout << "4. Uruchom badania (Pomiary czasowe)\n";
        std::cout << "0. Wyjdz\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        if (choice == 1) {
            structureMenu("ArrayList");
        } else if (choice == 2) {
            structureMenu("SinglyLinkedList");
        } else if (choice == 3) {
            structureMenu("DoublyLinkedList");
        } else if (choice == 4) {
            runBenchmark();
        }
    }
}
