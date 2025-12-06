#include "AutoSaveFile.h"
#include <iostream>
#include <fstream>

AutoSaveFile::AutoSaveFile(const std::string& filename, const std::string& content)
    : filename_(filename),
      content_(content)
{
    std::cout << "[AutoSaveFile ctor] Pregătit pentru salvare: '" 
              << filename_ << "'\n";
}

AutoSaveFile::~AutoSaveFile() {
    std::cout << "[AutoSaveFile dtor] Salvez automat '" << filename_ << "'...\n";

    std::ofstream file(filename_);
    if (file.is_open()) {
        file << content_;
        file.close();
        std::cout << "[AutoSaveFile] ✓ Salvat cu succes!\n";
    } else {
        std::cout << "[AutoSaveFile] ✗ Eroare la salvare!\n";
    }
}

void AutoSaveFile::updateContent(const std::string& newContent) {
    content_ = newContent;
    std::cout << "[AutoSaveFile::updateContent] Conținut actualizat\n";
}