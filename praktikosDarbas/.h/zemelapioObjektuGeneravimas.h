#include <iostream>
#include <windows.h>

using namespace std;

void generuotiZemelapi(char zemelapis[30][120], int zemPlotis, int zemAukstis, int &xZaid, int &yZaid, int &xPard, int &yPard, int dungKord[]) {
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
        rastiObjPoz(zemPlotis, zemAukstis, 3, xPard, yPard);
        if (xPard != xZaid && yPard != yZaid) nesutampaKord = true;
    }
    zemelapis[yPard][xPard] = 'M';
    Sleep(1000);
    //sugeneruoja dungeonu pozicijas, tikrina ar nesutampa su Z ir M, jeigu ne jas talpina i masyva
    int x, y;
    for (int i = 0; i < 30; i+=2) {
        rastiObjPoz(zemPlotis, zemAukstis, 3, x, y);
        if (x != xZaid && y != yZaid && x != xPard && y != yPard) {
            dungKord[i] = x;
            dungKord[i + 1] = y;  
        }       
        else i-=2;                                            
        Sleep(1000);   
    }
}