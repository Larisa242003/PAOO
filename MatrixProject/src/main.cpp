#include "Matrix.hpp"
#include <iostream>

int main() {
    std::cout << "===== MATRIX PROJECT =====\n\n";

    std::cout << "--- Deep Copy ---\n";

    Matrix A(2, 2);
    A.at(0, 0) = 1;
    A.at(0, 1) = 2;
    A.at(1, 0) = 3;
    A.at(1, 1) = 4;

    std::cout << "Matrix A:\n";
    A.print();

    Matrix B = A; 
    std::cout << "\nMatrix B (copied from A):\n";
    B.print();

    B.at(0, 0) = 99;
    std::cout << "\nMatrix B after modification (B[0,0] = 99):\n";
    B.print();

    std::cout << "\nMatrix A should remain unchanged (deep copy works):\n";
    A.print();


    std::cout << "\n--- operator= (Self-assignment + Return *this) ---\n";

    Matrix C(2, 2);
    C = A;  
    std::cout << "\nMatrix C (assigned from A):\n";
    C.print();

    Matrix D(2, 2);
    D = C = A; 
    std::cout << "\nMatrix D after chaining D = C = A:\n";
    D.print();


    std::cout << "\nTesting self-assignment A = A:\n";
    A = A;
    std::cout << "Matrix A after self-assignment (should be unchanged):\n";
    A.print();

    std::cout << "===== END OF MATRIX PROJECT =====\n";

    return 0;
}
