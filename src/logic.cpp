#include "logic.h"
#include <unordered_map>

static std::unordered_map<int, std::string> kv_store;

void set_value(int key, const std::string &value)
{
    kv_store[key] = value;
}

std::string get_value(int key)
{
    auto it = kv_store.find(key);
    if (it != kv_store.end())
    {
        return it->second;
    }
    return "";
}