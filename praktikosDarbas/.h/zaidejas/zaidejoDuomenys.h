#ifndef ZAIDEJODUOMENYS_H
#define ZAIDEJODUOMENYS_H

using namespace std;

bool zaidejasSukurtas = false;

struct zaidDuom {
    string vardas = "-";
    int sunkumas = 0; //1, 2, 3
    int hp = 100;
    int def = 0;
    int atk = 0;
    int shield = 0;
    int xp = 0; 
    int lvl = 0; 
    int gold = 500;
    int maistas = 200;
} zaidDuom[5];
struct lygis {
    int pliusPuolimas = 0;
    int pliusGyvybe = 0;
} lygis;
//efektai judant zemelapiu, krenta maistas, dideja xp
void zaidejoDuomenys(int nr, bool naujinti) {
    if (naujinti == true) {
        zaidDuom[nr].xp += 100;
        if (zaidDuom[nr].maistas > 0) zaidDuom[nr].maistas -= 2;
        if (zaidDuom[nr].maistas == 0) zaidDuom[nr].hp -= 2;
    }
}
//judant zemelapiu spausdina reguliariai duomenis
void zaidejoDuomenuSpausdinimas(int nr) {
    cout << "GYVYBE: " << zaidDuom[nr].hp + lygis.pliusGyvybe <<
            "\nSARVAI: " << zaidDuom[nr].def <<
            "\nPUOLIMAS: " << zaidDuom[nr].atk + lygis.pliusPuolimas <<
            "\nGYNYBA: " << zaidDuom[nr].shield <<
            "\nLYGIS: " << zaidDuom[nr].lvl <<
            "\nXP: " << zaidDuom[nr].xp <<
            "\nAUKSAS: " << zaidDuom[nr].gold <<
            "\nMAISTAS: " << zaidDuom[nr].maistas;
}
void pasirinktiSavybe(int nr) {
    int pasirinkti;
    cout << "\n\nPASIKELETE " << zaidDuom[nr].lvl << "-AJI LYGI!"
            "\n1. PUOLIMAS +10."
            "\n2. GYVYBE +10."
            "\n\nPASIRINKITE NAUJA ZAIDEJO SAVYBE: ";
    cin >> pasirinkti;
    switch (pasirinkti) {
        case 1: {
            lygis.pliusPuolimas = lygis.pliusPuolimas + 10;
            break;
        }
        case 2: {
            lygis.pliusGyvybe = lygis.pliusGyvybe + 10;
            break;
        }
        default: {
            cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
            break;
        }
    }
}
void pasikeleLygi(int nr) {
    if (zaidDuom[nr].xp >= 1000 && zaidDuom[nr].lvl < 1) {
        zaidDuom[nr].lvl = 1;
        pasirinktiSavybe(nr);
    }
    else if (zaidDuom[nr].xp >= 2500 && zaidDuom[nr].lvl < 2) {
        zaidDuom[nr].lvl = 2;   
        pasirinktiSavybe(nr);
    }
    else if (zaidDuom[nr].xp >= 5000 && zaidDuom[nr].lvl < 3) {
        zaidDuom[nr].lvl = 3;
        pasirinktiSavybe(nr);
    }
}

#endif