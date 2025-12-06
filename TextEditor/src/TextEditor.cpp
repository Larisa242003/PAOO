#include "TextEditor.h"
#include <iostream>

TextEditor::TextEditor(const std::string& filename)
    : buffer_(""),
      filename_(filename),
      modified_(false)
{
    std::cout << "[TextEditor ctor] file='" << filename_ << "'\n";
}

// Item 12: Copy constructor - copiem TOATE părțile
TextEditor::TextEditor(const TextEditor& other)
    : buffer_(other.buffer_),       // copiem buffer-ul
      filename_(other.filename_),   // copiem numele fișierului
      modified_(other.modified_)    // copiem flag-ul
{
    std::cout << "[TextEditor copy ctor] from '" << other.filename_ 
              << "' to '" << filename_ << "'\n";
}

// Item 12: Copy assignment - copiem TOATE părțile
TextEditor& TextEditor::operator=(const TextEditor& other) {
    std::cout << "[TextEditor operator=] '" << other.filename_ 
              << "' -> '" << filename_ << "'\n";

    if (this == &other) return *this;

    buffer_   = other.buffer_;
    filename_ = other.filename_;
    modified_ = other.modified_;

    return *this;
}

void TextEditor::write(const std::string& text) {
    buffer_.setText(text);
    modified_ = true;
    std::cout << "[TextEditor::write] '" << filename_ << "' modified\n";
}

void TextEditor::append(const std::string& text) {
    buffer_.append(text);
    modified_ = true;
    std::cout << "[TextEditor::append] '" << filename_ << "' modified\n";
}

void TextEditor::display() const {
    std::cout << "\n--- File: " << filename_ 
              << (modified_ ? " [MODIFIED]" : " [SAVED]") << " ---\n";
    std::cout << buffer_.getText() << "\n";
    std::cout << "--- End of file ---\n\n";
}