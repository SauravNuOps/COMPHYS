#include <complex>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

int main() {
  
  std::cout << std::setprecision(16) << std::acos(-1.0) << std::endl; // chnaged a bit here

  // Startinh with a hexagon on the unit circle
  std::complex<double> x0(1.0, 0.0);
  std::complex<double> x1(0.5, std::sqrt(3.0) / 2.0);  // 60° point
  unsigned int nsides = 6;

  while (nsides < std::numeric_limits<int>::max()) {
    // chord length between adjacent vertices
    double base = std::abs(x1 - x0);

    // apothem  for unit radius
    double apothem = std::sqrt(1.0 - 0.25 * base * base);

    // area of one isosceles triangle, then sum over n triangles (approx π)
    double approx = nsides * 0.5 * base * apothem;

    std::cout << "Sides " << nsides
              << "; approx=" << std::setprecision(16) << approx << std::endl;

    // bisect the arc to double the number of sides next step
    x1 = (x1 + x0) / std::abs(x1 + x0);
    nsides *= 2;
  }

  return 0;
}
