#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include "EditorBase.h"
#include "TextBuffer.h"
#include <string>

// Item 12 + moștenire:
// TextEditor DERIVĂ din EditorBase și conține TextBuffer ca membru.

class TextEditor : public EditorBase 
{
public:
    explicit TextEditor(const std::string& filename);

    TextEditor(const TextEditor& other);
    TextEditor& operator=(const TextEditor& other);

    void write(const std::string& text);
    void append(const std::string& text);
    void display() const;

    bool isModified() const { return modified; }
    
    // folosim filename moștenit din EditorBase
    std::string getFilename() const { return filename; }

private:
    TextBuffer buffer; // obiect-membru (resursa de text)
    bool       modified;
};

#endif // TEXT_EDITOR_H