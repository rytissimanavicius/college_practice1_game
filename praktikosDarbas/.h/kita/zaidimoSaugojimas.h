#ifndef ZAIDIMOSAUGOJIMAS_H
#define ZAIDIMOSAUGOJIMAS_H

#include <fstream>

using namespace std;

void atspausdintiIssaugotus(string zaidSaug[5]) {
    cout << "\nISSAUGOTI ZAIDIMAI: ";
    for (int i = 0; i < 5; i++) { 
        cout << "\n" << i + 1 << ". " << zaidSaug[i]; 
    }
    cout << "\n";
}
void sukurtiNauja(int &nr, string zaidSaug[5]) {
    cout << "\nPASIRINKITE SAUGOJIMO VIETA: "; //FIXME: arba pakeisti egzisuojancia
    cin >> nr; //TODO: failo objektu replacint negalima, visa faila teks pakeisti, bet mes masyvesaugom tai gerai
    while (nr < 1 || nr > 5 || zaidSaug[nr - 1] != "-") {
        cout << "KLAIDA! PASIRINKITE KITA SAUGOJIMO VIETA: ";
        cin >> nr;
    }
    cout << "PASIRINKITE SAUGOJIMO PAVADINIMA: ";
    cin >> zaidSaug[nr - 1]; 

    ofstream sudetiIssaugotus(".txt/uzsaugotiZaidimai.txt");
    if (sudetiIssaugotus.is_open()) {
        for (int i = 0; i < 5; i++) {
            sudetiIssaugotus << zaidSaug[i];
            sudetiIssaugotus << " ";
        }
    }
    cout << "\nIVESKITE ZAIDEJO VARDA: ";
    cin >> zaidDuom[nr].vardas;
    cout << "IVESKITE SUNKUMO LYGI: ";
    cin >> zaidDuom[nr].sunkumas;
    if (zaidDuom[nr].sunkumas < 1 && zaidDuom[nr].sunkumas > 3) {
        cout << "KLAIDA! PER NAUJO IVESKITE SUNKUMO LYGI: ";
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
            for (int i = 0; i < 15; i++) {
                saugoti << zaidejoPasiekimai[i];
                saugoti << " ";
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
        }
    }
}

#endif