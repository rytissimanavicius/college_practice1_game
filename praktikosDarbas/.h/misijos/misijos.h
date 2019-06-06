#ifndef MISIJOS_H
#define MISIJOS_H

#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoDuomenys.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\priesai\kova.h"
#include "C:\Users\rytuciss\Documents\GitHub\praktika_zaidimas\praktikosDarbas\.h\zaidejas\zaidejoInventorius.h"

void atspausdintiMisijosTiksla(int kuriMisija) {
    if (kuriMisija == 0) cout << "\nKELIAUJANT SU SAMDINIU KOMPANIJA JUS NETIKETAI BUVOTE UZPULTI! TAI BUVO PADARAI PANASUS I ZMONES, BET JU AKYSE NEBUVO JOKIOS GYVYBES. JIE NASRAIS IR DANTIMIS PO VIENA GNAIBE TAVO KOMPANIJONUS, NELIKO KITOS ISEITIES KAIP SPRUKTI. GRIZKITE I MIESTA PRANESTI NAUJIENAS.\n";
    if (kuriMisija == 1) cout << "\nATVYKES I MIESTA NUSKUBEJOTE PAS VALDOVA, UZ NAUJIENAS JIS JUMS ATSIDEKOJO 500 AUKSINIU. TUOJAU PRADEJOTE NERIMAUTI APIE SAVO SEIMA KURI GYVENO KAIME, VALDOVAS BE GINCU SKYRE JUMS NAUJA KOMPANIJA SU TIKSLUTA KAIMA APGYNTI, JUS ISKELIAVOTE...\n";
    if (kuriMisija == 2) cout << "\nATVYKES RADOTE KAIMA NUSIAUBTA: LAVONAI, TUSTI KAPAI, GAISRAS. NEPRAEJUS NEI AKIMIRKAI PUOLETE BEGTI LINK NAMU, SEIMOS BUVO NEMATYTI, TIK KRUVA INIRSUSIU PADARU. PUOLETE GYNTI.\n";
    if (kuriMisija == 3) cout << "\nGRIZOTE I MIESTA, JUSU NUSTABAI BENT CIA GYVENIMAS VIRE KAIP IPRASTA. POKALBIO METU SU VALDOVU, JIS PADEKOJO UZ JUSU PASTANGAS, BET LAUKE DAUG DARBO. JIS NORI PRADETI TERITORIJU VALYMA NUO ZOMBIU, APLANKYKITE DUNGEONA IR NUGALEKITE JUOS...\n";
    if (kuriMisija == 4) cout << "\nATVYKOTE I DUNGEONA, GINKITES!\n";
}
void misija(int &kuriMisija, int xZaid, int yZaid, int xMiest, int yMiest, int xKaim, int yKaim, int nr, int dungKord[30], int zaidejoPasiekimai[15]) {
    bool pralaimejoMisija = false;
    if (kuriMisija == 0 && xZaid == xMiest && yZaid == yMiest) {
        if (zaidejoPasiekimai[13] == 0) zaidejoPasiekimai[13] = 1;
        kuriMisija = 1;
        zaidDuom[nr].gold += 500;
        cout << "\n";
        atspausdintiMisijosTiksla(kuriMisija);
    }
    else if (kuriMisija == 1 && xZaid == xKaim && yZaid == yKaim) {
        kuriMisija = 2;           //FIXME: misijosEtapas, o ne kuriMisija
        atspausdintiMisijosTiksla(kuriMisija);
        kova(nr, pralaimejoMisija, zaidejoPasiekimai);
        if (pralaimejoMisija == false) {
            cout << "\nATMOSFERA STAIGA NUTILO. KOVA LAIMETA. NERIMAUDAMAS IZENGETE PRO SAVU NAMU SLENKSTI IR BUVOTE PASITIKTAS SAVO SEIMOS KURI BEGALO DZIAUGESI JUS PAMACIUSI. JUMS PAVYKO. DEJA, NEBUVO KADA SVAISTYTI LAIKO, REIKIA PERDUOTI SIAS NAUJIENAS VALDOVUI. PRIES ISEINANT JUS SUSTABDE SUNUS LAIKYDAMAS KALAVIJA KURI SAUGOJOTE SAVO SPINTOJE ILGA LAIKA, GERESNES PROGOS NEI SI NEBUS JO PANAUDOTI (GAVOTE KALAVIJA)...\n";
            if (zaidejoPasiekimai[14] == 0) zaidejoPasiekimai[14] = 1;
        }
        else if (pralaimejoMisija == true) cout << "\nPRABUDOTE APSUPTAS POROS KOMPANIJONU. VIENAS IS JU PRASNEKO, KAD JIE VIENINTELIAI ISGYVENE - KOVA TESESI IKI PASKUTINIO. JUSU SEIMA ZUVO, REIKIA STOTIS IR JUDETI TOLIAU. EINANT VIENAS IS KOMPANIJONU JUS SUSTABDE IR ITEIKE KARDA KURI NOREJO PASILIKT SAU, BET PAMATE ISGRAVIRUOTA JUSU PAVARDE (GAVOTE KALAVIJA)...\n";
        for (int i = 0; i < sizeof kardas / sizeof kardas[0]; i++) {
            if (kardas[i].pav == "-") {
                kardas[i].pav = "PROTEVIU KARDAS";
                kardas[i].puolimas = 30;
                for (int j = 0; j < sizeof zaidInv / sizeof zaidInv[0]; j++) {
                    if (zaidInv[j].pav == "-") {
                        zaidInv[j].pav = kardas[i].pav;
                        zaidInv[j].tipas = kardas[i].tipas;
                        break;
                    }
                }
                break;
            }
        }
        kuriMisija = 3;
    }
    else if (kuriMisija == 3 && xZaid == xMiest && yZaid == yMiest) { 
        atspausdintiMisijosTiksla(kuriMisija);
        kuriMisija = 4;
    }
    else if (kuriMisija == 4) {
        for (int i = 0; i < 30; i += 2) {
            if (xZaid == dungKord[i] && yZaid == dungKord[i + 1]) {
                atspausdintiMisijosTiksla(kuriMisija);
                kova(nr, pralaimejoMisija, zaidejoPasiekimai);
                if (pralaimejoMisija == false) cout << "\nJUMS PAVYKO! KOMPANIJA NEKANTRAVO BUTI GAUSIAI APDOVANOTI, GRIZKITE I MIESTA.\n";
                else if (pralaimejoMisija == true) cout << "\n\nNESEKME. VALDOVAS NENUDZIUGS TAI ISGIRDES.";
                kuriMisija = 5;
            }
        }
    }
}

#endif