//
// Created by px-gnom on 11/02/17.
//
#include <stdlib.h>
#include "chrypto.h"

// sezar chrypt
int sezar_chrypt(char c , int n){
    int base;

    if (c >= 'A'  && c <= 'Z') /*Maj*/
        base = 65;
    else
        if (c >= 'a'  && c <= 'z') /*Min*/
            base = 97;
        else
            return c;

    return ((c+n)-base)%26+base; /*Code*/

}

// sezar de_chrypt
int sezar_de_chrypt(char c , int n){
    int base;

    if (c >= 'A'  && c <= 'Z') /*Maj*/{
        base = 65;
        return ((c-n)+base)%26+base; /*Decode*/
    }
    else
        if (c >= 'a'  && c <= 'z') /*Min*/{
            base = 97;
            return ((c-n)+base-12)%26+base; /*Decode*/
        }

        else
            return c;


}

/* Convert the string Key to an integer*/
int cnvrt_alpha_key(char key){

    char buffer = key;
    int base;

    if (buffer >= 'A'  && buffer <= 'Z') /*Maj*/
        base = 65;
    else if (buffer >= 'a'  && buffer <= 'z') /*Min*/
        base = 97;
    else
        return atoi(""+key);

    return buffer-base;

}
