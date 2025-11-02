#include "Library.hpp"

int main() {
    std::cout << "=== Demonstration of C++ OOP concepts ===\n\n";

    Book b1("1984", "George Orwell", 1949);
    Book b2("The Hobbit", "J.R.R. Tolkien", 1937);

    Book b3 = b1; 
    b3.setTitle("Animal Farm");

    Book b4 = std::move(b2);

    Library lib;
    lib.addBook(b1);
    lib.addBook(b3);
    lib.addBook(b4);

    Library libCopy = lib;

    Library libMoved = std::move(libCopy);

    libMoved.print();

    std::cout << "\n=== End of demonstration ===\n";
    return 0;
}
