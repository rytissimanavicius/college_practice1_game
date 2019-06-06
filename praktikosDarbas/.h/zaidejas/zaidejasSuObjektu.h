#ifndef ZAIDEJASSUOBJEKTU_H
#define ZAIDEJASSUOBJEKTU_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\daiktai\daiktuStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\priesai\kova.h"

//atspausdina valdymo nustatymus 
void valdymoPaaiskinimas1() { //TODO: tureti viena paaiskinima, kazkuris kitas headeris irgi turi tokia funkcija
    cout << "\nESC - SUSTOTI."
            "\nUP - JUDETI I VIRSU."
            "\nDOWN - JUDETI I APACIA."
            "\nLEFT - JUDETI I KAIRE."
            "\nDESINE - JUDETI I DESINE."
            "\nSPACE - VALDYMAS.\n";
}
//nuolatos tikrina ar zaidejas atsistojo ant zemelapio objekto, kaip miestas ar dungeonas, jeigu taip - atidaro meniu
void zaidejasSuObjektu(char zemelapis[30][120], int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int nr, int dungKord[30], int zaidejoPasiekimai[15]) {
    int rinktis, rinktis1, kiekis;
    bool lankosi = true, lankosi1 = true, sveikinimas = true, sekmingai = false, pralaimejoMisija;
    while (lankosi == true) {
        while (xZaid == xMiest && yZaid == yMiest && lankosi1 == true) {
            if (zaidejoPasiekimai[1] == 0) zaidejoPasiekimai[1] = 1;
            if (sveikinimas == true) {
                cout << "\n\nLANKOTES MIESTE:\n";
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
                                if (zaidejoPasiekimai[11] == 0) zaidejoPasiekimai[11] = 1;
                                cout << "\nSEKMINGAI NUPIRKA!\n";
                                zaidDuom[nr].maistas += kiekis;
                                zaidDuom[nr].gold -= kiekis * 2;
                                sekmingai == true;
                            }
                        }
                        else if (rinktis1 == 2) {
                            cout << "\nIVESKITE KIEKI (JUSU AUKSAS - " << zaidDuom[nr].gold << "): ";
                            cin >> kiekis;
                            if (kiekis * potion.verteMieste > zaidDuom[nr].gold) {
                                cout << "\nNEPAKANKA AUKSO!\n";
                            }
                            else {
                                for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) {
                                    if (zaidInv[i].pav == "GYVYBES_POTION") {
                                        if (zaidejoPasiekimai[11] == 0) zaidejoPasiekimai[11] = 1;
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * potion.verteMieste);
                                        cout << "\nSEKMINGAI NUPIRKA!\n";
                                        break;
                                    }
                                    else if (zaidInv[i].pav == "-" && i != 0 && i != 1 && i != 2) {
                                        if (zaidejoPasiekimai[11] == 0) zaidejoPasiekimai[11] = 1;
                                        zaidInv[i].pav = potion.pav;
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * potion.verteMieste);
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
                    zaidejoInventoriusSpausdinimas(nr);
                    int vietaParduodamo = 0, kiekisPardavimo = 0;
                    while (vietaParduodamo < 1 || vietaParduodamo > 10) {
                        cout << "\nPASIRINKITE VIETA DAIKTO KURI PARDUODATE (0 - ATSAUKTI): ";
                        cin >> vietaParduodamo;
                    }
                    if (zaidInv[vietaParduodamo - 1].tipas == "sarvai" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        for (int i = 0; i < sizeof sarvai / sizeof sarvai[0]; i++) {
                            if (zaidInv[vietaParduodamo - 1].pav == sarvai[i].pav) {
                                zaidDuom[nr].gold += sarvai[i].gynyba * 2;
                                zaidInv[vietaParduodamo - 1].pav = "-";
                                zaidInv[vietaParduodamo - 1].tipas = "-";
                                sarvai[i].pav = "-";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].tipas == "kardas" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
                            if (zaidInv[vietaParduodamo - 1].pav == kardas[i].pav) {
                                zaidDuom[nr].gold += kardas[i].puolimas * 10;
                                zaidInv[vietaParduodamo - 1].pav = "-";
                                zaidInv[vietaParduodamo - 1].tipas = "-";
                                kardas[i].pav = "-";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].tipas == "skydas" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        for (int i = 0; i < sizeof skydas / sizeof skydas[0]; i++) {
                            if (zaidInv[vietaParduodamo - 1].pav == skydas[i].pav) {
                                zaidDuom[nr].gold += skydas[i].sansas * 5;
                                zaidInv[vietaParduodamo - 1].pav = "-";
                                zaidInv[vietaParduodamo - 1].tipas = "-";
                                skydas[i].pav = "-";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].pav == "GYVYBES_POTION" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        while (kiekisPardavimo < 1 || kiekisPardavimo > potion.kiekis) {
                            cout << "\nKOKI KIEKI GYVYBES ELIKSYRU PARDUODATE: ";
                            cin >> kiekisPardavimo;
                        }
                        potion.kiekis -= kiekisPardavimo;
                        zaidDuom[nr].gold += (kiekisPardavimo * (potion.verteMieste / 2));
                        if (potion.kiekis == 0) {
                            zaidInv[vietaParduodamo - 1].pav = "-";
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].pav == "BRANGAKMENIAI" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        zaidDuom[nr].gold += brangakmeniai.verte;
                        zaidInv[vietaParduodamo - 1].pav = "-";
                    }
                    break;
                }
                default: {
                    cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
                    break;
                }
            }
        }
        while (xZaid == xKaim && yZaid == yKaim && lankosi1 == true) {
            if (zaidejoPasiekimai[2] == 0) zaidejoPasiekimai[2] = 1;
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
                                if (zaidejoPasiekimai[11] == 0) zaidejoPasiekimai[11] = 1;
                                zaidDuom[nr].maistas += kiekis;
                                zaidDuom[nr].gold -= kiekis;
                                sekmingai == true;
                            }
                        }
                        else if (rinktis1 == 2) {
                            cout << "\nIVESKITE KIEKI (JUSU AUKSAS - " << zaidDuom[nr].gold << "): ";
                            cin >> kiekis;
                            if (kiekis * potion.verteKaime > zaidDuom[nr].gold) {
                                cout << "\nNEPAKANKA AUKSO!\n";
                            }
                            else {
                                for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) { 
                                    if (zaidInv[i].pav == "GYVYBES_POTION") {
                                        if (zaidejoPasiekimai[11] == 0) zaidejoPasiekimai[11] = 1;
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * potion.verteKaime);
                                        cout << "\nSEKMINGAI NUPIRKA!\n";
                                        break;
                                    }
                                    else if (zaidInv[i].pav == "-" && i != 0 && i != 1 && i != 2) {
                                        if (zaidejoPasiekimai[11] == 0) zaidejoPasiekimai[11] = 1;
                                        zaidInv[i].pav = potion.pav;
                                        potion.kiekis += kiekis;
                                        zaidDuom[nr].gold -= (kiekis * potion.verteKaime);
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
                    zaidejoInventoriusSpausdinimas(nr);
                    int vietaParduodamo = 0, kiekisPardavimo = 0; //FIXME: jeigu deklaruojam pora kartu, gal galima tik viena
                    while (vietaParduodamo < 1 || vietaParduodamo > 10) {
                        cout << "\nPASIRINKITE VIETA DAIKTO KURI PARDUODATE (0 - ATSAUKTI): ";
                        cin >> vietaParduodamo;
                    }
                    if (zaidInv[vietaParduodamo - 1].tipas == "sarvai" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        for (int i = 0; i < sizeof sarvai / sizeof sarvai[0]; i++) {
                            if (zaidInv[vietaParduodamo - 1].pav == sarvai[i].pav) {
                                zaidDuom[nr].gold += sarvai[i].gynyba * 1;
                                zaidInv[vietaParduodamo - 1].pav = "-";
                                zaidInv[vietaParduodamo - 1].tipas = "-";
                                sarvai[i].pav = "-";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].tipas == "kardas" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
                            if (zaidInv[vietaParduodamo - 1].pav == kardas[i].pav) {
                                zaidDuom[nr].gold += kardas[i].puolimas * 5;
                                zaidInv[vietaParduodamo - 1].pav = "-";
                                zaidInv[vietaParduodamo - 1].tipas = "-";
                                kardas[i].pav = "-";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].tipas == "skydas" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        for (int i = 0; i < sizeof skydas / sizeof skydas[0]; i++) {
                            if (zaidInv[vietaParduodamo - 1].pav == skydas[i].pav) {
                                zaidDuom[nr].gold += skydas[i].sansas * 2;
                                zaidInv[vietaParduodamo - 1].pav = "-";
                                zaidInv[vietaParduodamo - 1].tipas = "-";
                                skydas[i].pav = "-";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].pav == "GYVYBES_POTION" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        while (kiekisPardavimo < 1 || kiekisPardavimo > potion.kiekis) {
                            cout << "\nKOKI KIEKI GYVYBES ELIKSYRU PARDUODATE: ";
                            cin >> kiekisPardavimo;
                        }
                        potion.kiekis -= kiekisPardavimo;
                        zaidDuom[nr].gold += (kiekisPardavimo * (potion.verteKaime / 2));
                        if (potion.kiekis == 0) {
                            zaidInv[vietaParduodamo - 1].pav = "-";
                        }
                    }
                    else if (zaidInv[vietaParduodamo - 1].pav == "BRANGAKMENIAI" && vietaParduodamo != 0) {
                        if (zaidejoPasiekimai[12] == 0) zaidejoPasiekimai[12] = 1;
                        zaidDuom[nr].gold += brangakmeniai.verte;
                        zaidInv[vietaParduodamo - 1].pav = "-";
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
                cout << "\n\nIZENGETE I DUNGEONA:\n";
                sveikinimas = false;
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
                        kova(nr, pralaimejoMisija, zaidejoPasiekimai);
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