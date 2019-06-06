#ifndef ZAIDEJOINVENTORIUS_H
#define ZAIDEJOINVENTORIUS_H

#include <fstream>

#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\kita\sansoKauliukas.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\daiktai\daiktuStrukturos.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"

using namespace std;

//inventorius (10 vietu) laiko daikto varda ir tipa, pagal juos vyksta paieskos ir t.t.
struct zaidInv {
    string pav = "-";
    string tipas = "-";
} zaidInv[10];
void zaidejoInventoriusSpausdinimas(int nr) {
    cout << "\nINVENTORIUS:\n";
    for (int i = 0; i < sizeof zaidInv / sizeof zaidInv[0]; i++) {
        cout << i + 1 << ". " << zaidInv[i].pav;
        if (i == 0) cout << " (GYNYBA: " << zaidDuom[nr].def << ")";
        if (i == 1) cout << " (PUOLIMAS: " << zaidDuom[nr].atk << ")";
        if (i == 2) cout << " (BLOKO SANSAS: " << zaidDuom[nr].shield << "%)";
        if (zaidInv[i].pav == "GYVYBES_POTION") cout << " (KIEKIS: " << potion.kiekis << ")";
        if (zaidInv[i].pav == "BRANGAKMENIAI") cout << " (VERTE: " << brangakmeniai.verte << ")";
        cout << "\n";
    }
    cout << "\n";
}
//pagal uzdetus daiktus atnaujinti zaidejo duomenis
void atnaujintiZaidejoDuomenis(int nr, int duomenys, int daiktoVieta) {
    if (daiktoVieta == 0) zaidDuom[nr].def = duomenys;
    else if (daiktoVieta == 1) zaidDuom[nr].atk = duomenys;
    else zaidDuom[nr].shield = duomenys;
}
//meniu pasirinkus inventoriu, si funkcija leidzia turimus daiktus perziureti, sukeisti vietomis
void zaidejoInventoriausFunkcijos(int nr) {
    int pasirinkimas;
    cout << "0. GRIZTI."
            "\n1. SUKEISTI DAIKTUS"
            "\n\nPASIRINKITE VEIKSMA: ";
    cin >> pasirinkimas;
    if (pasirinkimas == 1) {
        int pirmas, antras;
        string temp;
        cout << "\nPASIRINKITE DAIKTA: ";
        cin >> pirmas;
        cout << "PASIRINKITE DAIKTA SU KURIUO SUKEISITE: ";
        cin >> antras;
        if (pirmas == 1 && (zaidInv[antras - 1].tipas == "sarvai" || zaidInv[antras - 1].tipas == "-")) {
            if (zaidInv[antras - 1].tipas == "sarvai") {
                for (int i = 0; i < sizeof sarvai / sizeof sarvai[0]; i++) {
                    if (zaidInv[antras - 1].pav == sarvai[i].pav) {
                        atnaujintiZaidejoDuomenis(nr, sarvai[i].gynyba, 0);
                        break;
                    }
                }
            }
            else atnaujintiZaidejoDuomenis(nr, 0, 0);
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
        else if (pirmas == 2 && (zaidInv[antras - 1].tipas == "kardas" || zaidInv[antras - 1].tipas == "-")) {
            if (zaidInv[antras - 1].tipas == "kardas") {
                for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
                    if (zaidInv[antras - 1].pav == kardas[i].pav) {
                        atnaujintiZaidejoDuomenis(nr, kardas[i].puolimas, 1);
                        break;
                    }
                }
            }
            else atnaujintiZaidejoDuomenis(nr, 10, 1);
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
        else if (pirmas == 3 && (zaidInv[antras - 1].tipas == "skydas" || zaidInv[antras - 1].tipas == "-")) {
            if (zaidInv[antras - 1].tipas == "skydas") {
                for (int i = 0; i < sizeof skydas / sizeof skydas[0]; i++) {
                    if (zaidInv[antras - 1].pav == skydas[i].pav) {
                        atnaujintiZaidejoDuomenis(nr, skydas[i].sansas, 2);
                        break;
                    }
                }
            }
            else atnaujintiZaidejoDuomenis(nr, 0, 2);
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
        else if (antras == 1 && (zaidInv[pirmas - 1].tipas == "sarvai" || zaidInv[pirmas - 1].tipas == "-")) {
            if (zaidInv[pirmas - 1].tipas == "sarvai") {
                for (int i = 0; i < sizeof sarvai / sizeof sarvai[0]; i++) {
                    if (zaidInv[pirmas - 1].pav == sarvai[i].pav) {
                        atnaujintiZaidejoDuomenis(nr, sarvai[i].gynyba, 0);
                        break;
                    }
                }
            }
            else atnaujintiZaidejoDuomenis(nr, 0, 0);
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
        else if (antras == 2 && (zaidInv[pirmas - 1].tipas == "kardas" || zaidInv[pirmas - 1].tipas == "-")) {
            if (zaidInv[pirmas - 1].tipas == "kardas") {
                for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
                    if (zaidInv[pirmas - 1].pav == kardas[i].pav) {
                        atnaujintiZaidejoDuomenis(nr, kardas[i].puolimas, 1);
                        break;
                    }
                }
            }
            else atnaujintiZaidejoDuomenis(nr, 10, 1);
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
        else if (antras == 3 && (zaidInv[pirmas - 1].tipas == "skydas" || zaidInv[pirmas - 1].tipas == "-")) {
            if (zaidInv[pirmas - 1].tipas == "skydas") {
                for (int i = 0; i < sizeof skydas / sizeof skydas[0]; i++) {
                    if (zaidInv[pirmas - 1].pav == skydas[i].pav) {
                        atnaujintiZaidejoDuomenis(nr, skydas[i].sansas, 2);
                        break;
                    }
                }
            }
            else atnaujintiZaidejoDuomenis(nr, 0, 2);
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
        else if (pirmas > 3 && pirmas < 11 && antras > 3 && antras < 11) {
            swap(zaidInv[pirmas - 1].pav, zaidInv[antras - 1].pav);
            swap(zaidInv[pirmas - 1].tipas, zaidInv[antras - 1].tipas);
        }
        else {
            cout << "\nPATIKRINKITE AR NEDEDATE NETINKAMU DAIKTU I SARVU, KARDO IR SKYDO VIETAS!\n";
        }
    }
}
//sarvu duomenis kaip gynyba priskirs zaidejo duomenims, sarvu masyve uzsaugos pilnus sarvu duomenis, inventoriuje ides juos pagal varda
void uzdetiSarvus(int nr, string irangosPav, int duomenys) {
    for (int i = 0; i < sizeof sarvai / sizeof sarvai[0]; i++) { //FIXME: nemanau, kad reikia atskiru funkciju uzdet pradine irangai, vistiek paskui nenaudoju
        if (sarvai[i].pav == "-") {
            sarvai[i].pav = irangosPav + "_SARVAI";
            sarvai[i].gynyba = duomenys;
            zaidInv[0].pav = sarvai[i].pav;
            zaidInv[0].tipas = sarvai[i].tipas;
            atnaujintiZaidejoDuomenis(nr, duomenys, 0);
            break;
        }
    }
}
//kardu duomenis kaip puolima priskirs zaidejo duomenims, kardu masyve uzsaugos pilnus kardo duomenis, inventoriuje ides juos pagal varda
void uzdetiKarda(int nr, string irangosPav, int duomenys) {
    for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
        if (kardas[i].pav == "-") {
            kardas[i].pav = irangosPav + "_KARDAS";
            kardas[i].puolimas = duomenys;
            zaidInv[1].pav = kardas[i].pav;
            zaidInv[1].tipas = kardas[i].tipas;
            atnaujintiZaidejoDuomenis(nr, duomenys, 1);
            break;
        }
    }
}
//skydo duomenis kaip apsigynimo sansa priskirs zaidejo duomenims, skydu masyve uzsaugos pilnus skydo duomenis, inventoriuje ides juos pagal varda
void uzdetiSkyda(int nr, string irangosPav, int duomenys) {
    for (int i = 0; i < sizeof skydas / sizeof skydas[0]; i++) {
        if (skydas[i].pav == "-") {
            skydas[i].pav = irangosPav + "_SKYDAS";
            skydas[i].sansas = duomenys;
            zaidInv[2].pav = skydas[i].pav;
            zaidInv[2].tipas = skydas[i].tipas;
            atnaujintiZaidejoDuomenis(nr, duomenys, 2);
            break;
        }
    }
}
//sukurus nauja veikeja duos pagrindinius daiktus, daiktams suteiks atsitiktini varda
void duotiPradineIranga(int nr) { //TODO: dublikuojancius kintamus ir t.t. gal i viena sujungt
    int pavadinimas;
    string irangosPav;
    string mas[1000];
    ifstream vardai(".txt/pavadinimaiIrangai.txt");
    if (vardai.is_open()) {
        for (int j = 0; j < 1000; j++) { 
            vardai >> mas[j];
        }
    }
    for (int i = 0; i < 3; i++) {
        sansoKauliukas(pavadinimas, 1, 1000);
        irangosPav = mas[pavadinimas];
        if (i == 0) uzdetiSarvus(nr, irangosPav, 100);
        if (i == 1) uzdetiKarda(nr, irangosPav, 20);
        if (i == 2) uzdetiSkyda(nr, irangosPav, 50);
    }
}
void sugeneruotiIranga() {
    
}

#endif