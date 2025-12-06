#ifndef TEXT_BUFFER_H
#define TEXT_BUFFER_H

#include <iostream>
#include <vector>
#include <string>

// Buffer simplu pentru text (gestionează dinamic conținutul)
class TextBuffer 
{
public:
    TextBuffer(const std::string& initialText = "");
    ~TextBuffer();

    TextBuffer(const TextBuffer& other);
    TextBuffer& operator=(const TextBuffer& other);

    const char* getText() const;
    size_t getSize() const;

    void setText(const std::string& text);
    void append(const std::string& text);

private:
    std::vector<char> buffer; // conține și '\0' la final
    size_t size;              // nr. de caractere fără '\0'
};

#endif // TEXT_BUFFER_H