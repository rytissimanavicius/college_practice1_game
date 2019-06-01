#ifndef KOVA_H
#define KOVA_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"

using namespace std;

void spausdintiDuomenis(int nr) {
    cout << "\nJUSU DUOMENYS:\nGYVYBE: " << zaidDuom[nr].hp << "\nSARVAI: " << zaidDuom[nr].def << "\nPUOLIMAS: " << zaidDuom[nr].atk << "\nSKYDAS: " << zaidDuom[nr].shield << "%\n";
}
void kova(int nr) {
    bool kovaVyksta = true;
    spausdintiDuomenis(nr);
}

#endif