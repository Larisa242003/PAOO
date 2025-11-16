#include "Matrix.hpp"
#include <iostream>

int main() 

{
    std::cout << "\n=== Practical Need for Item 12 (Deep Copy) ===\n";

    Matrix Original(2, 2);
    Original.at(0,0)=1; Original.at(0,1)=2;
    Original.at(1,0)=3; Original.at(1,1)=4;

    Matrix Backup = Original; 

    Backup.at(0,0) = 999;

    std::cout << "Original should stay unchanged:\n";
    Original.print();

    std::cout << "Backup modified independently:\n";
    Backup.print();

    std::cout << "If deep copy DID NOT exist, modifying Backup would CORRUPT Original.\n";





    std::cout << "\n=== Practical Need for Item 11 (Self-Assignment Protection) ===\n";

    Matrix M(2,2);
    M.at(0,0)=5; M.at(0,1)=6;
    M.at(1,0)=7; M.at(1,1)=8;

    Matrix& RefToSame = M;

    std::cout << "Before M = RefToSame (self-assign):\n";
    M.print();

    M = RefToSame; 

    std::cout << "After M = RefToSame (object should remain valid):\n";
    M.print();

    std::cout << "Without Item 11, this would corrupt or delete its own memory.\n";




    std::cout << "\n=== Practical Need for Item 10 (operator= returns *this) ===\n";

    Matrix X(2,2), Y(2,2), Z(2,2);

    X.at(0,0)=1; Y.at(0,0)=2; Z.at(0,0)=3;

    X = Y = Z;  

    std::cout << "After X = Y = Z, X becomes:\n";
    X.print();

    std::cout << "Without returning *this, chaining would NOT compile.\n";


    

    return 0;
}
