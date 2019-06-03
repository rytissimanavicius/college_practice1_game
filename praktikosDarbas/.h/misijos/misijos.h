#ifndef MISIJOS_H
#define MISIJOS_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika\praktikosDarbas\.h\priesai\kova.h"

void atspausdintiMisijosTiksla(int kuriMisija) {
    if (kuriMisija == 0) cout << "\nKELIAUJANT SU SAMDINIU KOMPANIJA JUS NETIKETAI BUVOTE UZPULTI! TAI BUVO PADARAI PANASUS I ZMONES, BET JU AKYSE NEBUVO JOKIOS GYVYBES. JIE NASRAIS IR DANTIMIS PO VIENA GNAIBE TAVO KOMPANIJONUS, NELIKO KITOS ISEITIES KAIP SPRUKTI. DEJA, TUREJAI PRIIMTI SPRENDIMA - AR GRIZTI I KAIMA IR ISITIKINTI, KAD TAVO SEIMA SAUGI, AR EITI I MIESTA IR ISPETI VALDOVA APIE SIA SITUACIJA...\n";
    if (kuriMisija == 1) cout << "\nNUSPRENDETE, KAD PRANESTI INFORMACIJA VALDZIAI BUVO PROTINGIAU. TAI TIESA IR UZ TAI BUVOTE GAUSIAI APDOVANOTAS (500 AUKSINIU), BET NERIMAS APIE SEIMA DARESI NESUVALDOMAS. UZTAT VALDOVO ZODZIAI JUS STAIGA PRADZIUGINO, JIS SKIRIA JUMS NAUJA KOMPANIJA VYRU IR PRASO NUVYKTI I KAIMA IR APGYNTI JI NUO GRESIANCIO PAVOJAUS, JEIGU DAR NEVELU...\n";
    if (kuriMisija == 2) cout << "\n\n";
    if (kuriMisija == 3) cout << "\nATVYKES RADOTE KAIMA NUSIAUBTA: LAVONAI, TUSTI KAPAI, GAISRAS. PUOLETE GINTI.\n";
}
void misija(int &kuriMisija, int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int nr, int dungKord[30]) {
    if (kuriMisija == 0) {
        if (xZaid == xMiest && yZaid == yMiest) {
            kuriMisija = 1;
            zaidDuom[nr].gold += 500;
            atspausdintiMisijosTiksla(kuriMisija);
        }
        if (xZaid == xKaim && yZaid == yKaim) {
            kuriMisija = 2;
            zaidDuom[nr].xp += 500;
            atspausdintiMisijosTiksla(kuriMisija);
        }
    }
    else if (kuriMisija == 1 && xZaid == xKaim && yZaid == yKaim) {
        bool pralaimejoMisija = false;
        kova(nr, pralaimejoMisija);
        if (pralaimejoMisija == false) {
            kuriMisija = 3;
            atspausdintiMisijosTiksla(kuriMisija);        
        }
        else cout << "\nDIDZIAUSIOS PASTANGOS BUVO VELTUI. TEKS KURIAM LAIKUI ATSITRAUKTI IR SUGRIZTI SU KITU PLANU.\n";
    }
    else if (kuriMisija == 2) {

    }
    else if (kuriMisija == 3) {

    }
}

#endif