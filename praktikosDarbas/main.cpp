#include <iostream>
#include <conio.h>

#include ".h/rastiObjektoPozicija.h"
#include ".h/atnaujintiZemelapi.h"
#include ".h/atnaujintiZaidejoMatomuma.h"
#include ".h/zemelapioObjektuGeneravimas.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main() {
    char zemelapis[30][120];
    int zemPlotis = 120;
    int zemAukstis = 30;

    bool procVeikia = true;
    int pagrMenu = -1;
    cout << "\n0 - BAIGTI ZAIDIMA;\n" 
            "1 - PRADETI NAUJA ZAIDIMA;\n";
    while (procVeikia == true) {
        cout << "\nPASIRINKITE MENU PUNKTA: ";
        cin >> pagrMenu;
        switch(pagrMenu) {
            case 0: {
                exit(0);
            }
            case 1: {
                cout << "\nPASAULIS GENERUOJAMAS...\n";                          //TODO: krovima pademonstruoti
                int xZaid, yZaid;
                int xPard, yPard;
                int dungKord[30];
                generuotiZemelapi(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xPard, yPard, dungKord);
                //nustatome zaidejo matomumo toli kuris yra 3, nezinoma zona zymima "*", o matoma "."
                zaidejoMatomumas(zemelapis, xZaid, yZaid, dungKord);
                while (true) {
                    vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    break;
                }
                bool zaidVeikia = true;
                int zaidMenu = -1;
                cout << "\n\n0 - ATGAL I MENU;\n"
                        "1 - JUDETI (RODYKLEMIS);\n";
                while (zaidVeikia == true) {
                    cout << "\nPASIRINKITE VEIKSMA: ";                  //TODO: sugeneruotus dungeonus matymo zonoje vaizduoti
                    cin >> zaidMenu;
                    switch(zaidMenu) {
                        case 0: {
                            zaidVeikia = false;
                            break;
                        }
                        case 1: {
                            bool zaidVaiksto = true, pirmEjimas = true;
                            char temp, temp1 = '.';
                            int bind;
                            while(zaidVaiksto == true) {
                                switch((bind = getch())) {
                                    case VK_ESCAPE: {
                                        zaidVaiksto = false;
                                        break;
                                    }
                                    case KEY_UP: {





                                        if (yZaid > 3) {
                                            temp = zemelapis[yZaid - 1][xZaid];                               //TODO: skaicius sutapatint su matmenimis
                                            zemelapis[yZaid - 1][xZaid] = zemelapis[yZaid][xZaid];            //TODO: uzejus pakeisti icona
                                            zemelapis[yZaid][xZaid] = temp1;                                  //TODO: prideti komentaru, pakeisti spalva i neutralesne
                                            temp1 = temp;                                                     
                                            yZaid = yZaid - 1;                                               
                                            if (yZaid > 2) zaidejoMatomumas(zemelapis, xZaid, yZaid, dungKord);
                                            vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                                            cout << "\n";
                                            Sleep(50);
                                        }
                                        else cout << "PASIEKETE RIBA!\n";
                                        break;





                                    }
                                    case KEY_DOWN: {
                                        if (yZaid < 26) {
                                            temp = zemelapis[yZaid + 1][xZaid];
                                            zemelapis[yZaid + 1][xZaid] = zemelapis[yZaid][xZaid]; 
                                            zemelapis[yZaid][xZaid] = temp1;
                                            temp1 = temp;
                                            yZaid = yZaid + 1;
                                            if (yZaid < 27) zaidejoMatomumas(zemelapis, xZaid, yZaid, dungKord);              //FIXME: crash TIK i apacia is virsaus
                                            vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                                            cout << "\n";                                                  //FIXME: pakilus i virsu pilnai, griztant atgal crash
                                            Sleep(50);
                                        }
                                        else cout << "\nPASIEKETE RIBA!\n";
                                        break;
                                    }
                                    case KEY_LEFT: {
                                        if (xZaid > 3) {
                                            temp = zemelapis[yZaid][xZaid - 1];
                                            zemelapis[yZaid][xZaid - 1] = zemelapis[yZaid][xZaid];
                                            zemelapis[yZaid][xZaid] = temp1;
                                            temp1 = temp;
                                            xZaid = xZaid - 1;
                                            if (xZaid > 2) zaidejoMatomumas(zemelapis, xZaid, yZaid, dungKord);
                                            vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                                            cout << "\n";
                                            Sleep(50);
                                        }
                                        else cout << "\nPASIEKETE RIBA!\n";
                                        break;
                                    }
                                    case KEY_RIGHT: {
                                        if (xZaid < 116) {
                                            temp = zemelapis[yZaid][xZaid + 1];
                                            zemelapis[yZaid][xZaid + 1] = zemelapis[yZaid][xZaid]; 
                                            zemelapis[yZaid][xZaid] = temp1;
                                            temp1 = temp;
                                            xZaid = xZaid + 1;
                                            if (xZaid < 116) zaidejoMatomumas(zemelapis, xZaid, yZaid, dungKord);
                                            vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                                            cout << "\n";
                                            Sleep(50);
                                        }
                                        else cout << "\nPASIEKETE RIBA!\n";
                                        break;
                                    }
                                    default: {
                                        
                                    }
                                }
                            }
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