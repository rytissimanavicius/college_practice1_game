#ifndef KOVA_H
#define KOVA_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\sansoKauliukas.h"

using namespace std;

struct priesas {
    int gyvybe = 0;
    int sarvai = 0;
    int puolimas = 0;
    int skydas = 0;
    int duosXp = 0;
    int duosAukso = 0;
} priesas;
void spausdintiZaidejoDuomenis(int nr) {
    cout << "\nJUSU DUOMENYS:\nGYVYBE: " << zaidDuom[nr].hp << "\nSARVAI: " << zaidDuom[nr].def << "\nPUOLIMAS: " << zaidDuom[nr].atk << "\nSKYDAS: " << zaidDuom[nr].shield << "%\n";
}
void spausdintiPriesoDuomenis() {
    cout << "\nPRIESO DUOMENYS:\nGYVYBE: " << priesas.gyvybe << "\nSARVAI: " << priesas.sarvai << "\nPUOLIMAS: " << priesas.puolimas << "\nSKYDAS: " << priesas.skydas << "%\n";
}
void sugeneruotiPriesa(int nr, int &priesoTipas) {
    //1 - zombis, 2 - zmogus
    sansoKauliukas(priesoTipas, 1, 2); //TODO: sunkumo lygis iterpt
    if (priesoTipas == 1) {
        priesas.gyvybe = 50;
        priesas.sarvai = zaidDuom[nr].def;
        priesas.puolimas = zaidDuom[nr].atk + (zaidDuom[nr].sunkumas * 5);
        priesas.skydas = 0;
        priesas.duosXp = priesas.sarvai + priesas.gyvybe;
        priesas.duosAukso = priesas.puolimas * 2;
    }
    else if (priesoTipas == 2) {
        priesas.gyvybe = 100;
        priesas.sarvai = zaidDuom[nr].def;
        priesas.puolimas = zaidDuom[nr].atk + (zaidDuom[nr].sunkumas * 5);
        priesas.skydas = zaidDuom[nr].shield;
        priesas.duosXp = priesas.sarvai + priesas.gyvybe;
        priesas.duosAukso = priesas.puolimas * 5;
    }
}
void kova(int nr) {
    int priesoTipas; 
    bool kovaVyksta = true;
    sugeneruotiPriesa(nr, priesoTipas);
    cout << "\nJUSU PRIESININKAS";
    if (priesoTipas == 1) cout << " ZOMBIS!\n";
    else if (priesoTipas == 2) cout << " ZMOGUS!\n";
    spausdintiZaidejoDuomenis(nr);
    spausdintiPriesoDuomenis();
    while (kovaVyksta == true) {
        int kovosVeiksmai;
        cout << "\n0. BEGTI."
                "\n1. ATAKUOTI."
                "\n2. NAUDOTI SKYDA."
                "\n3. SUTRYGDYTI.\n\n"
                "PASIRINKITE VEIKSMA: ";
        cin >> kovosVeiksmai;
        switch (kovosVeiksmai) {
            case 0: {
                cout << "\nPABEGOTE IS KOVOS!\n";
                kovaVyksta = false;
                break;
            }
            case 1: {
                
                break;
            }
            case 2: {

                break;
            }
            case 3: {

                break;
            }
            default: {
                cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
                break;
            }
        }
    }
}

#endif