#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;

const int zemPlotis = 120;
const int zemAukstis = 30;
char zemelapis[zemAukstis][zemPlotis];

struct zaidejas { //TODO: pildyt content

};
void vaizduotiZemelapi() {
    for (int i = 0; i < zemAukstis; i++) {
        cout << "\n";
        for (int j = 0; j < zemPlotis; j++) {
            cout << zemelapis[i][j];
        }
    }
}
void zemelapioAtsitiktinePozicija(int nuoKrasto, int &x, int &y) {
    mt19937 gen;
    gen.seed(time(0));
    uniform_int_distribution<uint32_t> random1(nuoKrasto, zemPlotis - nuoKrasto);
    uniform_int_distribution<uint32_t> random2(nuoKrasto, zemAukstis - nuoKrasto);
    x = random1(gen);
    y = random2(gen);
}
void zaidejoMatomumas(int &x, int &y) {
    for (int i = y - 3; i < y + 4; i++) {
        for (int j = x - 3; j < x + 4; j++) {
            if (zemelapis[i][j] != 'Z' && zemelapis[i][j] != 'P') {
                zemelapis[i][j] = '.';
            }
        }
    }
}
void generuotiZemelapi(int &xZaid, int &yZaid, int &xPard, int &yPard, int xDung, int yDung) {
    //zemelapis uzpildomas zvaigzdutemis
    for (int i = 0; i < zemAukstis; i++) {
        for (int j = 0; j < zemPlotis; j++) {
            zemelapis[i][j] = '*';
        }
    }
    //zaideja pastatome i atsitiktine pozicija, per tris vietas nuo zemelapio ribu
    zemelapioAtsitiktinePozicija(4, xZaid, yZaid);
    zemelapis[yZaid][xZaid] = 'Z';
    Sleep(1000);
    //parduotuve pastatome i atsitiktine pozicija, kurioje nera zaidejo
    bool nesutampaKord = false;
    while (nesutampaKord == false) {
        zemelapioAtsitiktinePozicija(1, xPard, yPard);
        if (xPard != xZaid && yPard != yZaid) nesutampaKord = true;
    }
    zemelapis[yPard][xPard] = 'P';
    Sleep(1000);
    //nustatome pozicija 5 pirmojo/antrojo/treciojo lygio dungeonu (jie bus atrasti tik tuo atveju, kai bus zaidejo matomumo zonoje)
    ofstream dungeonKord("dungeonuKoordinates.txt");
    if (dungeonKord.is_open()) {
        for (int i = 0; i < 15; i++) {
            zemelapioAtsitiktinePozicija(1, xDung, yDung);
            dungeonKord << xDung << " " << yDung << " " << endl;
            Sleep(1000);
        }
    }
    else cout << "Nepavyko atidaryti failo!";
    dungeonKord.close();
}
int main() {
    bool procVeikia = true;
    int pagrMenu = -1;
    cout << "\n0 - BAIGTI ZAIDIMA;\n" 
            "1 - PRADETI NAUJA ZAIDIMA;";
    while (procVeikia == true) {
        cout << "\n\nPASIRINKITE MENU PUNKTA: ";
        cin >> pagrMenu;
        switch(pagrMenu) {
            case 0: {
                exit(0);
            }
            case 1: {
                cout << "\nPASAULIS GENERUOJAMAS...\n"; //TODO: krovima pademonstruoti
                int xZaid, yZaid;
                int xPard, yPard;
                int xDung, yDung;
                generuotiZemelapi(xZaid, yZaid, xPard, yPard, xDung, yDung);
                //nustatome zaidejo matomumo toli kuris yra 3, nezinoma zona zymima "*", o matoma "."
                zaidejoMatomumas(xZaid, yZaid);
                while (true) {
                    vaizduotiZemelapi();
                    break;
                }
                bool zaidVeikia = true;
                int zaidMenu = -1;
                cout << "\n\n0 - ATGAL I MENU;\n"
                        "1 - JUDETI;";
                while (zaidVeikia == true) {
                    cout << "\n\nPASIRINKITE VEIKSMA: ";
                    cin >> zaidMenu;
                    switch(zaidMenu) {
                        case 0: {
                            zaidVeikia = false;
                            break;
                        }
                        case 1: {
                            int kryptis, temp;
                            cout << "1  2  3\n" //TODO: kalnai "^", vanduo "~" ir t.t.
                                    " * * * \n" //TODO: parodyti supancia terrain tiksliai, ar vanduo, ar kalnas...
                                    "4* Z *5\n"
                                    " * * * \n"
                                    "6(-1,-1)  7  8\n\n"
                                    "PASIRINKITE NORIMA KRYPTI (SKAICIUMI): ";
                            cin >> kryptis;
                            if (kryptis == 1) {
                                temp = zemelapis[yZaid][xZaid];
                                zemelapis[yZaid][xZaid] = zemelapis[yZaid + 1][xZaid + 1];
                                zemelapis[yZaid + 1][xZaid - 1] = temp;
                            }
                            /*if (kryptis == 2)
                            if (kryptis == 3)
                            if (kryptis == 4)
                            if (kryptis == 5)
                            if (kryptis == 6)
                            if (kryptis == 7)
                            if (kryptis == 8)*/
                            vaizduotiZemelapi();
                            //zaidejoMatomumas();
                            break;
                        }
                        default: {
                            cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!";
                        }
                    }
                }
                break;
            }
            default: {
                cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!";
                break;
            }
        }
    }
    return 0;
}