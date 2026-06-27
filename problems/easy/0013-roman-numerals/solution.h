#pragma once
#include <string_view>

int romanToInt(std::string_view s);

extern "C" int romanToInt_C(const char* s, size_t size);
