#include "TextEditor.h"
#include <iostream>

// Constructor normal: apelăm baza + inițializăm membrii proprii
TextEditor::TextEditor(const std::string& filename)
    : EditorBase(filename),
      buffer(""),
      modified(false)
{
    std::cout << "[TextEditor constructor]\n";
}


// Copy constructor
TextEditor::TextEditor(const TextEditor& other)
    : EditorBase(other),        // <-- APELĂM COPY CONSTRUCTOR DIN BAZĂ (EditorBase)
      buffer(other.buffer),   
      modified(other.modified)
{
    std::cout << "[TextEditor copy constructor] from '" << other.filename
              << "' to '" << filename << "'\n";
}


// Copy assignment
TextEditor& TextEditor::operator=(const TextEditor& other)
{
    std::cout << "[TextEditor operator=]\n";

    if (this == &other) return *this;

    // 1) copiem partea de BAZĂ (ca în exemplul din carte cu Customer::operator=)
    EditorBase::operator=(other);

    // 2) copiem membrii PROPRII ai lui TextEditor
    buffer  = other.buffer;
    modified = other.modified;

    return *this;
}


void TextEditor::write(const std::string& text) 
{
    buffer.setText(text);
    modified = true;
    std::cout << "[TextEditor::write] '" << filename << "' modified\n";
}


void TextEditor::append(const std::string& text) 
{
    buffer.append(text);
    modified = true;
    std::cout << "[TextEditor::append] '" << filename << "' modified\n";
}


void TextEditor::display() const 
{
    std::cout << "\n--- File: " << filename
              << (modified ? " [MODIFIED]" : " [SAVED]") << " ---\n";
    std::cout << buffer.getText() << "\n";
    std::cout << "--- End of file ---\n\n";
}