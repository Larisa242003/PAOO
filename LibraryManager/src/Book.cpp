#include "Book.hpp"


Book::Book(const char* t, const char* a, int y): title(nullptr), author(nullptr), year(y)
{
    std::cout << "[Book ctor] Creating book: " << t << "\n";

    title = new char[strlen(t) + 1]; 
    strcpy(title, t);

    author = new char[strlen(a) + 1];
    strcpy(author, a);
}

Book::~Book() 
{
    std::cout << "[Book dtor] Deleting book: " << (title ? title : "null") << "\n";
    delete[] title;
    delete[] author;
}

Book::Book(const Book& other) : year(other.year)
{
    std::cout << "[Book copy ctor] Copying book: " << other.title << "\n";

    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);

    author = new char[strlen(other.author) + 1];
    strcpy(author, other.author);
}


Book::Book(Book&& other) noexcept : title(other.title), author(other.author), year(other.year)
{
    std::cout << "[Book move ctor] Moving book: " << (other.title ? other.title : "null") << "\n";
    other.title = nullptr;
    other.author = nullptr;
    other.year = 0;
}

const char* Book::getTitle() const 
{ 
    return title; 
}

const char* Book::getAuthor() const 
{ 
    return author; 
}

int Book::getYear() const 
{ 
    return year; 
}


void Book::setTitle(const char* newTitle) 
{
    delete[] title;
    title = new char[strlen(newTitle) + 1];
    strcpy(title, newTitle);
}

void Book::print() const 
{
    std::cout << "Book: " << title << " by " << author << " (" << year << ")\n";
}

Book& Book::operator=(const Book& other) {
    std::cout << "[Book copy assignment] Copying from " 
              << (other.title ? other.title : "null") << "\n";

    if (this == &other)
        return *this; 

    delete[] title;
    delete[] author;

    year = other.year;

    title = new char[strlen(other.title) + 1];
    strcpy(title, other.title);

    author = new char[strlen(other.author) + 1];
    strcpy(author, other.author);

    return *this;
}
