#ifndef ZAIDIMOMENIU_H
#define ZAIDIMOMENIU_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\misijos\misijos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\kita\zaidimoSaugojimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\pasaulis\zaidejoValdymas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoPasiekimai.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\kita\zaidejuTopas.h"


using namespace std;

void zaidimoMeniu(char zemelapis[30][120], int zemPlotis, int zemAukstis, int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int dungKord[30], int nr, char &temp, char &temp1, int kuriMisija, int zaidejoPasiekimai[15], int &kiekis) {
    bool zaidVeikia = true;
    int zaidMenu = -1;
    while (zaidVeikia == true) {
        if (zaidDuom[nr].gold >= 1000) {
            if (zaidejoPasiekimai[4] == 0) zaidejoPasiekimai[4] = 1;
        }
        if (zaidDuom[nr].gold >= 5000) {
            if (zaidejoPasiekimai[5] == 0) zaidejoPasiekimai[5] = 1;    
        }
        if (zaidDuom[nr].gold >= 10000) {
            if (zaidejoPasiekimai[6] == 0) zaidejoPasiekimai[6] = 1;
        }
        if (zaidDuom[nr].lvl == 1) {
            if (zaidejoPasiekimai[7] == 0) zaidejoPasiekimai[7] = 1;
        }
        if (zaidDuom[nr].lvl == 2) {
            if (zaidejoPasiekimai[8] == 0) zaidejoPasiekimai[8] = 1;    
        }
        if (zaidDuom[nr].lvl == 3) {
            if (zaidejoPasiekimai[9] == 0) zaidejoPasiekimai[9] = 1;
        }
        if (zaidDuom[nr].hp > 100) {
            if (zaidejoPasiekimai[10] == 0) zaidejoPasiekimai[10] = 1;
        }
        cout << "\n0 - ISEITI IS ZAIDIMO (UZSAUGOTI).\n"
                "1 - JUDETI ZEMELAPYJE.\n"
                "2 - INVENTORIUS.\n"
                "3 - DUOMENYS.\n"
                "4 - AKTYVIOS MISIJOS.\n"
                "5 - PASIEKIMAI.\n"
                "\nPASIRINKITE VEIKSMA: ";             
        cin >> zaidMenu;
        switch(zaidMenu) {
            case 0: {
                zaidejuTopas(nr, kiekis);
                saugojimas(nr, zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, kuriMisija, temp, temp1, zaidejoPasiekimai); 
                cout << "\n0 - ISJUNGTI ZAIDIMA.\n" 
                        "1 - PRADETI NAUJA ZAIDIMA.\n"
                        "2 - ISSAUGOTI ZAIDIMAI.\n"
                        "3 - ZAIDEJO TOP.\n";
                zaidVeikia = false;
                break;
            }
            case 1: {
                //vaiksciojimo po zemelapi procesas
                zaidejoValdymas(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija, zaidejoPasiekimai);
                break;
            }
            case 2: {
                zaidejoInventoriusSpausdinimas(nr);
                zaidejoInventoriausFunkcijos(nr);
                break;
            }
            case 3: {
                cout << "\n";
                zaidejoDuomenuSpausdinimas(nr);
                cout << "\n";
                break;
            }
            case 4: {
                atspausdintiMisijosTiksla(kuriMisija);
                break;
            }
            case 5: {
                pasiekimaiSpausdinti(zaidejoPasiekimai);
                break;
            }
            default: {
                cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!";
                break;
            }
        }
    }
}

#endif