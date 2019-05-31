#ifndef SANSOKAULIUKAS_H
#define SANSOKAULIUKAS_H

#include <random>
#include <ctime>

using namespace std;

int sansoKauliukas(int &sk, int nuo, int iki) { //FIXME: pakeisti jeigu pavyks atsitiktiniu skaiciu generavima, kad nepriklausytu nuo laiko
    mt19937 gen;
    gen.seed(time(0));
    uniform_int_distribution<uint32_t> random(nuo, iki);
    sk = random(gen);
    Sleep(1000);
    return sk;
}

#endif