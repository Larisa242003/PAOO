#include "Library.hpp"

int main() {
    std::cout << "=== Demonstration of C++ OOP concepts ===\n\n";

    // Inițializare cu constructor
    Book b1("1984", "George Orwell", 1949);
    Book b2("The Hobbit", "J.R.R. Tolkien", 1937);

    // Testare copy constructor
    Book b3 = b1; // copiere
    b3.setTitle("Animal Farm");

    // Testare move constructor
    Book b4 = std::move(b2);

    // Creare bibliotecă
    Library lib;
    lib.addBook(b1);
    lib.addBook(b3);
    lib.addBook(b4);

    // Copiere bibliotecă
    Library libCopy = lib;

    // Mutare bibliotecă
    Library libMoved = std::move(libCopy);

    libMoved.print();

    std::cout << "\n=== End of demonstration ===\n";
    return 0;
}
