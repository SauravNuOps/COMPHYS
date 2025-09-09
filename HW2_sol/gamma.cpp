#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::cout << std::scientific << std::setprecision(15);

    using typrs = float;  // change to float to see the 0.1% break with single precision

    for (int k = 1; k <= 8; ++k) {
        // beta = 1 - 10^{-k}  → 0.9, 0.99, 0.999, ... loop to set beta values upto 8 digits
        typrs beta = typrs(1.0) - std::pow(typrs(10.0), -k);
        typrs eps  = typrs(1.0) - beta;                   // epsilon = 1 - beta: 1 - 0.9, 1 - 0.99 etc

        // gamma in the two equivalent forms
        typrs gamma_beta = typrs(1.0) / std::sqrt(typrs(1.0) - beta*beta);
        typrs gamma_eps  = typrs(1.0) / std::sqrt((typrs(2.0) - eps) * eps);

        // fractional (relative) error between the two
        typrs rel_err = std::fabs(gamma_beta - gamma_eps);

        std::cout << "beta=" << beta
                  << "  gamma_beta=" << gamma_beta
                  << "  gamma_eps="  << gamma_eps
                  << "  rel_err="    << rel_err << '\n';
    }
    return 0;
}
