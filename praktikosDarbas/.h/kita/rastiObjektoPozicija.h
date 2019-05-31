#ifndef RASTIOBJEKTOPOZICIJA_H
#define RASTIOBJEKTOPOZICIJA_H

#include <random>
#include <ctime>

using namespace std;

int rastiObjPoz(int zemPlotis, int zemAukstis, int nuoKrasto, int &x, int &y) { //FIXME: pakeisti jeigu pavyks atsitiktiniu skaiciu generavima, kad nepriklausytu nuo laiko
    mt19937 gen;
    gen.seed(time(0));
    uniform_int_distribution<uint32_t> random1(nuoKrasto, (zemPlotis - nuoKrasto) - 1);
    uniform_int_distribution<uint32_t> random2(nuoKrasto, (zemAukstis - nuoKrasto) - 1);
    return x = random1(gen), y = random2(gen);
}

#endif

