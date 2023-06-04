#pragma once

#include <numeric>
#include <cmath>
#include <string>
#include <cln/integer.h>

#include "my_utils.h"
#include "max_algebra.h"
#include "primes.h"

class Fraction
{
public:
    Fraction(long long numerator, long long denominator = 1)
        : numerator_(numerator),
          denominator_(denominator) {}

    friend std::ostream &operator<<(std::ostream &os, const Fraction &obj)
    {
        os << "{"
           << obj.numerator_;
        if (obj.denominator_ != 1)
        {
            os << "/" << obj.denominator_;
        }

        os << "}";

        return os;
    }

    friend inline Fraction operator+(const Fraction &lhs, const Fraction &rhs)
    {
        Fraction result(lhs.numerator_ * rhs.denominator_ +
                            rhs.numerator_ * lhs.denominator_,
                        lhs.denominator_ * rhs.denominator_);
        return result.Simplify();
    }
    inline Fraction operator-() const
    {
        return Fraction(-numerator_, denominator_);
    }
    friend inline Fraction operator-(const Fraction &lhs, const Fraction &rhs)
    {
        return lhs + (-rhs);
    }
    friend inline bool operator==(const Fraction &lhs, const Fraction &rhs)
    {
        return (lhs - rhs).numerator_ == 0;
    }
    friend inline bool operator!=(const Fraction &lhs, const Fraction &rhs)
    {
        return !(lhs == rhs);
    }
    friend inline bool operator<(const Fraction &lhs, const Fraction &rhs)
    {
        return (lhs - rhs).numerator_ < 0;
    }
    operator double() const
    {
        return (double)numerator_ / denominator_;
    }
    long long denominator() const
    {
        return denominator_;
    }

private:
    long long numerator_;
    long long denominator_;

    Fraction Simplify()
    {
        auto num_den_gcd = std::gcd(numerator_, denominator_);
        numerator_ = numerator_ / num_den_gcd;
        denominator_ = denominator_ / num_den_gcd;
        return *this;
    }
};

class StructB
{
public:
    StructB(unsigned long long numerator, unsigned long long denominator, uint root = 1)
    {
        Init(numerator, denominator, root);
    }

    StructB(double num = 0)
    {
        if (num >= 1 || num == 0)
        {
            Init(int64_t(llround(num)), 1);
        }
        else
        {
            Init(1, int64_t(llround(1 / num)));
        }
    }

    StructB(std::string str)
    {
        auto pos = str.find("/");
        if (pos == str.npos)
        {
            Init(atoll(str.c_str()), 1);
        }
        else
        {
            Init(atoll(str.substr(0, pos).c_str()),
                 atoll(str.substr(pos + 1).c_str()));
        }
    }

    operator double() const
    {
        if (is_zero)
        {
            return 0;
        }
        double result = 1;
        for (auto p : data)
        {
            result *= pow(p.first, double(p.second));
        }
        return result;
    }

    friend std::ostream &operator<<(std::ostream &os, const StructB &obj)
    {
        if (obj.is_zero)
        {
            os << 0;
            return os;
        }
        if (obj.data.empty())
        {
            os << 1;
            return os;
        }
        for (auto p : obj.data)
        {
            os << p.first;
            if (p.second != Fraction(1))
            {
                os << "^" << p.second;
            }
            if (p != obj.data.back())
            {
                os << "\\cdot ";
            }
        }

        return os;
    }

