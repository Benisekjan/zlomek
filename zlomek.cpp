#include "zlomek.h"

#include "zlomek.h"

int Zlomek::nejvetsiSpolecnyDelitel(int a, int b) const { // Změna zde
    if (b == 0)
        return a;
    return nejvetsiSpolecnyDelitel(b, a % b);
}

Zlomek::Zlomek() : citatel(1), jmenovatel(1) {}

Zlomek::Zlomek(int cit, int jmen) {
    if (jmen == 0) {
        std::cerr << "Chyba: Jmenovatel nemuze byt nula." << std::endl;
        citatel = 0;
        jmenovatel = 1;
        return;
    }
    int nsd = nejvetsiSpolecnyDelitel(std::abs(cit), std::abs(jmen));
    citatel = cit / nsd;
    jmenovatel = jmen / nsd;
}

int Zlomek::getCitatel() const {
    return citatel;
}

void Zlomek::setCitatel(int cit) {
    citatel = cit;
}

int Zlomek::getJmenovatel() const {
    return jmenovatel;
}

void Zlomek::setJmenovatel(int jmen) {
    if (jmen != 0) {
        jmenovatel = jmen;
    } else {
        std::cerr << "Chyba: Jmenovatel nemuze byt nula." << std::endl;
    }
}

std::string Zlomek::toString() const {
    return std::to_string(citatel) + "/" + std::to_string(jmenovatel);
}

double Zlomek::toDouble() const {
    return static_cast<double>(citatel) / jmenovatel;
}

Zlomek Zlomek::zkratit() const {
    int nsd = nejvetsiSpolecnyDelitel(std::abs(citatel), std::abs(jmenovatel));
    return Zlomek(citatel / nsd, jmenovatel / nsd);
}

Zlomek Zlomek::prevratit() const {
    if (citatel != 0)
        return Zlomek(jmenovatel, citatel);
    else {
        std::cerr << "Zlomek nelze prevratit." << std::endl;
        return *this;
    }
}

Zlomek& Zlomek::operator=(const Zlomek& z) {
    if (this == &z)
        return *this;

    citatel = z.citatel;
    jmenovatel = z.jmenovatel;

    return *this;
}

Zlomek operator+(const Zlomek& z1, const Zlomek& z2) {
    int novyCitatel = z1.getCitatel() * z2.getJmenovatel() + z2.getCitatel() * z1.getJmenovatel();
    int novyJmenovatel = z1.getJmenovatel() * z2.getJmenovatel();
    return Zlomek(novyCitatel, novyJmenovatel);
}

std::ostream& operator<<(std::ostream& os, const Zlomek& z) {
    os << z.toString();
    return os;
}
