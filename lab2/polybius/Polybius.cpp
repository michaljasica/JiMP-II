//
// Created by malikmontana on 11.03.18.
//


#include "Polybius.h"

std::string PolybiusCrypt(std::string message){
    std::string napis;
    int i = 0;
    while (message[i] != '\0') {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            if (message[i] <= 'J') {
                if (message[i] == 'J')
                    message[i] = 'I';

                napis+=std::to_string(((int(message[i]) - 65) / 5) + 1);
                napis+=std::to_string(((int(message[i]) - 65) % 5) + 1);
            }
            else {
                napis+=std::to_string(((int(message[i]) - 66) / 5) + 1);
                napis+=std::to_string(((int(message[i]) - 66) % 5) + 1);
            }
        }
        else if(message[i] >= 'a' && message[i] <= 'z') {
            if (message[i] <= 'j') {
                if (message[i] == 'j')
                    message[i] = 'i';

                napis+=std::to_string(((int(message[i]) - 97) / 5) + 1);
                napis+=std::to_string(((int(message[i]) - 97) % 5) + 1);

            }
            else {
                napis+=std::to_string(((int(message[i]) - 98) / 5) + 1);
                napis+=std::to_string(((int(message[i]) - 98) % 5) + 1);
            }
        }
        i++;
    }
    return napis;
}

std::string PolybiusDecrypt(std::string crypted){
    std::string napis;
    int i = 0;
    while (crypted[i] != '\0') {
        if (crypted[i] >= '0' && crypted[i] <= '9') {
            if ((crypted[i] <= '2' && crypted[i+1]<= '4') || (crypted[i] == '1' && crypted[i+1]== '5')) {
                if (crypted[i] == '2' && crypted[i+1]== '4')
                    napis+='i';
                else{
                    napis+=char(97+(crypted[i]-49)*5+crypted[i+1]-49);
                }
            }
            else {
                napis+=char(98+(crypted[i]-49)*5+crypted[i+1]-49);
            }
        }
        i=i+2;
    }
    return napis;

}