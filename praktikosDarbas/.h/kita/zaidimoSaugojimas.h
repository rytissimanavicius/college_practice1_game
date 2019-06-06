#ifndef ZAIDIMOSAUGOJIMAS_H
#define ZAIDIMOSAUGOJIMAS_H

#include <fstream>

#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\daiktai\daiktuStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h"

using namespace std;

void atspausdintiIssaugotus(string zaidSaug[5]) {
    cout << "\nISSAUGOTI ZAIDIMAI: ";
    for (int i = 0; i < 5; i++) { 
        cout << "\n" << i + 1 << ". " << zaidSaug[i]; 
    }
    cout << "\n";
}
void sukurtiNauja(int &nr, string zaidSaug[5]) {
    int pakeistiUzsaugota = 2;
    while (pakeistiUzsaugota == 2) {
        cout << "\nPASIRINKITE SAUGOJIMO VIETA: "; //FIXME: arba pakeisti egzisuojancia
        cin >> nr; 
        while (nr < 1 || nr > 5) {
            cout << "NETEISINGAI NURODETE VIETA, PAKARTOKITE: ";
            cin >> nr;
        }
        if (zaidSaug[nr - 1] != "-") {
            cout << "AR TIKRAI NORITE PAKEISTI SI UZSAUGOTA ZAIDIMA (1 - TAIP, 2 - NE): ";
            cin >> pakeistiUzsaugota;
            while (pakeistiUzsaugota < 1 || pakeistiUzsaugota > 2) {
                cout << "NETEISINGAI PASIRINKOTE, PAKARTOKITE: ";
                cin >> pakeistiUzsaugota;
            }
        }
        else break;
        if (pakeistiUzsaugota == 1) {
            pakeistiUzsaugota = 2;
            break;
        }
    }
    cout << "PASIRINKITE SAUGOJIMO PAVADINIMA: ";
    cin >> zaidSaug[nr - 1]; 
    ofstream sudetiIssaugotus(".txt/uzsaugotiZaidimai.txt"); //FIXME: 5 nesaugo?
    if (sudetiIssaugotus.is_open()) {
        for (int i = 0; i < 5; i++) {
            sudetiIssaugotus << zaidSaug[i];
            sudetiIssaugotus << " ";
        }
    }
    cout << "\nIVESKITE ZAIDEJO VARDA: ";
    cin >> zaidDuom[nr].vardas;
    cout << "IVESKITE SUNKUMO LYGI (1/2/3): ";
    cin >> zaidDuom[nr].sunkumas;
    if (zaidDuom[nr].sunkumas < 1 && zaidDuom[nr].sunkumas > 3) {
        cout << "KLAIDA! IVEDETE NETEISINGA SUNKUMO LYGI, PAKARTOKITE: ";
        cin >> zaidDuom[nr].sunkumas;
    }
}
void saugojimas(int nr, char zemelapis[30][120], int zemPlotis, int zemAukstis, int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int dungKord[30], int kuriMisija, char temp, char temp1, int zaidejoPasiekimai[15]) {
    if (nr == 1) {
        ofstream saugoti(".txt/saugojimoVieta_1.txt");
        if (saugoti.is_open()) {
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 120; j++) {
                    saugoti << zemelapis[i][j];
                }
            }
            saugoti << " ";
            saugoti << zemPlotis;
            saugoti << " ";
            saugoti << zemAukstis;
            saugoti << " ";
            saugoti << xZaid;
            saugoti << " ";
            saugoti << yZaid;
            saugoti << " ";
            saugoti << xMiest;
            saugoti << " ";
            saugoti << yMiest;
            saugoti << " ";
            saugoti << xKaim;
            saugoti << " ";
            saugoti << yKaim;
            saugoti << " ";
            saugoti << temp;
            saugoti << " ";
            saugoti << temp1;
            saugoti << " "; //TODO: nesaugo inventoriaus
            saugoti << kuriMisija;
            saugoti << " ";
            for (int i = 0; i < 30; i++) {
                saugoti << dungKord[i];
                saugoti << " ";
            }
            saugoti << zaidDuom[nr].vardas;
            saugoti << " ";
            saugoti << zaidDuom[nr].sunkumas;
            saugoti << " ";
            saugoti << zaidDuom[nr].hp;
            saugoti << " ";
            saugoti << zaidDuom[nr].def;
            saugoti << " ";
            saugoti << zaidDuom[nr].atk;
            saugoti << " ";
            saugoti << zaidDuom[nr].shield;
            saugoti << " ";
            saugoti << zaidDuom[nr].xp;
            saugoti << " ";
            saugoti << zaidDuom[nr].lvl;
            saugoti << " ";
            saugoti << zaidDuom[nr].gold;
            saugoti << " ";
            saugoti << zaidDuom[nr].maistas;
            saugoti << " ";
            for (int i = 0; i < 15; i++) {
                saugoti << zaidejoPasiekimai[i];
                saugoti << " ";
            }
            for (int i = 0; i < 10; i++) {
                if (zaidInv[i].pav != "-") {
                    if (zaidInv[i].tipas == "sarvai") {
                        for (int j = 0; j < sizeof sarvai / sizeof sarvai[0]; j++) {
                            if (zaidInv[i].pav == sarvai[j].pav) {
                                saugoti << sarvai[j].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << sarvai[j].pav;
                                saugoti << " ";
                                saugoti << sarvai[j].gynyba;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "kardas") {
                        for (int j = 0; j < sizeof kardas / sizeof kardas[0]; j++) {
                            if (zaidInv[i].pav == kardas[j].pav) {
                                saugoti << kardas[j].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << kardas[j].pav;
                                saugoti << " ";
                                saugoti << kardas[j].puolimas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "skydas") {
                        for (int j = 0; j < sizeof skydas / sizeof skydas[0]; j++) {
                            if (zaidInv[i].pav == skydas[j].pav) {
                                saugoti << skydas[j].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << skydas[j].pav;
                                saugoti << " ";
                                saugoti << skydas[j].sansas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].pav == "GYVYBES_POTION") {
                        saugoti << "GYVYBES_POTION";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                        saugoti << potion.kiekis;
                        saugoti << " ";
                    }
                    else if (zaidInv[i].pav == "BRANGAKMENIAI") {
                        saugoti << "BRANGAKMENIAI";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                    }
                }
                else {
                    saugoti << "-";
                    saugoti << " ";
                    saugoti << i;
                    saugoti << " ";
                }
            }
        }
    }
    else if (nr == 2) {
        ofstream saugoti(".txt/saugojimoVieta_2.txt");
        if (saugoti.is_open()) {
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 120; j++) {
                    saugoti << zemelapis[i][j];
                }
            }
            saugoti << " ";
            saugoti << zemPlotis;
            saugoti << " ";
            saugoti << zemAukstis;
            saugoti << " ";
            saugoti << xZaid;
            saugoti << " ";
            saugoti << yZaid;
            saugoti << " ";
            saugoti << xMiest;
            saugoti << " ";
            saugoti << yMiest;
            saugoti << " ";
            saugoti << xKaim;
            saugoti << " ";
            saugoti << yKaim;
            saugoti << " ";
            saugoti << temp;
            saugoti << " ";
            saugoti << temp1;
            saugoti << " "; //TODO: nesaugo inventoriaus
            saugoti << kuriMisija;
            saugoti << " ";
            for (int i = 0; i < 30; i++) {
                saugoti << dungKord[i];
                saugoti << " ";
            }
            saugoti << zaidDuom[nr].vardas;
            saugoti << " ";
            saugoti << zaidDuom[nr].sunkumas;
            saugoti << " ";
            saugoti << zaidDuom[nr].hp;
            saugoti << " ";
            saugoti << zaidDuom[nr].def;
            saugoti << " ";
            saugoti << zaidDuom[nr].atk;
            saugoti << " ";
            saugoti << zaidDuom[nr].shield;
            saugoti << " ";
            saugoti << zaidDuom[nr].xp;
            saugoti << " ";
            saugoti << zaidDuom[nr].lvl;
            saugoti << " ";
            saugoti << zaidDuom[nr].gold;
            saugoti << " ";
            saugoti << zaidDuom[nr].maistas;
            for (int i = 0; i < 15; i++) {
                saugoti << zaidejoPasiekimai[i];
                saugoti << " ";
            }
            for (int i = 0; i < 10; i++) {
                if (zaidInv[i].pav != "-") {
                    if (zaidInv[i].tipas == "sarvai") {
                        for (int j = 0; j < sizeof sarvai / sizeof sarvai[0]; j++) {
                            if (zaidInv[i].pav == sarvai[j].pav) {
                                saugoti << sarvai[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << sarvai[i].pav;
                                saugoti << " ";
                                saugoti << sarvai[i].gynyba;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "kardas") {
                        for (int j = 0; j < sizeof kardas / sizeof kardas[0]; j++) {
                            if (zaidInv[i].pav == kardas[j].pav) {
                                saugoti << kardas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << kardas[i].pav;
                                saugoti << " ";
                                saugoti << kardas[i].puolimas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "skydas") {
                        for (int j = 0; j < sizeof skydas / sizeof skydas[0]; j++) {
                            if (zaidInv[i].pav == skydas[j].pav) {
                                saugoti << skydas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << skydas[i].pav;
                                saugoti << " ";
                                saugoti << skydas[i].sansas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].pav == "GYVYBES_POTION") {
                        saugoti << "GYVYBES_POTION";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                        saugoti << potion.kiekis;
                        saugoti << " ";
                    }
                    else if (zaidInv[i].pav == "BRANGAKMENIAI") {
                        saugoti << "BRANGAKMENIAI";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                    }
                }
                else {
                    saugoti << "-";
                    saugoti << " ";
                    saugoti << i;
                    saugoti << " ";
                }
            }
        }
    }
    else if (nr == 3) {
        ofstream saugoti(".txt/saugojimoVieta_3.txt");
        if (saugoti.is_open()) {
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 120; j++) {
                    saugoti << zemelapis[i][j];
                }
            }
            saugoti << " ";
            saugoti << zemPlotis;
            saugoti << " ";
            saugoti << zemAukstis;
            saugoti << " ";
            saugoti << xZaid;
            saugoti << " ";
            saugoti << yZaid;
            saugoti << " ";
            saugoti << xMiest;
            saugoti << " ";
            saugoti << yMiest;
            saugoti << " ";
            saugoti << xKaim;
            saugoti << " ";
            saugoti << yKaim;
            saugoti << " ";
            saugoti << temp;
            saugoti << " ";
            saugoti << temp1;
            saugoti << " "; //TODO: nesaugo inventoriaus
            saugoti << kuriMisija;
            saugoti << " ";
            for (int i = 0; i < 30; i++) {
                saugoti << dungKord[i];
                saugoti << " ";
            }
            saugoti << zaidDuom[nr].vardas;
            saugoti << " ";
            saugoti << zaidDuom[nr].sunkumas;
            saugoti << " ";
            saugoti << zaidDuom[nr].hp;
            saugoti << " ";
            saugoti << zaidDuom[nr].def;
            saugoti << " ";
            saugoti << zaidDuom[nr].atk;
            saugoti << " ";
            saugoti << zaidDuom[nr].shield;
            saugoti << " ";
            saugoti << zaidDuom[nr].xp;
            saugoti << " ";
            saugoti << zaidDuom[nr].lvl;
            saugoti << " ";
            saugoti << zaidDuom[nr].gold;
            saugoti << " ";
            saugoti << zaidDuom[nr].maistas;
            for (int i = 0; i < 15; i++) {
                saugoti << zaidejoPasiekimai[i];
                saugoti << " ";
            }
            for (int i = 0; i < 10; i++) {
                if (zaidInv[i].pav != "-") {
                    if (zaidInv[i].tipas == "sarvai") {
                        for (int j = 0; j < sizeof sarvai / sizeof sarvai[0]; j++) {
                            if (zaidInv[i].pav == sarvai[j].pav) {
                                saugoti << sarvai[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << sarvai[i].pav;
                                saugoti << " ";
                                saugoti << sarvai[i].gynyba;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "kardas") {
                        for (int j = 0; j < sizeof kardas / sizeof kardas[0]; j++) {
                            if (zaidInv[i].pav == kardas[j].pav) {
                                saugoti << kardas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << kardas[i].pav;
                                saugoti << " ";
                                saugoti << kardas[i].puolimas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "skydas") {
                        for (int j = 0; j < sizeof skydas / sizeof skydas[0]; j++) {
                            if (zaidInv[i].pav == skydas[j].pav) {
                                saugoti << skydas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << skydas[i].pav;
                                saugoti << " ";
                                saugoti << skydas[i].sansas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].pav == "GYVYBES_POTION") {
                        saugoti << "GYVYBES_POTION";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                        saugoti << potion.kiekis;
                        saugoti << " ";
                    }
                    else if (zaidInv[i].pav == "BRANGAKMENIAI") {
                        saugoti << "BRANGAKMENIAI";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                    }
                }
                else {
                    saugoti << "-";
                    saugoti << " ";
                    saugoti << i;
                    saugoti << " ";
                }
            }
        }
    }
    else if (nr == 4) {
        ofstream saugoti(".txt/saugojimoVieta_4.txt");
        if (saugoti.is_open()) {
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 120; j++) {
                    saugoti << zemelapis[i][j];
                }
            }
            saugoti << " ";
            saugoti << zemPlotis;
            saugoti << " ";
            saugoti << zemAukstis;
            saugoti << " ";
            saugoti << xZaid;
            saugoti << " ";
            saugoti << yZaid;
            saugoti << " ";
            saugoti << xMiest;
            saugoti << " ";
            saugoti << yMiest;
            saugoti << " ";
            saugoti << xKaim;
            saugoti << " ";
            saugoti << yKaim;
            saugoti << " ";
            saugoti << temp;
            saugoti << " ";
            saugoti << temp1;
            saugoti << " "; //TODO: nesaugo inventoriaus
            saugoti << kuriMisija;
            saugoti << " ";
            for (int i = 0; i < 30; i++) {
                saugoti << dungKord[i];
                saugoti << " ";
            }
            saugoti << zaidDuom[nr].vardas;
            saugoti << " ";
            saugoti << zaidDuom[nr].sunkumas;
            saugoti << " ";
            saugoti << zaidDuom[nr].hp;
            saugoti << " ";
            saugoti << zaidDuom[nr].def;
            saugoti << " ";
            saugoti << zaidDuom[nr].atk;
            saugoti << " ";
            saugoti << zaidDuom[nr].shield;
            saugoti << " ";
            saugoti << zaidDuom[nr].xp;
            saugoti << " ";
            saugoti << zaidDuom[nr].lvl;
            saugoti << " ";
            saugoti << zaidDuom[nr].gold;
            saugoti << " ";
            saugoti << zaidDuom[nr].maistas;
            for (int i = 0; i < 15; i++) {
                saugoti << zaidejoPasiekimai[i];
                saugoti << " ";
            }
            for (int i = 0; i < 10; i++) {
                if (zaidInv[i].pav != "-") {
                    if (zaidInv[i].tipas == "sarvai") {
                        for (int j = 0; j < sizeof sarvai / sizeof sarvai[0]; j++) {
                            if (zaidInv[i].pav == sarvai[j].pav) {
                                saugoti << sarvai[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << sarvai[i].pav;
                                saugoti << " ";
                                saugoti << sarvai[i].gynyba;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "kardas") {
                        for (int j = 0; j < sizeof kardas / sizeof kardas[0]; j++) {
                            if (zaidInv[i].pav == kardas[j].pav) {
                                saugoti << kardas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << kardas[i].pav;
                                saugoti << " ";
                                saugoti << kardas[i].puolimas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "skydas") {
                        for (int j = 0; j < sizeof skydas / sizeof skydas[0]; j++) {
                            if (zaidInv[i].pav == skydas[j].pav) {
                                saugoti << skydas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << skydas[i].pav;
                                saugoti << " ";
                                saugoti << skydas[i].sansas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].pav == "GYVYBES_POTION") {
                        saugoti << "GYVYBES_POTION";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                        saugoti << potion.kiekis;
                        saugoti << " ";
                    }
                    else if (zaidInv[i].pav == "BRANGAKMENIAI") {
                        saugoti << "BRANGAKMENIAI";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                    }
                }
                else {
                    saugoti << "-";
                    saugoti << " ";
                    saugoti << i;
                    saugoti << " ";
                }
            }
        }
    }
    else if (nr == 5) { 
        ofstream saugoti(".txt/saugojimoVieta_5.txt");
        if (saugoti.is_open()) {
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 120; j++) {
                    saugoti << zemelapis[i][j];
                }
            }
            saugoti << " ";
            saugoti << zemPlotis;
            saugoti << " ";
            saugoti << zemAukstis;
            saugoti << " ";
            saugoti << xZaid;
            saugoti << " ";
            saugoti << yZaid;
            saugoti << " ";
            saugoti << xMiest;
            saugoti << " ";
            saugoti << yMiest;
            saugoti << " ";
            saugoti << xKaim;
            saugoti << " ";
            saugoti << yKaim;
            saugoti << " ";
            saugoti << temp;
            saugoti << " ";
            saugoti << temp1;
            saugoti << " "; //TODO: nesaugo inventoriaus
            saugoti << kuriMisija;
            saugoti << " ";
            for (int i = 0; i < 30; i++) {
                saugoti << dungKord[i];
                saugoti << " ";
            }
            saugoti << zaidDuom[nr].vardas;
            saugoti << " ";
            saugoti << zaidDuom[nr].sunkumas;
            saugoti << " ";
            saugoti << zaidDuom[nr].hp;
            saugoti << " ";
            saugoti << zaidDuom[nr].def;
            saugoti << " ";
            saugoti << zaidDuom[nr].atk;
            saugoti << " ";
            saugoti << zaidDuom[nr].shield;
            saugoti << " ";
            saugoti << zaidDuom[nr].xp;
            saugoti << " ";
            saugoti << zaidDuom[nr].lvl;
            saugoti << " ";
            saugoti << zaidDuom[nr].gold;
            saugoti << " ";
            saugoti << zaidDuom[nr].maistas;
            for (int i = 0; i < 15; i++) {
                saugoti << zaidejoPasiekimai[i];
                saugoti << " ";
            }
            for (int i = 0; i < 10; i++) {
                if (zaidInv[i].pav != "-") {
                    if (zaidInv[i].tipas == "sarvai") {
                        for (int j = 0; j < sizeof sarvai / sizeof sarvai[0]; j++) {
                            if (zaidInv[i].pav == sarvai[j].pav) {
                                saugoti << sarvai[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << sarvai[i].pav;
                                saugoti << " ";
                                saugoti << sarvai[i].gynyba;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "kardas") {
                        for (int j = 0; j < sizeof kardas / sizeof kardas[0]; j++) {
                            if (zaidInv[i].pav == kardas[j].pav) {
                                saugoti << kardas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << kardas[i].pav;
                                saugoti << " ";
                                saugoti << kardas[i].puolimas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].tipas == "skydas") {
                        for (int j = 0; j < sizeof skydas / sizeof skydas[0]; j++) {
                            if (zaidInv[i].pav == skydas[j].pav) {
                                saugoti << skydas[i].tipas;
                                saugoti << " ";
                                saugoti << i;
                                saugoti << " ";
                                saugoti << skydas[i].pav;
                                saugoti << " ";
                                saugoti << skydas[i].sansas;
                                saugoti << " ";
                                break;
                            }
                        }
                    }
                    else if (zaidInv[i].pav == "GYVYBES_POTION") {
                        saugoti << "GYVYBES_POTION";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                        saugoti << potion.kiekis;
                        saugoti << " ";
                    }
                    else if (zaidInv[i].pav == "BRANGAKMENIAI") {
                        saugoti << "BRANGAKMENIAI";
                        saugoti << " ";
                        saugoti << i;
                        saugoti << " ";
                    }
                }
                else {
                    saugoti << "-";
                    saugoti << " ";
                    saugoti << i;
                    saugoti << " ";
                }
            }
        }
    }
}

#endif