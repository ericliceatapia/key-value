#include "parser.h"
#include <sstream>
#include <stdexcept>

Command parse_input(const std::string &input) {
  Command cmd;
  cmd.valid = false;

  std::stringstream ss(input);
  std::string segment;
  std::vector<std::string> tokens;

  while (std::getline(ss, segment, ',')) {
    tokens.push_back(segment);
  }

  if (tokens.empty())
    return cmd;

  std::string cmd_str = tokens[0];
  int num_tok = tokens.size();

  if (cmd_str == "p" && num_tok == 3) {
    cmd.key = std::stoi(tokens[1]);
    cmd.value = tokens[2];
    cmd.valid = true;
    cmd.type = 'p';
  } else if (cmd_str == "g" && num_tok == 2) {
    cmd.key = std::stoi(tokens[1]);
    cmd.valid = true;
    cmd.type = 'g';
  } else if (cmd_str == "d" && num_tok == 2) {
    cmd.key = std::stoi(tokens[1]);
    cmd.valid = true;
    cmd.type = 'd';
  } else if (cmd_str == "c" && num_tok == 1) {
    cmd.valid = true;
    cmd.type = 'c';
  } else if (cmd_str == "a" && num_tok == 1) {
    cmd.valid = true;
    cmd.type = 'a';
  } else
    cmd.valid = false;

  return cmd;
}