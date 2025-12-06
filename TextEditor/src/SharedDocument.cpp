#include "SharedDocument.h"

// ---- Document ----

Document::Document(const std::string& name, const std::string& content) : name(name),content(content)
{
    std::cout << "[Document constructor] '" << name << "'\n";
}

Document::~Document() 
{
    std::cout << "[Document destructor] '" << name << "'\n";
}

void Document::addLine(const std::string& line) 
{
    content += line + "\n";
}

void Document::display() const 
{
    std::cout << "\n=== Document: " << name << " ===\n";
    std::cout << content;
    std::cout << "=== End ===\n\n";
}

// ---- SharedDocument ----

SharedDocument::SharedDocument(std::shared_ptr<Document> doc) : doc(std::move(doc))
{
    std::cout << "[SharedDocument constructor] use_count=" << doc.use_count() << "\n";
}

void SharedDocument::edit(const std::string& line) 
{
    if (doc) 
    {
        doc->addLine(line);
    }
}

void SharedDocument::view() const 
{
    if (doc) 
    {
        doc->display();
    }
}

void SharedDocument::printInfo(const std::string& userName) const 
{
    std::cout << "User '" << userName << "' - document '" 
              << doc->getName() << "' - use_count=" 
              << doc.use_count() << "\n";
}