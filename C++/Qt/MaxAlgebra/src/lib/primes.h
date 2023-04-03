#pragma once
#include <vector>

#include "my_utils.h"

// singleton

class Primes
{
public:
    static Primes &getInstance()
    {
        static Primes instance; // Guaranteed to be destroyed.
                                // Instantiated on first use.
        return instance;
    }

    void Expand();

    std::vector<uint> factorize(huge_int num);

private:
    Primes()
        : wheel{1},
          primes{2} {}

    // std::vector<uint> data;
    std::vector<uint> wheel;
    std::vector<uint> primes;

public:
    Primes(Primes const &) = delete;
    void operator=(Primes const &) = delete;
};