#include "Library.hpp"

Library::Library(int c) : books(nullptr), count(0)
{
    std::cout << "[Library constructor] Creating library with capacity: " << c << "\n";
    if (c > 0) 
    {
        books = new Book[c];
        count = c;
    }
}

Library::~Library() 
{
    std::cout << "[Library destructor] Deleting library with " << count << " books\n";
    delete[] books;
}

Library::Library(const Library& other) : count(other.count)
{
    std::cout << "[Library copy constructor] Copying library with " << other.count << " books\n";
    if (count > 0) 
    {
        books = new Book[count];
        for (int i = 0; i < count; ++i) 
        {
            books[i] = other.books[i]; 
        }
    } 
    else 
    {
        books = nullptr;
    }
}

Library::Library(Library&& other) noexcept : books(other.books), count(other.count)
{
    std::cout << "[Library move constructor] Moving library with " << other.count << " books\n";
    other.books = nullptr;
    other.count = 0;
}

void Library::addBook(const Book& b) 
{
    std::cout << "[Library] Adding book: " << b.getTitle() << "\n";

    Book* newBooks = new Book[count + 1];
    for (int i = 0; i < count; ++i)
        newBooks[i] = books[i]; 

    newBooks[count] = b;

    delete[] books;
    books = newBooks;
    ++count;
}

void Library::print() const 
{
    std::cout << "Library contains " << count << " books:\n";
    for (int i = 0; i < count; ++i)
        books[i].print();
}
