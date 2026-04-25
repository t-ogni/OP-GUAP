#ifndef MAGIC_H
#define MAGIC_H
#include <iostream>
#include <string>

class Magic {
protected:
    std::string name;  
    int manaCost;  

public:
    Magic(std::string n, int cost) : name(n), manaCost(cost) {}
    virtual ~Magic() { std::cout << "Магия удалена\n"; }

    virtual void cast() = 0;
    virtual void info() {    // Метод для перекрытия
        std::cout << "Заклинание: " << name << ", Мана: " << manaCost;
    }
};
#endif
