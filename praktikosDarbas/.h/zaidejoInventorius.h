#ifndef ZAIDEJOINVENTORIUS_H
#define ZAIDEJOINVENTORIUS_H

#include "salmai.h"

using namespace std;

struct zaidInv {
    string pav = "-";
} zaidInv[10];
void zaidejoInventoriusSpausdinti() {
    cout << "\nINVENTORIUS:";
    for (int i = 0; i < 10; i++) {
        //salmas
        if (i == 0) cout << "\n" << i << ". " << zaidInv[i].pav << " (salmas)";
        //sarvai
        else if (i == 1) cout << "\n" << i << ". " << zaidInv[i].pav << " (sarvai)"; 
        //ginklas
        else if (i == 2) cout << "\n" << i << ". " << zaidInv[i].pav << " (ginklas)";
        //skydas
        else if (i == 3) cout << "\n" << i << ". " << zaidInv[i].pav << " (skydas)";
        //gyvybes potion
        else if (i == 4) cout << "\n" << i << ". " << zaidInv[i].pav << " (gyvybes potion)";
        //daiktai
        else cout << "\n" << i << ". " << zaidInv[i].pav;
    }
}

#endif