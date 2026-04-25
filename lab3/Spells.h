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
#endif
