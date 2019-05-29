#include <iostream>

using namespace std;

const int zemPlotis = 40;
const int zemAukstis = 10;
char mas[zemAukstis][zemPlotis];

struct zaidejas {

};
void generuotiZemelapi() {
    for (int i = 0; i < zemAukstis; i++) {
        for (int j = 0; j < zemPlotis; j++) {
            mas[i][j] = '*';
        }
    }
}
void vaizduotiZemelapi() {
    for (int i = 0; i < zemAukstis; i++) {
        cout << "\n";
        for (int j = 0; j < zemPlotis; j++) {
            cout << mas[i][j];
        }
    }
}
void pozicijosZemelapiRadimas() {

}
int main() {
    bool zemelapisSukurtas = false;
    while (true) {
        if (zemelapisSukurtas == false) {
            generuotiZemelapi();
            zemelapisSukurtas = true;
        }
        vaizduotiZemelapi();
    }
    int x, y;
    //pozicijosZemelapiRadimas(x, y);
    return 0;
}