#ifndef ATNAUJINTIZEMELAPI_H
#define ATNAUJINTIZEMELAPI_H

using namespace std;

void atnaujintiZemelapi(char zemelapis[30][120], int zemPlotis, int zemAukstis) {
    cout << "\n";
    for (int i = 0; i < zemAukstis; i++) {
        cout << "\n";
        for (int j = 0; j < zemPlotis; j++) {
            cout << zemelapis[i][j];
        }
    }
    cout << "\n";
}

#endif