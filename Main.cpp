#include "Menu.hpp"
#include <ctime>
#include <cstdlib>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Menu menu;
    menu.showMainMenu();
    return 0;
}
