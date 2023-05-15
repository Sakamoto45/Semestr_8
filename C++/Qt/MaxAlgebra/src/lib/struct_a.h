#pragma once

#include <numeric> //gcd
#include <cmath>
#include <string>
#include <cln/integer.h>
#include <cln/integer_io.h>

#include "my_utils.h"
#include "max_algebra.h"

class StructA
{
public:
    StructA(cln::cl_I numerator, cln::cl_I denominator, uint root = 1)
        : numerator_(numerator),
          denominator_(denominator),
          root_(root)
    {
        Simplify();
    }

    StructA(double num = 0)
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

    StructA(std::string str)
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
        return std::pow(cln::double_approx(numerator_) / cln::double_approx(denominator_), 1.0 / root_);
    }

    friend std::ostream &operator<<(std::ostream &os, const StructA &obj)
    {
        // os << obj.value_;
        os << (obj.root_ == 1 ? "" : "(")
           << to_string(obj.numerator_)
           << (obj.denominator_ == 1 ? "" : "/" + to_string(obj.denominator_))
           << (obj.root_ == 1 ? "" : ")^{1/" + std::to_string(obj.root_) + "}");

        return os;
    }

    friend inline bool operator<(const StructA &lhs, const StructA &rhs)
    {
        StructA relation(lhs / rhs);
        return relation.numerator_ < relation.denominator_;
    }
    friend inline bool operator==(const StructA &lhs, const StructA &rhs)
    {
        StructA relation(lhs / rhs);
        return relation.numerator_ == relation.denominator_;
    }
    friend inline StructA operator*(const StructA &lhs, const StructA &rhs)
    {
        uint gcd_root = std::gcd(lhs.root_, rhs.root_);
        uint lhs_root = lhs.root_ / gcd_root;
        uint rhs_root = rhs.root_ / gcd_root;
        StructA result(FastPow(lhs.numerator_, rhs_root) *
                           FastPow(rhs.numerator_, lhs_root),
                       FastPow(lhs.denominator_, rhs_root) *
                           FastPow(rhs.denominator_, lhs_root),
                       lhs_root * rhs_root * gcd_root);
        return result.Simplify();
    }
    friend inline StructA operator/(const StructA &lhs, const StructA &rhs)
    {
        uint gcd_root = std::gcd(lhs.root_, rhs.root_);
        uint lhs_root = lhs.root_ / gcd_root;
        uint rhs_root = rhs.root_ / gcd_root;
        StructA result(FastPow(lhs.numerator_, rhs_root) *
                           FastPow(rhs.denominator_, lhs_root),
                       FastPow(lhs.denominator_, rhs_root) *
                           FastPow(rhs.numerator_, lhs_root),
                       lhs_root * rhs_root * gcd_root);
        return result.Simplify();
    }
    inline StructA Root(const uint &root)
    {
        return StructA(numerator_, denominator_, root_ * root);
    }

private:
    cln::cl_I numerator_;
    cln::cl_I denominator_;
    uint root_;

    StructA Simplify()
    {
        cln::cl_I num_den_gcd = cln::gcd(numerator_, denominator_);
        numerator_ = cln::exquo(numerator_, num_den_gcd);
        denominator_ = cln::exquo(denominator_, num_den_gcd);
        if (numerator_ == 0 || numerator_ == denominator_)
        {
            root_ = 1;
        }
        return *this;
    }
};

typedef MyAlgebra::MaxAlgebra<StructA> MaxAlgebraA;

namespace Eigen
{
    using namespace MyAlgebra;
    template <>
    struct NumTraits<MaxAlgebra<StructA>>
        : GenericNumTraits<MaxAlgebra<StructA>> // permits to get the epsilon, dummy_precision, lowest, highest functions
    {
        typedef MaxAlgebra<StructA> Real;
        typedef MaxAlgebra<StructA> NonInteger;
        typedef MaxAlgebra<StructA> Nested;
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
    struct ScalarBinaryOpTraits<MaxAlgebra<StructA>, StructA, BinaryOp>
    {
        typedef MaxAlgebra<StructA> ReturnType;
    };

    template <typename BinaryOp>
    struct ScalarBinaryOpTraits<StructA, MaxAlgebra<StructA>, BinaryOp>
    {
        typedef MaxAlgebra<StructA> ReturnType;
    };
}