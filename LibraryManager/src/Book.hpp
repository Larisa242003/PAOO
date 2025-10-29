#pragma once
#include <iostream>
#include <cstring>

class Book {
private:
    char* title;   
    char* author;  
    int year;

public:
    Book(const char* t = "Unknown", const char* a = "Unknown", int y = 0);

    ~Book();

    Book(const Book& other);

    Book(Book&& other) noexcept;

    const char* getTitle() const;
    const char* getAuthor() const;
    int getYear() const;

    void setTitle(const char* newTitle);

    void print() const;

    Book& operator=(const Book& other);

};
