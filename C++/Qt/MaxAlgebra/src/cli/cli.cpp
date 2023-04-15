// #include <QCoreApplication>
#include "../lib/max_algebra.h"
#include "../lib/primes.h"

#include <cmath>
#include <complex>

#include <eigen3/Eigen/Dense>

using namespace MyAlgebra;
// using namespace Prime;

typedef MaxAlgebra<double> MyDouble;

using namespace std;

int main(/*int argc, char *argv[]*/)
{
    Prime::Primes &primes = Prime::Primes::getInstance();

    // for (uint i = 0; i < 1000; i++)
    // {
    //     cout << i << "  " << primes[i] << "\n";
    // }
    cout << primes[100000] << endl;

    auto decomposition = Prime::factorize(62615533);
    for (auto i : decomposition)
    {
        cout << i.first << "  " << i.second << endl;
    }

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
