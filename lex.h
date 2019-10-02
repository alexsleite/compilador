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
            if (ch == 'p' || ch == 'P'){ //comeca a identificar PROGRAMAINICIO // PASSOS // PARE // PRONTO // PARADO
                s = 1;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'd' || ch == 'D'){ //comeca a identificar DEFINAINSTRUCAO // DIREITA
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
            if (ch == 'm' || ch == 'M'){ //comeca a identificar MOVA // MOVIMENTANDO
                s = 40;
                buffer[j++] = ch;
                break;
            }
            if (ch >= 48 && ch <=57){ //comeca a identificar NUMERO
                s = 44;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'a' || ch == 'A'){ //comeca a identificar Aguarde Até // Apague // Acenda // ACESA // APAGADA
                s = 50;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'r' || ch == 'R'){ //comeca a identificar Robo // REPITA /
                s = 61;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'v' || ch == 'V'){ //comeca a identificar Vire Para // VEZES
                s = 72;
                buffer[j++] = ch;
                break;
            }
			if (ch == 's' || ch == 'S'){ //comeca a identificar SE // SENAO
                s = 629;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'e' || ch == 'E'){ //comeca a identificar ESQUERDA //ENTÃO //ENQUANTO // EXECUCAOINICIO
                s = 81;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'f' || ch == 'F'){ //comeca a identificar FIM // FIMREPITA // FIMSE // FIMSENAO // FRENTE ROBO BLOQUEADA // FIMEXECUCAO // FIMPROGRAMA // FINALIZE
                s =620;
				buffer[j++] = ch;
                break;
            }
            if (ch == 'o' || ch == 'O'){ // comeca a identificar OCUPADO
                s = 666;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'b' || ch == 'B'){ // comeca a identificar BLOQUEADA
                s = 312;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'b' || ch == 'B'){ // comeca a identificar BLOQUEADA
                s = 312;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'l' || ch == 'L'){ // comeca a identificar LAMPADA
                s = 5051;
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
            if (ch == 'a' || ch=='A'){ // PASSOS // PARE // PARADO
                s = 45;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            if (ch == 'n' || ch == 'N'){
                s = 69;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 14:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu PROGRAMAINICIO!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == 'r' || ch == 'R'){ //... DEFINAINSTRUCAO
                s = 695;
                buffer[j++] = ch;
                break;
            }

			else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 29:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu DEFINAINSTRUCAO!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 33:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu COMO!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 39:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu INICIO!!!!!
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
            if (ch == 'o' || ch == 'O'){ //... MOVA // MOVIMENTANDO
                s = 41;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 41:
            if (ch == 'v' || ch == 'V'){ //... MOVA // MOVIMENTANDO
                s = 42;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            if (ch == 'i' || ch == 'I'){ //... MOVIMENTANDO
                s = 685;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 43:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu MOVA!!!!!
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu NUM!!!!!!
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
            if (ch == 'r' || ch == 'R'){ //... PARE // PARADO
                s = 460;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu PASSO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "INSTRUCAO";
                token.nome = buffer;
                return token;
            }
            break;
        case 49:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu PASSOS!!!!!!
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
        case 460:
            if (ch == 'e' || ch == 'E'){ //... PARE
                s = 461;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'a' || ch == 'A'){ //... PARADO
                s = 679;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 461:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu PARE!!!!!!
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
            if (ch == 'g' || ch == 'G'){ //... AGUARDE
                s = 51;
                buffer[j++] = ch;
                break;
            }
            else if (ch == 't' || ch == 'T'){ //... ATE
                s = 59;
                buffer[j++] = ch;
                break;
            }
            else if (ch == 'p' || ch == 'P'){ // ... APAGUE // APAGADA
                s = 5001;
                buffer[j++] = ch;
                break;
            }
            else if (ch == 'c' || ch == 'C'){ // ... ACENDA // ACESA
                s = 50001;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
            }
            break;
        case 51:
            if (ch == 'u' || ch == 'U'){ //... AGUARDE
                s = 52;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 52:
            if (ch == 'a' || ch == 'A'){ //... AGUARDE
                s = 53;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 53:
            if (ch == 'r' || ch == 'R'){ //... AGUARDE
                s = 54;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 54:
            if (ch == 'd' || ch == 'D'){ //... AGUARDE
                s = 55;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 55:
            if (ch == 'e' || ch == 'E'){ //... AGUARDE
                s = 56;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 56:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu AGUARDE!!!!!!
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
            else if (ch == '\n' || ch == '\r'){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu AGUARDE ATE!!!!!!
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
            if (ch == 'o' || ch == 'O'){ //... Robo -> Ro
                s = 62;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'e' || ch == 'E'){ //... Repita -> Repita
                s = 611;
                buffer[j++] = ch;
                break;
            }

			else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 62:
            if (ch == 'b' || ch == 'B'){ //... Robo -> Rob
                s = 63;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 63:
            if (ch == 'o' || ch == 'O'){ //... Robo -> Robo
                s = 64;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 64:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //... Robo
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ROBO PRONTO!!!!!!
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
			if (ch == 'e' || ch == 'E'){ //... Vezes
                s = 616;
                buffer[j++] = ch;
                break;
            }

			else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu VIRE PARA!!!!!!
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
			if (ch == 'n' || ch == 'N'){ //... EN
                s = 631;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'x' || ch == 'X'){ //... EXECUCAOINICIO
                s = 801;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 88:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ESQUERDA!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 94:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu DIREITA!!!!!!
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
//-----------------------------------------------------------------------------------------------------------------------------------------

																		//RECORTAR APARTIR DAQUI
//--------------------------------- ITERACAO-----------------------------------------------------------------------------------------------
		case 611:
            if (ch == 'p' || ch == 'P'){ //... REPITA
                s = 612;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 612:
            if (ch == 'i' || ch == 'I'){ //... REPITA
                s = 613;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 613:
            if (ch == 't' || ch == 'T'){ //... REPITA
                s = 614;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 614:
            if (ch == 'a' || ch == 'A'){ //... REPITA
                s = 615;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 615:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu REPITA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ITERACAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
		case 616:
            if (ch == 'z' || ch == 'Z'){ //... VEZES
                s = 617;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 617:
            if (ch == 'e' || ch == 'E'){ //... VEZES
                s = 618;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 618:
            if (ch == 's' || ch == 'S'){ //... VEZES
                s = 619;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 619:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu VEZES!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ITERACAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
		case 620:
            if (ch == 'i' || ch == 'I'){ //... fim // finalize
				s = 621;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'a' || ch == 'A'){ //... faca
				s = 643;
                buffer[j++] = ch;
                break;
            }
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 621:
            if (ch == 'm' || ch == 'M'){ //... fim
                s = 622;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'n' || ch == 'N'){ //... FINALIZE
                s = 6022;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 622:
            if (ch == 'r' || ch == 'R'){ //fimrepita
                s = 623;
                buffer[j++] = ch;
                break;
            }
			if (ch == 's' || ch == 'S'){ //fimse
                s = 635;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'p' || ch == 'P'){ //fimpara // fimprograma*
                s = 646;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'r' || ch == 'R'){ //... Frente Robo Bloqueada  (frente)
                s = 301;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'e' || ch == 'E'){ //... fimexecucao
                s = 901;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FIM -> BLOCO!!!!!!
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
		case 623:
            if (ch == 'e' || ch == 'E'){
                s = 624;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 624:
            if (ch == 'p' || ch == 'P'){
                s = 625;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 625:
            if (ch == 'i' || ch == 'I'){
                s = 626;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 626:
            if (ch == 't' || ch == 'T'){
                s = 627;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 627:
            if (ch == 'a' || ch == 'A'){
                s = 628;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 628:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FIMREPITA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ITERACAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;

//-------------------------------------------------------------condição--------------------------------------
		case 629:
            if (ch == 'e' || ch == 'E'){
                s = 650;
                buffer[j++] = ch;
                break;
            }

            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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

		case 631:
            if (ch == 't' || ch == 'T'){
                s = 632;
                buffer[j++] = ch;
                break;
            }
			if (ch == 'q' || ch == 'Q'){
                s = 637;
                buffer[j++] = ch;
                break;
            }

            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 632:
            if (ch == 'a' || ch == 'A'){ //ENTAO
                s = 633;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 633:
            if (ch == 'o' || ch == 'O'){ //ENTAO
                s = 634;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 634:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ENTAO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICIONAL";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
		case 635:
            if (ch == 'e' || ch == 'E'){
                s = 636;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 636:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FIMSE!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICIONAL";
                token.nome = buffer;
                return token;
            }
            else if (ch == 'n' || ch == 'N'){ //FIMSENAO
                s = 6037;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        case 6037:
            if (ch == 'a' || ch == 'A'){ //FIMSENAO
                s = 6038;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6038:
            if (ch == 'o' || ch == 'O'){ //FIMSENAO
                s = 6039;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6039:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FIMSENAO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICIONAL";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
            break;
//---------------------------------------------------------------------laço------------------------------------------------------------
		case 637:
            if (ch == 'u' || ch == 'U'){ //ENQUANTO
                s = 638;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 638: //ENQUANTO
            if (ch == 'a' || ch == 'A'){
                s = 639;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 639:  //ENQUANTO
            if (ch == 'n' || ch == 'N'){
                s = 640;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 640: //ENQUANTO
            if (ch == 't' || ch == 'T'){
                s = 641;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 641: //ENQUANTO
            if (ch == 'o' || ch == 'O'){
                s = 642;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;


		case 642:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ENQUANTO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "LACO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;

		case 643:
            if (ch == 'c' || ch == 'C'){ //FACA
                s = 644;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 644:
            if (ch == 'a' || ch == 'A'){ //FACA
                s = 645;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 645:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FACA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "LACO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
		case 646:
            if (ch == 'a' || ch == 'A'){ //fimpara
                s = 647;
                buffer[j++] = ch;
                break;
            }
            if (ch == 'r' || ch == 'R'){ //fimprograma
                s = 911;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 647:
            if (ch == 'r' || ch == 'R'){
                s = 648;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 648:
            if (ch == 'a' || ch == 'A'){
                s = 649;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;

		case 649:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FIMPARA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "LACO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
//-------------------------------------------------------------------------------------condicional senão---------------------------
		case 650:
            if (ch == 'n' || ch == 'N'){
                s = 651;
                buffer[j++] = ch;
                break;
            }

            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICIONAL";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }


		break;

		case 651:
            if (ch == 'a' || ch == 'A'){
                s = 652;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
		case 652:
            if (ch == 'o' || ch == 'O'){
                s = 653;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;

		case 653:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu SENAO!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICIONAL";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
//-------------------------------------------------------------------------------------------------------------------------------------------------
                                                                        //RECORTAR
//-------------------------------------------------------------------------------------------------------------------------------------------------
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
            if (ch == 'o' || ch == 'O'){ //... -> Robo Ocupado
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ROBO ocupado!!!!!!
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ROBO parado!!!!!!
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

//		case 682:
//            if (ch == 'o' || ch == 'O'){ //... Robo Pronto -> Robo Mo
//                s = 683;
//                buffer[j++] = ch;
//                break;
//            }
//
//		else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
//                s = 501;
//                buffer[j++] = ch;
//                break;
//            }
//            break;
//		case 683:
//            if (ch == 'v' || ch == 'V'){ //... Robo Pronto -> Robo Mov
//                s = 684;
//                buffer[j++] = ch;
//                break;
//            }
//
//		else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
//                s = 501;
//                buffer[j++] = ch;
//                break;
//            }
//            break;
//		case 684:
//            if (ch == 'i' || ch == 'I'){ //... Robo Pronto -> Robo Movi
//                s = 685;
//                buffer[j++] = ch;
//                break;
//            }
//        	else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO MOVIMENTANDO
//                s = 501;
//                buffer[j++] = ch;
//                break;
//            }
//            break;
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ROBO Movimentando!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
             if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ROBO frente robo bloqueada!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
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
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu Frente Robo Bloqueada!!!!!!
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
            if (ch == 'a' || ch == 'A'){ //... APAGUE LAMPADA  (AP*A*GUE) // APAGADA
                s = 5002;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5002:
            if (ch == 'g' || ch == 'G'){ //... APAGUE LAMPADA  (AP*A*GUE)// APAGADA
                s = 5003;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            if (ch == 'a' || ch == 'A'){ //... APAGADA
                s = 5904;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5005:
             if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu APAGUE!!!!!!
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
            else if (ch == '\n' || ch == '\r'){
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5904:
            if (ch == 'd' || ch == 'D'){ //...  APAGADA
                s = 5905;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5905:
            if (ch == 'a' || ch == 'A'){ //...  APAGADA
                s = 5906;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 5906:
             if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu APAGADA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
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
        case 50001:
            if (ch == 'e' || ch == 'E'){ //... ACENDA LAMPADA  (ACENDA)
                s = 50002;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 50002:
            if (ch == 'n' || ch == 'N'){ //... ACENDA (ACENDA)
                s = 50003;
                buffer[j++] = ch;
                break;
            }
            if (ch == 's' || ch == 's'){ //... ACESA
                s = 500003;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 50003:
            if (ch == 'd' || ch == 'D'){ //... ACENDA LAMPADA  (ACENDA)
                s = 50004;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 50004:
            if (ch == 'a' || ch == 'A'){ //... ACENDA LAMPADA  (ACENDA)
                s = 50005;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 50005:
             if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu acenda lampada!!!!!!
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
        case 500003:
            if (ch == 'a' || ch == 'A'){ //... ACESA
                s = 500004;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 500004:
             if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu ACESA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "CONDICAO";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            break;
        break;
        case 5051:
            if (ch == 'a' || ch == 'A'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5052;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5052:
            if (ch == 'm' || ch == 'M'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5053;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5053:
            if (ch == 'p' || ch == 'P'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5054;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5054:
            if (ch == 'a' || ch == 'A'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5055;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5055:
            if (ch == 'd' || ch == 'D'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5056;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5056:
            if (ch == 'a' || ch == 'A'){ //... APAGUE|ACENDA LAMPADA  (LAMPADA)
                s = 5057;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) || ch == ' ' || ch == '\n' || ch == '\r' ){ // verificando se houve erro na digitacao de ROBO PRONTO
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5057:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu APAGUE|ACENDA LAMPADA!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "LAMPADA";
                token.nome = buffer;
                return token;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57)){ // verificando se houve erro ao digitar VIRE PARA
                s = 501;
                buffer[j++] = ch;
                break;
            }
            break;
        case 801:
            if (ch == 'e' || ch == 'E'){ //EX*E*CUCAOINICIO
                s = 802;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 802:
            if (ch == 'c' || ch == 'C'){ //EXECUCAOINICIO
                s = 803;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 803:
            if (ch == 'u' || ch == 'U'){ //EXECUCAOINICIO
                s = 804;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 804:
            if (ch == 'c' || ch == 'C'){ //EXECUCAOINICIO
                s = 805;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 805:
            if (ch == 'a' || ch == 'A'){ //EXECUCAOINICIO
                s = 806;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 806:
            if (ch == 'o' || ch == 'O'){ //EXECUCAOINICIO
                s = 807;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 807:
            if (ch == 'i' || ch == 'I'){ //EXECUCAO*I*NICIO
                s = 808;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 808:
            if (ch == 'n' || ch == 'N'){ //EXECUCAOINICIO
                s = 809;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 809:
            if (ch == 'i' || ch == 'I'){ //EXECUCAOINICIO
                s = 810;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
   		case 810:
            if (ch == 'c' || ch == 'C'){ //EXECUCAOINICIO
                s = 811;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 811:
            if (ch == 'i' || ch == 'I'){ //EXECUCAOINICIO
                s = 812;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 812:
            if (ch == 'o' || ch == 'O'){ //EXECUCAOINICIO
                s = 813;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 813:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu PROGRAMAINICIO!!!!!!
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

        case 901:
            if (ch == 'x' || ch == 'X'){ //FIME*X*ECUCAO
                s = 902;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 902:
            if (ch == 'e' || ch == 'E'){ //FIMEXECUCAO
                s = 903;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 903:
            if (ch == 'c' || ch == 'C'){ //FIMEXECUCAO
                s = 904;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 904:
            if (ch == 'u' || ch == 'U'){ //FIMEXECUCAO
                s = 905;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 905:
            if (ch == 'c' || ch == 'C'){ //FIMEXECUCAO
                s = 906;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 906:
            if (ch == 'a' || ch == 'A'){ //FIMEXECUCAO
                s = 907;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 907:
            if (ch == 'o' || ch == 'O'){ //FIMEXECUCAO
                s = 908;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 908:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FIMEXECUCAO!!!!!!
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
        case 911:
            if (ch == 'o' || ch == 'O'){ //FIMPR*O*GRAMA
                s = 912;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 912:
            if (ch == 'g' || ch == 'G'){ //FIMPROGRAMA
                s = 913;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 913:
            if (ch == 'r' || ch == 'R'){ //FIMPROGRAMA
                s = 914;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 914:
            if (ch == 'a' || ch == 'A'){ //FIMPROGRAMA
                s = 915;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 915:
            if (ch == 'm' || ch == 'M'){ //FIMPROGRAMA
                s = 916;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 916:
            if (ch == 'a' || ch == 'A'){ //FIMPROGRAMA
                s = 917;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 917:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu FIMPROGRAMA!!!!!!
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
        case 6022:
            if (ch == 'a' || ch == 'A'){ //FIN*A*LIZE
                s = 6024;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6024:
            if (ch == 'l' || ch == 'L'){ //FINALIZE
                s = 6025;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6025:
            if (ch == 'i' || ch == 'I'){ //FINALIZE
                s = 6026;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6026:
            if (ch == 'z' || ch == 'Z'){ //FINALIZE
                s = 6027;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6027:
            if (ch == 'e' || ch == 'E'){ //FINALIZE
                s = 6028;
                buffer[j++] = ch;
                break;
            }
            else if( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <=57) ){ // verificando se é IDENTIFICADOR
                s = 500;
                buffer[j++] = ch;
                break;
            }
            else if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "ID";
                token.nome = buffer;
                return token;
            }
            break;
        case 6028:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu //FINALIZE!!!!!!
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
//-------------------------------------------------------------------------------------------------------------



       case 500:
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == EOF){ //reconheceu IDENTIFICADOR!!!!!!
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
                s = 501;
                buffer[j++] = ch;
                break;
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
