#include "logic.h"
#include "parser.h"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }

  load_data();

  for (int i = 1; i < argc; ++i) {
    Command cmd = parse_input(argv[i]);

    if (!cmd.valid) {
      std::cout << "bad command" << std::endl;
      continue;
    }

    if (cmd.type == 'p') {
      put(cmd.key, cmd.value);
    } else if (cmd.type == 'g') {
      std::cout << get(cmd.key) << std::endl;

    } else if (cmd.type == 'd') {
      if (!del(cmd.key).empty()) {
        std::cout << del(cmd.key) << std::endl;
      }
    } else if (cmd.type == 'c') {
      clr();
    } else if (cmd.type == 'a') {
      std::cout << all();
    }
  }

  save_data();

  return 0;
}