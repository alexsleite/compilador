#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

typedef struct tokenTipo{
    string tipo;
    string nome;
}tokenTipo;

ifstream fin("programa.txt");

void openFile(){
    if(!fin.is_open()){
		cout<<"error while opening the file\n";
		exit(0);
	}
}

bool checaFim(){
    if (fin.eof())
        return false;
    else
        return true;
}

void closeFile(){
    fin.close();
}

tokenTipo getToken(){

    char buffer[40], ch;
    int s = 0, j=0;
    ch = fin.get();
	while(!fin.eof()){

   		switch (s){
        case 0:
            if (ch == 'p' || ch == 'P'){ //comeca a identificar PROGRAMAINICIO
                s = 1;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 1:
            if (ch == 'r' || ch == 'R'){ //PROGRAMAINICIO
                s = 2;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 2:
            if (ch == 'o' || ch == 'O'){ //PROGRAMAINICIO
                s = 3;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 3:
            if (ch == 'g' || ch == 'G'){ //PROGRAMAINICIO
                s = 4;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 4:
            if (ch == 'r' || ch == 'R'){ //PROGRAMAINICIO
                s = 5;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5:
            if (ch == 'a' || ch == 'A'){ //PROGRAMAINICIO
                s = 6;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 6:
            if (ch == 'm' || ch == 'M'){ //PROGRAMAINICIO
                s = 7;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 7:
            if (ch == 'a' || ch == 'A'){ //PROGRAMAINICIO
                s = 8;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 8:
            if (ch == 'i' || ch == 'I'){ //PROGRAMAINICIO
                s = 9;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 9:
            if (ch == 'n' || ch == 'N'){ //PROGRAMAINICIO
                s = 10;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
   		case 10:
            if (ch == 'i' || ch == 'I'){ //PROGRAMAINICIO
                s = 11;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 11:
            if (ch == 'c' || ch == 'C'){ //PROGRAMAINICIO
                s = 12;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 12:
            if (ch == 'i' || ch == 'I'){ //PROGRAMAINICIO
                s = 13;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 13:
            if (ch == 'o' || ch == 'O'){ //PROGRAMAINICIO
                s = 14;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 14:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu PROGRAMAINICIO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "programa";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 500:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "id";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
   		default:
            tokenTipo token;
            token.tipo = "erro";
            token.nome= "transicao nao existente";
            return token;
        }

        ch = fin.get();
	}

    tokenTipo token;
    token.tipo = "fim";
    token.nome = "fim";
    return token;

}
