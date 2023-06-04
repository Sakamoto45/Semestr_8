#pragma once

#include <eigen3/Eigen/Dense>
#include <iostream>

namespace MyAlgebra
{

    // T must have operators * / < == << Root
    template <class T>
    class MaxAlgebra
    {
    private:
        T value_;

    public:
        MaxAlgebra(T value) : value_(value) {}
        MaxAlgebra(){};

        operator double() const
        {
            return double(value_);
        }
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
        friend inline MaxAlgebra<T> operator*(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return lhs.value_ * rhs.value_;
        }
        friend inline MaxAlgebra<T> operator/(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
        {
            return lhs.value_ / rhs.value_;
        }
        friend inline MaxAlgebra<T> operator+(const MaxAlgebra<T> &lhs, const MaxAlgebra<T> &rhs)
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
        inline MaxAlgebra<T> Root(const uint &root)
        {
            return value_.Root(root);
        }
    };
}