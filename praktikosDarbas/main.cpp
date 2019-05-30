#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <random>
#include <ctime>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

const int zemPlotis = 120;
const int zemAukstis = 30;
char zemelapis[zemAukstis][zemPlotis];

struct zaidejas {                                    //TODO: pildyt content

};
void vaizduotiZemelapi() {
    for (int i = 0; i < zemAukstis; i++) {
        cout << "\n";
        for (int j = 0; j < zemPlotis; j++) {
            cout << zemelapis[i][j];
        }
    }
}
void zaidejoMatomumas(int &x, int &y, int dungKord[]) {
    int xDung, yDung;
    for (unsigned int i = y - 3; i < y + 4; i++) {
        for (unsigned int j = x - 3; j < x + 4; j++) {
            for (int k = 0; k < 30; k+=2) {
                if (zemelapis[i][j] != 'Z' && zemelapis[i][j] != 'D' && j == dungKord[k] && i == dungKord[k + 1]) zemelapis[i][j] = 'D';
            }
            if (zemelapis[i][j] != 'Z' && zemelapis[i][j] != 'M' && zemelapis[i][j] != '.' && zemelapis[i][j] != '^' && zemelapis[i][j] != 'D') {
                zemelapis[i][j] = '.';
            }
        }
    }
}
void zemelapioAtsitiktinePozicija(int nuoKrasto, int &x, int &y) {                        //FIXME: kiti budai generuoja tuos pacius skaicius nors be time lib :/
    mt19937 gen;
    gen.seed(time(0));
    uniform_int_distribution<uint32_t> random1(nuoKrasto, (zemPlotis - nuoKrasto) - 1);
    uniform_int_distribution<uint32_t> random2(nuoKrasto, (zemAukstis - nuoKrasto) - 1);
    x = random1(gen);
    y = random2(gen);
}
void generuotiZemelapi(int &xZaid, int &yZaid, int &xPard, int &yPard, int xDung, int yDung, int dungKord[]) {
    for (int i = 0; i < zemAukstis; i++) {
        for (int j = 0; j < zemPlotis; j++) {
            if (i < 3 || i > zemAukstis - 4 || j < 3 || j > zemPlotis - 4) zemelapis[i][j] = '^';
            else zemelapis[i][j] = '*';                                                             
        }
    }





    zemelapioAtsitiktinePozicija(3, xZaid, yZaid);
    cout << xZaid << " " << yZaid << "/////";
    zemelapis[yZaid][xZaid] = 'Z';
    Sleep(1000);





    bool nesutampaKord = false;
    while (nesutampaKord == false) {
        zemelapioAtsitiktinePozicija(3, xPard, yPard);
        if (xPard != xZaid && yPard != yZaid) nesutampaKord = true;
    }
    zemelapis[yPard][xPard] = 'M';
    Sleep(1000);





    for (int i = 0; i < 30; i+=2) {
        zemelapioAtsitiktinePozicija(3, xDung, yDung);
        dungKord[i] = xDung;
        dungKord[i + 1] = yDung;  
        cout << dungKord[i] << " " << dungKord[i + 1] << " / ";                                                                //TODO: patikrinti ar nesutampa su Z ir M
        Sleep(1000);   
    }
}
int main() {
    bool procVeikia = true;
    int pagrMenu = -1;
    cout << "\n0 - BAIGTI ZAIDIMA;\n" 
            "1 - PRADETI NAUJA ZAIDIMA;\n";
    while (procVeikia == true) {
        cout << "\nPASIRINKITE MENU PUNKTA: ";
        cin >> pagrMenu;
        switch(pagrMenu) {
            case 0: {
                exit(0);
            }
            case 1: {
                cout << "\nPASAULIS GENERUOJAMAS...\n";                          //TODO: krovima pademonstruoti
                int xZaid, yZaid;
                int xPard, yPard;
                int xDung, yDung, dungKord[30];
                generuotiZemelapi(xZaid, yZaid, xPard, yPard, xDung, yDung, dungKord);
                //nustatome zaidejo matomumo toli kuris yra 3, nezinoma zona zymima "*", o matoma "."
                zaidejoMatomumas(xZaid, yZaid, dungKord);
                while (true) {
                    vaizduotiZemelapi();
                    break;
                }
                bool zaidVeikia = true;
                int zaidMenu = -1;
                cout << "\n\n0 - ATGAL I MENU;\n"
                        "1 - JUDETI (RODYKLEMIS);\n";
                while (zaidVeikia == true) {
                    cout << "\nPASIRINKITE VEIKSMA: ";                  //TODO: sugeneruotus dungeonus matymo zonoje vaizduoti
                    cin >> zaidMenu;
                    switch(zaidMenu) {
                        case 0: {
                            zaidVeikia = false;
                            break;
                        }
                        case 1: {
                            bool zaidVaiksto = true, pirmEjimas = true;
                            char temp, temp1 = '.';
                            int bind;
                            while(zaidVaiksto == true) {
                                switch((bind = getch())) {
                                    case VK_ESCAPE: {
                                        zaidVaiksto = false;
                                        break;
                                    }
                                    case KEY_UP: {





                                        if (yZaid > 3) {
                                            temp = zemelapis[yZaid - 1][xZaid];                               //TODO: skaicius sutapatint su matmenimis
                                            zemelapis[yZaid - 1][xZaid] = zemelapis[yZaid][xZaid];            //TODO: uzejus pakeisti icona
                                            zemelapis[yZaid][xZaid] = temp1;                                  //TODO: prideti komentaru, pakeisti spalva i neutralesne
                                            temp1 = temp;                                                     
                                            yZaid = yZaid - 1;                                               
                                            if (yZaid > 2) zaidejoMatomumas(xZaid, yZaid, dungKord);
                                            vaizduotiZemelapi();
                                            cout << "\n";
                                            Sleep(50);
                                        }
                                        else cout << "PASIEKETE RIBA!\n";
                                        break;





                                    }
                                    case KEY_DOWN: {
                                        if (yZaid < 26) {
                                            temp = zemelapis[yZaid + 1][xZaid];
                                            zemelapis[yZaid + 1][xZaid] = zemelapis[yZaid][xZaid]; 
                                            zemelapis[yZaid][xZaid] = temp1;
                                            temp1 = temp;
                                            yZaid = yZaid + 1;
                                            if (yZaid < 27) zaidejoMatomumas(xZaid, yZaid, dungKord);              //FIXME: crash TIK i apacia is virsaus
                                            vaizduotiZemelapi();
                                            cout << "\n";                                                  //FIXME: pakilus i virsu pilnai, griztant atgal crash
                                            Sleep(50);
                                        }
                                        else cout << "\nPASIEKETE RIBA!\n";
                                        break;
                                    }
                                    case KEY_LEFT: {
                                        if (xZaid > 3) {
                                            temp = zemelapis[yZaid][xZaid - 1];
                                            zemelapis[yZaid][xZaid - 1] = zemelapis[yZaid][xZaid];
                                            zemelapis[yZaid][xZaid] = temp1;
                                            temp1 = temp;
                                            xZaid = xZaid - 1;
                                            if (xZaid > 2) zaidejoMatomumas(xZaid, yZaid, dungKord);
                                            vaizduotiZemelapi();
                                            cout << "\n";
                                            Sleep(50);
                                        }
                                        else cout << "\nPASIEKETE RIBA!\n";
                                        break;
                                    }
                                    case KEY_RIGHT: {
                                        if (xZaid < 116) {
                                            temp = zemelapis[yZaid][xZaid + 1];
                                            zemelapis[yZaid][xZaid + 1] = zemelapis[yZaid][xZaid]; 
                                            zemelapis[yZaid][xZaid] = temp1;
                                            temp1 = temp;
                                            xZaid = xZaid + 1;
                                            if (xZaid < 116) zaidejoMatomumas(xZaid, yZaid, dungKord);
                                            vaizduotiZemelapi();
                                            cout << "\n";
                                            Sleep(50);
                                        }
                                        else cout << "\nPASIEKETE RIBA!\n";
                                        break;
                                    }
                                    default: {
                                        
                                    }
                                }
                            }
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