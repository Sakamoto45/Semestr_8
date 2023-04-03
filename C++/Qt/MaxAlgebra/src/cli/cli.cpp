// #include <QCoreApplication>
#include "../lib/max_algebra.h"

#include <cmath>
#include <complex>

#include <eigen3/Eigen/Dense>

using namespace MyAlgebra;

typedef MaxAlgebra<double> MyDouble;

using namespace std;

int main(/*int argc, char *argv[]*/)
{

    Eigen::Matrix<MyDouble, 2, 2> test;
    test << 1, 2, 3, 4;

    Eigen::Matrix<double, 2, 2> reference;
    reference << 1, 2, 3, 4;

    MyDouble a = 3;
    a += 2;
    a = 2 + a;
    a = a + 2;
    a = a * 2;
    a *= 2;
    a /= 2;
    a /= MyDouble(3);

    a = a / a;

    std::complex<MyDouble> complexTest(3, 4);
    complexTest *= 2;

    // Eigen::EigenSolver<Eigen::Matrix<MyDouble, 2, 2>> solver(test);
    Eigen::EigenSolver<Eigen::Matrix<double, 2, 2>> refSolver(reference);
    std::cout << "MyDouble:" << std::endl;
    std::cout << test.trace() << std::endl;

    // cout << test << endl;

    // ;

    auto test2 = (test * test);

    cout << test << endl;
    cout << 2 * test << endl;
    cout << test * test << endl;

    // cout << (Eigen::Matrix<MyDouble, 2, 2>(test * test)).trace() << endl;
    // cout << (test2) << endl;
    cout << reference * reference << endl;

    // MyAlgebra::MaxAlgebra<double> a(3), b(2);
    // cout << a << " + " << b << " = " << a + b << endl;
    // cout << a << " * " << b << " = " << a * b << endl;
    // cout << a << " / " << b << " = " << a / b << endl;
    // cout << a << " * 2 = " << a * 2 << endl;
    // cout << "a *= 2 = " << (a *= 2) << endl;

    // MaxMulti number;

    // QCoreApplication a(argc, argv);

    // return a.exec();
    return 0;
}
