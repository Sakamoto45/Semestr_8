// #include <QCoreApplication>
#include "../lib/max_algebra.h"
#include "../lib/primes.h"

#include <cmath>
#include <complex>

#include <eigen3/Eigen/Dense>

using namespace MyAlgebra;
// using namespace Prime;

class DoubleWrapper
{
public:
    DoubleWrapper(double value = 0)
        : value_(value)
    {
    }

    operator double() const
    {
        return value_;
    }

    friend std::ostream &operator<<(std::ostream &os, const DoubleWrapper &obj)
    {
        os << obj.value_;
        return os;
    }

    friend inline bool operator<(const DoubleWrapper &lhs, const DoubleWrapper &rhs)
    {
        return lhs.value_ > rhs.value_;
    }
    friend inline bool operator==(const DoubleWrapper &lhs, const DoubleWrapper &rhs)
    {
        return lhs.value_ == rhs.value_;
    }
    friend inline DoubleWrapper operator*(const DoubleWrapper &lhs, const DoubleWrapper &rhs)
    {
        return lhs.value_ + rhs.value_;
    }
    friend inline DoubleWrapper operator/(const DoubleWrapper &lhs, const DoubleWrapper &rhs)
    {
        return lhs.value_ - rhs.value_;
    }
    inline DoubleWrapper Root(const uint &root)
    {
        return DoubleWrapper(value_ / root);
    }

private:
    double value_;
};

typedef MaxAlgebra<DoubleWrapper> MyDouble;

namespace Eigen
{
    using namespace MyAlgebra;
    template <>
    struct NumTraits<MaxAlgebra<DoubleWrapper>>
        : GenericNumTraits<MaxAlgebra<DoubleWrapper>> // permits to get the epsilon, dummy_precision, lowest, highest functions
    {
        typedef MaxAlgebra<DoubleWrapper> Real;
        typedef MaxAlgebra<DoubleWrapper> NonInteger;
        typedef MaxAlgebra<DoubleWrapper> Nested;
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
    struct ScalarBinaryOpTraits<MaxAlgebra<DoubleWrapper>, DoubleWrapper, BinaryOp>
    {
        typedef MaxAlgebra<DoubleWrapper> ReturnType;
    };

    template <typename BinaryOp>
    struct ScalarBinaryOpTraits<DoubleWrapper, MaxAlgebra<DoubleWrapper>, BinaryOp>
    {
        typedef MaxAlgebra<DoubleWrapper> ReturnType;
    };
}

using namespace std;

int main(/*int argc, char *argv[]*/)
{
    // Eigen::Matrix3d A_;
    // A_ << 1.0, 2.0, 1.0, 1.0 / 2, 1.0, 1.0 / 3, 1.0, 1.0, 1.0 / 2;

    // cout << A_ << endl;

    // Eigen::Matrix<MyDouble, 3, 3> A(Eigen::Matrix<DoubleWrapper, 3, 3>(A_));
    Eigen::Matrix<MyDouble, 3, 3> A;
    Eigen::Matrix<MyDouble, 3, 3> d;

    A << MyDouble(1.0), MyDouble(2.0), MyDouble(1.0), MyDouble(1.0 / 2), MyDouble(1.0), MyDouble(1.0 / 3), MyDouble(1.0), MyDouble(1.0), MyDouble(1.0 / 2);

    cout << A << endl;
    cout << A * A << endl;
    cout << A * A * A << endl;
    cout << A + A * A << endl;

    // A << 1, 2, 1, 1.0/2, 1, 1.0/3, 1, 1, 1.0/2;

    // Prime::Primes &primes = Prime::Primes::getInstance();

    // // for (uint i = 0; i < 1000; i++)
    // // {
    // //     cout << i << "  " << primes[i] << "\n";
    // // }
    // cout << primes[100000] << endl;

    // auto decomposition = Prime::factorize(62615533);
    // for (auto i : decomposition)
    // {
    //     cout << i.first << "  " << i.second << endl;
    // }

    // Eigen::Matrix<MyDouble, 2, 2> test;
    // test << 1, 2, 3, 4;

    // Eigen::Matrix<double, 2, 2> reference;
    // reference << 1, 2, 3, 4;

    // MyDouble a = 3;
    // a += 2;
    // a = 2 + a;
    // a = a + 2;
    // a = a * 2;
    // a *= 2;
    // a /= 2;
    // a /= MyDouble(3);

    // a = a / a;

    // std::complex<MyDouble> complexTest(3, 4);
    // complexTest *= 2;

    // // Eigen::EigenSolver<Eigen::Matrix<MyDouble, 2, 2>> solver(test);
    // Eigen::EigenSolver<Eigen::Matrix<double, 2, 2>> refSolver(reference);
    // std::cout << "MyAlgebra:" << std::endl;
    // std::cout << test.trace() << std::endl;

    // // cout << test << endl;

    // // ;

    // auto test2 = (test * test);

    // cout << test << endl;
    // cout << 2 * test << endl;
    // cout << test * test << endl;

    // // cout << (Eigen::Matrix<MyDouble, 2, 2>(test * test)).trace() << endl;
    // // cout << (test2) << endl;
    // cout << reference * reference << endl;

    // // MyAlgebra::MaxAlgebra<double> a(3), b(2);
    // // cout << a << " + " << b << " = " << a + b << endl;
    // // cout << a << " * " << b << " = " << a * b << endl;
    // // cout << a << " / " << b << " = " << a / b << endl;
    // // cout << a << " * 2 = " << a * 2 << endl;
    // // cout << "a *= 2 = " << (a *= 2) << endl;

    return 0;
}
