#ifndef ZLOMEK_H
#define ZLOMEK_H

#include <iostream>

class Zlomek {
private:
    int citatel;
    int jmenovatel;

    int nejvetsiSpolecnyDelitel(int a, int b) const; // Změna zde

public:
    Zlomek();
    Zlomek(int cit, int jmen);

    int getCitatel() const;
    void setCitatel(int cit);

    int getJmenovatel() const;
    void setJmenovatel(int jmen);

    std::string toString() const;

    double toDouble() const;

    Zlomek zkratit() const;
    Zlomek prevratit() const;

    Zlomek& operator=(const Zlomek& z);

    friend Zlomek operator+(const Zlomek& z1, const Zlomek& z2);

    friend std::ostream& operator<<(std::ostream& os, const Zlomek& z);
};

#endif // ZLOMEK_H
