#include "SharedDocument.h"

// ---- Document ----

Document::Document(const std::string& name, const std::string& content)
    : name_(name),
      content_(content)
{
    std::cout << "[Document ctor] '" << name_ << "'\n";
}

Document::~Document() {
    std::cout << "[Document dtor] '" << name_ << "'\n";
}

void Document::addLine(const std::string& line) {
    content_ += line + "\n";
}

void Document::display() const {
    std::cout << "\n=== Document: " << name_ << " ===\n";
    std::cout << content_;
    std::cout << "=== End ===\n\n";
}

// ---- SharedDocument ----

SharedDocument::SharedDocument(std::shared_ptr<Document> doc)
    : doc_(std::move(doc))
{
    std::cout << "[SharedDocument ctor] use_count=" << doc_.use_count() << "\n";
}

void SharedDocument::edit(const std::string& line) {
    if (doc_) {
        doc_->addLine(line);
    }
}

void SharedDocument::view() const {
    if (doc_) {
        doc_->display();
    }
}

void SharedDocument::printInfo(const std::string& userName) const {
    std::cout << "User '" << userName << "' - document '" 
              << doc_->getName() << "' - use_count=" 
              << doc_.use_count() << "\n";
}