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
void saugojimas(int nr, char zemelapis[30][120], int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int dungKord[30]) {
    if (nr == 1) {
        ofstream saugoti(".txt/saugojimoVieta_1.txt");
        if (saugoti.is_open()) {
            for (int i = 0; i < 30; i++) {
                for (int j = 0; j < 120; j++) {
                    saugoti << zemelapis[i][j];
                }
            }
            saugoti << " ";
        }
    }
}

#endif