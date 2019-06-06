#ifndef ZAIDEJOPASIEKIMAI_H
#define ZAIDEJOPASIEKIMAI_H

using namespace std;

void pasiekimaiSpausdinti(int zaidejoPasiekimai[15]) {
    for (int i = 0; i < 15; i++) {
        if (i == 0 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". PAJUDEKITE ZEMELAPI (PASIEKTA).\n";
        else if (i == 0 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". PAJUDEKITE ZEMELAPI (NEPASIEKTA).\n";

        if (i == 1 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". APLANKYKITE MIESTA (PASIEKTA).\n";
        else if (i == 1 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". APLANKYKITE MIESTA (NEPASIEKTA).\n";

        if (i == 2 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". APLANKYKITE KAIMA (PASIEKTA).\n";
        else if (i == 2 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". APLANKYKITE MIESTA (NEPASIEKTA).\n";

        if (i == 3 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". LAIMEKITE KOVA (PASIEKTA).\n";
        else if (i == 3 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". LAIMEKITE KOVA (NEPASIEKTA).\n";

        if (i == 4 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". TUREKITE 1000 AUKSINIU (PASIEKTA).\n";
        else if (i == 4 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". TUREKITE 1000 AUKSINIU (NEPASIEKTA).\n";

        if (i == 5 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". TUREKITE 5000 AUKSINIU (PASIEKTA).\n";
        else if (i == 5 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". TUREKITE 5000 AUKSINIU (NEPASIEKTA).\n";

        if (i == 6 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". TUREKITE 10000 AUKSINIU (PASIEKTA).\n";
        else if (i == 6 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". TUREKITE 10000 AUKSINIU (NEPASIEKTA).\n";

        if (i == 7 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". PASIEKITE 1 LYGI (PASIEKTA).\n";
        else if (i == 7 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". PASIEKITE 1 LYGI (NEPASIEKTA).\n";

        if (i == 8 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". PASIEKITE 2 LYGI (PASIEKTA).\n";
        else if (i == 8 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". PASIEKITE 2 LYGI (NEPASIEKTA).\n";

        if (i == 9 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". PASIEKITE 3 LYGI (PASIEKTA).\n";
        else if (i == 9 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". PASIEKITE 3 LYGI (NEPASIEKTA).\n";

        if (i == 10 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". TUREKITE DAUGIAU NEI 100 GYVYBIU (PASIEKTA).\n";
        else if (i == 10 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". TUREKITE DAUGIAU NEI 100 GYVYBIU (NEPASIEKTA).\n";

        if (i == 11 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". NUSIPIRKITE DAIKTA (PASIEKTA).\n";
        else if (i == 11 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". NUSIPIRKITE DAIKTA (NEPASIEKTA).\n";

        if (i == 12 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". PARDUOKITE DAIKTA (PASIEKTA).\n";
        else if (i == 12 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". PARDUOKITE DAIKTA (NEPASIEKTA).\n";

        if (i == 13 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". ATLIKITE PIRMA MISIJA (PASIEKTA).\n";
        else if (i == 13 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". ATLIKITE PIRMA MISIJA (NEPASIEKTA).\n";

        if (i == 14 && zaidejoPasiekimai[i] == 1) cout << i + 1 << ". PAVYKO ISGELBETI SEIMA (PASIEKTA).\n";
        else if (i == 14 && zaidejoPasiekimai[i] == 0) cout << i + 1 << ". PAVYKO ISGELBETI SEIMA (NEPASIEKTA).\n";
    }
}
void zaidejoPasiekimaiNaujas(int zaidejoPasiekimai[15]) {
    for (int i = 0; i < 15; i++) {
        zaidejoPasiekimai[i] = 0;
    }
}

#endif