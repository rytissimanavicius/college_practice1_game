#ifndef ZAIDEJOVALDYMAS_H
#define ZAIDEJOVALDYMAS_H

#include <conio.h>

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejasSuObjektu.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\misijos\misijos.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void valdymoPaaiskinimas() {
    cout << "\nESC - SUSTOTI."
            "\nUP - JUDETI I VIRSU."
            "\nDOWN - JUDETI I APACIA."
            "\nLEFT - JUDETI I KAIRE."
            "\nDESINE - JUDETI I DESINE." //FIXME: zemPlotis ir zemAukstis gal nereikalingi, galim naudot sizeof
            "\nSPACE - VALDYMAS.\n";
}
void zaidejoValdymas(char zemelapis[30][120], int zemPlotis, int zemAukstis, int &xZaid, int &yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int dungKord[30], int nr, char &temp, char &temp1, int kuriMisija) {
    bool zaidVaiksto = true, pirmEjimas = true, naujinti = false;
    int bind;
    valdymoPaaiskinimas();
    while(zaidVaiksto == true) {
        switch((bind = getch())) {
            case VK_ESCAPE: {
                zaidVaiksto = false;
                break;
            }
            case KEY_UP: {
                if (yZaid > 3) {
                    //temp atsimena vietos i kuria einame objekta
                    temp = zemelapis[yZaid - 1][xZaid];      
                    //tuomet ta objekta pakeicia zaideju                        
                    zemelapis[yZaid - 1][xZaid] = zemelapis[yZaid][xZaid];
                    //pirma karta pajudejus po zaidejo atsiras ".", temp1 toliau saugos kas buvo vietoje zaidejo, o temp saugos tos vietos objekta kur eis            
                    zemelapis[yZaid][xZaid] = temp1; 
                    //dabar zaidejas ten kur buvo temp, tai temp1 ateis irgi                                
                    temp1 = temp;      
                    //keitesi pozicija zaidejo, tai reikia ir jo koordinate pakeisti                                               
                    yZaid = yZaid - 1;    
                    //iskviecia funkcija kuri po judejimo atnaujina matymo zona, neskaitant kalnu siaurese (nes cia juda i virsu)                                           
                    if (yZaid > 2) atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                    atnaujintiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";
                    //gaus 5 xp uz viena ejima, praras maisto...
                    naujinti = true;
                    Sleep(100);
                    }
                else cout << "\n\nPASIEKETE RIBA!";
                break;
            }
            case KEY_DOWN: {
                if (yZaid < 26) {
                    temp = zemelapis[yZaid + 1][xZaid];
                    zemelapis[yZaid + 1][xZaid] = zemelapis[yZaid][xZaid]; 
                    zemelapis[yZaid][xZaid] = temp1;
                    temp1 = temp;
                    yZaid = yZaid + 1;
                    if (yZaid < 27) atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);              
                    atnaujintiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";   
                    naujinti = true;                                              
                    Sleep(100);
                }
                else cout << "\n\nPASIEKETE RIBA!";
                break;
            }
            case KEY_LEFT: {
                if (xZaid > 3) {
                    temp = zemelapis[yZaid][xZaid - 1];
                    zemelapis[yZaid][xZaid - 1] = zemelapis[yZaid][xZaid];
                    zemelapis[yZaid][xZaid] = temp1;
                    temp1 = temp;
                    xZaid = xZaid - 1;
                    if (xZaid > 2) atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                    atnaujintiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";
                    naujinti = true;
                    Sleep(100);
                }
                else cout << "\n\nPASIEKETE RIBA!";
                break;
            }
            case KEY_RIGHT: {
                if (xZaid < 116) {
                    temp = zemelapis[yZaid][xZaid + 1];
                    zemelapis[yZaid][xZaid + 1] = zemelapis[yZaid][xZaid]; 
                    zemelapis[yZaid][xZaid] = temp1;
                    temp1 = temp;
                    xZaid = xZaid + 1;
                    if (xZaid < 116) atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                    atnaujintiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";
                    naujinti = true;
                    Sleep(100);
                }
                else cout << "\n\nPASIEKETE RIBA!";
                break;
            }
            case VK_SPACE: {
                valdymoPaaiskinimas();
            }
        }
        if (naujinti == true) {
            zaidejoDuomenys(nr, naujinti);
            zaidejoDuomenuSpausdinimas(nr);
            pasikeleLygi(nr);
            misija(kuriMisija, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, nr, dungKord);
            zaidejasSuObjektu(zemelapis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, nr, dungKord);
            naujinti = false;
        }
    }
}

#endif

//TODO: default prideti, tikrinimus