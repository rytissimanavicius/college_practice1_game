#ifndef ZAIDEJUTOPAS_H
#define ZAIDEJUTOPAS_H

#include <fstream>

#include "zaidejoDuomenys.h"

using namespace std;

struct topas {
    string vardas;
    int taskai;
    int auksas;
} topas[1000];

void generuotiHtml(int kiekis) {
    ofstream zaidejuTop("zaidejuTop.html"); 
    if (zaidejuTop.is_open()) {
        zaidejuTop << "<!DOCTYPE html>" << "\n";
        zaidejuTop << "<html>" << "\n";
        zaidejuTop << "<head>" << "\n";
        zaidejuTop << "<style>" << "\n";
        zaidejuTop << "html{" << "\n";
        zaidejuTop << "    background: url('https://image.ibb.co/cH625y/fonas.jpg') no-repeat center center fixed; " << "\n";
        zaidejuTop << "    -webkit-background-size: cover;" << "\n";
        zaidejuTop << "    -moz-background-size: cover;" << "\n";
        zaidejuTop << "    -o-background-size: cover;" << "\n";
        zaidejuTop << "    background-size: cover;" << "\n";
        zaidejuTop << "}" << "\n";
        zaidejuTop << "table {" << "\n";
        zaidejuTop << "    font-family: arial, sans-serif;" << "\n";
        zaidejuTop << "    border-collapse: collapse;" << "\n";
        zaidejuTop << "    width: 100%;" << "\n";
        zaidejuTop << "}" << "\n";
        zaidejuTop << "td, th {" << "\n";
        zaidejuTop << "    border: 1px solid #dddddd;" << "\n";
        zaidejuTop << "    text-align: left;" << "\n";
        zaidejuTop << "    padding: 8px;" << "\n";
        zaidejuTop << "    font-size: 30px;" << "\n";
        zaidejuTop << "    font-weight: bold;" << "\n";
        zaidejuTop << "}" << "\n";
        zaidejuTop << "tr:nth-child(even) {" << "\n";
        zaidejuTop << "    background-color: #dddddd;" << "\n";
        zaidejuTop << "    opacity: 0.6;" << "\n";
        zaidejuTop << "}" << "\n";
        zaidejuTop << "tr:nth-child(odd) {" << "\n";
        zaidejuTop << "    background-color: red;" << "\n";
        zaidejuTop << "    opacity: 0.6;" << "\n";
        zaidejuTop << "}" << "\n";
        zaidejuTop << "</style>" << "\n";
        zaidejuTop << "</head>" << "\n";
        zaidejuTop << "<body>" << "\n";
        zaidejuTop << "<h1 align=\"center\" style=\"color:white\">KOMPANIJA</h2>" << "\n";
        zaidejuTop << "<table style=\"width:600px\" align=\"center\">" << "\n";
        zaidejuTop << "<tr>" << "\n";
        zaidejuTop << "    <th>ZAIDEJAS</th>" << "\n";
        zaidejuTop << "    <th>PATIRTIS</th>" << "\n";
        zaidejuTop << "    <th>AUKSINIAI</th>" << "\n";
        zaidejuTop << "</tr>" << "\n";
        for (int i = 0; i < kiekis; i++) {
            zaidejuTop << "<tr>" << "\n";
            zaidejuTop << "    <td>" << topas[i].vardas << "</td>" << "\n";
            zaidejuTop << "    <td>" << topas[i].taskai << "</td>" << "\n";
            zaidejuTop << "    <td>" << topas[i].auksas << "</td>" << "\n";
            zaidejuTop << "</tr>" << "\n";
        }
        zaidejuTop << "</table>" << "\n";
    }
}
void zaidejuTopas(int nr, int &kiekis) {
    ifstream topPaimt("zaidejuTopasNerusiuotas.txt");
    if (topPaimt.is_open()) {
        topPaimt >> kiekis;
        kiekis++;
        if (kiekis > 1) {
            for (int i = 0; i < kiekis; i++) {
                topPaimt >> topas[i].vardas;
                if (topas[i].vardas == zaidDuom[nr].vardas) {
                    topas[i].taskai = zaidDuom[nr].xp;
                    topas[i].auksas = zaidDuom[nr].gold;
                }
                else {
                    topPaimt >> topas[i].taskai;
                    topPaimt >> topas[i].auksas;
                }
            }
        }
        topas[kiekis - 1].vardas = zaidDuom[nr].vardas;
        topas[kiekis - 1].taskai = zaidDuom[nr].xp;
        topas[kiekis - 1].auksas = zaidDuom[nr].gold;
    }
    topPaimt.close();
    ofstream topSudet("zaidejuTopasNerusiuotas.txt");
    topSudet << kiekis << "\n";
    for (int i = 0; i < kiekis; i++) {
        topSudet << topas[i].vardas << "\n";
        topSudet << topas[i].taskai << "\n";
        topSudet << topas[i].auksas << "\n";
    }
    topSudet.close();
}
void pagalPatirti(int kiekis) {
    string temp;
    int temp1, temp2;
    ifstream topPaimt("zaidejuTopasNerusiuotas.txt");
    if (topPaimt.is_open()) {
        topPaimt >> kiekis;
        for (int i = 0; i < kiekis; i++) {
            topPaimt >> topas[i].vardas;
            topPaimt >> topas[i].taskai;
            topPaimt >> topas[i].auksas;
        }
    }
    topPaimt.close();
    if (kiekis > 1) {
        for (int i = 0; i < kiekis; i++) {
            for (int j = i + 1; j < kiekis; j++) {
                if (topas[i].taskai < topas[j].taskai) {
                    temp = topas[i].vardas;
                    temp1 = topas[i].taskai;
                    temp2 = topas[i].auksas;
                    topas[i].vardas = topas[j].vardas;
                    topas[i].taskai = topas[j].taskai;
                    topas[i].auksas = topas[j].auksas;
                    topas[j].vardas = temp;
                    topas[j].taskai = temp1;
                    topas[j].auksas = temp2;
                }
            }
        }
    }
    ofstream topSudet("zaidejuTopasNerusiuotas.txt");
    topSudet << kiekis << "\n";
    for (int i = 0; i < kiekis; i++) {
        topSudet << topas[i].vardas << "\n";
        topSudet << topas[i].taskai << "\n";
        topSudet << topas[i].auksas << "\n";
    }
    generuotiHtml(kiekis);
    topSudet.close();
}
void pagalPinigus(int kiekis) {
    string temp;
    int temp1, temp2;
    ifstream topPaimt("zaidejuTopasNerusiuotas.txt");
    if (topPaimt.is_open()) {
        topPaimt >> kiekis;
        for (int i = 0; i < kiekis; i++) {
            topPaimt >> topas[i].vardas;
            topPaimt >> topas[i].taskai;
            topPaimt >> topas[i].auksas;
        }
    }
    topPaimt.close();
    if (kiekis > 1) {
        for (int i = 0; i < kiekis; i++) {
            for (int j = i + 1; j < kiekis; j++) {
                if (topas[i].auksas < topas[j].auksas) {
                    temp = topas[i].vardas;
                    temp1 = topas[i].taskai;
                    temp2 = topas[i].auksas;
                    topas[i].vardas = topas[j].vardas;
                    topas[i].taskai = topas[j].taskai;
                    topas[i].auksas = topas[j].auksas;
                    topas[j].vardas = temp;
                    topas[j].taskai = temp1;
                    topas[j].auksas = temp2;
                }
            }
        }
    }
    ofstream topSudet("zaidejuTopasNerusiuotas.txt");
    topSudet << kiekis << "\n";
    for (int i = 0; i < kiekis; i++) {
        topSudet << topas[i].vardas << "\n";
        topSudet << topas[i].taskai << "\n";
        topSudet << topas[i].auksas << "\n";
    }
    generuotiHtml(kiekis);
    topSudet.close();
}

#endif