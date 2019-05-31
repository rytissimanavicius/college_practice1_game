#ifndef DUOTIPRADINEIRANGA_H
#define DUOTIPRADINEIRANGA_H

#include <fstream>

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\sansoKauliukas.h" //FIXME: itariu, kad galima optimaliau sita headeri padaryti?
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\daiktai\sarvuStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\daiktai\karduStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\daiktai\skyduStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h"

void duotiPradineIranga() {
    int temp;
    string mas[1000];
    string irangosVardas;
    ifstream irangosPav(".txt/pavadinimaiIrangai.txt");
    if (irangosPav.is_open()) {
        for (int j = 0; j < 1000; j++) {
            irangosPav >> mas[j];
        }
    }
    for (int i = 0; i < 3; i++) {
        sansoKauliukas(temp, 1, 1000);
        if (i == 0) {
            sarvaiLygis_1[0].pav = mas[temp] + " SARVAI";
            sarvaiLygis_1[0].gynyba = 10;
            sarvaiLygis_1[0].kokybe = 100;
            sarvaiLygis_1[0].pliusHp = 0;
            sarvaiLygis_1[0].pliusDmg = 0;
            zaidInv[0].pav = sarvaiLygis_1[0].pav;
        }
        else if (i == 1) {
            kardasLygis_1[0].pav = mas[temp] + " KARDAS";
            kardasLygis_1[0].puolimasMin = 5;
            kardasLygis_1[0].puolimasMax = 15;
            kardasLygis_1[0].kokybe = 100;
            kardasLygis_1[0].pliusDmg = 0;
            zaidInv[1].pav = kardasLygis_1[0].pav;
        }
        else {
            skydasLygis_1[0].pav = mas[temp] + " SKYDAS";
            skydasLygis_1[0].sansas = 0.25;
            skydasLygis_1[0].kokybe = 100;
            zaidInv[2].pav = skydasLygis_1[0].pav;
        }
    }
}

#endif