#include "TextBuffer.h"

TextBuffer::TextBuffer(const std::string& initialText) : buffer(initialText.begin(), initialText.end()),size(initialText.length())
{
    buffer.push_back('\0');
    std::cout << "[TextBuffer constructor] size=" << size << "\n";
}

TextBuffer::~TextBuffer() 
{
    std::cout << "[TextBuffer destructor] size=" << size << "\n";
}

TextBuffer::TextBuffer(const TextBuffer& other) : buffer(other.buffer),size(other.size)
{
    std::cout << "[TextBuffer copy constructor] size=" << size << "\n";
}

TextBuffer& TextBuffer::operator=(const TextBuffer& other) 
{
    std::cout << "[TextBuffer operator=]\n";
    if (this == &other) return *this;

    buffer = other.buffer;
    size = other.size;
    return *this;
}

const char* TextBuffer::getText() const 
{
    return buffer.data();
}

size_t TextBuffer::getSize() const 
{
    return size;
}

void TextBuffer::setText(const std::string& text) 
{
    buffer.assign(text.begin(), text.end());
    buffer.push_back('\0');
    size = text.length();
}

void TextBuffer::append(const std::string& text) 
{
    if (size> 0) {
        buffer.pop_back(); // scoatem vechiul '\0'
    }
    buffer.insert(buffer.end(), text.begin(), text.end());
    buffer.push_back('\0');
    size = buffer.size() - 1;
}