#ifndef BANDITAS_H
#define BANDITAS_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\priesai\kova.h"

using namespace std;

void banditas(int nr) {
    int priimtiMisija = 0;
    while (priimtiMisija < 1 || priimtiMisija > 2) {
        cout << "\nGATVEJE PLESIAMAS ZMOGUS, PADETI: \n"
                "1. TAIP\n"
                "2. NE\n"
                "\nPASIRINKITE VEIKSMA: ";
        cin >> priimtiMisija;
    }
    if (priimtiMisija == 1) {
        kova(nr);
    }
}

#endif