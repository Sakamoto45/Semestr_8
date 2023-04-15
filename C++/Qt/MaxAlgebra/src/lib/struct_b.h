#include <numeric> //gcd
#include <cmath>
#include <string>
#include <cln/integer.h>
#include <cln/integer_io.h>

#include "my_utils.h"
#include "max_algebra.h"
#include "primes.h"

class Fraction
{
public:
    Fraction(long long numerator, unsigned long long denominator = 1)
        : numerator_(numerator),
          denominator_(denominator) {}

    friend std::ostream &operator<<(std::ostream &os, const Fraction &obj)
    {
        os << "{"
           << obj.numerator_
           << (obj.denominator_ == 1 ? "" : "/" + obj.denominator_)
           << "}";

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
    friend inline bool operator<(const Fraction &lhs, const Fraction &rhs)
    {
        return (lhs - rhs).numerator_ < 0;
    }

private:
    long long numerator_;
    unsigned long long denominator_;

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
    StructB(cln::cl_I numerator, cln::cl_I denominator, uint root = 1)
    {
    }

    StructB(double num = 0)
        : numerator_(1),
          denominator_(1),
          root_(1)
    {
        if (num >= 1 || num == 0)
        {
            numerator_ = int64_t(llround(num));
        }
        else
        {
            denominator_ = int64_t(llround(1 / num));
        }
    }

    StructB(std::string str)
        : numerator_(1),
          denominator_(1),
          root_(1)
    {
        auto pos = str.find("/");
        if (pos == str.npos)
        {
            numerator_ = str.c_str();
        }
        else
        {
            numerator_ = str.substr(0, pos).c_str();
            denominator_ = str.substr(pos + 1).c_str();
        }
    }

    operator double() const
    {
        // return std::pow(cln::double_approx(numerator_) / cln::double_approx(denominator_), 1.0 / root_);
    }

    friend std::ostream &operator<<(std::ostream &os, const StructB &obj)
    {
        // os << obj.value_;
        os << (obj.root_ == 1 ? "" : "(")
           << obj.numerator_
           << (obj.denominator_ == 1 ? "" : "/" + obj.denominator_)
           << (obj.root_ == 1 ? "" : ")^{1/" + std::to_string(obj.root_) + "}");

        return os;
    }

    friend inline bool operator<(const StructB &lhs, const StructB &rhs)
    {
        StructB relation(lhs / rhs);
        return relation.numerator_ < relation.denominator_;
    }
    friend inline bool operator==(const StructB &lhs, const StructB &rhs)
    {
        StructB relation(lhs / rhs);
        return relation.numerator_ == relation.denominator_;
    }
    friend inline StructB operator*(const StructB &lhs, const StructB &rhs)
    {
    }
    friend inline StructB operator/(const StructB &lhs, const StructB &rhs)
    {
    }
    inline StructB Root(const uint &root)
    {
    }

private:
    cln::cl_I numerator_;
    cln::cl_I denominator_;
    uint root_;
};
