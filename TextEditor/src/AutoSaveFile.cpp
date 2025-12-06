#include "AutoSaveFile.h"
#include <iostream>
#include <fstream>

AutoSaveFile::AutoSaveFile(const std::string& filename, const std::string& content) : filename(filename),content(content)
{
    std::cout << "[AutoSaveFile constructor] Pregătit pentru salvare: '" << filename << "'\n";
}


AutoSaveFile::~AutoSaveFile() 
{
    std::cout << "[AutoSaveFile dtor] Salvez automat '" << filename << "'...\n";

    std::ofstream file(filename);
    if (file.is_open()) 
    {
        file << content;
        file.close();
        std::cout << "[AutoSaveFile] ✓ Salvat cu succes!\n";
    } 
    else 
    {
        std::cout << "[AutoSaveFile] ✗ Eroare la salvare!\n";
    }
}


void AutoSaveFile::updateContent(const std::string& newContent) 
{
    content = newContent;
    std::cout << "[AutoSaveFile::updateContent] Conținut actualizat\n";
}