#include <iostream>
#include <conio.h>

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\zemelapioObjektuGeneravimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\zaidimoSaugojimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\atnaujintiZaidejoMatomuma.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\atnaujintiZemelapi.h" 
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\zaidejoValdymas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\duotiPradineIranga.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h"
                                                                       //FIXME: aplamai headerius su funkcijomis vadink vienodai

using namespace std;

int main() {
    //zemelapio dydis ir kintamieji jam prisiminti
    char zemelapis[30][120];
    int zemPlotis = 120;
    int zemAukstis = 30;
    //pagrindinio meniu pradzia
    bool procVeikia = true;
    int pagrMeniu = -1;
    cout << "\n0 - ISJUNGTI ZAIDIMA.\n" 
            "1 - PRADETI NAUJA ZAIDIMA.\n"
            "2 - ISSAUGOTI ZAIDIMAI.\n";
    while (procVeikia == true) {
        cout << "\nPASIRINKITE MENU PUNKTA: ";
        cin >> pagrMeniu;
        switch(pagrMeniu) {
            case 0: {
                exit(0);
            }
            case 1: {     
                //kintamieji ir masyvai skirti pagrindiniams pasaulio objektams prisiminti                    
                int xZaid, yZaid;
                int xMiest, yMiest;
                int xKaim, yKaim;
                int dungKord[30], nr = 0;
                //issaugotu zaideju sarasas ir vietos pasirinkimas
                atspausdintiIssaugotus();
                issaugotiDabartini();
                //zaidejo kurimas
                cout << "\nIVESKITE ZAIDEJO VARDA: ";
                cin >> zaidDuom[nr].vardas;
                zaidejasSukurtas = true;
                //generavimo progreso atvaizdavimas
                cout << "\nPASAULIS GENERUOJAMAS...\n"; //TODO: pademonstruoti krovima
                //sudeda objektus, nustato matymo zonas ir vaizduoja zemelapi
                generuotiZemelapi(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord);
                atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                //priskiria pradinius daiktus
                duotiPradineIranga();
                //zaidimo meniu pradzia
                bool zaidVeikia = true;
                int zaidMenu = -1;
                while (zaidVeikia == true) {
                    cout << "\n\n0 - ISEITI IS ZAIDIMO.\n"
                            "1 - JUDETI ZEMELAPYJE.\n"
                            "2 - INVENTORIUS.\n" 
                            "\nPASIRINKITE VEIKSMA: ";             
                    cin >> zaidMenu;
                    switch(zaidMenu) {
                        case 0: {
                            //gris i pagrindini meniu
                            zaidVeikia = false;
                            break;
                        }
                        case 1: {
                            //vaiksciojimo po zemelapi procesas
                            zaidejoValdymas(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr);
                            break;
                        }
                        case 2: {
                            zaidejoInventoriusSpausdinti();
                            break;
                        }
                        default: {
                            cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!";
                        }
                    }
                }
                break;
            }
            case 2: {
                atspausdintiIssaugotus();
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