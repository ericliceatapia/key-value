#include <iostream>
#include "logic.h"

int main()
{
    std::cout << "Initializing program...\n";
    int status = get_status();

    if (status == 0) {
        std::cout << "Build successful. Logic module linked.\n";
    } else {
        std::cerr << "Error\n";
        return 1;
    }
    return 0;
}