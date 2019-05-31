#ifndef SANSOKAULIUKAS_H
#define SANSOKAULIUKAS_H

#include <random>
#include <ctime>

using namespace std;

int sansoKauliukas(int sk, int nuo, int iki) {
    mt19937 gen;
    gen.seed(time(0));
    uniform_int_distribution<uint32_t> random1(nuo, iki);
    uniform_int_distribution<uint32_t> random2(nuo, iki);
    return sk;
}

#endif