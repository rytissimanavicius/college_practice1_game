#ifndef DAIKTUSTRUKTUROS_H
#define DAIKTUSTRUKTUROS_H

struct sarvai {       
    string pav = "-";
    int gynyba = 0;
    const string tipas = "sarvai";
} sarvai[100];
struct kardas {       
    string pav = "-";
    int puolimas = 0;
    const string tipas = "kardas";
} kardas[100];
struct skydas {       
    string pav = "-";
    int sansas = 0;
    const string tipas = "skydas";
} skydas[100];
struct potion {       
    string pav = "GYVYBES_POTION";
    int verteMieste = 150;
    int verteKaime = 100;
    int kiekis = 0;
    int hp = 25;
} potion;
struct brangakmeniai {       
    string pav = "BRANGAKMENIAI";
    int verte = 250;
} brangakmeniai;

#endif