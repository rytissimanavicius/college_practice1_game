#include <iostream>
#include <fstream>

using namespace std;

bool zaidejasSukurtas = false;

struct zaidDuom {
    string vardas;
    int hp;
    int def;
    int xp;
    int lvl;
} zaidDuom[5];
void zaidejoDuomenys(int &nr) {
    if (zaidejasSukurtas == true) {
        cout << "\nGYVYBE: " << zaidDuom[nr].hp <<
                "\nSARVAI: " << zaidDuom[nr].def <<
                "\nXP: " << zaidDuom[nr].xp <<
                "\nLYGIS: " << zaidDuom[nr].lvl;
    }
    else {
        while (nr < 1 || nr > 5) {
            cout << "\nKURIA ZAIDEJO VIETA RENKATES: ";
            cin >> nr;
        }
        cout << "IVESKITE ZAIDEJO VARDA: ";
        cin >> zaidDuom[nr].vardas;
        zaidDuom[nr].xp = 0;
        zaidDuom[nr].hp = 100;
        zaidDuom[nr].def = 0;
        zaidDuom[nr].lvl = 0;
        zaidejasSukurtas = true;
    }
}