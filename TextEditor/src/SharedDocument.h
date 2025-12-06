#ifndef SHARED_DOCUMENT_H
#define SHARED_DOCUMENT_H

#include <memory>
#include <string>
#include <iostream>

// Document simplu partajat între mai mulți utilizatori
class Document 
{
public:
    Document(const std::string& name, const std::string& content);
    ~Document();

    void addLine(const std::string& line);
    void display() const;

    std::string getName() const { return name; }

private:
    std::string name;
    std::string content;
};



// Ambalaj RAII + copying behavior clar: shared_ptr pentru ownership partajat
class SharedDocument 
{
public:
    explicit SharedDocument(std::shared_ptr<Document> doc);

    // Copy ctor + operator= generate implicit sunt OK (shared_ptr face ref counting)

    void edit(const std::string& line);
    void view() const;
    void printInfo(const std::string& userName) const;

private:
    std::shared_ptr<Document> doc;
};

#endif 