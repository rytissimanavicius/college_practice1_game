#ifndef ZAIDEJODUOMENYS_H
#define ZAIDEJODUOMENYS_H

#include <fstream>

using namespace std;

bool zaidejasSukurtas = false;

struct zaidDuom {
    string vardas;
    int hp;
    int def;
    int xp;
    int lvl;
    int gold;
    int maistas;
} zaidDuom[5];
void zaidejoDuomenys(int &nr, bool naujinti) {
    if (naujinti == true) {
        zaidDuom[nr].xp+=5;
        if (zaidDuom[nr].maistas > 0) zaidDuom[nr].maistas-=2;
        if (zaidDuom[nr].maistas == 0) zaidDuom[nr].hp-=2;
    }
}
void duomSpausdinimas(int nr) {
    cout << "\nGYVYBE: " << zaidDuom[nr].hp <<
            "\nSARVAI: " << zaidDuom[nr].def <<
            "\nXP: " << zaidDuom[nr].xp <<
            "\nLYGIS: " << zaidDuom[nr].lvl <<
            "\nAUKSAS: " << zaidDuom[nr].gold <<
            "\nMAISTAS: " << zaidDuom[nr].maistas;
}

#endif