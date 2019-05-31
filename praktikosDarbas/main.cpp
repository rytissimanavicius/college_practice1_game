#include <iostream>
#include <conio.h>

#include ".h/rastiObjektoPozicija.h"
#include ".h/atnaujintiZemelapi.h"
#include ".h/atnaujintiZaidejoMatomuma.h"
#include ".h/zemelapioObjektuGeneravimas.h"
#include ".h/zaidejoValdymas.h"
#include ".h/zaidejoDuomenys.h"
#include ".h/zaidejoInventorius.h"
#include ".h/zaidimoSaugojimas.h"

using namespace std;

int main() {
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
                int xZaid, yZaid;
                int xMiest, yMiest;
                int xKaim, yKaim;
                int dungKord[30], nr = 0;
                //zaidejo informacijos deklaravimas
                atspausdintiIssaugotus();
                issaugoti();
                cout << "\nIVESKITE ZAIDEJO VARDA: ";
                cin >> zaidDuom[nr].vardas;
                zaidejasSukurtas = true;
                cout << "\nPASAULIS GENERUOJAMAS...\n";
                //generuoja pasauli: sudeda objektus, nustato matymo zonas ir t.t.
                generuotiZemelapi(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord);
                atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                //duoda pradinius daiktus
                




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

//TODO: pademonstruoti pasaulio krovima