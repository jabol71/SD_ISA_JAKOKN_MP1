#pragma once
#include <string>

class Menu {
public:
    void showMainMenu();

private:
    void structureMenu(const std::string& structName);
    void runBenchmark();
    int getRandomNumber(int min, int max);
};
