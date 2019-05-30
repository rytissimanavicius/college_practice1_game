#include <iostream>

using namespace std;

void vaizduotiZemelapi(char zemelapis[30][120], int zemPlotis, int zemAukstis) {
    for (int i = 0; i < zemAukstis; i++) {
        cout << "\n";
        for (int j = 0; j < zemPlotis; j++) {
            cout << zemelapis[i][j];
        }
    }
}