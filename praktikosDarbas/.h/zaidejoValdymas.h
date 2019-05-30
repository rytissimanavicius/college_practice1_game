#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void valdymoPaaiskinimas() {
    cout << "\nESC - SUSTOTI."
            "\nW - JUDETI I VIRSU."
            "\nS - JUDETI I APACIA."
            "\nA - JUDETI I KAIRE."
            "\nD - JUDETI I DESINE.";
}
void zaidejoValdymas(char zemelapis[30][120], int zemPlotis, int zemAukstis, int &xZaid, int &yZaid, int dungKord[30]) {
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
                    vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";
                    Sleep(100);
                    }
                else cout << "PASIEKETE RIBA!\n";
                valdymoPaaiskinimas();
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
                    vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";                                                 
                    Sleep(100);
                }
                else cout << "\nPASIEKETE RIBA!\n";
                valdymoPaaiskinimas();
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
                    vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";
                    Sleep(100);
                }
                else cout << "\nPASIEKETE RIBA!\n";
                valdymoPaaiskinimas();
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
                    vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                    cout << "\n";
                    Sleep(100);
                }
                else cout << "\nPASIEKETE RIBA!\n";
                valdymoPaaiskinimas();
                break;
            }
        }
    }
}

//TODO: default prideti, tikrinimus