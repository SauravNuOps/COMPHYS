#include <complex>
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    using cd = std::complex<double>;
    const cd I(0.0, 1.0);

   
    double E = 1.0;      // energy
    double V = 0.8;      // barrier height (turns on at x >= 0)

    //Wavenumbers (complex handles both E>V and E<V) 
    cd k1 = std::sqrt(cd(E, 0.0));        // sqroot(E)
    cd k2 = std::sqrt(cd(E - V, 0.0));    // sqrt(E - V)  (imaginary if E<V)

    // Reflection/Transmission amplitudes
    cd r = (k1 - k2) / (k1 + k2);
    cd t = (2.0 * k1) / (k1 + k2);

    // Probabilities 
    double R = std::norm(r);  // |r|^2
    double T = (std::real(k2) / std::real(k1)) * std::norm(t); // (Real k2 / k1)*|t|^2

    // Wavefuntion 
      auto psi = [&](double x) -> cd {
        if (x < 0.0) {
            return std::exp(I * k1 * x) + r * std::exp(-I * k1 * x);
        } else {
            return t * std::exp(I * k2 * x);
        }
    };

  
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "E=" << E << "  V=" << V << "  V/E=" << V/E << "\n";
    std::cout << "k1=" << k1 << "  k2=" << k2 << "\n";
    std::cout << "r=" << r << "  t=" << t << "\n";
    std::cout << "R=" << R << "  T=" << T << "  (R+T=" << (R+T) << ")\n\n";

    
    for (double x : {-4, -2, -1, 0, 1, 2, 4}) {
        cd val = psi(x);
        std::cout << "psi(" << std::setw(4) << x << ") = " << val << "\n";
    }
    return 0;
}
