#ifndef SALMAI_H
#define SALMAI_H

#include <fstream>

#include "sansoKauliukas.h"

using namespace std;

struct salmas_1 {       //FIXME: per ilgai uztruks kiekvienam, apsistokim ties paprastesniu varijantu
    string pav;
    int gynyba;
    int pliusXp = 0;
    int pliusHp = 0;
    int pliusDmg = 0;
} salmas_1[100];
void salmoSukurimas() {
    
    int sk;
    sansoKauliukas(sk, 1, 1000);

}
#endif