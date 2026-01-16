#pragma once
#include <string>

void load_data();
void save_data();

void put(int key, const std::string &value);
std::string get(int key);
std::string del(int key);
std::string clr();
std::string all();