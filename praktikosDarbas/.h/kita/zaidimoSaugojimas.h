#ifndef ZAIDIMOSAUGOJIMAS_H
#define ZAIDIMOSAUGOJIMAS_H

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
}
void zaidimoSaugojimas() {
    int vieta;
    cout << "\n\nPASIRINKITE SAUGOJIMO VIETA: ";
    cin >> vieta;
    while (vieta < 1 || vieta > 5 || zaidSaug[vieta - 1].laisva == false) {
        cout << "PASIRINKITE SAUGOJIMO VIETA: ";
        cin >> vieta;
    }
    zaidSaug[vieta - 1].laisva == false;
    cout << "PASIRINKITE SAUGOJIMO PAVADINIMA: ";
    cin >> zaidSaug[vieta - 1].saugoti; 
}
#endif