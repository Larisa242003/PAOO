#ifndef AUTO_SAVE_FILE_H
#define AUTO_SAVE_FILE_H

#include <string>

// Item 13: RAII - salvează automat la distrugere
// Item 14: Copiere interzisă (pentru siguranța resursei)

class AutoSaveFile 
{
public:
    AutoSaveFile(const std::string& filename, const std::string& content);
    ~AutoSaveFile();

    AutoSaveFile(const AutoSaveFile&)            = delete;
    AutoSaveFile& operator=(const AutoSaveFile&) = delete;

    void updateContent(const std::string& newContent);
    std::string getFilename() const { return filename; }

private:
    std::string filename;
    std::string content;
};

#endif 
