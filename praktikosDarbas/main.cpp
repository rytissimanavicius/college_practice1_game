#include <iostream>
#include <fstream>

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\zemelapioObjektuGeneravimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\kita\zaidimoSaugojimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\atnaujintiZaidejoMatomuma.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\atnaujintiZemelapi.h" 
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\pasaulis\zaidejoValdymas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h" 
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\misijos\misijos.h"

using namespace std;

int main() {
    string zaidSaug[5];
    ifstream uzsaugotiZaidimai(".txt/uzsaugotiZaidimai.txt");
    if (uzsaugotiZaidimai.is_open()) {
        for (int j = 0; j < sizeof zaidSaug / sizeof zaidSaug[0]; j++) { 
            uzsaugotiZaidimai >> zaidSaug[j];
            cout << zaidSaug[j];
        }
    }
    //skirti atsiminti objektams zemelapi vaikstant, deklaruoti cia tam, kad isejus is vaiksciojimo rezimo esant mieste atsimintu, kad ten stovejo miestas
    char temp, temp1 = '.';
    //zemelapio dydis ir kintamieji jam prisiminti
    char zemelapis[30][120];
    int zemPlotis = 120, zemAukstis = 30;
    //pagrindinio meniu pradzia
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
                //kintamieji laikantys koordinates pagrindiniu zemelapio objektu, taip pat zaidejo numeris (pagal uzsaugota zaidima)               
                int xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord[30], nr, kuriMisija = 0;
                //issaugotu zaideju sarasas ir vietos pasirinkimas
                atspausdintiIssaugotus();
                sukurtiNauja(nr, zaidSaug);
                //TODO: patikrins uzsaugotu zaidimu .txt, jeigu 5 pavadinimai = 5 uzimti slotai, kiti .txt failai laikis konkreciu slotu info ar i ja irasis
                
                
                //generavimo progreso atvaizdavimas
                cout << "\nPASAULIS GENERUOJAMAS...\n"; //TODO: pademonstruoti krovima
                //sudeda objektus, nustato matymo zonas ir vaizduoja zemelapi
                zemelapioObjektuGeneravimas(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord);
                atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                atnaujintiZemelapi(zemelapis, zemPlotis, zemAukstis);
                //priskiria pradinius daiktus
                duotiPradineIranga(nr);
                //zaidimo meniu pradzia
                bool zaidVeikia = true;
                int zaidMenu = -1;
                while (zaidVeikia == true) {
                    cout << "\n0 - ISEITI IS ZAIDIMO.\n"
                            "1 - JUDETI ZEMELAPYJE.\n"
                            "2 - INVENTORIUS.\n"
                            "3 - DUOMENYS.\n"
                            "4 - AKTYVIOS MISIJOS\n"
                            "\nPASIRINKITE VEIKSMA: ";             
                    cin >> zaidMenu;
                    switch(zaidMenu) {
                        case 0: {
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