/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója.
 *
 * Folytassa a megvalósítást sorrendben a komplex.h fájlban levő feladatoknak megfelelően!
 *
 */


#include <iostream>         // Valószínű, hogy a kiíráshoz majd kell
#include <iomanip>          // ... és ez is.
#include <cmath>            // az sqrt miatt kell.

#include "komplex.h"        // Ebben van a Komplex osztály, és néhány globális függvény deklarációja

///using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret, a headerben soha!

/// Előre elkészített tagfüggvények

/// 0, 1 és 2 paraméteres konstruktor
/// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
/// adtuk meg!
Komplex::Komplex(double r, double im) {
    re = r; // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}

///---- Egy példa a konstans tagfüggvényre, ehhez hasonlóan kell
///     elkészíteni a gettereket az 1. feladatban (ELKESZULT=1)
/// Abszolút érték lekérdezése
/// @return - abszolút érték
double Komplex::abs() const { return sqrt(re*re + im*im); }

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false
bool Komplex::operator!=(const Komplex& rhs_k) const {  // visszavezetjük az egyenlőség vizsgálatra
    return !(*this == rhs_k);
}
#endif

#if ELKESZULT >= 6
// 6. feladathoz (ELKESZULT 6)
// a += művelet viszont módosítja önmagát!
/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
    re += rhs_d;
    return *this;
}
#endif

// ------------------------ Eddig elkészítettük -------------------------
// TODO: A hiányzó tag- és globális függvények itt következnek

// 1-es feladat
double Komplex::getRe() const {
    return re;
}

double Komplex::getIm() const {
    return im;
}
// 1-es feladat vége

// 2-es feladat
void Komplex::setRe(double re) {
    this->re = re;
}

void Komplex::setIm(double im) {
    this->im = im;
}
// 2-es feladat vége

// 3-as feladat
bool Komplex::operator==(const Komplex& rhs_k) const {
    return (re == rhs_k.re) && (im == rhs_k.im);
}
// 3-as feladat vége

// 4-es feladat
Komplex Komplex::operator+(const Komplex& rhs_k) const {
    return Komplex(re + rhs_k.re, im + rhs_k.im);
}

Komplex Komplex::operator+(double rhs_d) const {
    return Komplex(re + rhs_d, im);
}
// 4-es feladat vége

// 5-ös feladat
Komplex operator+(double lhs_d, const Komplex& rhs_k) {
    return Komplex(lhs_d + rhs_k.getRe(), rhs_k.getIm());
}
// 5-ös feladat vége

// 6-os feladat
Komplex& Komplex::operator+=(const Komplex& rhs_k) {
    re += rhs_k.re;
    im += rhs_k.im;
    return *this;
}

// 6-os feladat vége
