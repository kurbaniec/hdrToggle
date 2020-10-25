#include <iostream>
#include "api/toggle.h"

int main() {
    std::cout << "Welcome to hdrToggle!" << std::endl;
    std::cout << "Press any key to exit HDR mode" << std::endl;
    auto switcher = std::make_unique<api::Toggle>();
    switcher->setHdrMode(true);
    std::cin.get();
    return 0;
}
