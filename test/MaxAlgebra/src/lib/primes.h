#pragma once
#include <set>
#include <vector>
#include <stdexcept>

#include "my_utils.h"

namespace Prime
{
    // typedef unsigned long long ull;

    class Primes
    {
    public:
        static Primes &getInstance()
        {
            static Primes instance; // Guaranteed to be destroyed.
            return instance;        // Instantiated on first use.
        }

        void Expand()
        {
            // add to wheel all length + w while < p*length
            // w from wheel
            for (auto w = wheel.begin(); length + *w < p * length; w++)
            {
                wheel.emplace_hint(wheel.end(), length + *w);
            }
            // remove from wheel all p*w in reverse
            for (auto w = wheel.upper_bound(length); w != wheel.begin(); w--)
            {
                wheel.erase(*w * p);
            }

            length *= p;

            // add p to primes
            // add W - 1 to Primes

            for (auto w = wheel.upper_bound(primes.back()); w != wheel.end() && *w < p * p; w++)
            {
                primes.push_back(*w);
            }

            std::set<uint> buffer;
            for (auto w = wheel.upper_bound(primes.back()); w != wheel.end(); w++)
            {
                buffer.emplace_hint(buffer.end(), *w);
                // primes.push_back(*w);
            }
            if (!buffer.empty())
            {
                for (auto w1 = wheel.lower_bound(p); w1 != wheel.end() && *w1 * (*w1) <= *buffer.rbegin(); w1++)
                {
                    for (auto w2 = w1; w2 != wheel.end() && *w1 * (*w2) <= *buffer.rbegin(); w2++)
                    {
                        buffer.erase(*w1 * (*w2));
                    }
                }
                for (auto b = buffer.begin(); b != buffer.end(); b++)
                {
                    primes.push_back(*b);
                }
            }

            wheel.erase(p);
            // p = second from W

            //            p = primes[k];
            p = *wheel.upper_bound(1);
            k++;
        }

        uint operator[](uint i)
        {
            while (i >= primes.size())
            {
                Expand();
            }
            return primes[i];
        }

    private:
        Primes()
            : wheel{1},
              primes{2},
              k(1),
              p(3),
              length(2) {}

        // std::vector<uint> data;
        std::set<uint> wheel;
        std::vector<uint> primes;
        // number of wheel
        uint k;
        // p_{k+1} - prime
        uint p;
        // length of wheel
        // p_1*p_2*p_3*...*p_k
        uint length;

    public:
        Primes(Primes const &) = delete;
        void operator=(Primes const &) = delete;
    };

    std::vector<std::pair<uint, int>> factorize(unsigned long long n)
    {
        if (n == 0)
        {
            throw std::out_of_range("n must be greater than 0");
        }
        std::vector<std::pair<uint, int>>
            result;
        Primes &primes = Primes::getInstance();
        for (uint i = 0; primes[i] * primes[i] <= n; i++)
        {
            uint count = 0;
            while (n % primes[i] == 0)
            {
                count++;
                n /= primes[i];
            }
            if (count)
            {
                result.push_back({primes[i], count});
            }
        }
        if (n != 1)
        {
            result.push_back({n, 1});
        }

        return result;
    }

}
