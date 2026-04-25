#include "Spells.h"

void showMagic(Magic* m) {
    std::cout << " Вызываю указанный эффект " << std::endl;
    m->cast(); 
    std::cout << " Инфа по нему: " << std::endl;
    m->info();
}

int main() {
    setlocale(LC_ALL, "Russian");

    Fire* f = new Fire("Огненный шар", 30, 800);
    Steam* s = new Steam("Пар", 60, 100, 50);

    showMagic(f); 
    std::cout << "\n";
    std::cout << "\n";
    showMagic(static_cast<Fire*>(s)); 
    std::cout << "\n";
    
    delete f;
    delete s;
    return 0;
}
