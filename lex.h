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
	while(!fin.eof()){
        ch = fin.get();
   		switch (s){
        case 0:
            if (ch == 'p' || ch == 'P'){ //comeca a identificar PROGRAMAINICIO, PASSOS
                s = 1;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'd' || ch == 'D'){ //comeca a identificar DEFINAINSTRUCAO, DIREITA
                s = 15;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'c' || ch == 'C'){ //comeca a identificar COMO
                s = 30;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'i' || ch == 'I'){ //comeca a identificar INICIO
                s = 34;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'm' || ch == 'M'){ //comeca a identificar MOVA
                s = 40;
                buffer[j++] = ch;
                break;
            }
            if (ch >= 48 && ch <=57){ //comeca a identificar NUMERO
                s = 44;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'a' || ch == 'A'){ //comeca a identificar Aguarde Até, APAGUE LAMPADA, ACENDA LAMPADA
                s = 50;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'r' || ch == 'R'){ //comeca a identificar Robo Pronto
                s = 61;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'v' || ch == 'V'){ //comeca a identificar Vire Para
                s = 72;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'e' || ch == 'E'){ //comeca a identificar ESQUERDA
                s = 81;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'f' || ch == 'F'){ //comeca a identificar FIMEXECUCAO*, FIMPROGRAMA*, “Frente Robo Bloqueada”  \\ALEX      *falta implementar
                s = 300;
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
            if (ch == 'a' || ch=='A'){
                s = 45;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 2:
            if (ch == 'o' || ch == 'O'){ //PROGRAMAINICIO
                s = 3;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 3:
            if (ch == 'g' || ch == 'G'){ //PROGRAMAINICIO
                s = 4;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 4:
            if (ch == 'r' || ch == 'R'){ //PROGRAMAINICIO
                s = 5;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5:
            if (ch == 'a' || ch == 'A'){ //PROGRAMAINICIO
                s = 6;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6:
            if (ch == 'm' || ch == 'M'){ //PROGRAMAINICIO
                s = 7;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 7:
            if (ch == 'a' || ch == 'A'){ //PROGRAMAINICIO
                s = 8;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 8:
            if (ch == 'i' || ch == 'I'){ //PROGRAMAINICIO
                s = 9;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 9:
            if (ch == 'n' || ch == 'N'){ //PROGRAMAINICIO
                s = 10;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
   		case 10:
            if (ch == 'i' || ch == 'I'){ //PROGRAMAINICIO
                s = 11;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 11:
            if (ch == 'c' || ch == 'C'){ //PROGRAMAINICIO
                s = 12;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 12:
            if (ch == 'i' || ch == 'I'){ //PROGRAMAINICIO
                s = 13;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 13:
            if (ch == 'o' || ch == 'O'){ //PROGRAMAINICIO
                s = 14;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 14:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu PROGRAMAINICIO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "PROGRAMA";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 15:
            if (ch == 'e' || ch == 'E'){ //... DEFINAINSTRUCAO
                s = 16;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'i' || ch == 'I'){ // ... DIREITA
                s = 89;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 16:
            if (ch == 'f' || ch == 'F'){ //... DEFINAINSTRUCAO
                s = 17;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 17:
            if (ch == 'i' || ch == 'I'){ //... DEFINAINSTRUCAO
                s = 18;
                buffer[j++] = ch;
                break;
            }
			else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 18:
            if (ch == 'n' || ch == 'N'){ //... DEFINAINSTRUCAO
                s = 19;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 19:
            if (ch == 'a' || ch == 'A'){ //... DEFINAINSTRUCAO
                s = 20;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 20:
            if (ch == 'i' || ch == 'I'){ //... DEFINAINSTRUCAO
                s = 21;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 21:
            if (ch == 'n' || ch == 'N'){ //... DEFINAINSTRUCAO
                s = 22;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 22:
            if (ch == 's' || ch == 'S'){ //... DEFINAINSTRUCAO
                s = 23;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 23:
            if (ch == 't' || ch == 'T'){ //... DEFINAINSTRUCAO
                s = 24;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 24:
            if (ch == 'r' || ch == 'R'){ //... DEFINAINSTRUCAO
                s = 25;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 25:
            if (ch == 'u' || ch == 'U'){ //... DEFINAINSTRUCAO
                s = 26;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 26:
            if (ch == 'c' || ch == 'C'){ //... DEFINAINSTRUCAO
                s = 27;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 27:
            if (ch == 'a' || ch == 'A'){ //... DEFINAINSTRUCAO
                s = 28;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 28:
            if (ch == 'o' || ch == 'O'){ //... DEFINAINSTRUCAO
                s = 29;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 29:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu DEFINAINSTRUCAO!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "DECLARACAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 30:
            if (ch == 'o' || ch == 'O'){ //... COMO
                s = 31;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 31:
            if (ch == 'm' || ch == 'M'){ //... COMO
                s = 32;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 32:
            if (ch == 'o' || ch == 'O'){ //... COMO
                s = 33;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 33:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu COMO!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "DECLARACAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 34:
            if (ch == 'n' || ch == 'N'){ //... INICIO
                s = 35;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 35:
            if (ch == 'i' || ch == 'I'){ //... INICIO
                s = 36;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 36:
            if (ch == 'c' || ch == 'C'){ //... INICIO
                s = 37;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 37:
            if (ch == 'i' || ch == 'I'){ //... INICIO
                s = 38;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 38:
            if (ch == 'o' || ch == 'O'){ //... INICIO
                s = 39;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 39:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu INICIO!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "BLOCO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 40:
            if (ch == 'o' || ch == 'O'){ //... MOVA
                s = 41;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 41:
            if (ch == 'v' || ch == 'V'){ //... MOVA
                s = 42;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 42:
            if (ch == 'a' || ch == 'A'){ //... MOVA
                s = 43;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 43:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu MOVA!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "INSTRUCAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }

            break;
        case 44:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu NUM!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "NUMERO";
                token.nome = buffer;
                return token;
            }
            else if(ch >= 48 && ch <=57){
                s = 44; //loop
                buffer[j++] = ch;
                break;
            }
            else{ // ERRO DE NUMERO
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ERRONUM";
                token.nome = buffer;
                return token;
            }
            break;
        case 45:
            if (ch == 's' || ch == 'S'){ //... PASSOS
                s = 46;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 46:
            if (ch == 's' || ch == 'S'){ //... PASSOS
                s = 47;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 47:
            if (ch == 'o' || ch == 'O'){ //... PASSOS
                s = 48;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 48:
            if (ch == 's' || ch == 'S'){ //... PASSOS
                s = 49;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu PASSO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "INSTRUCAO";
                token.nome = buffer;
                return token;
            }
            break;
        case 49:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu PASSOS!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "INSTRUCAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 50:
            if (ch == 'g' || ch == 'G'){ //... AGUARDE ATE
                s = 51;
                buffer[j++] = ch;
                break;
            }
            else if (ch == 'p' || ch == 'P'){ // ... APAGUE LAMPADA
                s = 5001;
                buffer[j++] = ch;
                break;
            }
//            else if (ch == 'c' || ch == 'c'){ // ... ACENDA LAMPADA
//                s = 6001;
//                buffer[j++] = ch;
//                break;
//            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 51:
            if (ch == 'u' || ch == 'U'){ //... AGUARDE ATE
                s = 52;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 52:
            if (ch == 'a' || ch == 'A'){ //... AGUARDE ATE
                s = 53;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 53:
            if (ch == 'r' || ch == 'R'){ //... AGUARDE ATE
                s = 54;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 54:
            if (ch == 'd' || ch == 'D'){ //... AGUARDE ATE
                s = 55;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 55:
            if (ch == 'e' || ch == 'E'){ //... AGUARDE ATE
                s = 56;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 56:
            if (ch == ' '){ //... AGUARDE ATE
                s = 57;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 57:
            if (ch == 'a' || ch == 'A'){ //... AGUARDE ATE
                s = 58;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r'){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 58:
            if (ch == 't' || ch == 'T'){ //... AGUARDE ATE
                s = 59;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r'){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 59:
            if (ch == 'e' || ch == 'E'){ //... AGUARDE ATE
                s = 60;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r'){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 60:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu AGUARDE ATE!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "INSTRUCAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 61:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Ro
                s = 62;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 62:
            if (ch == 'b' || ch == 'B'){ //... Robo Pronto -> Rob
                s = 63;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 63:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Robo
                s = 64;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 64:
            if (ch == ' '){ //... Robo Pronto
                s = 65;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 65:
            if (ch == 'p' || ch == 'P'){ //... Robo Pronto -> Robo P
                s = 66;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'o' || ch == 'O'){ //... Robo Ocupado -> Robo O
                s = 666;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'm' || ch == 'M'){ //... Robo Ocupado -> Robo M
                s = 682;
                buffer[j++] = ch;
                break;
            }

            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 66:
            if (ch == 'r' || ch == 'R'){ //... Robo Pronto -> Robo Pr
                s = 67;
                buffer[j++] = ch;
                break;
            }
        	if (ch == 'a' || ch == 'A'){ //... Robo Ocupado -> Robo Pa
                s = 677;
                buffer[j++] = ch;
                break;
            }


		else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 67:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto ->Robo Pro
                s = 68;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 68:
            if (ch == 'n' || ch == 'N'){ //... Robo Pronto -> Robo Pron
                s = 69;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 69:
            if (ch == 't' || ch == 'T'){ //... Robo Pronto ->Robo Pront
                s = 70;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 70:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Robo Pronto
                s = 71;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 71:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu ROBO PRONTO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 72:
            if (ch == 'i' || ch == 'I'){ //... Vire Para
                s = 73;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 73:
            if (ch == 'r' || ch == 'R'){ //... Vire Para
                s = 74;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 74:
            if (ch == 'e' || ch == 'E'){ //... Vire Para
                s = 75;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 75:
            if (ch == ' '){ //... Vire Para
                s = 76;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 76:
            if (ch == 'p' || ch == 'P'){ //... Vire Para
                s = 77;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 77:
            if (ch == 'a' || ch == 'A'){ //... Vire Para
                s = 78;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 78:
            if (ch == 'r' || ch == 'R'){ //... Vire Para
                s = 79;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 79:
            if (ch == 'a' || ch == 'A'){ //... Vire Para
                s = 80;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 80:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu VIRE PARA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "INSTRUCAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 81:
            if (ch == 's' || ch == 'S'){ //... ESQUERDA
                s = 82;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 82:
            if (ch == 'q' || ch == 'Q'){ //... ESQUERDA
                s = 83;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 83:
            if (ch == 'u' || ch == 'U'){ //... ESQUERDA
                s = 84;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 84:
            if (ch == 'e' || ch == 'E'){ //... ESQUERDA
                s = 85;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 85:
            if (ch == 'r' || ch == 'R'){ //... ESQUERDA
                s = 86;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 86:
            if (ch == 'd' || ch == 'D'){ //... ESQUERDA
                s = 87;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 87:
            if (ch == 'a' || ch == 'A'){ //... ESQUERDA
                s = 88;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 88:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu ESQUERDA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "SENTIDO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 89:
            if (ch == 'r' || ch == 'R'){ //... DIREITA
                s = 90;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 90:
            if (ch == 'e' || ch == 'E'){ //... DIREITA
                s = 91;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 91:
            if (ch == 'i' || ch == 'I'){ //... DIREITA
                s = 92;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 92:
            if (ch == 't' || ch == 'T'){ //... DIREITA
                s = 93;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 93:
            if (ch == 'a' || ch == 'A'){ //... DIREITA
                s = 94;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 94:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu DIREITA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "SENTIDO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
 		case 666:
            if (ch == 'c' || ch == 'C'){ //... Robo Pronto -> Robo O
                s = 667;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO Ocupado
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 667:
            if (ch == 'u' || ch == 'U'){ //... Robo Pronto -> Robo Oc
                s = 668;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO Ocupado
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 668:
            if (ch == 'p' || ch == 'P'){ //... Robo Pronto -> Robo Ocu
                s = 669;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO Ocupado
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 669:
            if (ch == 'a' || ch == 'A'){ //... Robo Pronto -> Robo Ocup
                s = 670;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO Ocupado
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 670:
            if (ch == 'd' || ch == 'D'){ //... Robo Pronto -> Robo Ocup
                s = 671;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO Ocupado
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;

		case 671:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Robo Ocupado
                s = 672;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO OCUPADO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 672:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu ROBO ocupado!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;

        case 677:
            if (ch == 'r' || ch == 'R'){ //... Robo Pronto -> Robo Par
                s = 678;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 678:
            if (ch == 'a' || ch == 'A'){ //... Robo Pronto -> Robo Para
                s = 679;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 679:
            if (ch == 'd' || ch == 'D'){ //... Robo Pronto -> Robo Parad
                s = 680;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 680:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Robo Parado
                s = 681;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 681: //fim parado
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu ROBO parado!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;

		case 682:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Robo Mo
                s = 683;
                buffer[j++] = ch;
                break;
            }

		else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 683:
            if (ch == 'v' || ch == 'V'){ //... Robo Pronto -> Robo Mov
                s = 684;
                buffer[j++] = ch;
                break;
            }

		else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 684:
            if (ch == 'i' || ch == 'I'){ //... Robo Pronto -> Robo Movi
                s = 685;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 685:
            if (ch == 'm' || ch == 'M'){ //... Robo Pronto -> Robo Movim
                s = 686;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 686:
            if (ch == 'e' || ch == 'E'){ //... Robo Pronto -> Robo Movime
                s = 687;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 687:
            if (ch == 'n' || ch == 'N'){ //... Robo Pronto -> Robo Movimen
                s = 688;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 688:
            if (ch == 't' || ch == 'T'){ //... Robo Pronto -> Robo Moviment
                s = 689;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 689:
            if (ch == 'a' || ch == 'A'){ //... Robo Pronto -> Robo Movimenta
                s = 690;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 690:
            if (ch == 'n' || ch == 'N'){ //... Robo Pronto -> Robo Movimentan
                s = 691;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 691:
            if ( ch == 'd' || ch == 'D'){ //... Robo Pronto -> Robo Movimentand
                s = 692;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 692:
            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Robo Movimentando
                s = 693;
                buffer[j++] = ch;
                break;
            }
        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
		case 693: //fim movimentando
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu ROBO Movimentando!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar AGUARDE ATE
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 300:
            if (ch == 'r' || ch == 'R'){ //... Frente Robo Bloqueada  (frente)
                s = 301;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 301:
            if (ch == 'e' || ch == 'E'){ //... Frente Robo Bloqueada  (frente)
                s = 302;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 302:
            if (ch == 'n' || ch == 'N'){ //...Frente Robo Bloqueada  (frente)
                s = 303;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 303:
            if (ch == 't' || ch == 'T'){ //... Frente Robo Bloqueada  (frente)
                s = 304;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 304:
            if (ch == 'e' || ch == 'E'){ //... Frente Robo Bloqueada  (frente)
                s = 305;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 305:
             if (ch == ' '){ //... Frente Robo Bloqueada  (frente)
                s = 306;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 306:
            if (ch == 'r' || ch == 'R'){ //... Frente Robo Bloqueada  (robo)
                s = 307;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 307:
            if (ch == 'o' || ch == 'O'){ //... Frente Robo Bloqueada  (robo)
                s = 308;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 308:
            if (ch == 'b' || ch == 'B'){ //... Frente Robo Bloqueada  (robo)
                s = 309;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 309:
            if (ch == 'o' || ch == 'O'){ //... Frente Robo Bloqueada  (robo)
                s = 310;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 310:
             if (ch == ' '){ //... Frente Robo Bloqueada  (robo)
                s = 311;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == '\n' || ch == '\r'){
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "Palavra reservada escrita incorretamente";
                token.nome = buffer;
                return token;
            }
            break;
        case 311:
            if (ch == 'b' || ch == 'B'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 312;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 312:
            if (ch == 'l' || ch == 'L'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 313;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 313:
            if (ch == 'o' || ch == 'O'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 314;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 314:
            if (ch == 'q' || ch == 'Q'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 315;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 315:
            if (ch == 'u' || ch == 'U'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 316;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 316:
            if (ch == 'e' || ch == 'E'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 317;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 317:
            if (ch == 'a' || ch == 'A'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 318;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 318:
            if (ch == 'd' || ch == 'D'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 319;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 319:
            if (ch == 'a' || ch == 'A'){ //... Frente Robo Bloqueada  (bloqueada)
                s = 3000;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 3000:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu Frente Robo Bloqueada!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;

        case 5001:
            if (ch == 'a' || ch == 'A'){ //... APAGUE LAMPADA  (AP*A*GUE)
                s = 5002;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5002:
            if (ch == 'g' || ch == 'G'){ //... APAGUE LAMPADA  (AP*A*GUE)
                s = 5003;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5003:
            if (ch == 'u' || ch == 'U'){ //... APAGUE LAMPADA  (AP*A*GUE)
                s = 5004;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5004:
            if (ch == 'e' || ch == 'E'){ //... APAGUE LAMPADA  (AP*A*GUE)
                s = 5005;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5005:
             if (ch == ' '){ //... APAGUE LAMPADA  (APAGUE)
                s = 5006;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == '\n' || ch == '\r'){
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5006:
            if (ch == 'l' || ch == 'L'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5007;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5007:
            if (ch == 'a' || ch == 'A'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5008;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5008:
            if (ch == 'm' || ch == 'M'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5009;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5009:
            if (ch == 'p' || ch == 'P'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5010;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5010:
            if (ch == 'a' || ch == 'A'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5011;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5011:
            if (ch == 'd' || ch == 'D'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5012;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5012:
            if (ch == 'a' || ch == 'A'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5013;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5013:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu APAGUE|ACENDA LAMPADA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "INSTRUCAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
//-------------------------------------------------------------------------------------------------------------

       case 500:
            if (ch == ' ' || ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;

        //tratamento de erros
        case 501:
            if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ //CASO TENHA APARECIDO CARACTER INVALIDO EM UMA PALAVRA RESERVADA COMPOSTA
                buffer[j++] = ch;
                s = 501;
                break;
            }
            else if((ch == ' ' || ch == '\n' || ch == '\r')){ // verificando se houve erro ao digitar AGUARDE ATE
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ERROINSTRUCAO";
                token.nome = buffer;
                return token;
            }
        break;

   		default:
            tokenTipo token;
            token.tipo = "ERRO";
            token.nome= "transicao nao existente";
            return token;
        }
	}

    tokenTipo token;
    token.tipo = "FIM";
    token.nome = "FIM";
    return token;

}
