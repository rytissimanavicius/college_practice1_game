#ifndef ZAIDEJOINVENTORIUS_H
#define ZAIDEJOINVENTORIUS_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\daiktai\sarvuStrukturos.h"

using namespace std;

struct zaidInv {
    string pav = "-";
} zaidInv[10];
void zaidejoInventoriusSpausdinti() {
    cout << "\nINVENTORIUS:";
    for (int i = 0; i < 10; i++) {
        //sarvai
        if (i == 0) cout << "\n" << i << ". " << zaidInv[i].pav << " (SARVAI)"; //TODO: kreiptis i sarvai.h, prasyti sarvu stats kai sutampa pavadinimai
        //ginklas
        else if (i == 1) cout << "\n" << i << ". " << zaidInv[i].pav << " (GINKLAS)";
        //skydas
        else if (i == 2) cout << "\n" << i << ". " << zaidInv[i].pav << " (SKYDAS)";
        //gyvybes potion
        else if (i == 3) cout << "\n" << i << ". " << zaidInv[i].pav << " (GYVYBES POTION)";
        //daiktai
        else cout << "\n" << i << ". " << zaidInv[i].pav;
    }
}

#endif