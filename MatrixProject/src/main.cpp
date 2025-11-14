#include "Matrix.hpp"
#include <iostream>

int main() {
    std::cout << "=== Demonstrating Correct Matrix Implementation ===\n";

    Matrix A(2, 2);
    A.at(0, 0) = 1;
    A.at(0, 1) = 2;
    A.at(1, 0) = 3;
    A.at(1, 1) = 4;

    std::cout << "Matrix A:\n";
    A.print();

    // Test copy constructor
    Matrix B = A;
    std::cout << "\nMatrix B (copied from A):\n";
    B.print();

    // Modify B to verify deep copy
    B.at(0, 0) = 99;
    std::cout << "\nMatrix B after modification:\n";
    B.print();

    std::cout << "\nMatrix A should remain unchanged:\n";
    A.print();

    // Test assignment operator
    Matrix C(2, 2);
    C = A;
    std::cout << "\nMatrix C (assigned from A):\n";
    C.print();

    // Chaining
    Matrix D(2, 2);
    D = C = A;
    std::cout << "\nMatrix D after chaining D = C = A:\n";
    D.print();

    // Self-assignment
    A = A;
    std::cout << "\nMatrix A after self-assignment (should be unchanged):\n";
    A.print();

    return 0;
}
