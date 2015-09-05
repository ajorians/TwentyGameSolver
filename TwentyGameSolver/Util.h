#pragma once

#include <cctype>

#define SIZEOF(x) sizeof(x)/sizeof(x[0])

char NUM(int n) { return '0' + n; }

bool isNum(char c) { return ::isdigit(c); }
