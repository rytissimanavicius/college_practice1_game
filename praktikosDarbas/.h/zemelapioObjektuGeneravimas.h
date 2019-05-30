#ifndef ZEMELAPIOOBJEKTUGENERAVIMAS_H
#define ZEMELAPIOOBJEKTUGENERAVIMAS_H

#include <windows.h>

using namespace std;

void generuotiZemelapi(char zemelapis[30][120], int zemPlotis, int zemAukstis, int &xZaid, int &yZaid, int &xMiest, int &yMiest, int dungKord[]) {
    //uzpildo zemelapi
    for (int i = 0; i < zemAukstis; i++) {
        for (int j = 0; j < zemPlotis; j++) {
            if (i < 3 || i > zemAukstis - 4 || j < 3 || j > zemPlotis - 4) zemelapis[i][j] = '^';
            else zemelapis[i][j] = '*';                                                             
        }
    }
    //iskviecia funkcija kuri pasirenka atsitiktine zaidejo pozicija
    rastiObjPoz(zemPlotis, zemAukstis, 3, xZaid, yZaid);
    zemelapis[yZaid][xZaid] = 'Z';
    Sleep(1000);
    //iskviecia funkcija kuri pasirenka atsitiktine miesto pozicija
    bool nesutampaKord = false;
    while (nesutampaKord == false) {
        rastiObjPoz(zemPlotis, zemAukstis, 3, xMiest, yMiest);
        if (xMiest != xZaid && yMiest != yZaid) nesutampaKord = true;                      //TODO: kaima sukurt ekonomikai simuliuot
    } 
    zemelapis[yMiest][xMiest] = 'M';
    Sleep(1000);
    //iskviecia funkcija kuri pasirenka atsitiktine kaimo pozicija
    
    //sugeneruoja dungeonu pozicijas, tikrina ar nesutampa su Z ir M, jeigu ne jas talpina i masyva
    int x, y;
    for (int i = 0; i < 30; i+=2) {
        rastiObjPoz(zemPlotis, zemAukstis, 3, x, y);
        if (x != xZaid && y != yZaid && x != xMiest && y != yMiest) {
            dungKord[i] = x;
            dungKord[i + 1] = y;  
        }       
        else i-=2;                                            
        Sleep(1000);   
    }
}

#endif