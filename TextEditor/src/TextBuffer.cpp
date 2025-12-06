#include "TextBuffer.h"

TextBuffer::TextBuffer(const std::string& initialText)
    : buffer_(initialText.begin(), initialText.end()),
      size_(initialText.length())
{
    buffer_.push_back('\0');
    std::cout << "[TextBuffer ctor] size=" << size_ << "\n";
}

TextBuffer::~TextBuffer() {
    std::cout << "[TextBuffer dtor] size=" << size_ << "\n";
}

TextBuffer::TextBuffer(const TextBuffer& other)
    : buffer_(other.buffer_),
      size_(other.size_)
{
    std::cout << "[TextBuffer copy ctor] size=" << size_ << "\n";
}

TextBuffer& TextBuffer::operator=(const TextBuffer& other) {
    std::cout << "[TextBuffer operator=]\n";
    if (this == &other) return *this;

    buffer_ = other.buffer_;
    size_   = other.size_;
    return *this;
}

const char* TextBuffer::getText() const {
    return buffer_.data();
}

size_t TextBuffer::getSize() const {
    return size_;
}

void TextBuffer::setText(const std::string& text) {
    buffer_.assign(text.begin(), text.end());
    buffer_.push_back('\0');
    size_ = text.length();
}

void TextBuffer::append(const std::string& text) {
    if (size_ > 0) {
        buffer_.pop_back(); // scoatem vechiul '\0'
    }
    buffer_.insert(buffer_.end(), text.begin(), text.end());
    buffer_.push_back('\0');
    size_ = buffer_.size() - 1;
}