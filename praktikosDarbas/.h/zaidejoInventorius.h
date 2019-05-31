#ifndef ZAIDEJOINVENTORIUS_H
#define ZAIDEJOINVENTORIUS_H

using namespace std;

struct zaidInv {
    string pav;
    int wat;
} zaidInv[10];
void zaidejoIventorius() {
    for (int i = 0; i < 10; i++) {
        cout << zaidInv[i];
    }
}

#endif