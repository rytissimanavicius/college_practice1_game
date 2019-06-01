is, zemAukstis, xZaid, yZaid, xMiest, yMiest, xKaim, yKaim, dungKord);
                atnaujintiZaidejoMatomuma(zemelapis, xZaid, yZaid, dungKord);
                vaizduotiZemelapi(zemelapis, zemPlotis, zemAukstis);
                //priskiria pradinius daiktus
                duotiPradineIranga(nr);
                //zaidimo meniu pradzia
                bool zaidVeikia = true;
                int zaidMenu = -1;
                while (zaidVeikia == true) {
                    cout << "\n\n0 - ISEITI IS ZAIDIMO.\n"
                            "1 - JUDETI ZEMELAPYJE.\n"
                            "2 - INVENTORIUS.\n" 
                            "\nPASIRINKITE VEIKSMA: 