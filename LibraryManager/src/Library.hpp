#pragma once
#include "Book.hpp"
#include <iostream>

class Library {
private:
    Book* books;     
    int count;       

public:

    Library(int c = 0);

    ~Library();

    Library(const Library& other);

    Library(Library&& other) noexcept;

    void addBook(const Book& b);

    void print() const;

    int getCount() const { return count; }
};