    friend inline bool operator<(const StructB &lhs, const StructB &rhs)
    {
        if (rhs.is_zero)
        {
            return false;
        }
        if (lhs.is_zero)
        {
            return true;
        }
        StructB relation(lhs / rhs);
        double approx = double(relation);
        if (abs(approx - 1) > 1e-15)
        {
            return approx < 1;
        }

        long long root_lcm = 1;
        for (auto p : relation.data)
        {
            root_lcm = std::lcm(root_lcm, p.second.denominator());
        }
        cln::cl_I numerator = 1;
        cln::cl_I denominator = 1;
        for (auto p : relation.data)
        {
            if (p.second > Fraction(0))
            {
                numerator *= FastPow(cln::cl_I(p.first), p.second * root_lcm);
            }
            else
            {
                denominator *= FastPow(cln::cl_I(p.first), -p.second * root_lcm);
            }
        }
        return numerator < denominator;
    }
    friend inline bool operator==(const StructB &lhs, const StructB &rhs)
    {
        if (lhs.is_zero && rhs.is_zero)
        {
            return true;
        }
        if (lhs.is_zero || rhs.is_zero)
        {
            return false;
        }
        for (auto i = lhs.data.begin(),
                  j = rhs.data.begin();
             i != lhs.data.end() ||
             j != rhs.data.end();)
        {
            if (i == lhs.data.end() ||
                j == rhs.data.end())
            {
                return false;
            }
            if (*i != *j)
            {
                return false;
            }
        }
        return true;
    }
    friend inline StructB operator*(const StructB &lhs, const StructB &rhs)
    {
        if (lhs.is_zero || rhs.is_zero)
        {
            return 0;
        }

        StructB result(1);

        for (auto i = lhs.data.begin(),
                  j = rhs.data.begin();
             i != lhs.data.end() ||
             j != rhs.data.end();)
        {
            if (i == lhs.data.end())
            {
                result.data.push_back({j->first, j->second});
                j++;
            }
            else if (j == rhs.data.end())
            {
                result.data.push_back({i->first, i->second});
                i++;
            }
            else
            {
                uint min_p = std::min(i->first, j->first);
                Fraction tmp(0);
                if (i->first == min_p)
                {
                    tmp = tmp + Fraction(i->second);
                    i++;
                }
                if (j->first == min_p)
                {
                    tmp = tmp + Fraction(j->second);
                    j++;
                }
                if (tmp != Fraction(0))
                {
                    result.data.push_back({min_p, tmp});
                }
            }
        }
        return result;
    }
    friend inline StructB operator/(const StructB &lhs, const StructB &rhs)
    {
        if (lhs.is_zero || rhs.is_zero)
        {
            return 0;
        }

        StructB result(1);

        for (auto i = lhs.data.begin(),
                  j = rhs.data.begin();
             i != lhs.data.end() ||
             j != rhs.data.end();)
        {
            if (i == lhs.data.end())
            {
                result.data.push_back({j->first, -(j->second)});
                j++;
            }
            else if (j == rhs.data.end())
            {
                result.data.push_back({i->first, i->second});
                i++;
            }
            else
            {
                uint min_p = std::min(i->first, j->first);
                Fraction tmp(0);
                if (i->first == min_p)
                {
                    tmp = tmp + Fraction(i->second);
                    i++;
                }
                if (j->first == min_p)
                {
                    tmp = tmp - Fraction(j->second);
                    j++;
                }
                if (tmp != Fraction(0))
                {
                    result.data.push_back({min_p, tmp});
                }
            }
        }
        return result;
    }
    inline StructB Root(const uint &root)
    {
        if (is_zero)
        {
            return 0;
        }
        StructB result(1);
        for (auto p : data)
        {
            result.data.push_back({p.first, Fraction(p.second, root)});
        }
        return result;
    }

private:
    void Init(unsigned long long numerator, unsigned long long denominator, uint root = 1)
    {
        if (numerator == 0)
        {
            is_zero = true;
            return;
        }
        is_zero = false;

        auto factorized_numerator = Prime::factorize(numerator);
        auto factorized_denominator = Prime::factorize(denominator);

        for (auto i = factorized_numerator.begin(),
                  j = factorized_denominator.begin();
             i != factorized_numerator.end() ||
             j != factorized_denominator.end();)
        {
            if (i == factorized_numerator.end())
            {
                data.push_back({j->first, -Fraction(j->second, root)});
                j++;
            }
            else if (j == factorized_denominator.end())
            {
                data.push_back({i->first, Fraction(i->second, root)});
                i++;
            }
            else
            {
                uint min_p = std::min(i->first, j->first);
                Fraction tmp(0);
                if (i->first == min_p)
                {
                    tmp = tmp + Fraction(i->second, root);
                    i++;
                }
                if (j->first == min_p)
                {
                    tmp = tmp - Fraction(j->second, root);
                    j++;
                }
                if (tmp != Fraction(0))
                {
                    data.push_back({min_p, tmp});
                }
            }
        }
    }

    std::vector<std::pair<uint, Fraction>> data;
    bool is_zero;
};

typedef MyAlgebra::MaxAlgebra<StructB> MaxAlgebraB;

namespace Eigen
{
    using namespace MyAlgebra;
    template <>
    struct NumTraits<MaxAlgebra<StructB>>
        : GenericNumTraits<MaxAlgebra<StructB>> // permits to get the epsilon, dummy_precision, lowest, highest functions
    {
        typedef MaxAlgebra<StructB> Real;
        typedef MaxAlgebra<StructB> NonInteger;
        typedef MaxAlgebra<StructB> Nested;
        static inline int digits10() { return 0; }
        enum
        {
            IsComplex = 0,
            IsInteger = 0,
            IsSigned = 0,
            RequireInitialization = 1,
            ReadCost = 2,
            AddCost = 3,
            MulCost = 3
        };
    };

    template <typename BinaryOp>
    struct ScalarBinaryOpTraits<MaxAlgebra<StructB>, StructB, BinaryOp>
    {
        typedef MaxAlgebra<StructB> ReturnType;
    };

    template <typename BinaryOp>
    struct ScalarBinaryOpTraits<StructB, MaxAlgebra<StructB>, BinaryOp>
    {
        typedef MaxAlgebra<StructB> ReturnType;
    };
}