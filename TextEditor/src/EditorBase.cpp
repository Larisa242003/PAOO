#include "EditorBase.h"

EditorBase::EditorBase(const std::string& filename) : filename(filename)
{
    std::cout << "[EditorBase constructor] file='" << filename << "'\n";
}

EditorBase::EditorBase(const EditorBase& other) : filename(other.filename)
{
    std::cout << "[EditorBase copy constructor] from '" << other.filename
              << "' to '" << filename << "'\n";
}

EditorBase& EditorBase::operator=(const EditorBase& other)
{
    std::cout << "[EditorBase operator=] '" << other.filename
              << "' -> '" << filename << "'\n";

    if (this == &other) return *this;

    filename = other.filename;
    return *this;
}