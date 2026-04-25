#ifndef SPELLS_H
#define SPELLS_H
#include "Magic.h"

class Fire : public Magic {
protected:
    int temperature;
public:
    Fire(std::string n, int cost, int t) : Magic(n, cost), temperature(t) {}
    void cast() override { std::cout << "Вызван огонь (" << temperature << "°C)!\n"; }
    void info() override { Magic::info(); std::cout << ", Температура: " << temperature << "\n"; }
};

class Water : public Magic {
protected:
    int volume;
public:
    Water(std::string n, int cost, int v) : Magic(n, cost), volume(v) {}
    void cast() override { std::cout << "Вызвана вода (" << volume << " л)!\n"; } 
    void info() override { Magic::info(); std::cout << ", Объем: " << volume << "\n"; }
};

class Stone : public PhysicsObject {
public:
    Stone(std::string name, double w) : PhysicsObject(name, w) {}
    void cast() override { std::cout << "Вызван камень (weight = " << weight << ")!\n"; }
    void info() override { 
        PhysicsObject::info(); 
        std::cout << ", камень без атрибутов\n"; 
    }
};

// Множественное наследование
class Steam : public Fire, public Water {
public:
    Steam(std::string n, int cost, int t, int v) 
        : Fire(n, cost, t), Water(n, cost, v) {}

    void cast() override { 
        std::cout << "Вызван эффект пара (" << volume << "л, в температуре " << temperature << ")!\n"; 
    }
    
    void info() override {
        std::cout << "[Комбинированное заклинание]\n";
        Fire::info();
        Water::info();
    }
};

// --- 2 Уровень: Множественное наследование ---
// Комбинация: Лава (Огонь + Камень)
class Lava : public Fire, public Stone {
public:
    Lava(std::string name, double w, int mana, int temp) : Fire(name, mana, temp), Stone(name, w) {}
    
    void cast() override {
        std::cout << "Вызвана лава! ";
        Fire::cast(); 
    }

    void info() override {
        std::cout << "[Комбинированный объект (Огонь+Камень)]\n";
        Fire::info(); 
        Stone::info(); 
    }
};
#endif
