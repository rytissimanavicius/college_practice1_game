#include <iostream>
#include <fstream>

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\zemelapioObjektuGeneravimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\zaidimoSaugojimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\atnaujintiZaidejoMatomuma.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\atnaujintiZemelapi.h" 
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h" 
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\zaidimoMeniu.h"

using namespace std;

int main() {
    string zaidSaug[5];
    ifstream uzsaugotiZaidimai(".txt/uzsaugotiZaidimai.txt");
    if (uzsaugotiZaidimai.is_open()) {
        for (int j = 0; j < sizeof zaidSaug / sizeof zaidSaug[0]; j++) { 
            uzsaugotiZaidimai >> zaidSaug[j];
        }
    }
    char temp, temp1 = '.';
    char zemelapis[30][120];
    int zemPlotis = 120, zemAukstis = 30, nr, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord[30], kuriMisija = 0;
    bool procVeikia = true;
    int pagrMeniu = -1;
    cout << "\n0 - ISJUNGTI ZAIDIMA.\n" 
            "1 - PRADETI NAUJA ZAIDIMA.\n"
            "2 - PAKRAUTI ISSAUGOTA ZAIDIMA.\n";
    while (procVeikia == true) {
        cout << "\nPASIRINKITE MENU PUNKTA: ";
        cin >> pagrMeniu;
        switch(pagrMeniu) {
            case 0: {
                exit(0);
            }
            case 1: {     
                atspausdintiIssaugotus(zaidSaug);
                sukurtiNauja(nr, zaidSaug);
                cout << "\nPASAULIS GENERUOJAMAS...\n";
                zemelapioObjektuGeneravimas(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord);
                atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                atnaujintiZemelapi(zemelapis, zemPlotis, zemAukstis);
                duotiPradineIranga(nr);
                zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija);
                break;
            }
            case 2: {
                atspausdintiIssaugotus(zaidSaug);
                cout << "\nPASIRINKITE ISSAUGOTA: ";
                cin >> nr;
                if (nr - 1 == 0) {
                    ifstream pirmas(".txt/saugojimoVieta_1.txt");
                    if (pirmas.is_open()) {
                        for (int i = 0; i < 30; i++) {
                            for (int j = 0; j < 120; j++) {
                                pirmas >> zemelapis[i][j];
                            }
                        }
                        pirmas >> zemPlotis;
                        pirmas >> zemAukstis;
                        pirmas >> xZaid;
                        pirmas >> yZaid;
                        pirmas >> xMiest;
                        pirmas >> yMiest;
                        pirmas >> xKaim;
                        pirmas >> yKaim;
                        pirmas >> temp;
                        pirmas >> temp1;
                        pirmas >> kuriMisija;
                        for (int i = 0; i < 30; i++) {
                            pirmas >> dungKord[i];
                        }
                        pirmas >> zaidDuom[nr].vardas;
                        pirmas >> zaidDuom[nr].sunkumas;
                        pirmas >> zaidDuom[nr].hp;
                        pirmas >> zaidDuom[nr].def;
                        pirmas >> zaidDuom[nr].atk;
                        pirmas >> zaidDuom[nr].shield;
                        pirmas >> zaidDuom[nr].xp;
                        pirmas >> zaidDuom[nr].lvl;
                        pirmas >> zaidDuom[nr].gold;
                        pirmas >> zaidDuom[nr].maistas;
                        zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija);
                    }
                }
                
                break;
            }
            default: {
                cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
                break;
            }
        }
    }
    return 0;
}