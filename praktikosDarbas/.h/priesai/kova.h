#ifndef KOVA_H
#define KOVA_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\kita\sansoKauliukas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\daiktai\daiktuStrukturos.h"

using namespace std;

struct priesas {
    int gyvybe = 0;
    int sarvai = 0;
    int puolimas = 0;
    int skydas = 0;
    int duosXp = 0;
    int duosAukso = 0;
} priesas;
void valdymoPaaiskinimas2() {
    cout << "\nESC - SUSTOTI."
            "\nUP - JUDETI I VIRSU."
            "\nDOWN - JUDETI I APACIA."
            "\nLEFT - JUDETI I KAIRE."
            "\nDESINE - JUDETI I DESINE." 
            "\nSPACE - VALDYMAS.\n";
}
void spausdintiZaidejoDuomenis(int nr) {
    cout << "\nJUSU DUOMENYS:\nGYVYBE: " << zaidDuom[nr].hp << "\nSARVAI: " << zaidDuom[nr].def << "\nPUOLIMAS: " << zaidDuom[nr].atk << "\nSKYDAS: " << zaidDuom[nr].shield << "%\n";
}
void spausdintiPriesoDuomenis() {
    cout << "\nPRIESO DUOMENYS:\nGYVYBE: " << priesas.gyvybe << "\nSARVAI: " << priesas.sarvai << "\nPUOLIMAS: " << priesas.puolimas << "\nSKYDAS: " << priesas.skydas << "%\n";
}
void sugeneruotiPriesa(int nr, int &priesoTipas) {
    sansoKauliukas(priesoTipas, 1, 1);
    if (priesoTipas == 1) {
        priesas.gyvybe = 50;
        priesas.sarvai = zaidDuom[nr].def;
        priesas.puolimas = zaidDuom[nr].atk + (zaidDuom[nr].sunkumas * 5);
        priesas.skydas = 0;
        priesas.duosXp = priesas.sarvai + priesas.gyvybe;
        priesas.duosAukso = priesas.puolimas * 2;
    }
    else if (priesoTipas == 2) {
        //TODO: 2 yra zmogus, bet nebutina ji sukurt, patobulink kova su zombiais 
    }
}
void zombisPuola(int nr, bool &kovaVyksta, int pataikymoSansas, bool &skydasPakeltas, bool &pralaimejoMisija) {
    if (skydasPakeltas == false) {
        cout << "\nZOMBIS JUMS IKANDO!\n";
        zaidDuom[nr].hp = zaidDuom[nr].hp - (priesas.puolimas - (zaidDuom[nr].def * 0.1));
    }
    else {
        sansoKauliukas(pataikymoSansas, 1, 100);
        if (pataikymoSansas >= zaidDuom[nr].shield) {
            cout << "\nZOMBIS NEPRASIBROVE PRO JUSU SKYDA!\n";
        }
        else {
            cout << "\nZOMBIS JUMS IKANDO!\n";
            zaidDuom[nr].hp = zaidDuom[nr].hp - (priesas.puolimas - (zaidDuom[nr].def * 0.1));
        }
    }
    if (zaidDuom[nr].hp <= 0) {
        cout << "\nPRALAIMEJOME, BET NEPAZYSTAMASIS UZ 200 AUKSO JUMS ISGELBEJO GYVYBE!\n";
        pralaimejoMisija = true;
        zaidDuom[nr].hp == 20;
        zaidDuom[nr].gold -= 200;
        kovaVyksta = false;
    }
}
void lobis(int nr) {
    int lobis;
    sansoKauliukas(lobis, 1, 100);
    if (lobis > 0 && lobis < 21) {
        cout << "\nRADOTE LOBI - BRANGAKMENIUS!";
        for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) {
            if (zaidInv[i].pav == "-") {
                zaidInv[i].pav = brangakmeniai.pav;
                break;
            }
            else if (i == sizeof zaidInv / sizeof zaidInv[0]) {
                int lobisMeniu;
                cout << "\nINVENTORIUS PILNAS:\n";
                        "1. IDETI VIETOJE KITO DAIKTO.\n"
                        "2. GAUTI PUSE LOBIO VERTES IR ATSISAKYTI.";
                        "\nPASIRINKITE VEIKSMA: \n";
                cin >> lobisMeniu;
                switch(lobisMeniu) {
                    case 1: {
                        int lobiuiVieta;
                        zaidejoInventoriusSpausdinimas(nr);
                        cout << "\nVIETOJE KURIO DAIKTO NORITE PADETI: ";
                        cin >> lobiuiVieta;
                        zaidInv[lobiuiVieta].pav = brangakmeniai.pav;
                        break;
                    }
                    case 2: {
                        zaidDuom[nr].gold =+ (brangakmeniai.verte / 2);
                        break;
                    }
                    default: {
                        cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
                        break;
                    }
                }
                break;
            }
        }
    }
}
void kova(int nr, bool &pralaimejoMisija, int zaidejoPasiekimai[15]) {
    int priesoTipas, pataikymoSansas;
    bool kovaVyksta = true, skydasPakeltas = false;
    sugeneruotiPriesa(nr, priesoTipas);
    cout << "\nJUSU PRIESININKAS";
    if (priesoTipas == 1) cout << " ZOMBIS!\n";
    else if (priesoTipas == 2) cout << " ZMOGUS!\n";
    spausdintiZaidejoDuomenis(nr);
    spausdintiPriesoDuomenis();
    while (kovaVyksta == true) {
        int kovosVeiksmai;
        cout << "\n0. BEGTI."
                "\n1. ATAKUOTI."
                "\n2. PAKELTI SKYDA."
                "\n3. SUTRYGDYTI."
                "\n4. GYVYBES ELIKSYRAS.\n\n"
                "PASIRINKITE VEIKSMA: ";
        cin >> kovosVeiksmai;
        switch (kovosVeiksmai) {
            case 0: {
                cout << "\nPABEGOTE IS KOVOS!\n";
                valdymoPaaiskinimas2();
                pralaimejoMisija = true;
                kovaVyksta = false;
                break;
            }
            case 1: {
                if (priesoTipas == 1) {
                    zombisPuola(nr, kovaVyksta, pataikymoSansas, skydasPakeltas, pralaimejoMisija);
                    if (kovaVyksta == true) {
                        cout << "JUS PATAIKETE I ZOMBI SU KARDU!\n";
                        priesas.gyvybe = priesas.gyvybe - zaidDuom[nr].atk;
                        if (skydasPakeltas == true) { 
                            priesas.gyvybe += zaidDuom[nr].atk / 2;
                            skydasPakeltas = false;
                        }
                        if (priesas.gyvybe <= 0) {
                            if (zaidejoPasiekimai[3] == 0) zaidejoPasiekimai[3] = 1;
                            cout << "ZOMBIS IVEIKTAS!\n";
                            zaidDuom[nr].xp += priesas.duosXp;
                            zaidDuom[nr].gold += priesas.duosAukso;
                            pasikeleLygi(nr);
                            lobis(nr);
                            kovaVyksta = false;
                            valdymoPaaiskinimas2();
                        }
                        if (kovaVyksta == true) {
                            spausdintiZaidejoDuomenis(nr);
                            spausdintiPriesoDuomenis();
                        }
                    }
                }
                break;
            }
            case 2: {
                skydasPakeltas = true;
                break;
            }
            case 3: {
                if (priesoTipas == 1) cout << "\nZOMBIO INIRSIS NESUVALDOMAS, JUSU MEGINIMAI SUTRYGDYTI NESEKMINGI!\n"; //TODO: dadeti mechanika, ar daugiau net
                break;
            }
            case 4: {
                if (potion.kiekis > 0) {
                    zaidDuom[nr].hp += potion.hp;
                    if (zaidDuom[nr].hp > (100 + lygis.pliusGyvybe)) zaidDuom[nr].hp = 100 + lygis.pliusGyvybe;
                    potion.kiekis -= 1;
                    if (potion.kiekis == 0) {
                        for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) {
                            if (zaidInv[nr].pav == "GYVYBES_POTION") zaidInv[nr].pav = "-";
                        }
                    }
                    cout << "\nSEKMINGAI PANAUDOJOTE GYVYBES ELEKSYRA (+25 GYVYBES).\n";
                }
                else {
                    cout << "\nNETURITE GYVYBES ELIKSYRU!\n";
                }
                break;
            }
            default: {
                cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
                break;
            }
        }
    }
}

#endif