#include "tlist.h"
#include "tpolynom.h"
#include <iostream>
#include <string>

int main() {
  try {
    std::cout << "=== Enter the first polynomial:\n";
    std::string P1;
    std::cin >> P1;

    std::cout << "=== Enter the second polynomial:\n";
    std::string P2;
    std::cin >> P2;

    TPolynom pol1 = TPolynom(P1);
    TPolynom pol2 = TPolynom(P2);

    std::cout << "=== Your polinomials:\n";
    std::cout << "pol1:\n";
    std::cout << pol1;
    std::cout << pol1.ToString() << "\n";

    std::cout << "pol2:\n";
    std::cout << pol2;
    std::cout << pol2.ToString() << "\n";

    std::cout << "\n=== Let's try every operations with these polinomials:::\n";
    std::cout << "Addition (pol1 + pol2) :\n";
    std::cout << pol1 + pol2;
    std::cout << (pol1 + pol2).ToString() << "\n";

    std::cout << "Unary minus (-pol1) :\n";
    std::cout << -pol1;
    std::cout << (-pol1).ToString() << "\n";

    std::cout << "Subtraction (pol1 - pol2) :\n";
    std::cout << pol1 - pol2;
    std::cout << (pol1 - pol2).ToString() << "\n";

    std::cout << "Multiplication (pol1 * pol2) :\n";
    std::cout << pol1 * pol2;
    std::cout << (pol1 * pol2).ToString() << "\n";

    std::cout << "\n=== Derivatives:::\n";
    std::cout << "pol1 By X:\n";
    std::cout << pol1.dx();
    std::cout << (pol1.dx()).ToString() << "\n";

    std::cout << "pol1 By Y:\n";
    std::cout << pol1.dy();
    std::cout << (pol1.dy()).ToString() << "\n";

    std::cout << "pol1 By Z:\n";
    std::cout << pol1.dz();
    std::cout << (pol1.dz()).ToString() << "\n";

    std::cout << "\n=== Output of the value of the pol1 at a point:::\n";
    double x, y, z;
    std::cout << "enter value of X: ";
    std::cin >> x;
    std::cout << "enter value of Y: ";
    std::cin >> y;
    std::cout << "enter value of Z: ";
    std::cin >> z;

    std::cout << "pol2(x, y, z) => pol1(" << x << ", " << y << ", " << z << "):\n";
    std::cout << pol1(x, y, z);
  }
  catch (const std::exception ex) {
    std::cerr << ex.what() << "\n";
  }
  return 0;
}