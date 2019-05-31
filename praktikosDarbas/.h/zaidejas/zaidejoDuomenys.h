#ifndef ZAIDEJODUOMENYS_H
#define ZAIDEJODUOMENYS_H

using namespace std;

bool zaidejasSukurtas = false;

struct zaidDuom {
    string vardas;
    int hp = 100;
    int def = 0;
    int xp = 0; //TODO: optimaliau bandyti
    int lvl = 0; //TODO:
    int gold = 500;
    int maistas = 200;
    int karma = 50; //TODO:
} zaidDuom[5];
void zaidejoDuomenys(int &nr, bool naujinti) {
    if (naujinti == true) {
        zaidDuom[nr].xp += 5;
        if (zaidDuom[nr].maistas > 0) zaidDuom[nr].maistas -= 2;
        if (zaidDuom[nr].maistas == 0) zaidDuom[nr].hp -= 2;
    }
}
void karma() {

}
void duomSpausdinimas(int nr) {
    cout << "\nGYVYBE: " << zaidDuom[nr].hp <<
            "\nSARVAI: " << zaidDuom[nr].def <<
            "\nXP: " << zaidDuom[nr].xp <<
            "\nLYGIS: " << zaidDuom[nr].lvl <<
            "\nAUKSAS: " << zaidDuom[nr].gold <<
            "\nMAISTAS: " << zaidDuom[nr].maistas <<
            "\nKARMA: " << zaidDuom[nr].karma;
}

#endif