#include "Matrix.hpp"
#include <iostream>

int main() 

{
    //NEVOIE REALĂ de Deep Copy (Item 12)
    //Scenariu realist:A = imaginea originală,B = copie pentru pre-procesare->Dacă B se modifică, A trebuie să rămână intactă.
    std::cout << "\n=== Practical Need for Item 12 (Deep Copy) ===\n";

    Matrix Original(2, 2);
    Original.at(0,0)=1; Original.at(0,1)=2;
    Original.at(1,0)=3; Original.at(1,1)=4;

    Matrix Backup = Original; // We want a REAL backup

    // Modify the backup
    Backup.at(0,0) = 999;

    std::cout << "Original should stay unchanged:\n";
    Original.print();

    std::cout << "Backup modified independently:\n";
    Backup.print();

    std::cout << "If deep copy DID NOT exist, modifying Backup would CORRUPT Original.\n";




    //2. NEVOIE REALĂ de Self-Assignment (Item 11)
    //Scenariu real:ai o funcție care trebuie să „refacă” o matrice cu ea însăși (de exemplu, normalizează, scalează, sortează),sau în cod real: A = f(A); unde f poate returna aceeași referință.
    std::cout << "\n=== Practical Need for Item 11 (Self-Assignment Protection) ===\n";

    Matrix M(2,2);
    M.at(0,0)=5; M.at(0,1)=6;
    M.at(1,0)=7; M.at(1,1)=8;

    // Real scenario: resetting an object to itself
    Matrix& RefToSame = M;

    std::cout << "Before M = RefToSame (self-assign):\n";
    M.print();

    M = RefToSame; // Safe only because we handle self-assignment

    std::cout << "After M = RefToSame (object should remain valid):\n";
    M.print();

    std::cout << "Without Item 11, this would corrupt or delete its own memory.\n";






    //3. NEVOIE REALĂ de operator= care returnează *this (Item 10)
    //Vrei să aplici mai multe operații într-o singură linie, ca într-un pipeline:
    std::cout << "\n=== Practical Need for Item 10 (operator= returns *this) ===\n";

    Matrix X(2,2), Y(2,2), Z(2,2);

    X.at(0,0)=1; Y.at(0,0)=2; Z.at(0,0)=3;

    X = Y = Z;  // Chaining requires return *this

    std::cout << "After X = Y = Z, X becomes:\n";
    X.print();

    std::cout << "Without returning *this, chaining would NOT compile.\n";



    return 0;
}
