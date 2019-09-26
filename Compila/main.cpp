#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "lex.h"

using namespace std;

int main(){

    openFile();
    tokenTipo token = getToken();
    printf("Tipo: %s, Nome: %s\n", token.tipo.c_str(), token.nome.c_str());
    token = getToken();
    printf("Tipo: %s, Nome: %s\n", token.tipo.c_str(), token.nome.c_str());
    closeFile();

}
