#pragma once

#include <string>
#include <vector>

struct Command
{
    char type;
    int key;
    std::string value;
    bool valid;
};

Command parse_input(const std::string &input);