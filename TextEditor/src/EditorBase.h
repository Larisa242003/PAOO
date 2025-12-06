#ifndef EDITOR_BASE_H
#define EDITOR_BASE_H

#include <string>
#include <iostream>

// Clasă de bază pentru editori (ține numele fișierului)
class EditorBase 
{
public:
    explicit EditorBase(const std::string& filename);
  
    EditorBase(const EditorBase& other);
  
    EditorBase& operator=(const EditorBase& other);
    
    virtual ~EditorBase() = default;

    const std::string& getFilename() const { return filename; }

protected:
    std::string filename; // protejat, ca să-l poată folosi clasele derivate
};

#endif // EDITOR_BASE_H