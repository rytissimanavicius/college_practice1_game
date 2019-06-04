#ifndef ZAIDIMOSAUGOJIMAS_H
#define ZAIDIMOSAUGOJIMAS_H

#include <fstream>

using namespace std;

void atspausdintiIssaugotus() {
    cout << "\nISSAUGOTI ZAIDIMAI: ";
    for (int i = 0; i < sizeof zaidSaug / sizeof zaidSaug[0]; i++) { //FIXME: pradeti sizeof naudoti visur
        cout << "\n" << i + 1 << ". " << zaidSaug[i].saugoti;
    }
    cout << "\n";
}
void sukurtiNauja(int &nr, string zaidSaug[5]) {
    cout << "\nPASIRINKITE SAUGOJIMO VIETA: "; //FIXME: arba pakeisti egzisuojancia
    cin >> nr; //TODO: failo objektu replacint negalima, visa faila teks pakeisti, bet mes masyvesaugom tai gerai
    while (nr < 1 || nr > 5 || zaidSaug[nr] != "-") {
        cout << "KLAIDA! PASIRINKITE KITA SAUGOJIMO VIETA: ";
        cin >> nr;
    }
    cout << "PASIRINKITE SAUGOJIMO PAVADINIMA: ";
    cin >> zaidSaug[nr]; 
    ofstream atnaujintiUzsaugotus(".txt/uzsaugotiZaidimai.txt");
    if (atnaujintiUzsaugotus.is_open()) {

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
void saugojimas() {

}
#endif