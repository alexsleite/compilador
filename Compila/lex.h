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

void closeFile(){
    fin.close();
}

tokenTipo getToken(){

    char buffer[40], ch;
    int s = 0, j=0;
    bool flag = true;
	while(!fin.eof()){
        ch = fin.get();
   		switch (s){
        case 0:
            if (ch == 'p' || ch == 'P'){ //comeca a identificar PROGRAMAINICIO
                s = 1;
                buffer[j++] = ch;
                break;
            }
            break;
        case 1:
            if (ch == 'r' || ch == 'R'){
                s = 2;
                buffer[j++] = ch;
                break;
            }
            break;
        case 2:
            if (ch == 'o' || ch == 'O'){
                s = 3;
                buffer[j++] = ch;
                break;
            }
            break;
        case 3:
            if (ch == 'g' || ch == 'G'){
                s = 4;
                buffer[j++] = ch;
                break;
            }
            break;
        case 4:
            if (ch == 'r' || ch == 'R'){
                s = 5;
                buffer[j++] = ch;
                break;
            }
            break;
        case 5:
            if (ch == 'a' || ch == 'A'){
                s = 6;
                buffer[j++] = ch;
                break;
            }
            break;
        case 6:
            if (ch == 'm' || ch == 'M'){
                s = 7;
                buffer[j++] = ch;
                break;
            }
            break;
        case 7:
            if (ch == 'a' || ch == 'A'){
                s = 8;
                buffer[j++] = ch;
                break;
            }
            break;
        case 8:
            if (ch == 'i' || ch == 'I'){
                s = 9;
                buffer[j++] = ch;
                break;
            }
            break;
        case 9:
            if (ch == 'n' || ch == 'N'){
                s = 10;
                buffer[j++] = ch;
                break;
            }
            break;
   		case 10:
            if (ch == 'i' || ch == 'I'){
                s = 11;
                buffer[j++] = ch;
                break;
            }
            break;
        case 11:
            if (ch == 'c' || ch == 'C'){
                s = 12;
                buffer[j++] = ch;
                break;
            }
            break;
        case 12:
            if (ch == 'i' || ch == 'I'){
                s = 13;
                buffer[j++] = ch;
                break;
            }
            break;
        case 13:
            if (ch == 'o' || ch == 'O'){
                s = 14;
                buffer[j++] = ch;
                break;
            }
            break;
        case 14:
            if (ch == ' ' || ch == '\n' || ch == '\r'){
                s = 999;
                buffer[j] = '\0';
                j=0;
                tokenTipo token;
                token.tipo = "programa";
                token.nome = buffer;
                return token;
            }
            break;
        case 999:
            flag = false;
            break;
   		default:
            tokenTipo token;
            token.tipo = "erro";
            token.nome= "transição nao existente";
            return token;
        }
	}

    tokenTipo token;

    return token;

}
