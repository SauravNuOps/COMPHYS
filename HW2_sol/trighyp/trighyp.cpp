#include <complex>
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    using cplx = std::complex<double>;
    const cplx i(0.0, 1.0);                 // the imaginary unit i

    double xs[] = {-2.0, -0.5, 0.0, 0.5, 2.0};

    std::cout << std::fixed << std::setprecision(12);

    for (double x : xs) {
        cplx lhs1 = std::sin(i * x);        // sin(i x)
        cplx rhs1 = i * std::sinh(x);       // i*sinh(x)

        cplx lhs2 = std::cos(i * x);        // cos(i x)
        cplx rhs2 =std::cosh(x);        // cosh(x)
        std::cout << "x = " << x << "\n";
        std::cout << "  sin(i x)   = " << lhs1
                  << "   i*sinh(x)  = " << rhs1
                  << "   |diff| = " << std::abs(lhs1 - rhs1) << "\n";
        std::cout << "  cos(i x)   = " << lhs2
                  << "   cosh(x)    = " << rhs2
                  << "   |diff| = " << std::abs(lhs2 - rhs2) << "\n\n";
    }
    return 0;
}
