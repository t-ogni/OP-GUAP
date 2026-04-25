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

// базовый класс 2
class PhysicsObject {
protected:
    std::string name;  
    int weight;  

public:
    PhysicsObject(std::string n, int w) : name(n), weight(w) {}
    virtual ~PhysicsObject() { std::cout << "PhysicsObject удален\n"; }

    virtual void cast() = 0;
    virtual void info() {    // Метод для перекрытия
        std::cout << "PhysicsObject: " << name << ", вес: " << weight;
    }
};

#endif
