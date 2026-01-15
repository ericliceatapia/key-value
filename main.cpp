#include <iostream>

#include "parser.h"
#include "logic.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Missing arguments. Type 'help'.\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        Command cmd = parse_input(argv[i]);

        if (!cmd.valid)
        {
            std::cerr << "Command [" << i << "] Error: Invalid format '" << argv[i] << "'\n";
            continue;
        }
        if (cmd.type == 'p')
        {
            set_value(cmd.key, cmd.value);
        }
        else if (cmd.type == 'g')
        {
            std::string result = get_value(cmd.key);
            if (result.empty())
            {
                std::cout << cmd.key << " not found\n";
            }
            else
            {
                std::cout << result << std::endl;
            }
        }
    }

    return 0;
}