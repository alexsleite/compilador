#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "lex.h"

using namespace std;

int main(){
    openFile();
    int *linhaAux;
    int linha = 0;
    linhaAux = &linha;
    while (checaFim()){
        tokenTipo token = getToken(*linhaAux);
        if (token.tipo != "FIM"){
            if (token.ehErro == false)
                printf("Token: %s, Lexema: %s\n", token.tipo.c_str(), token.nome.c_str());
            else
                printf("Erro: %s, Lexema: %s, Linha: %d, Coluna: %d\n", token.tipo.c_str(), token.nome.c_str(), token.linha, token.coluna);
        }
    }


    closeFile();
    return 0;
}
