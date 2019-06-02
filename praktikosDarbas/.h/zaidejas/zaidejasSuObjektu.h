#ifndef ZAIDEJASSUOBJEKTU_H
#define ZAIDEJASSUOBJEKTU_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\daiktai\daiktuStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\misijos\banditas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\priesai\kova.h"

void valdymoPaaiskinimas1() {
    cout << "\nESC - SUSTOTI."
            "\nUP - JUDETI I VIRSU."
            "\nDOWN - JUDETI I APACIA."
            "\nLEFT - JUDETI I KAIRE."
            "\nDESINE - JUDETI I DESINE."
            "\nSPACE - VALDYMAS.\n";
}
void zaidejasSuObjektu(char zemelapis[30][120], int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int nr, int dungKord[30]) {
    int rinktis, rinktis1, kiekis;
    bool lankosi = true, lankosi1 = true, sveikinimas = true, sekmingai = false;
    while (lankosi == true) {
        while (xZaid == xMiest && yZaid == yMiest && lankosi1 == true) {
            if (sveikinimas == true) {
                cout << "\n\nLANKOTES MIESTE:\n";
                sveikinimas = false;
            }
            cout << "0. ISEITI."
                    "\n1. PIRKTI."
                    "\n2. PARDUOTI."
                    "\n3. MISIJA."
                    "\n\nPASIRINKITE VEIKSMA: ";
            cin >> rinktis;
            switch(rinktis) {
                case 0: {
                    lankosi1 = false;
                    valdymoPaaiskinimas1();
                    break;
                }
                case 1: {
                    while(sekmingai == false) {
                        cout << "\nPARDUOTUVES PREKES:\n"
                                "0. GRIZTI.\n"
                                "1. MAISTAS (2 AUKSO).\n"
                                "2. GYVYBES ELEKSYRAI (150 AUKSO).\n\n"
                                "PASIRINKITE VEIKSMA: ";
                        cin >> rinktis1;
                        if (rinktis1 == 0) sekmingai = true;
                        if (rinktis1 == 1) {
                            cout << "\nIVESKITE KIEKI (JUSU AUKSAS - " << zaidDuom[nr].gold << "): "; //TODO: taisyti sarvus
                            cin >> kiekis;
                            if (kiekis * 2 > zaidDuom[nr].gold) {
                                cout << "\nNEPAKANKA AUKSO!\n";
                            } 
                            else {
                                cout << "\nSEKMINGAI NUPIRKA!\n";
                                zaidDuom[nr].maistas += kiekis;
                                zaidDuom[nr].gold -= kiekis * 2;
                                sekmingai == true;
                            }
                        }
                        else if (rinktis1 == 2) {
                            cout << "\nIVESKITE KIEKI (JUSU AUKSAS - " << zaidDuom[nr].gold << "): ";
                            cin >> kiekis;
                            if (kiekis * 150 > zaidDuom[nr].gold) {
                                cout << "\nNEPAKANKA AUKSO!\n";
                            }
                            else {
                                for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) {
                                    //jeigu jau toks slot egzistuoja
                                    if (zaidInv[i].pav == "GYVYBES POTION") {
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * 150);
                                        cout << "\nSEKMINGAI NUPIRKA!\n";
                                        break;
                                    }
                                    //jeigu potionu nebera parinks laisva slot jiem
                                    else if (zaidInv[i].pav == "-" && i != 0 && i != 1 && i != 2) {
                                        zaidInv[i].pav = potion.pav;
                                        zaidInv[i].tipas = potion.tipas;
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * 150);
                                        cout << "\nSEKMINGAI NUPIRKA!\n";
                                        break;
                                    }
                                    else if (i == 9) cout << "\nINVENTORIUS PILNAS!\n";
                                }
                            }
                        }
                    } 
                    break;
                }
                case 2: {

                    break;
                }
                case 3: {
                    banditas(nr);
                    break;
                }
                default: {
                    cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
                    break;
                }
            }
        }
        while (xZaid == xKaim && yZaid == yKaim && lankosi1 == true) {
            if (sveikinimas == true) {
                cout << "\n\nLANKOTES KAIME:\n";
                sveikinimas = false;
            }
            cout << "0. ISEITI."
                    "\n1. PIRKTI."
                    "\n2. PARDUOTI."
                    "\n\nPASIRINKITE VEIKSMA: ";
            cin >> rinktis;
            switch(rinktis) {
                case 0: {
                    lankosi1 = false;
                    valdymoPaaiskinimas1();
                    break;
                }
                case 1: {
                    while(sekmingai == false) {
                        cout << "\nPARDUOTUVES PREKES:\n"
                                "0. GRIZTI.\n"
                                "1. MAISTAS (1 AUKSO).\n"
                                "2. GYVYBES ELEKSYRAI (100 AUKSO).\n\n"
                                "PASIRINKITE VEIKSMA: ";
                        cin >> rinktis1;
                        if (rinktis1 == 0) sekmingai = true;
                        if (rinktis1 == 1) {
                            cout << "\nIVESKITE KIEKI (JUSU AUKSAS - " << zaidDuom[nr].gold << "): ";  
                            cin >> kiekis;
                            if (kiekis > zaidDuom[nr].gold) {
                                cout << "\nNEPAKANKA AUKSO!\n";
                            } 
                            else {
                                cout << "\nSEKMINGAI NUPIRKA!\n";
                                zaidDuom[nr].maistas += kiekis;
                                zaidDuom[nr].gold -= kiekis;
                                sekmingai == true;
                            }
                        }
                        else if (rinktis1 == 2) {
                            cout << "\nIVESKITE KIEKI (JUSU AUKSAS - " << zaidDuom[nr].gold << "): ";
                            cin >> kiekis;
                            if (kiekis * 100 > zaidDuom[nr].gold) {
                                cout << "\nNEPAKANKA AUKSO!\n";
                            }
                            else {
                                for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) { //TODO:
                                    if (zaidInv[i].pav == "GYVYBES POTION") {
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * 100);
                                        cout << "\nSEKMINGAI NUPIRKA!\n";
                                        break;
                                    }
                                    else if (zaidInv[i].pav == "-" && i != 0 && i != 1 && i != 2) {
                                        zaidInv[i].pav = potion.pav;
                                        zaidInv[i].tipas = potion.tipas;
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * 100);
                                        cout << "\nSEKMINGAI NUPIRKA!\n";
                                        break;
                                    }
                                    else if (i == 9) cout << "\nINVENTORIUS PILNAS!\n";
                                }
                            }
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
        for (int i = 0; i < 30; i += 2) { //TODO: neveike su sizeof?
            if (xZaid == dungKord[i] && yZaid == dungKord[i + 1] && lankosi1 == true) {
                if (sveikinimas == true) {
                    cout << "\n\nIZENGETE I DUNGEONA:\n";
                    sveikinimas = false;
                }
                cout << "0. PABEGTI."
                        "\n1. KOVOTI."
                        "\n\nPASIRINKITE VEIKSMA: ";
                cin >> rinktis;
                switch(rinktis) {
                    case 0: {
                        lankosi1 = false;
                        valdymoPaaiskinimas1();
                        break;
                    }
                    case 1: {
                        kova(nr);
                        break;
                    }
                    default: {
                        cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
                        break;
                    }
                }
            }
        }
        lankosi = false;    
    }
}

#endif