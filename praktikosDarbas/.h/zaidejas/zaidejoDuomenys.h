#ifndef ZAIDEJODUOMENYS_H
#define ZAIDEJODUOMENYS_H

using namespace std;

bool zaidejasSukurtas = false;

struct zaidDuom {
    string vardas = "-";
    char sunkumas = '0'; //1, 2, 3
    int hp = 100;
    int def = 0;
    int atk = 0;
    int shield = 0;
    int xp = 0; 
    int lvl = 0; 
    int gold = 500;
    int maistas = 200;
} zaidDuom[5];
//efektai judant zemelapiu, krenta maistas, dideja xp
void zaidejoDuomenys(int nr, bool naujinti) {
    if (naujinti == true) {
        zaidDuom[nr].xp += 5;
        if (zaidDuom[nr].maistas > 0) zaidDuom[nr].maistas -= 2;
        if (zaidDuom[nr].maistas == 0) zaidDuom[nr].hp -= 2;
    }
}
//judant zemelapiu spausdina reguliariai duomenis
void zaidejoDuomenuSpausdinimas(int nr) {
    cout << "GYVYBE: " << zaidDuom[nr].hp <<
            "\nSARVAI: " << zaidDuom[nr].def <<
            "\n\nPUOLIMAS: " << zaidDuom[nr].atk <<
            "\nGYNYBA: " << zaidDuom[nr].shield <<
            "\n\nLYGIS: " << zaidDuom[nr].lvl <<
            "\nXP: " << zaidDuom[nr].xp <<
            "\n\nAUKSAS: " << zaidDuom[nr].gold <<
            "\nMAISTAS: " << zaidDuom[nr].maistas;
}

#endif