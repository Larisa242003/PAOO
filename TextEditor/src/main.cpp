#include <iostream>
#include <memory>

#include "TextEditor.h"
#include "AutoSaveFile.h"
#include "SharedDocument.h"

int main() 
{
    std::cout << "=== EDITOR DE TEXT SIMPLU ===\n\n";

    // =======================
    // Item 12: Copy all parts
    // =======================
    std::cout << "--- Item 12: Copiere corectă a tuturor părților ---\n";
    {
        TextEditor editor1("document.txt");
        editor1.write("Acesta este primul paragraf.\n");
        editor1.append("Acesta este al doilea paragraf.\n");
        editor1.display();

        std::cout << "\n-- Copiere prin copy constructor (editor2 = editor1) --\n";
        TextEditor editor2 = editor1; 
        editor2.display();

        std::cout << "\n-- Copiere prin assignment (editor3 = editor1) --\n";
        TextEditor editor3("alt_document.txt");
        editor3 = editor1;       
        editor3.display();
    }

    std::cout << "\n";

    // ==========================
    // Item 13: RAII AutoSaveFile
    // ==========================
    std::cout << "--- Item 13: RAII - salvare automată ---\n";
    {
        AutoSaveFile autoFile("autosave.txt", "Conținut inițial\n");
        autoFile.updateContent("Conținut inițial\nLinie adăugată\n");
        autoFile.updateContent("Conținut inițial\nLinie adăugată\nÎncă o linie\n");

        // AutoSaveFile autoFile2 = autoFile; // ar da eroare de compilare (copy = delete)
        std::cout << "La ieșirea din acest bloc, 'autosave.txt' se salvează automat...\n";
    }

    std::cout << "\n";

    // ===========================================
    // Item 14: copying behavior + shared_ptr RAII
    // ===========================================
    std::cout << "--- Item 14: Document partajat (reference counting) ---\n";
    {
        auto doc = std::make_shared<Document>("Raport.txt","Titlu: Raport Anual\n\n");

        std::cout << "\n-- User1 deschide documentul --\n";
        SharedDocument user1(doc);
        user1.printInfo("User1");
        user1.edit("Secțiunea 1: Introducere");

        std::cout << "\n-- User2 deschide același document --\n";
        SharedDocument user2 = user1;  // copy -> use_count crește
        user2.printInfo("User2");
        user2.edit("Secțiunea 2: Analiză");

        std::cout << "\n-- User3 se alătură temporar --\n";
        {
            SharedDocument user3 = user2;
            user3.printInfo("User3");
            user3.edit("Secțiunea 3: Concluzii");

            user3.view();
        } // user3 iese din scope -> use_count scade

        std::cout << "\n-- După ce User3 a ieșit --\n";
        user1.printInfo("User1");
        user2.printInfo("User2");
    }

    std::cout << "\n=== EDITOR ÎNCHIS ===\n";
    return 0;
}