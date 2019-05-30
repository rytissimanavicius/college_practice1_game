#include <iostream>
#include <conio.h>

#include ".h/rastiObjektoPozicija.h"
#include ".h/atnaujintiZemelapi.h"
#include ".h/atnaujintiZaidejoMatomuma.h"
#include ".h/zemelapioObjektuGeneravimas.h"
#include ".h/zaidejoValdymas.h"

using namespace std;

int main() {
    char zemelapis[30][120];
    int zemPlotis = 120;
    int zemAukstis = 30;
    //pagrindinio meniu pradzia
    bool procVeikia = true;
    int pagrMeniu = -1;
    cout << "\n0 - BAIGTI ZAIDIMA;\n" 
            "1 - PRADETI NAUJA ZAIDIMA;\n";
    while (procVeikia == true) {
        cout << "\nPASIRINKITE MENU PUNKTA: ";
        cin >> pagrMeniu;
        switch(pagrMeniu) {
            case 0: {
                exit(0);
            }
            case 1: {
                cout << "\nPASAULIS GENERUOJAMAS...\n";                          
                int xZaid, yZaid;
                int xPard, yPard;
                int dungKord[30];
                generuotiZemelapi(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xPard, yPard, dungKord);
                zaidejoMatomumas(zemelapis, xZaid, yZaid, dungKord);
                vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                //zaidimo meniu pradzia
                bool zaidVeikia = true;
                int zaidMenu = -1;
                cout << "\n\n0 - ATGAL I MENU;\n"
                        "1 - JUDETI (RODYKLEMIS);\n";
                while (zaidVeikia == true) {
                    cout << "\nPASIRINKITE VEIKSMA: ";               
                    cin >> zaidMenu;
                    switch(zaidMenu) {
                        case 0: {
                            //gris i pagrindini meniu
                            zaidVeikia = false;
                            break;
                        }
                        case 1: {
                            zaidejoValdymas(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, dungKord);
                            break;
                        }
                        default: {
                            cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!";
                        }
                    }
                }
                break;
            }
            default: {
                cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!";
                break;
            }
        }
    }
    return 0;
}

//TODO: pademonstruoti pasaulio krovima
//TODO: komentaru spalva pakeist