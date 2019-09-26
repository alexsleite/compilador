#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "lex.h"

using namespace std;

int main(){
    openFile();

    while (checaFim()){
        tokenTipo token = getToken();
        if (token.tipo != "fim")
            printf("Tipo: %s, Nome: %s\n", token.tipo.c_str(), token.nome.c_str());
    }


    closeFile();
    return 0;
}
