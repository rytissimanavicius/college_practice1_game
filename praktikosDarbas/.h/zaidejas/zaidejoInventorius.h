#ifndef ZAIDEJOINVENTORIUS_H
#define ZAIDEJOINVENTORIUS_H

#include <fstream>

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\sansoKauliukas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\daiktai\daiktuStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"

using namespace std;

struct zaidInv {
    string pav = "-";
    string tipas = "-";
} zaidInv[10];
void zaidejoInventoriusSpausdinimas(int nr) {
    cout << "\nINVENTORIUS:\n";
    for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) {
        cout << i + 1 << ". " << zaidInv[i].pav;
        if (zaidInv[i].tipas == "sarvai") cout << " (GYNYBA: " << zaidDuom[nr].def << ")";
        if (zaidInv[i].tipas == "kardas") cout << " (PUOLIMAS: " << zaidDuom[nr].atk << ")";
        if (zaidInv[i].tipas == "skydas") cout << " (BLOKO SANSAS: " << zaidDuom[nr].shield << "%)";
        if (zaidInv[i].tipas == "gyvybe") cout << " (KIEKIS: " << potion.kiekis << ")";
        cout << "\n";
    }
}
void zaidejoInventoriausFunkcijos(int nr) {
    int pasirinkimas;
    cout << "\n0. GRIZTI."
            "\n1. SUKEISTI DAIKTUS"
            "\n\nPASIRINKITE VEIKSMA: ";
    cin >> pasirinkimas;
    if (pasirinkimas == 1) {
        int pirmas, antras;
        string temp;
        cout << "\nPASIRINKITE DAIKTA: ";
        cin >> pirmas;
        cout << "PASIRINKITE DAIKTA SU KURIUO SUKEISITE: ";
        cin >> antras;
        if (pirmas == 1 && (zaidInv[antras - 1].tipas == "sarvai" || zaidInv[antras - 1].tipas == "-")) {
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
    }
}
void atnaujintiZaidejoDuomenis(int nr, int duomenys, int daiktoVieta) {
    if (daiktoVieta == 0) zaidDuom[nr].def = duomenys;
    else if (daiktoVieta == 1) zaidDuom[nr].atk = duomenys;
    else zaidDuom[nr].shield = duomenys;
}
void uzdetiSarvus(int nr, string irangosPav, int duomenys) {
    for (int i = 0; i < sizeof sarvai / sizeof sarvai[0]; i++) {
        if (sarvai[i].pav == "-") {
            sarvai[i].pav = irangosPav + " SARVAI";
            sarvai[i].gynyba = duomenys;
            zaidInv[0].pav = sarvai[i].pav;
            zaidInv[0].tipas = sarvai[i].tipas;
            atnaujintiZaidejoDuomenis(nr, duomenys, 0);
            break;
        }
    }
}
void uzdetiKarda(int nr, string irangosPav, int duomenys) {
    for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
        if (kardas[i].pav == "-") {
            kardas[i].pav = irangosPav + " KARDAS";
            kardas[i].puolimas = duomenys;
            zaidInv[1].pav = kardas[i].pav;
            zaidInv[1].tipas = kardas[i].tipas;
            atnaujintiZaidejoDuomenis(nr, duomenys, 1);
            break;
        }
    }
}
void uzdetiSkyda(int nr, string irangosPav, int duomenys) {
    for (int i = 0; i < sizeof skydas / sizeof skydas[0]; i++) {
        if (skydas[i].pav == "-") {
            skydas[i].pav = irangosPav + " SKYDAS";
            skydas[i].sansas = duomenys;
            zaidInv[2].pav = skydas[i].pav;
            zaidInv[2].tipas = skydas[i].tipas;
            atnaujintiZaidejoDuomenis(nr, duomenys, 2);
            break;
        }
    }
}

void duotiPradineIranga(int nr) {
    int pavadinimas;
    string irangosPav;
    string mas[1000];
    ifstream vardai(".txt/pavadinimaiIrangai.txt");
    if (vardai.is_open()) {
        for (int j = 0; j < 1000; j++) { 
            vardai >> mas[j];
        }
    }
    for (int i = 0; i < 3; i++) {
        sansoKauliukas(pavadinimas, 1, 1000);
        irangosPav = mas[pavadinimas];
        if (i == 0) uzdetiSarvus(nr, irangosPav, 10);
        if (i == 1) uzdetiKarda(nr, irangosPav, 20);
        if (i == 2) uzdetiSkyda(nr, irangosPav, 10);
    }
}

#endif