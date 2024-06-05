#include <iostream>
#include "zlomek.h"

int main() {
    Zlomek z1;
    std::cout << "objekt 'z1' vytvoreny konstruktorem bez parametru: " << z1 << ", " << z1.toDouble() << std::endl;

    Zlomek z2(3, 2);
    std::cout << "objekt 'z2' vytvoreny konstruktorem s parametry : " << z2 << ", " << z2.toDouble() << std::endl;

    Zlomek z3(2, 6);
    std::cout << "objekt 'z3' vytvoreny konstruktorem s parametry : " << z3 << ", " << z3.toDouble() << std::endl;

    Zlomek z4(0, 2);
    std::cout << "objekt 'z4' vytvoreny konstruktorem s parametry : " << z4 << ", " << z4.toDouble() << std::endl;

    std::cout << std::endl;

    std::cout << "objekt 'z2' po prevraceni : " << z2.prevratit() << std::endl;
    std::cout << "Zlomek 'z4' nelze prevratit." << std::endl;

    std::cout << std::endl;

    std::cout << "Zmena zlomku 'z1'" << std::endl;
    int novyCitatel, novyJmenovatel;
    std::cout << "Zadej citatele:";
    std::cin >> novyCitatel;
    std::cout << "Zadej jmenovatele:";
    std::cin >> novyJmenovatel;
    z1.setCitatel(novyCitatel);
    z1.setJmenovatel(novyJmenovatel);
    std::cout << "objekt 'z1' po zmene: " << z1 << ", " << z1.toDouble() << std::endl;

    std::cout << std::endl;

    std::cout << "Scitani a prirazovani zlomku" << std::endl;
    Zlomek z3_z1 = z1 + z2.prevratit();
    std::cout << "z3 = z1 + z2 = " << z1 << " + " << z2.prevratit()  << " = " << z3_z1 << ", " << z3_z1.toDouble() << std::endl;

    return 0;
}