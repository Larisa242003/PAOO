#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "TextBuffer.h"
#include <string>

// Item 12: TextEditor conține TextBuffer + metadata
// -> Copy ctor și operator= trebuie să copieze TOATE părțile
class TextEditor {
public:
    TextEditor(const std::string& filename);

    TextEditor(const TextEditor& other);
    TextEditor& operator=(const TextEditor& other);

    void write(const std::string& text);
    void append(const std::string& text);
    void display() const;

    bool isModified() const { return modified_; }
    std::string getFilename() const { return filename_; }

private:
    TextBuffer  buffer_;   // obiect-membru (resursa de text)
    std::string filename_; // numele fișierului
    bool        modified_; // stare
};

#endif // TEXT_EDITOR_H