#pragma once

#include <eigen3/Eigen/Dense>
#include <iostream>

namespace MyAlgebra
{

    // T must have operators * / < == <<
    template <class T>
    class MaxAlgebra
    {
    private:
        T value_;

    public:
        MaxAlgebra(T value) : value_(value) {}
        MaxAlgebra(){};

        friend std::ostream &operator<<(std::ostream &os, const MaxAlgebra<T> &obj)
        {
            os << obj.value_;
            return os;
        }

        friend inline bool operator==(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return lhs.value_ == rhs.value_;
        }
        friend inline bool operator!=(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return !(rhs == lhs);
        }
        friend inline bool operator<(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return lhs.value_ < rhs.value_;
        }
        friend inline bool operator>(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return rhs < lhs;
        }
        friend inline bool operator<=(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return !(lhs > rhs);
        }
        friend inline bool operator>=(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return !(rhs < lhs);
        }
        friend MaxAlgebra<T> operator*(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return lhs.value_ * rhs.value_;
        }
        friend MaxAlgebra<T> operator/(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return lhs.value_ / rhs.value_;
        }
        friend MaxAlgebra<T> operator+(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return lhs < rhs ? rhs : lhs;
        }
        inline MaxAlgebra<T> &operator*=(const MaxAlgebra<T> &other)
        {
            return *this = *this * other;
        }
        inline MaxAlgebra<T> &operator/=(const MaxAlgebra<T> &other)
        {
            return *this = *this / other;
        }
        inline MaxAlgebra<T> &operator+=(const MaxAlgebra<T> &other)
        {
            return *this = *this + other;
        }
        MaxAlgebra &operator-=(const MaxAlgebra &other) = delete;
        MaxAlgebra operator-(const MaxAlgebra &other) const = delete;
    };

    // template <class T>
    // MaxAlgebra<T> sqrt(MaxAlgebra<T> val)
    // {
    //     return std::sqrt(val.value_);
    // }
    // template <class T>
    // MaxAlgebra<T> abs(MaxAlgebra<T> val)
    // {
    //     return std::abs(val.value_);
    // }
    // template <class T>
    // MaxAlgebra<T> abs2(MaxAlgebra<T> val)
    // {
    //     return val * val;
    // }
    // template <class T>
    // bool isfinite(const MaxAlgebra<T> &)
    // {
    //     return true;
    // }

}

namespace Eigen
{
    using namespace MyAlgebra;
    template <>
    struct NumTraits<MaxAlgebra<double>>
        : GenericNumTraits<MaxAlgebra<double>> // permits to get the epsilon, dummy_precision, lowest, highest functions
    {
        typedef MaxAlgebra<double> Real;
        typedef MaxAlgebra<double> NonInteger;
        typedef MaxAlgebra<double> Nested;
        static inline int digits10() { return 0; }
        enum
        {
            IsComplex = 0,
            IsInteger = 0,
            IsSigned = 0,
            RequireInitialization = 0,
            ReadCost = 2,
            AddCost = 3,
            MulCost = 3
        };
    };

    template <typename BinaryOp>
    struct ScalarBinaryOpTraits<MaxAlgebra<double>, double, BinaryOp>
    {
        typedef MaxAlgebra<double> ReturnType;
    };

    template <typename BinaryOp>
    struct ScalarBinaryOpTraits<double, MaxAlgebra<double>, BinaryOp>
    {
        typedef MaxAlgebra<double> ReturnType;
    };
}
