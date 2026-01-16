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

  try {
    cmd.type = tokens[0][0];

    if (cmd.type == 'p' && tokens.size() == 3) {
      cmd.key = std::stoi(tokens[1]);
      cmd.value = tokens[2];
      cmd.valid = true;
    } else if (cmd.type == 'g' && tokens.size() == 2) {
      cmd.key = std::stoi(tokens[1]);
      cmd.valid = true;
    } else if (cmd.type == 'd' && tokens.size() == 2) {
      cmd.key = std::stoi(tokens[1]);
      cmd.valid = true;
    } else if (cmd.type == 'c' && tokens.size() == 1) {
      cmd.valid = true;
    } else if (cmd.type == 'a' && tokens.size() == 1) {
      cmd.valid = true;
    }
  } catch (...) {
    cmd.valid = false;
  }

  return cmd;
}