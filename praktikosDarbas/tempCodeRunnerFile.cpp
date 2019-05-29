 }
                                    case KEY_UP: {
                                        if (yZaid > 0) {



                                            temp = zemelapis[yZaid - 1][xZaid];
                                            zemelapis[yZaid - 1][xZaid] = zemelapis[yZaid][xZaid]; 
                                            zemelapis[yZaid][xZaid] = temp1;
                                            temp1 = temp;
                                            


                                            yZaid = yZaid - 1;
                                            if (yZaid > 2) zaidejoMatomumas(xZaid, yZaid);
                                            vaizduotiZemelapi();
                                            cout << "\n";
                                            Sleep(50);
                                        }
                                        else cout << "PASIEKETE RIBA!\n";
                                        break;
                                    }