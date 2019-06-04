#ifndef ZAIDIMOSAUGOJIMAS_H
#define ZAIDIMOSAUGOJIMAS_H

#include <fstream>

using namespace std;

struct zaidSaug {
    bool laisva = true;
    string saugoti = "-";
} zaidSaug[5];
void atspausdintiIssaugotus() {
    cout << "\nISSAUGOTI ZAIDIMAI: ";
    for (int i = 0; i < sizeof zaidSaug / sizeof zaidSaug[0]; i++) { //FIXME: pradeti sizeof naudoti visur
        cout << "\n" << i + 1 << ". " << zaidSaug[i].saugoti;
    }
    cout << "\n";
}
void zaidimoSaugojimas(int &nr) {
    cout << "\nPASIRINKITE SAUGOJIMO VIETA: ";
    cin >> nr;
    while (nr < 1 || nr > 5 || zaidSaug[nr - 1].laisva == false) {
        cout << "PASIRINKITE SAUGOJIMO VIETA: ";
        cin >> nr;
    }
    zaidSaug[nr - 1].laisva == false;
    cout << "PASIRINKITE SAUGOJIMO PAVADINIMA: ";
    cin >> zaidSaug[nr - 1].saugoti; 
}
#endif