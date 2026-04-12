#include "Benchmark.hpp"
#include "ArrayList.hpp"
#include "SinglyLinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std::chrono;

void Benchmark::runAllBenchmarks() {
    int sizes[] = {5000, 10000, 15000, 20000, 25000, 30000, 40000, 50000};
    int numSizes = 8;
    int iterations = 100; // Liczba prob dla kazdego rozmiaru

    std::ofstream out("results.csv");
    out << "Structure,Operation,Size,Time_ns\n";

    std::cout << "Rozpoczynam testy (moze to chwile potrwac)...\n";

    for (int s = 0; s < numSizes; ++s) {
        int currentSize = sizes[s];
        std::cout << "Testuje rozmiar: " << currentSize << std::endl;

        long long timeArr_addF = 0, timeSLL_addF = 0, timeDLL_addF = 0;
        long long timeArr_addB = 0, timeSLL_addB = 0, timeDLL_addB = 0;
        long long timeArr_addR = 0, timeSLL_addR = 0, timeDLL_addR = 0;

        long long timeArr_remF = 0, timeSLL_remF = 0, timeDLL_remF = 0;
        long long timeArr_remB = 0, timeSLL_remB = 0, timeDLL_remB = 0;
        long long timeArr_remR = 0, timeSLL_remR = 0, timeDLL_remR = 0;

        long long timeArr_find = 0, timeSLL_find = 0, timeDLL_find = 0;

        for (int i = 0; i < iterations; ++i) {
            std::vector<int> initData(currentSize);
            for(int j=0; j<currentSize; ++j) {
                initData[j] = std::rand();
            }

            int randIndexAdd = std::rand() % (currentSize + 1);
            int randIndexRem = std::rand() % currentSize;
            int randValAdd = std::rand();
            int randValSearch = std::rand();

            // --- ARRAY LIST ---
            ArrayList arr;
            for(int j=0; j<currentSize; ++j) arr.addBack(initData[j]);
            
            auto start = high_resolution_clock::now();
            arr.addFront(randValAdd);
            auto end = high_resolution_clock::now();
            timeArr_addF += duration_cast<nanoseconds>(end - start).count();

            arr.removeFront(); // Przywrocenie rozmiaru

            start = high_resolution_clock::now();
            arr.addBack(randValAdd);
            end = high_resolution_clock::now();
            timeArr_addB += duration_cast<nanoseconds>(end - start).count();

            arr.removeBack();

            start = high_resolution_clock::now();
            arr.addAt(randIndexAdd, randValAdd);
            end = high_resolution_clock::now();
            timeArr_addR += duration_cast<nanoseconds>(end - start).count();

            arr.removeAt(randIndexAdd);

            start = high_resolution_clock::now();
            arr.removeFront();
            end = high_resolution_clock::now();
            timeArr_remF += duration_cast<nanoseconds>(end - start).count();

            arr.addFront(initData[0]); // Przywrocenie

            start = high_resolution_clock::now();
            arr.removeBack();
            end = high_resolution_clock::now();
            timeArr_remB += duration_cast<nanoseconds>(end - start).count();

            arr.addBack(initData[currentSize-1]);

            start = high_resolution_clock::now();
            arr.removeAt(randIndexRem);
            end = high_resolution_clock::now();
            timeArr_remR += duration_cast<nanoseconds>(end - start).count();

            arr.addAt(randIndexRem, initData[randIndexRem]);

            start = high_resolution_clock::now();
            arr.find(randValSearch);
            end = high_resolution_clock::now();
            timeArr_find += duration_cast<nanoseconds>(end - start).count();


            // --- SINGLY LINKED LIST ---
            SinglyLinkedList sll;
            for(int j=0; j<currentSize; ++j) sll.addBack(initData[j]);

            start = high_resolution_clock::now();
            sll.addFront(randValAdd);
            end = high_resolution_clock::now();
            timeSLL_addF += duration_cast<nanoseconds>(end - start).count();
            sll.removeFront();

            start = high_resolution_clock::now();
            sll.addBack(randValAdd);
            end = high_resolution_clock::now();
            timeSLL_addB += duration_cast<nanoseconds>(end - start).count();
            sll.removeBack();

            start = high_resolution_clock::now();
            sll.addAt(randIndexAdd, randValAdd);
            end = high_resolution_clock::now();
            timeSLL_addR += duration_cast<nanoseconds>(end - start).count();
            sll.removeAt(randIndexAdd);

            start = high_resolution_clock::now();
            sll.removeFront();
            end = high_resolution_clock::now();
            timeSLL_remF += duration_cast<nanoseconds>(end - start).count();
            sll.addFront(initData[0]);

            start = high_resolution_clock::now();
            sll.removeBack();
            end = high_resolution_clock::now();
            timeSLL_remB += duration_cast<nanoseconds>(end - start).count();
            sll.addBack(initData[currentSize-1]);

            start = high_resolution_clock::now();
            sll.removeAt(randIndexRem);
            end = high_resolution_clock::now();
            timeSLL_remR += duration_cast<nanoseconds>(end - start).count();
            sll.addAt(randIndexRem, initData[randIndexRem]);

            start = high_resolution_clock::now();
            sll.find(randValSearch);
            end = high_resolution_clock::now();
            timeSLL_find += duration_cast<nanoseconds>(end - start).count();


            // --- DOUBLY LINKED LIST ---
            DoublyLinkedList dll;
            for(int j=0; j<currentSize; ++j) dll.addBack(initData[j]);

            start = high_resolution_clock::now();
            dll.addFront(randValAdd);
            end = high_resolution_clock::now();
            timeDLL_addF += duration_cast<nanoseconds>(end - start).count();
            dll.removeFront();

            start = high_resolution_clock::now();
            dll.addBack(randValAdd);
            end = high_resolution_clock::now();
            timeDLL_addB += duration_cast<nanoseconds>(end - start).count();
            dll.removeBack();

            start = high_resolution_clock::now();
            dll.addAt(randIndexAdd, randValAdd);
            end = high_resolution_clock::now();
            timeDLL_addR += duration_cast<nanoseconds>(end - start).count();
            dll.removeAt(randIndexAdd);

            start = high_resolution_clock::now();
            dll.removeFront();
            end = high_resolution_clock::now();
            timeDLL_remF += duration_cast<nanoseconds>(end - start).count();
            dll.addFront(initData[0]);

            start = high_resolution_clock::now();
            dll.removeBack();
            end = high_resolution_clock::now();
            timeDLL_remB += duration_cast<nanoseconds>(end - start).count();
            dll.addBack(initData[currentSize-1]);

            start = high_resolution_clock::now();
            dll.removeAt(randIndexRem);
            end = high_resolution_clock::now();
            timeDLL_remR += duration_cast<nanoseconds>(end - start).count();
            dll.addAt(randIndexRem, initData[randIndexRem]);

            start = high_resolution_clock::now();
            dll.find(randValSearch);
            end = high_resolution_clock::now();
            timeDLL_find += duration_cast<nanoseconds>(end - start).count();
        }

        // Zapis dla tablicy dynamicznej
        out << "ArrayList,AddFront," << currentSize << "," << timeArr_addF / iterations << "\n";
        out << "ArrayList,AddBack," << currentSize << "," << timeArr_addB / iterations << "\n";
        out << "ArrayList,AddRandom," << currentSize << "," << timeArr_addR / iterations << "\n";
        out << "ArrayList,RemoveFront," << currentSize << "," << timeArr_remF / iterations << "\n";
        out << "ArrayList,RemoveBack," << currentSize << "," << timeArr_remB / iterations << "\n";
        out << "ArrayList,RemoveRandom," << currentSize << "," << timeArr_remR / iterations << "\n";
        out << "ArrayList,Find," << currentSize << "," << timeArr_find / iterations << "\n";

        // Zapis dla listy jednokierunkowej
        out << "SinglyLinkedList,AddFront," << currentSize << "," << timeSLL_addF / iterations << "\n";
        out << "SinglyLinkedList,AddBack," << currentSize << "," << timeSLL_addB / iterations << "\n";
        out << "SinglyLinkedList,AddRandom," << currentSize << "," << timeSLL_addR / iterations << "\n";
        out << "SinglyLinkedList,RemoveFront," << currentSize << "," << timeSLL_remF / iterations << "\n";
        out << "SinglyLinkedList,RemoveBack," << currentSize << "," << timeSLL_remB / iterations << "\n";
        out << "SinglyLinkedList,RemoveRandom," << currentSize << "," << timeSLL_remR / iterations << "\n";
        out << "SinglyLinkedList,Find," << currentSize << "," << timeSLL_find / iterations << "\n";

        // Zapis dla listy dwukierunkowej
        out << "DoublyLinkedList,AddFront," << currentSize << "," << timeDLL_addF / iterations << "\n";
        out << "DoublyLinkedList,AddBack," << currentSize << "," << timeDLL_addB / iterations << "\n";
        out << "DoublyLinkedList,AddRandom," << currentSize << "," << timeDLL_addR / iterations << "\n";
        out << "DoublyLinkedList,RemoveFront," << currentSize << "," << timeDLL_remF / iterations << "\n";
        out << "DoublyLinkedList,RemoveBack," << currentSize << "," << timeDLL_remB / iterations << "\n";
        out << "DoublyLinkedList,RemoveRandom," << currentSize << "," << timeDLL_remR / iterations << "\n";
        out << "DoublyLinkedList,Find," << currentSize << "," << timeDLL_find / iterations << "\n";
    }

    out.close();
    std::cout << "Testy zakonczone. Wyniki zapisane do pliku results.csv\n";
}
