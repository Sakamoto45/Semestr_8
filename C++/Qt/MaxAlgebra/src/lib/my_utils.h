#pragma once

#include <cln/integer.h>
#include <cln/integer_io.h>
#include <string>
#include <sstream>

template <class T>
T FastPow(T base, uint exp)
{
    T result(1);
    while (exp)
    {
        if (exp & 1)
        {
            result *= base;
        }
        base *= base;
        exp >>= 1;
    }
    return result;
}

std::string to_string(const cln::cl_I &integer)
{
    std::stringstream ss;
    cln::print_integer(ss, 10, integer);

    return ss.str();
}