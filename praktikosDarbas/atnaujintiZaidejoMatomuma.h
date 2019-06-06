#ifndef ATNAUJINTIZAIDEJOMATOMUMA_H
#define ATNAUJINTIZAIDEJOMATOMUMA_H

void atnaujintiZaidejoMatomuma(char zemelapis[30][120], int &xZaid, int &yZaid, int dungKord[]) {
    int xDung, yDung;
    //zaidejas mato 7x7 plota (jis viduri), pajudejus sie ciklai atnaujina matymo zona jeigu reikia, taip pat atranda dungeonus tame plote jeigu yra
    for (unsigned int i = yZaid - 3; i < yZaid + 4; i++) {
        for (unsigned int j = xZaid - 3; j < xZaid + 4; j++) {
            //zinodami visu 15 dungeonu koordinates, tikriname ar i naujai matoma zona jie ieina, jeigu taip zaidejas dungeona "atranda" //TODO: atradus dungeona pranesti?
            for (int k = 0; k < 30; k += 2) {
                //nekeis jeigu zaidejas stovi ant dungeono bei pacio dungeono nekeis su juo paciu
                if (zemelapis[i][j] != 'Z' && zemelapis[i][j] != 'D' && j == dungKord[k] && i == dungKord[k + 1]) zemelapis[i][j] = 'D';
            }
            //naujai matoma zona tampa ".", isskyrus duotus atvejus
            if (zemelapis[i][j] != '.' && zemelapis[i][j] != '^' && zemelapis[i][j] != 'Z' && zemelapis[i][j] != 'M' && zemelapis[i][j] != 'K' && zemelapis[i][j] != 'D') {
                zemelapis[i][j] = '.';
            }
        }
    }
}

#endif