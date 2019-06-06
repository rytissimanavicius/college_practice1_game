#include <iostream>
#include <fstream>
#include <windows.h>

#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\pasaulis\zemelapioObjektuGeneravimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\kita\zaidimoSaugojimas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\pasaulis\atnaujintiZaidejoMatomuma.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\pasaulis\atnaujintiZemelapi.h" 
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h" 
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\kita\zaidimoMeniu.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoPasiekimai.h"

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
    int zemPlotis = 120, zemAukstis = 30, nr, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord[30], kuriMisija = 0, zaidejoPasiekimai[15], kiekis;
    bool procVeikia = true;
    int pagrMeniu = -1;
    while (procVeikia == true) {
        cout << "\n0 - ISJUNGTI ZAIDIMA.\n" 
                "1 - PRADETI NAUJA ZAIDIMA.\n"
                "2 - PAKRAUTI ISSAUGOTA ZAIDIMA.\n"
                "3 - ZAIDEJO TOP.\n"
                "\nPASIRINKITE MENU PUNKTA: ";
        cin >> pagrMeniu;
        switch(pagrMeniu) {
            case 0: {
                exit(0);
            }
            case 1: {     
                zaidejoPasiekimaiNaujas(zaidejoPasiekimai);
                atspausdintiIssaugotus(zaidSaug);
                sukurtiNauja(nr, zaidSaug);
                cout << "\nPASAULIS GENERUOJAMAS...\n";
                zemelapioObjektuGeneravimas(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord);
                atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                atnaujintiZemelapi(zemelapis, zemPlotis, zemAukstis);
                duotiPradineIranga(nr);
                zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija, zaidejoPasiekimai, kiekis);
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
                        for (int i = 0; i < 15; i++) {
                            pirmas >> zaidejoPasiekimai[i];
                        }
                        string invDaiktas;
                        int vieta;
                        for (int i = 0; i < 10; i++) {
                            pirmas >> invDaiktas;
                            if (invDaiktas == "sarvai") {
                                pirmas >> vieta;
                                for (int i = 0; i < sizeof sarvai / sizeof sarvai[0]; i++) {
                                    if (sarvai[i].pav == "-") {
                                        pirmas >> sarvai[i].pav;
                                        pirmas >> sarvai[i].gynyba;
                                        zaidInv[vieta].pav = sarvai[i].pav;
                                        zaidInv[vieta].tipas = sarvai[i].tipas;
                                        break;
                                    }
                                }
                            }
                            else if (invDaiktas == "kardas") {
                                pirmas >> vieta;
                                for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
                                    if (kardas[i].pav == "-") {
                                        pirmas >> kardas[i].pav;
                                        pirmas >> kardas[i].puolimas;
                                        zaidInv[vieta].pav = kardas[i].pav;
                                        zaidInv[vieta].tipas = kardas[i].tipas;
                                        break;
                                    }
                                }
                            }
                            else if (invDaiktas == "skydas") {
                                pirmas >> vieta;
                                for (int i = 0; i < sizeof skydas / sizeof skydas[0]; i++) {
                                    if (skydas[i].pav == "-") {
                                        pirmas >> skydas[i].pav;
                                        pirmas >> skydas[i].sansas;
                                        zaidInv[vieta].pav = skydas[i].pav;
                                        zaidInv[vieta].tipas = skydas[i].tipas;
                                        break;
                                    }
                                }
                            }
                            else if (invDaiktas == "GYVYBES_POTION") {
                                pirmas >> vieta;
                                pirmas >> potion.kiekis;
                                zaidInv[vieta].pav = potion.pav;
                            }
                            else if (invDaiktas == "BRANGAKMENIAI") {
                                pirmas >> vieta;
                                zaidInv[vieta].pav = "BRANGAKMENIAI";
                            }
                            else {
                                pirmas >> vieta;
                                zaidInv[vieta].pav = "-";
                            }
                        }
                        zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija, zaidejoPasiekimai, kiekis);
                    }
                }
                else if (nr - 1 == 1) {
                    ifstream antras(".txt/saugojimoVieta_2.txt");
                    if (antras.is_open()) {
                        for (int i = 0; i < 30; i++) {
                            for (int j = 0; j < 120; j++) {
                                antras >> zemelapis[i][j];
                            }
                        }
                        antras >> zemPlotis;
                        antras >> zemAukstis;
                        antras >> xZaid;
                        antras >> yZaid;
                        antras >> xMiest;
                        antras >> yMiest;
                        antras >> xKaim;
                        antras >> yKaim;
                        antras >> temp;
                        antras >> temp1;
                        antras >> kuriMisija;
                        for (int i = 0; i < 30; i++) {
                            antras >> dungKord[i];
                        }
                        antras >> zaidDuom[nr].vardas;
                        antras >> zaidDuom[nr].sunkumas;
                        antras >> zaidDuom[nr].hp;
                        antras >> zaidDuom[nr].def;
                        antras >> zaidDuom[nr].atk;
                        antras >> zaidDuom[nr].shield;
                        antras >> zaidDuom[nr].xp;
                        antras >> zaidDuom[nr].lvl;
                        antras >> zaidDuom[nr].gold;
                        antras >> zaidDuom[nr].maistas;
                        for (int i = 0; i < 15; i++) {
                            antras >> zaidejoPasiekimai[i];
                        }
                        zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija, zaidejoPasiekimai, kiekis);
                    }
                }
                else if (nr - 1 == 2) {
                    ifstream trecias(".txt/saugojimoVieta_3.txt");
                    if (trecias.is_open()) {
                        for (int i = 0; i < 30; i++) {
                            for (int j = 0; j < 120; j++) {
                                trecias >> zemelapis[i][j];
                            }
                        }
                        trecias >> zemPlotis;
                        trecias >> zemAukstis;
                        trecias >> xZaid;
                        trecias >> yZaid;
                        trecias >> xMiest;
                        trecias >> yMiest;
                        trecias >> xKaim;
                        trecias >> yKaim;
                        trecias >> temp;
                        trecias >> temp1;
                        trecias >> kuriMisija;
                        for (int i = 0; i < 30; i++) {
                            trecias >> dungKord[i];
                        }
                        trecias >> zaidDuom[nr].vardas;
                        trecias >> zaidDuom[nr].sunkumas;
                        trecias >> zaidDuom[nr].hp;
                        trecias >> zaidDuom[nr].def;
                        trecias >> zaidDuom[nr].atk;
                        trecias >> zaidDuom[nr].shield;
                        trecias >> zaidDuom[nr].xp;
                        trecias >> zaidDuom[nr].lvl;
                        trecias >> zaidDuom[nr].gold;
                        trecias >> zaidDuom[nr].maistas;
                        for (int i = 0; i < 15; i++) {
                            trecias >> zaidejoPasiekimai[i];
                        }
                        zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija, zaidejoPasiekimai, kiekis);
                    }
                }
                else if (nr - 1 == 3) {
                    ifstream ketvirtas(".txt/saugojimoVieta_4.txt");
                    if (ketvirtas.is_open()) {
                        for (int i = 0; i < 30; i++) {
                            for (int j = 0; j < 120; j++) {
                                ketvirtas >> zemelapis[i][j];
                            }
                        }
                        ketvirtas >> zemPlotis;
                        ketvirtas >> zemAukstis;
                        ketvirtas >> xZaid;
                        ketvirtas >> yZaid;
                        ketvirtas >> xMiest;
                        ketvirtas >> yMiest;
                        ketvirtas >> xKaim;
                        ketvirtas >> yKaim;
                        ketvirtas >> temp;
                        ketvirtas >> temp1;
                        ketvirtas >> kuriMisija;
                        for (int i = 0; i < 30; i++) {
                            ketvirtas >> dungKord[i];
                        }
                        ketvirtas >> zaidDuom[nr].vardas;
                        ketvirtas >> zaidDuom[nr].sunkumas;
                        ketvirtas >> zaidDuom[nr].hp;
                        ketvirtas >> zaidDuom[nr].def;
                        ketvirtas >> zaidDuom[nr].atk;
                        ketvirtas >> zaidDuom[nr].shield;
                        ketvirtas >> zaidDuom[nr].xp;
                        ketvirtas >> zaidDuom[nr].lvl;
                        ketvirtas >> zaidDuom[nr].gold;
                        ketvirtas >> zaidDuom[nr].maistas;
                        for (int i = 0; i < 15; i++) {
                            ketvirtas >> zaidejoPasiekimai[i];
                        }
                        zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija, zaidejoPasiekimai, kiekis);
                    }
                }
                else if (nr - 1 == 4) {
                    ifstream penktas(".txt/saugojimoVieta_5.txt");
                    if (penktas.is_open()) {
                        for (int i = 0; i < 30; i++) {
                            for (int j = 0; j < 120; j++) {
                                penktas >> zemelapis[i][j];
                            }
                        }
                        penktas >> zemPlotis;
                        penktas >> zemAukstis;
                        penktas >> xZaid;
                        penktas >> yZaid;
                        penktas >> xMiest;
                        penktas >> yMiest;
                        penktas >> xKaim;
                        penktas >> yKaim;
                        penktas >> temp;
                        penktas >> temp1;
                        penktas >> kuriMisija;
                        for (int i = 0; i < 30; i++) {
                            penktas >> dungKord[i];
                        }
                        penktas >> zaidDuom[nr].vardas;
                        penktas >> zaidDuom[nr].sunkumas;
                        penktas >> zaidDuom[nr].hp;
                        penktas >> zaidDuom[nr].def;
                        penktas >> zaidDuom[nr].atk;
                        penktas >> zaidDuom[nr].shield;
                        penktas >> zaidDuom[nr].xp;
                        penktas >> zaidDuom[nr].lvl;
                        penktas >> zaidDuom[nr].gold;
                        penktas >> zaidDuom[nr].maistas;
                        for (int i = 0; i < 15; i++) {
                            penktas >> zaidejoPasiekimai[i];
                        }
                        zaidimoMeniu(zemelapis, zemPlotis, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord, nr, temp, temp1, kuriMisija, zaidejoPasiekimai, kiekis);
                    }
                }
                break;
            }
            case 3: {
                int pagalKa = 0;
                cout << "\n1. RUSIUOTI PAGAL DIDZIAUSIA XP KIEKI."
                        "\n2. RUSIUOTI PAGAL DIDZIAUSIA PINIGU KIEKI.\n"
                        "\nIVESKITE PAGAL KA RUSIUOSITE: ";
                cin >> pagalKa;
                while (pagalKa < 1 || pagalKa > 2) {
                    cout << "\nTOKS PASIRINKIMAS NEEGZISTUOJA!\n\n"
                            "\n1. RUSIUOTI PAGAL DIDZIAUSIA XP KIEKI."
                            "\n2. RUSIUOTI PAGAL DIDZIAUSIA PINIGU KIEKI.\n"
                            "\nIVESKITE PAGAL KA RUSIUOSITE: ";
                    cin >> pagalKa;
                }
                if (pagalKa == 1) pagalPatirti(kiekis);
                else pagalPinigus(kiekis);
                system("C:/Users/rytuciss/Documents/GitHub/praktika_zaidimas/praktikosDarbas/.html/zaidejuTop.html");
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