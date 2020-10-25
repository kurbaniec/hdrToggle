#include <iostream>
#include "api/toggle.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto switcher = std::make_unique<core::Toggle>();
    switcher->setHdrMode(true);
    std::cin.get();
    return 0;
}
