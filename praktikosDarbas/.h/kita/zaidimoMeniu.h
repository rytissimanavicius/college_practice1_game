#ifndef ZAIDIMOMENIU_H
#define ZAIDIMOMENIU_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\misijos\misijos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\zaidimoSaugojimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\zaidejoValdymas.h"


using namespace std;

void zaidimoMeniu(char zemelapis[30][120], int zemPlotis, int zemAukstis, int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int dungKord[30], int nr, char &temp, char &temp1, int kuriMisija) {
    bool zaidVeikia = true;
    int zaidMenu = -1;
    while (zaidVeikia == true) {
        cout << "\n0 - ISEITI IS ZAIDIMO (UZSAUGOTI).\n"
                "1 - JUDETI ZEMELAPYJE.\n"
                "2 - INVENTORIUS.\n"
                "3 - DUOMENYS.\n"
                "4 - AKTYVIOS MISIJOS\n"
                "\nPASIRINKITE VEIKSMA: ";             
        cin >> zaidMenu;
        switch(zaidMenu) {
            case 0: {
                saugojimas(nr, zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, kuriMisija, temp, temp1); 
                cout << "\n0 - ISJUNGTI ZAIDIMA.\n" 
                        "1 - PRADETI NAUJA ZAIDIMA.\n"
                        "2 - ISSAUGOTI ZAIDIMAI.\n";
                zaidVeikia = false;
                break;
            }
            case 1: {
                //vaiksciojimo po zemelapi procesas
                zaidejoValdymas(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija);
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
            default: {
                cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!";
                break;
            }
        }
    }
}

#endif