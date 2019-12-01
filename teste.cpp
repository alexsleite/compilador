#include <bits/stdc++.h>
using namespace std;

struct keyword{
string nome;
string tipo;
int linha;
};

struct instru_traducao{
string nome;
vector<string>traducao;
};

struct store{
string nome;
int line;
};

struct instru{
string id = "";
string inicio ="";
string fim = "";
};

struct precedencia{
string precede;
int linha;
};

void inv (stack<store> & guarda, stack<store> & inverte, vector<keyword> & tabela){
    while(guarda.size()>0) //se existem palavras que eram dependente desta
    {
        inverte.push(guarda.top());
        guarda.pop();
    }
    while(inverte.size()>0)
    {
        if(inverte.top().nome=="direita"||inverte.top().nome=="esquerda"){ //se for esquerda ou direita, vira palavra chave
            keyword g;
            g.nome = inverte.top().nome;
            g.tipo = "Sentido";
            g.linha = inverte.top().line;
            tabela.push_back(g);
            inverte.pop();
        }
        else{
            keyword g;
            g.nome = inverte.top().nome;
            g.tipo = "ID";
            g.linha = inverte.top().line;
            tabela.push_back(g);
            inverte.pop();
            }
    }
}

int main () {

  vector<char>buffer;
  keyword aux;
  char first=' ';         //guarda o primeiro caracter de cada palavra
  int ascll_first;        //para determinar se o caracter é um numero ou letra
  vector<keyword>reserved_words;  //guarda palavras chave
  vector<keyword>tabela;
  stack<store>guarda; //guarda combinações de palavras chave
  stack<store>inverte;
  int estado =0;

  //============PALAVRAS CHAVE======================================================

  aux.nome = "programainicio", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "fimprograma", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "execucaoinicio", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "fimexecucao", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "definainstrucao", aux.tipo = "Declaracao", reserved_words.push_back(aux);
  aux.nome = "como", aux.tipo = "Declaracao", reserved_words.push_back(aux);
  aux.nome = "inicio", aux.tipo = "Bloco", reserved_words.push_back(aux);
  aux.nome = "fim", aux.tipo = "Declaracao", reserved_words.push_back(aux);
  aux.nome = "repita", aux.tipo = "Iteracao", reserved_words.push_back(aux);
  aux.nome = "fimrepita", aux.tipo = "Iteracao", reserved_words.push_back(aux);
  aux.nome = "vezes", aux.tipo = "Iteracao", reserved_words.push_back(aux);
  aux.nome = "enquanto", aux.tipo = "Laco", reserved_words.push_back(aux);
  aux.nome = "faca", aux.tipo = "Laco", reserved_words.push_back(aux);
  aux.nome = "fimpara", aux.tipo = "Laco", reserved_words.push_back(aux);
  aux.nome = "se", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "fimse", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "entao", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "senao", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "fimsenao", aux.tipo = "Condicional", reserved_words.push_back(aux);
  aux.nome = "mova", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "passos", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "vire para", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "pare", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "finalize", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "apague lampada", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "acenda lampada", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "aguarde ate", aux.tipo = "Instrucao", reserved_words.push_back(aux);
  aux.nome = "robo pronto", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "robo ocupado", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "robo parado", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "robo movimentando", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "frente robo bloqueada", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "direita robo bloqueada", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "esquerda robo bloqueada", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada acesa a frente", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada apagada a frente", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada acesa a esquerda", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada apagada a esquerda", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada acesa a direita", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "lampada apagada a direita", aux.tipo = "Condicao", reserved_words.push_back(aux);
  aux.nome = "esquerda", aux.tipo = "Sentido", reserved_words.push_back(aux);
  aux.nome = "direita", aux.tipo = "Sentido", reserved_words.push_back(aux);

  //================================================================================

  int lin = 1, col=0;
    char c;           //para ler caracter por caracter do arquivo
    string aux_palavra = ""; //gera palavra
    string sugere = ""; //IA
    ifstream myfile("example.txt");//("example.txt");

     if(myfile.is_open()){ //guarda todos os caracteres do arquivo no buffer
        myfile.get(c);
        while (!myfile.eof()){
            buffer.push_back(c);
            myfile.get(c);
            }
     }
   cout<<"-----------------"<<endl;
   cout<<"--ERROS LEXICOS--"<<endl;
   cout<<"-----------------"<<endl;
   bool coment = 0;
   bool error = 0;
   for(int k =0;k<buffer.size();k++){
      int ascll = buffer[k];
      if(ascll>=65&&ascll<=90){//maiusculo{
        ascll = ascll + 32; //converte
        buffer[k]=buffer[k]+32;
      }
      if(ascll==35){//comentario
         coment=1;
      }
      if(ascll!=9) //tabulação
      {
        if(coment!=1)
        {
            if(buffer[k]!=' '&&((ascll>=97&&ascll<=122)||(ascll>=48&&ascll<=57))) // buffer[k] é uma letra ou numero válido (tabela ascll)
            {
                if(first==' ') //se não salvei nada no primeiro caracter ainda
                {
                    ascll_first = buffer[k]; //vejo se é numero ou letra
                    first = buffer[k]; //salvo
                    aux_palavra = aux_palavra + buffer[k]; //armazena na palavra a ser gerada
                    sugere = sugere + buffer[k];
                }
                else if(first!=' '&&(ascll_first>=97&&ascll_first<=122)){ // first é uma letra, logo todo char valido continua valido
                    aux_palavra  = aux_palavra +buffer[k]; //armazena na palavra a ser gerada
                    sugere = sugere + buffer[k];
                }
                else if(first!=' '&&((ascll_first>=48&&ascll_first<=57)&&(ascll>=48&&ascll<=57))){// first é um numero, portanto c deve ser um numero
                    aux_palavra  = aux_palavra +buffer[k]; //armazena na palavra a ser gerada
                    sugere = sugere + buffer[k];
                }
                else{
                    aux_palavra  = aux_palavra + buffer[k]; // começou como numero e incluiu caracter
                    error = 1;
                }
            }
            else if(buffer[k]!=' '&&(ascll>122||(ascll<97&&ascll>57)||ascll<48) && ascll!=10)//caracter invalido (10 = fim da linha)
            {
                 aux_palavra = aux_palavra + buffer[k];
                 error = 1;
            }
        }
      }
        if(buffer[k]==' '||buffer[k]=='\n'|| k == buffer.size()-1){//possivel palavra encontrada
            bool achou = 0;
            if(buffer[k]=='\n'&&aux_palavra.size()==0){
                 coment=0;
                 if(col>0) //se achou pelo menos alguma palavra
                 {
                     lin++;
                     col=0;
                 }
            }
            if(aux_palavra.size()>0)//se foi gerada uma palavra
            {
                if(buffer[k]==' '&&error==0)
                    col++;
                if(error==1){//se palavra for invalida
                        if(buffer[k]==' '){
                            col++;
                            inv (guarda,inverte,tabela);
                            cout<<"Palavra invalida na linha: "<<lin<<", coluna: "<<col<<", Voce quis dizer "<<sugere<<"?"<<endl;
                            estado=0;
                            aux_palavra ="";
                            sugere ="";
                            first=' ';
                            achou=1;
                            error = 0;
                        }
                        else{
                            col++;
                            inv (guarda,inverte,tabela);
                            cout<<"Palavra invalida na linha: "<<lin<<", coluna: "<<col<<", Voce quis dizer "<<sugere<<"?"<<endl;
                            lin++;
                            col=0;
                            estado=0;
                            aux_palavra ="";
                            sugere ="";
                            first=' ';
                            achou=1;
                            error = 0;
                            coment=0;
                        }

                }
                else // é valida
                {

                    if (ascll_first>=48&&ascll_first<=57)//eh um numero
                    {
                        inv (guarda,inverte,tabela);
                        //cout<<aux_palavra<<" Numero"<<endl;
                        keyword g;
                        g.nome = aux_palavra;
                        g.tipo = "Numero";
                        g.linha = lin;
                        tabela.push_back(g);
                        achou=1;
                        aux_palavra ="";
                        sugere="";
                        first=' ';
                        error = 0;
                        estado=0;
                    }
                    else //eh uma palavra
                    {
                        for(vector<keyword>::iterator it=reserved_words.begin();it!=reserved_words.end();it++){ // busca na lista de palavras reservadas
                            if(aux_palavra==(*it).nome && aux_palavra!= "esquerda" && aux_palavra !="direita"){ //Achei uma palavra (esquerda/direita causa conflito)

                                inv (guarda,inverte,tabela);
                               // cout<<(*it).nome<<"  "<<(*it).tipo<<endl;
                                keyword g;
                                g.nome = (*it).nome;
                                g.tipo = (*it).tipo;
                                g.linha = lin;
                                tabela.push_back(g);
                                //vou para próxima palavra
                                achou=1;
                                aux_palavra ="";
                                sugere = "";
                                first=' ';
                                error = 0;
                                estado =0;
                                break;
                            }
                        }
                    }
               }

            if(achou!=1&&error==0) //se não é uma palavra reservada nem há erro, pode ser parte de uma palavra reservada ou um id.
            {

              bool retorna=1;
              while(retorna==1){
                   if(estado==0 && (buffer[k]==' '||(buffer[k]=='\n'&&k<buffer.size()-1))&& (aux_palavra=="lampada"||aux_palavra=="robo"||aux_palavra=="esquerda"||aux_palavra=="direita"||aux_palavra=="frente"||
                   aux_palavra=="acenda"||aux_palavra=="apague"||aux_palavra=="vire"||aux_palavra=="aguarde")) //possiveis inicios de palavras chave
                    {
                        store a;
                        a.nome = aux_palavra;
                        a.line = lin;
                        guarda.push(a); //coloca na fila
                        estado++; //avança estado
                        retorna=0; // solicito uma nova palavra
                    }

                    else if((estado==0 &&k==buffer.size()-1)|| (estado==0&&(aux_palavra!="lampada"&&aux_palavra!="robo"&&aux_palavra!="esquerda"&&aux_palavra!="direita"&&aux_palavra!="frente"&&
                    aux_palavra!="acenda"&&aux_palavra!="apague"&&aux_palavra!="vire"&&aux_palavra!="aguarde" )))
                    { //nova palavra retornada não gera combinações
                        if(aux_palavra=="esquerda"||aux_palavra=="direita"){
                            keyword g;
                            g.nome = aux_palavra;
                            g.tipo = "Sentido";
                            g.linha = lin;
                            tabela.push_back(g);
                            //cout<<aux_palavra<<" Sentido"<<endl;
                        }
                        else{
                            keyword g;
                            g.nome = aux_palavra;
                            g.tipo = "ID";
                            g.linha = lin;
                            tabela.push_back(g);
                            //cout<<aux_palavra<<"  ID"<<endl;
                        }
                        retorna=0;
                        estado=0;
                    }

                    else if(estado==1&&(aux_palavra=="apagada"||aux_palavra=="acesa"||aux_palavra=="robo"||aux_palavra=="movimentando"||aux_palavra=="parado"
                        ||aux_palavra=="ocupado"||aux_palavra=="pronto"||aux_palavra=="ate"||aux_palavra=="lampada"||aux_palavra=="para"))
                    {
                          if(guarda.top().nome=="lampada")
                          {
                              if(aux_palavra=="acesa"||aux_palavra=="apagada")
                              {
                                  if(k<buffer.size()-1){ //da para continuar
                                    store a;
                                    a.nome = aux_palavra;
                                    a.line = lin;
                                    guarda.push(a); //coloca na fila
                                    estado++;
                                    retorna=0;
                                  }
                                  else{ //não é possivel combinar
                                    store a;
                                    a.nome = aux_palavra;
                                    a.line = lin;
                                    guarda.push(a); //coloca na fila
                                    inv (guarda,inverte,tabela);
                                    estado=0;
                                    retorna=0;
                                  }
                              }
                              else//lampada eh id, mas aux_palavra pode ser o começo de uma nova sequencia
                              {
                                 //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = aux_palavra;
                                  g.tipo = "ID";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra para aux_palavra
                              }
                          }

                          else if(guarda.top().nome=="robo")
                          {
                              if(aux_palavra=="pronto"||aux_palavra=="parado"||aux_palavra=="ocupado") //eh uma palavra reservada
                              {

                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Condicao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome+' '+aux_palavra;
                                  g.tipo = "Condicao";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else// robo eh id
                              {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome;
                                  g.tipo = "ID";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }

                          else if(guarda.top().nome=="acenda"||guarda.top().nome=="apague")
                          {
                              if(aux_palavra=="lampada")
                              {
                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome+' '+aux_palavra;
                                  g.tipo = "Instrucao";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else
                              {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome;
                                  g.tipo = "ID";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }
                          else if(guarda.top().nome=="vire")
                          {
                               if(aux_palavra=="para")
                              {
                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome+' '+aux_palavra;
                                  g.tipo = "Instrucao";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else
                              {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome;
                                  g.tipo = "ID";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }

                          else if(guarda.top().nome=="aguarde")
                          {
                             if(aux_palavra=="ate")
                             {
                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome+' '+aux_palavra;
                                  g.tipo = "Instrucao";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                             }
                             else
                             {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top().nome;
                                  g.tipo = "ID";
                                  g.linha = lin;
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                             }
                           }
                          else if(guarda.top().nome=="esquerda"||guarda.top().nome=="direita"||guarda.top().nome=="frente")
                          {
                               if(aux_palavra=="robo")
                              {

                                 if(k<buffer.size()-1){ //da para continuar
                                    store a;
                                    a.nome = aux_palavra;
                                    a.line = lin;
                                    guarda.push(a); //coloca na fila
                                    estado++;
                                    retorna=0;
                                  }
                                  else{  //não da para alocar outra palavra na sequencia
                                      store a;
                                      a.nome = aux_palavra;
                                      a.line = lin;
                                      guarda.push(a); //coloca na fila
                                      inv (guarda,inverte,tabela); //desempilha
                                      estado=0;
                                      retorna=0;
                                  }
                              }
                              else // guarda.top é sentido ou id
                              {
                                   if(guarda.top().nome=="direita"||guarda.top().nome=="esquerda"){ //se for esquerda ou direita, vira palavra chave
                                        keyword g;
                                        g.nome = guarda.top().nome;
                                        g.tipo = "Sentido";
                                        g.linha = lin;
                                        tabela.push_back(g);
                                        //cout<<guarda.top()<<"  Sentido"<<endl;
                                        guarda.pop();
                                    }
                                    else{
                                        keyword g;
                                        g.nome = guarda.top().nome;
                                        g.tipo = "ID";
                                        g.linha = lin;
                                        tabela.push_back(g);
                                        //cout<<guarda.top()<<"  ID"<<endl;
                                        guarda.pop();
                                    }
                                   estado--; //volta 1 estado
                                   retorna=1; //nova possivel palavra
                              }
                         }
                }

                else if(estado==2&&(aux_palavra=="a"||aux_palavra=="bloqueada"))
                {
                    if(guarda.top().nome=="robo"){
                        if(aux_palavra=="bloqueada") //palavra chave formada
                        {
                              string forma = "";
                              while(guarda.size()>0)
                              {
                                 inverte.push(guarda.top());
                                 guarda.pop();
                              }
                              while(inverte.size()>0)
                              {
                                 forma = forma+inverte.top().nome+' '; //concatena
                                 inverte.pop();
                              }
                               //cout<<forma<<" Condicao"<<endl;
                               keyword g;
                               g.nome = forma+aux_palavra;
                               g.tipo = "Condicao";
                               g.linha = lin;
                               tabela.push_back(g);
                               retorna=0; //combinação completa
                               estado=0; // solicita novo token
                         }
                         else//cadeia não combina - entrada 'a'
                              {
                                  store a;
                                  a.nome = aux_palavra;
                                  a.line = lin;
                                  guarda.push(a); //coloca na fila
                                  inv (guarda,inverte,tabela);
                                  estado=0;  //novo token
                                  retorna=0; //solicita nova palavra
                              }
                        }

                        else if(guarda.top().nome=="acesa"||guarda.top().nome=="apagada")
                        {
                              if(aux_palavra=="a")
                              {

                                    if(k<buffer.size()-1){ //da para continuar
                                    store a;
                                    a.nome = aux_palavra;
                                    a.line = lin;
                                    guarda.push(a); //coloca na fila
                                    estado++;
                                    retorna=0;
                                    }
                                    else //não combina
                                    {
                                        store a;
                                        a.nome = aux_palavra;
                                        a.line = lin;
                                        guarda.push(a); //coloca na fila
                                        inv (guarda,inverte,tabela);
                                        estado=0; //novo token
                                        retorna=0; //solicita nova palavra
                                    }
                              }
                              else//não combina
                              {
                                  store a;
                                  a.nome = aux_palavra;
                                  a.line = lin;
                                  guarda.push(a); //coloca na fila
                                  inv (guarda,inverte,tabela);
                                  estado=0;  //novo token
                                  retorna=0; //solicita nova palavra
                              }
                      }

                }
                 else if(estado==3&&(aux_palavra=="direita"||aux_palavra=="esquerda"||aux_palavra=="frente")) //só tem uma forma de chegar aqui
                 {
                                   while(guarda.size()>0)
                                    {
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                    }
                                    string forma = "";
                                    while(inverte.size()>0)
                                    {
                                            forma = forma+inverte.top().nome+' ';
                                            inverte.pop();
                                    }
                                    //cout<<forma<<"  Condicao"<<endl;
                                    keyword g;
                                    g.nome = forma+aux_palavra;
                                    g.tipo = "Condicao";
                                    g.linha = lin;
                                    tabela.push_back(g);
                            retorna=0; //novo token
                            estado=0; // solicita nova palavra
                 }
                else{
                    if(estado==0){ //id
                        if(aux_palavra!="esquerda"&&aux_palavra!="direita")
                        {
                            //cout<<aux_palavra<<" ID"<<endl;
                            keyword g;
                            g.nome = aux_palavra;
                            g.tipo = "ID";
                            g.linha = lin;
                            tabela.push_back(g);
                        }
                        else{
                            //cout<<aux_palavra<<" Sentido"<<endl;
                            keyword g;
                            g.nome = aux_palavra;
                            g.tipo = "Sentido";
                            g.linha = lin;
                            tabela.push_back(g);
                        }
                        estado=0;
                        retorna=0;
                    }
                    else{ //não faz combinação

                        estado--;  //retorna 1 estado
                        retorna=1; //tentar nova combinação
                            while(guarda.size()>0){
                                inverte.push(guarda.top());
                                guarda.pop();
                            }
                            if(inverte.size()>0)
                            {
                                if(inverte.top().nome!="esquerda"&&inverte.top().nome!="direita")
                                {
                                    //cout<<inverte.top()<<" ID"<<endl;
                                    keyword g;
                                    g.nome = inverte.top().nome;
                                    g.tipo = "ID";
                                    g.linha = lin;
                                    tabela.push_back(g);
                                    inverte.pop();
                                }
                                else{
                                    //cout<<inverte.top()<<" Sentido"<<endl;
                                    keyword g;
                                    g.nome = inverte.top().nome;
                                    g.tipo = "Sentido";
                                    g.linha = lin;
                                    tabela.push_back(g);
                                    inverte.pop();
                                }
                            }
                            while(inverte.size()>0){ //guarda o que sobrou para a proxima tentativa de combinação
                              guarda.push(inverte.top());
                              inverte.pop();
                            }

                        }
                    }
              }

                aux_palavra ="";
                sugere ="";
                first=' ';
                error = 0;
            }
              if(buffer[k]=='\n'&&error==0)
              {
                col=0;
                lin++;
                coment=0;
              }
         }
         else if(k==buffer.size()-1){ //arquivo terminou com tokens na pila;
                inv(guarda,inverte,tabela);
         }
      }
    }
    cout<<endl;
    cout<<"------------------"<<endl;
    cout<<"--TOKENS GERADOS--"<<endl;
    cout<<"------------------"<<endl;
    for(int i =0;i<tabela.size();i++){
        cout<<"Lexema : "<<tabela[i].nome<<" | Tipo: "<<tabela[i].tipo<<endl;
    }

    //----------------------------------------------------------//
    ////////////////////ANALISADOR SINTATICO//////////////////////
    //----------------------------------------------------------//
   cout<<endl;
   cout<<"--------------------"<<endl;
   cout<<"--ERROS SINTATICOS--"<<endl;
   cout<<"--------------------"<<endl;
   stack<keyword>save;
   stack<keyword>base;
   vector<keyword>producoes;
   int duplicidade = 0;
   vector<string>ids_criados;
   vector<instru>guarda_ids;
   instru id_instru;
   int state = 0;
   int cont_comando = 0;
   bool erro_sitantico = 0;
   bool execut = false;
    for(int i =0;i<tabela.size();i++){
        int retorna=1;
        while(retorna==1)
        {
            if(state==0 && tabela[i].nome=="programainicio")
            {
                state++;
                save.push(tabela[i]);
                retorna=0;
            }
             else if(state==0){
                cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                retorna=0;
                i=tabela.size();
                erro_sitantico=1;
            }

            else if(state==1 && (tabela[i].nome=="definainstrucao" || tabela[i].nome == "execucaoinicio"))
            {

                if(tabela[i].nome=="definainstrucao") //cria nova instrução
                {
                    producoes.push_back(tabela[i]);
                    state=100;
                    save.push(tabela[i]);
                    retorna=0;
                }
                else                                //executa instrução
                {
                    producoes.push_back(tabela[i]);
                    state++;
                    execut=true;
                    save.push(tabela[i]);
                    retorna=0;
                }

            }
             else if(state==1){
                cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                retorna=0;
                i=tabela.size();
            }

            else if(state==2 && (tabela[i].tipo=="ID"|| tabela[i].nome=="repita"||tabela[i].nome=="se"||tabela[i].nome=="mova"||tabela[i].nome=="enquanto"
                            ||tabela[i].nome=="inicio"||tabela[i].nome=="vire para"||tabela[i].nome=="pare"||tabela[i].nome=="finalize"||tabela[i].nome=="apague lampada"
                            ||tabela[i].nome=="acenda lampada"||tabela[i].nome=="aguarde ate"||tabela[i].nome=="fimexecucao"||tabela[i].nome=="execucaoinicio"
                            ||tabela[i].nome=="definainstrucao")) //solicita comandos
            {
                    if(tabela[i].tipo=="ID")//ID pode ser um comando definido
                    {

                        int x = 0;
                        for(vector<string>::iterator it = ids_criados.begin();it!=ids_criados.end();it++) //verifica se o Id ja foi definido como instrucao
                        {
                            if(tabela[i].nome == (*it))//comando existe
                            {
                                producoes.push_back(tabela[i]);
                                if(execut==false){ //salva inicio e fim das instrucoes
                                    for(vector<instru>::iterator it3 = guarda_ids.begin();it3!=guarda_ids.end();it3++)
                                        {
                                            if((*it)==((*it3).id))
                                            {
                                                if(id_instru.inicio=="")
                                                    id_instru.inicio = (*it3).inicio;
                                                id_instru.fim=(*it3).fim;
                                                break;
                                            }
                                        }
                                }
                                retorna=0;
                                cont_comando++;
                                x = 1;
                                break;
                                // não salva, pois o comando está completo
                                // não avança estado pois pode ler outro comando
                            }
                        }
                        if(x==0)
                        {
                            cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                            erro_sitantico=1;
                            retorna=0;
                            i=tabela.size();
                        }
                    }
                    else if(tabela[i].nome=="pare"||tabela[i].nome=="finalize"||tabela[i].nome=="acenda lampada"||tabela[i].nome=="apague lampada")
                    {
                         if(execut==false){
                            if(id_instru.inicio=="")
                                id_instru.inicio=tabela[i].nome;
                            id_instru.fim = tabela[i].nome;
                         }
                         retorna=0;
                         producoes.push_back(tabela[i]);
                         if(execut==true) //garante que tenha pelo menos 1 instrução na execução
                            cont_comando++;
                        // não salva, pois o comando está completo
                        // não avança estado pois pode ler outro comando
                    }
                    else if(tabela[i].nome=="repita"||tabela[i].nome=="se"||tabela[i].nome=="mova"||tabela[i].nome=="enquanto"||tabela[i].nome=="vire para"
                            ||tabela[i].nome=="aguarde ate")
                    {
                        state++;
                        if(execut==true)
                            cont_comando++;
                        retorna=0;
                        save.push(tabela[i]);
                    }
                    else if(tabela[i].nome=="inicio")
                    {
                        if(execut==true)
                            cont_comando++;
                        retorna=0;
                        save.push(tabela[i]);
                        //mantem o estado, solicitando comando
                    }
                    else if(tabela[i].nome=="fimexecucao"&&cont_comando>0&&save.top().nome=="execucaoinicio")
                    {
                        save.pop();
                        retorna=0;
                        state=1000;
                    }
                    else if(tabela[i].nome=="execucaoinicio") //nesse caso houve uma ou mais deinições de instruções
                    {
                        producoes.push_back(tabela[i]);
                        guarda_ids.push_back(id_instru);
                        id_instru.id ="";
                        id_instru.inicio="";
                        id_instru.fim="";
                        if(save.top().nome=="como")
                        {
                            while(save.top().nome!="programainicio"){ //processa todas as instruções criadas
                                save.pop();
                            }
                            retorna=0;
                            execut=true;
                            save.push(tabela[i]);
                        }
                        else{
                            cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                            erro_sitantico=1;
                            retorna=0;
                            i =  tabela.size()-1;
                        }
                    }
                    else if(tabela[i].nome=="definainstrucao")//definindo mais de uma instrucao
                    {
                        if(save.top().nome=="como") //vem depois de uma definição, logo é valida
                        {
                            guarda_ids.push_back(id_instru);
                            id_instru.id ="";
                            id_instru.inicio="";
                            id_instru.fim="";
                            producoes.push_back(tabela[i]);
                            state=100;
                            retorna=0;
                            while(save.top().nome!="programainicio")//processa todas as instruções anteriores
                                save.pop();
                             save.push(tabela[i]); //inicia nova defiçao
                        }
                        else
                        {
                            cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl; //vem depois de um argumento invalido;
                            retorna=0;
                            i =  tabela.size();
                            erro_sitantico=1;
                        }
                    }
                    else  //loop não foi finalizado
                    {
                        cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                        erro_sitantico=1;
                        retorna=0;
                        i=tabela.size();
                    }
           }
            else if(state==2 && tabela[i].nome=="fimrepita"||tabela[i].nome=="fimpara"||tabela[i].nome=="fim"||tabela[i].nome=="fimse"
                    ||tabela[i].nome=="fimsenao") //finaliza comandos
            {
                if(tabela[i].nome=="fimrepita"&&save.top().nome=="vezes") //loop repita
                {
                    /////////////////////////////// para verificacao semantica em loops
                    keyword a;
                    a.nome = tabela[i].nome;
                    a.linha = tabela[i].linha;
                    a.tipo = tabela[i].tipo;
                    producoes.push_back(a);
                    ////////////////////////////////
                    save.pop();
                    save.pop();
                    save.pop();
                    retorna=0;
                }
                else if(tabela[i].nome=="fimpara"&&save.top().nome=="faca")  //loop enquanto
                {
                    /////////////////////////////// para verificacao semantica em loops
                    keyword a;
                    a.nome = tabela[i].nome;
                    a.linha = tabela[i].linha;
                    a.tipo = tabela[i].tipo;
                    producoes.push_back(a);
                    ////////////////////////////////
                    save.pop();
                    save.pop();
                    save.pop();
                    retorna=0;
                }
                else if(tabela[i].nome=="fim"&&save.top().nome=="inicio")   //loop inicio
                {
                    save.pop();
                    retorna=0;
                }
                else if(tabela[i].nome=="fimse"&&save.top().nome=="entao")  //loop se
                {
                    keyword a;
                    a.nome = tabela[i].nome;
                    a.linha = tabela[i].linha;
                    a.tipo = tabela[i].tipo;
                    producoes.push_back(a);

                    if(i<tabela.size()-1&&tabela[i+1].nome=="senao") //se existe um proximo elemento e ele é senao
                    {
                        keyword a;
                        a.nome = tabela[i+1].nome;
                        a.linha = tabela[i+1].linha;
                        a.tipo = tabela[i+1].tipo;
                        producoes.push_back(a);
                        ////////////////////////////
                        state=3001;
                        save.pop();
                        save.pop();
                        save.pop();
                        retorna=0;
                    }
                    else
                    {
                        save.pop();
                        save.pop();
                        save.pop();
                        retorna=0;
                    }
                }
                else if(tabela[i].nome=="fimsenao"&&save.top().nome=="senao")
                {
                    keyword a;
                    a.nome = tabela[i].nome;
                    a.linha = tabela[i].linha;
                    a.tipo = tabela[i].tipo;
                    producoes.push_back(a);
                    ////////////////////////////
                    save.pop();
                    retorna=0;
                }
                else //tentativa falha para finalização de loop
                {
                    cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                    retorna=0;
                    erro_sitantico=1;
                    i=tabela.size();
                }
            }
            else if(state==2){ //comando invalido
               cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
               erro_sitantico=1;
               retorna=0;
               i=tabela.size();
            }

            else if(state==3 && (tabela[i].tipo=="Sentido" ||tabela[i].tipo=="Numero"||tabela[i].tipo=="Condicao"))
            {
                if(tabela[i].tipo=="Sentido") //chegou através de vire para?
                {
                    if(save.top().nome=="vire para")
                    {
                        keyword a;
                        a.nome = save.top().nome+ ' ' + tabela[i].nome;
                        a.linha = save.top().linha;
                        a.tipo = save.top().tipo;
                        producoes.push_back(a);
                        if(execut==false){
                            if(id_instru.inicio=="")
                                id_instru.inicio=a.nome;
                            id_instru.fim = a.nome;
                        }
                        save.pop(); //comando completo
                        state--;   //verifica se há outro comando
                        retorna = 0;
                    }
                    else
                    {
                         cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                         erro_sitantico=1;
                         retorna=0;
                         i=tabela.size();
                    }
                }

                else if(tabela[i].tipo=="Numero")
                {
                    if(save.top().nome=="repita")
                    {
                        /////////////////////////////////////////////// caso precise tratar semantica em loops
                        keyword a;
                        a.nome = save.top().nome;
                        a.linha = save.top().linha;
                        a.tipo = save.top().tipo;
                        producoes.push_back(a);
                        ///////////////////////////////////////////////
                        state++;
                        retorna=0;
                        save.push(tabela[i]);
                    }
                    else if(save.top().nome=="mova")
                    {

                        keyword a;
                        a.nome = save.top().nome;
                        a.linha = save.top().linha;
                        a.tipo = save.top().tipo;
                        producoes.push_back(a);

                        state=2000;
                        retorna=0;
                        save.push(tabela[i]);
                    }
                    else
                    {
                         cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                         retorna=0;
                         i=tabela.size();
                         erro_sitantico=1;
                    }
                }

                else if(tabela[i].tipo=="Condicao")
                {
                    if(save.top().nome=="enquanto")
                    {
                        //////////////////////////////////////////////// caso precise tratar semantica em loops
                        keyword a;
                        a.nome = save.top().nome;
                        a.linha = save.top().linha;
                        a.tipo = save.top().tipo;
                        producoes.push_back(a);
                        a.nome = tabela[i].nome;
                        a.linha = tabela[i].linha;
                        a.tipo = tabela[i].tipo;
                        producoes.push_back(a);
                        ////////////////////////////////////////////////
                        state++;
                        retorna=0;
                        save.push(tabela[i]);
                    }
                    else if(save.top().nome=="se")
                    {
                        keyword a;
                        a.nome = save.top().nome;
                        a.linha = save.top().linha;
                        a.tipo = save.top().tipo;
                        producoes.push_back(a);
                        a.nome = tabela[i].nome;
                        a.linha = tabela[i].linha;
                        a.tipo = tabela[i].tipo;
                        producoes.push_back(a);
                        ////////////////////////////
                        state = 3000;
                        retorna=0;
                        save.push(tabela[i]);
                    }
                    else if(save.top().nome=="aguarde ate")
                    {
                        keyword a;
                        a.nome = save.top().nome+ ' ' + tabela[i].nome;
                        a.linha = save.top().linha;
                        a.tipo = save.top().tipo;
                        producoes.push_back(a);
                        if(execut==false){
                            if(id_instru.inicio=="")
                                id_instru.inicio=a.nome;
                            id_instru.fim = a.nome;
                        }
                        state--;
                        retorna=0;
                        save.pop();// producao aceita
                    }
                    else
                    {
                         cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                         retorna=0;
                         erro_sitantico=1;
                         i=tabela.size();
                    }
                }
            }
            else if(state==3)
            {
                if(save.top().nome=="inicio")
                {
                    if(tabela[i].nome=="fim")
                    {
                        state--;
                        save.pop();
                        retorna=0;
                    }
                    else
                    {
                       state--;
                       save.push(tabela[i]);
                       retorna=0;
                    }
                }

                else if(save.top().nome=="mova")
                {
                        producoes.push_back(save.top());
                        if(execut==false){
                            if(id_instru.inicio=="")
                                id_instru.inicio=save.top().nome;
                            id_instru.fim = save.top().nome;
                        }
                        retorna=1; //checa o token novamente
                        state--;
                        save.pop(); //aceita 'mova'
                }
                else{
                    cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                    retorna=0;
                    erro_sitantico=1;
                    i=tabela.size();
                }
            }

            else if(state==4 && (tabela[i].nome=="faca"||tabela[i].nome=="vezes"))
            {
                if(tabela[i].nome=="faca")
                {
                    if(save.top().tipo=="Condicao")
                    {
                        state=2; //solicita um comando
                        retorna=0;
                        save.push(tabela[i]);
                    }
                    else
                    {
                        cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                        retorna=0;
                        erro_sitantico=1;
                        i=tabela.size();
                    }
                }

                else if (tabela[i].nome=="vezes")
                {
                        if(save.top().tipo == "Numero")
                        {
                            keyword a;
                            a.nome = save.top().nome;
                            a.linha = save.top().linha;
                            a.tipo = save.top().tipo;
                            producoes.push_back(a);
                           /////////
                            state=2; //solicita um comando
                            retorna=0;
                            save.push(tabela[i]);
                        }
                        else
                        {
                            cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                            retorna=0;
                            erro_sitantico=1;
                            i=tabela.size();
                        }
                }
                else
                {
                    cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                    retorna=0;
                    erro_sitantico=1;
                    i=tabela.size();
                }
            }

            else if(state==1000)
            {
                if(tabela[i].nome=="fimprograma" && i == tabela.size()-1)
                {
                    cout<<"NENHUM ERRO! SINTATICAMENTE CORRETO"<<endl;
                    retorna=0;
                }
                else
                {
                     cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                     retorna=0;
                     erro_sitantico=1;
                     i=tabela.size();
                }
            }

            else if(state==2000)
            {
                keyword a;
                a.nome  = save.top().nome;
                a.linha  = save.top().linha;
                a.tipo  = save.top().tipo;
                producoes.push_back(a);

                if(tabela[i].nome=="passos")
                {
                    save.pop();
                    save.pop();
                    if(execut==false){
                        if(id_instru.inicio=="")
                            id_instru.inicio=a.nome;
                        id_instru.fim = a.nome;
                    }
                    retorna=0;
                    state=2; //aceita
                }
                else
                {
                    save.pop();
                    save.pop();
                    if(execut==false){
                        if(id_instru.inicio=="")
                            id_instru.inicio=a.nome;
                        id_instru.fim = a.nome;
                    }
                    retorna=1; //repete verificação do token
                    state=2; //aceita
                }
            }
            else if(state == 3000) //implementar se
            {
                if(tabela[i].nome=="entao")
                {
                    state=2;
                    retorna=0;
                    save.push(tabela[i]);
                }
                else
                {
                     cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                     retorna=0;
                     erro_sitantico=1;
                     i=tabela.size();
                }
            }
            else if(state==3001) //senao
            {
                save.push(tabela[i]);
                state=2; //solicita comando
                retorna=0;
            }
            else if(state==100)
            {
                if(tabela[i].tipo == "ID")
                {
                    //verifico se já criei esse ID anterioremente para evitar duplicidade (semantico)
                     for(vector<string>::iterator it = ids_criados.begin();it!=ids_criados.end();it++)
                     {
                        if(tabela[i].nome == (*it))//comando já existe / conflito.
                        {
                            // cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                             retorna=0;
                             i=tabela.size()-1;
                             if(duplicidade == 0) //pega a primmeira ocorrencia
                                duplicidade = tabela[i].linha;
                             break;
                             // não salva, pois o comando está completo
                             // não avança estado pois pode ler outro comando
                        }
                    }
                        id_instru.id = tabela[i].nome;
                        ids_criados.push_back(tabela[i].nome); //crio o id
                        retorna=0;
                        state++;
                        save.push(tabela[i]);
                }
                else
                {
                     cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                     retorna=0;
                     erro_sitantico=1;
                     i=tabela.size();
                }

            }
             else if(state==101)
             {
                 if(tabela[i].nome=="como")
                 {
                     state=2; //busca comando
                     retorna=0;
                     save.push(tabela[i]);
                 }
                 else
                 {
                    cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                    retorna=0;
                    erro_sitantico=1;
                    i = tabela.size()-1;
                 }
             }
             else  //palavra não associada a um estado adequado
             {
                 cout<<"Erro Sintatico na linha "<<tabela[i].linha<<endl;
                 retorna=0;
                 erro_sitantico=1;
                 i = tabela.size()-1;
             }
        }
    }

   cout<<endl;
   cout<<"--------------------"<<endl;
   cout<<"--ERROS SEMANTICOS--"<<endl;
   cout<<"--------------------"<<endl;

   bool correct = 1;
   stack<int>loop;
   stack<string>warning;
  if(erro_sitantico==0){
   if(duplicidade!=0){
        cout<<"Erro Semantico por duplicidade de instrucoes, na linha "<<duplicidade<<endl;
        correct = 0;
   }
   else{
     int i = 0;
     while(i < producoes.size())
     {
          precedencia precede;
          precede.precede= "";
          precede.linha = 0;
         if(producoes[i].nome == "definainstrucao") //verifica se instrucao está ok
         {
            i++;
            if(i<producoes.size()-1 && (producoes[i].nome!="definainstrucao" && producoes[i].nome!="execucaoinicio")) //existe um comando
            {
                while(producoes[i].nome!="definainstrucao" &&  producoes[i].nome!="execucaoinicio")
                {
                              //      cout<<producoes[i].linha<<" :: "<<producoes[i].nome<<endl;
                    if(producoes[i].tipo != "Numero" &&producoes[i].tipo != "ID" && (producoes[i].nome != "repita" && producoes[i].nome != "enquanto"&& producoes[i].nome != "fimrepita"&& producoes[i].nome != "fimpara"
                                                     && producoes[i].nome != "se"&& producoes[i].nome != "fimse"&& producoes[i].nome != "senao"&& producoes[i].nome != "fimsenao"))//se esse comando não é um ID
                    {
                        if(precede.precede==""){
                             precede.precede = producoes[i].nome; //atualiza precedencia
                             precede.linha = producoes[i].linha;
                        }
                        else
                        {
                            if(precede.precede=="vire para esquerda" && producoes[i].nome=="vire para direita"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para esquerda seguido' de 'vire para direita'"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="vire para direita" && producoes[i].nome=="vire para esquerda"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para direita seguido' de 'vire para esquerda'"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="mova" && producoes[i].nome!= "aguarde ate robo pronto"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - Nao indicou 'robo pronto'"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else{
                                precede.precede = producoes[i].nome; //atualiza precedencia
                                precede.linha = producoes[i].linha;
                            }
                        }
                    }
                    else if(producoes[i].tipo=="ID" ) //eh ID
                    {
                        string aux_fim = "";
                        string aux_incio = "";
                        for(int b = 0;b<guarda_ids.size();b++)
                        {
                            if(producoes[i].nome==guarda_ids[b].id)
                            {
                                aux_fim = guarda_ids[b].fim;
                                aux_incio = guarda_ids[b].inicio;
                                break;
                            }
                        }
                        if( precede.precede==""){
                            precede.precede = aux_fim;
                            precede.linha = producoes[i].linha;
                        }
                        else
                        {
                            if(precede.precede=="vire para esquerda" &&  aux_incio == "vire para direita"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para esquerda seguido' de 'vire para direita' implicito em ID"<<endl;
                                 precede.precede = aux_fim;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="vire para direita" &&  aux_incio == "vire para esquerda"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para direita seguido' de 'vire para esquerda' implicito em ID"<<endl;
                                 precede.precede = aux_fim;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="mova" &&  aux_incio != "aguarde ate robo pronto"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - Nao indicou 'robo pronto' implicito em ID"<<endl;
                                 precede.precede = aux_fim;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else{
                                precede.precede = aux_fim; //atualiza precedencia
                                precede.linha = producoes[i].linha;
                            }
                        }
                    }
                    else if(producoes[i].tipo != "Numero" &&producoes[i].nome != "se"&& producoes[i].nome != "fimse"&& producoes[i].nome != "senao"&& producoes[i].nome != "fimsenao") // eh um loop
                    {
                        string warning_aux_primeiro = "";
                        string warning_aux_ultimo = "";
                        if(producoes[i].nome=="repita"||producoes[i].nome=="enquanto")
                        {
                            int salvo = i;
                            int cont_repita = 0;
                            while(producoes[i].nome=="repita"||producoes[i].nome=="enquanto"||producoes[i].nome=="fimrepita"||producoes[i].nome=="fimpara"){
                                 if(producoes[i].nome=="fimrepita"||producoes[i].nome=="fimpara")
                                    cont_repita--;
                                 else
                                    cont_repita++;
                                if(producoes[i].nome=="enquanto") //pula condicao
                                    i++;
                                 i++;
                            }
                                if(cont_repita>0){//achei primeira instrucao
                                     string aux_fim = "";
                                     string aux_inicio = "";
                                     if(producoes[i].tipo!="ID"){
                                        warning_aux_primeiro = producoes[i].nome;
                                     }
                                     else//tem que pegar o primeiro do id
                                     {
                                        for(int b = 0;b<guarda_ids.size();b++)
                                        {
                                            if(producoes[i].nome==guarda_ids[b].id)
                                            {
                                                aux_fim = guarda_ids[b].fim;
                                                aux_inicio = guarda_ids[b].inicio;
                                                break;
                                            }
                                        }
                                        warning_aux_primeiro = aux_inicio;
                                    }
                                     while(cont_repita>0)
                                     {
                                         i++;
                                          if(producoes[i].nome=="fimrepita"||producoes[i].nome=="fimpara")
                                            cont_repita--;
                                          else if(producoes[i].nome=="repita"||producoes[i].nome=="enquanto")
                                            cont_repita++;
                                          else
                                          {
                                               if(producoes[i].tipo!="ID"&&producoes[i].tipo!="Condicao")
                                                    warning_aux_ultimo= producoes[i].nome;
                                               else if(producoes[i].tipo!="Condicao")
                                               {
                                                   for(int b = 0;b<guarda_ids.size();b++)
                                                    {
                                                        if(producoes[i].nome==guarda_ids[b].id)
                                                        {
                                                        aux_fim = guarda_ids[b].fim;
                                                        aux_inicio = guarda_ids[b].inicio;
                                                        break;
                                                        }
                                                    }
                                                warning_aux_ultimo = aux_fim;
                                               }
                                          }
                                     }
                                     if(warning_aux_ultimo=="")
                                        warning_aux_ultimo=warning_aux_primeiro;//achei a ultima instrucao
                                }
                                i = salvo;
                                if(warning_aux_primeiro=="vire para esquerda" && warning_aux_ultimo=="vire para direita")
                                    cout<<"WARNING! NA LINHA "<<producoes[i].linha<<" - 'vire para esquerda seguido' de 'vire para direita' implicito em Loop"<<endl;

                                else if(warning_aux_primeiro=="vire para direita" && warning_aux_ultimo=="vire para esquerda")
                                    cout<<"WARNING! NA LINHA "<<producoes[i].linha<<" - 'vire para direita seguido' de 'vire para esquerda' implicito em Loop"<<endl;

                                else if(warning_aux_primeiro=="mova" && warning_aux_ultimo!= "aguarde ate robo pronto")
                                 cout<<"WARNING! NA LINHA "<<producoes[i].linha<<" - Nao indicou 'robo pronto' implicito em Loop"<<endl;
                            }
                        }
                        else if(producoes[i].nome=="se")
                            i++; //pula condicao
                    i++;
                }
            }
         }

         if(producoes[i].nome == "execucaoinicio") //verifica execucao
         {
             i++;
             while(i<producoes.size())
             {
                  if(producoes[i].tipo != "Numero" &&producoes[i].tipo != "ID" && (producoes[i].nome != "repita" && producoes[i].nome != "enquanto"&& producoes[i].nome != "fimrepita"&& producoes[i].nome != "fimpara"
                                                   && producoes[i].nome != "se"&& producoes[i].nome != "fimse"&& producoes[i].nome != "senao"&& producoes[i].nome != "fimsenao"))//se esse comando não é um ID
                  {
                        if(precede.precede==""){
                             precede.precede = producoes[i].nome; //atualiza precedencia
                             precede.linha = producoes[i].linha;
                        }
                        else
                        {
                             if(precede.precede=="vire para esquerda" && producoes[i].nome=="vire para direita"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para esquerda seguido' de 'vire para direita'"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="vire para direita" && producoes[i].nome=="vire para esquerda"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para direita seguido' de 'vire para esquerda'"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="mova" && producoes[i].nome!= "aguarde ate robo pronto"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - Nao indicou 'robo pronto'"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else{
                                precede.precede = producoes[i].nome; //atualiza precedencia
                                precede.linha = producoes[i].linha;
                            }
                        }
                    }
                     else if(producoes[i].tipo=="ID" ) //é id
                    {
                        string aux_fim = "";
                        string aux_incio = "";
                        for(int b = 0;b<guarda_ids.size();b++)
                        {
                            if(producoes[i].nome==guarda_ids[b].id)
                            {
                                aux_fim = guarda_ids[b].fim;
                                aux_incio = guarda_ids[b].inicio;
                                break;
                            }
                        }
                         if(precede.precede==""){
                            precede.precede = aux_fim;
                            precede.linha = producoes[i].linha;
                        }
                        else
                        {
                            if(precede.precede=="vire para esquerda" && producoes[i].nome=="vire para direita"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para esquerda seguido' de 'vire para direita' implicito em ID"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="vire para direita" && producoes[i].nome=="vire para esquerda"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - 'vire para direita seguido' de 'vire para esquerda' implicito em ID"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else if(precede.precede=="mova" && producoes[i].nome!= "aguarde ate robo pronto"){
                                 cout<<"ERRO SEMANTICO NA LINHA "<<precede.linha<<" - Nao indicou 'robo pronto' implicito em ID"<<endl;
                                 precede.precede = producoes[i].nome;
                                 precede.linha = producoes[i].linha;
                                 correct = 0;
                            }
                            else{
                                precede.precede = producoes[i].nome; //atualiza precedencia
                                precede.linha = producoes[i].linha;
                            }
                        }
                    }
                   else if(producoes[i].tipo != "Numero" &&producoes[i].nome != "se"&& producoes[i].nome != "fimse"&& producoes[i].nome != "senao"&& producoes[i].nome != "fimsenao") // eh um loop
                    {

                        string warning_aux_primeiro = "";
                        string warning_aux_ultimo = "";
                        if(producoes[i].nome=="repita"||producoes[i].nome=="enquanto")
                        {
                            int salvo = i;
                            int cont_repita = 0;
                            while(producoes[i].nome=="repita"||producoes[i].nome=="enquanto"||producoes[i].nome=="fimrepita"||producoes[i].nome=="fimpara"){
                                 if(producoes[i].nome=="fimrepita"||producoes[i].nome=="fimpara")
                                    cont_repita--;
                                 else
                                    cont_repita++;
                                 i++;
                            }
                                if(producoes[i].tipo=="Numero")
                                    i++; //pula num (reputa 'num')
                                if(cont_repita>0){//achei primeira instrucao
                                     string aux_fim = "";
                                     string aux_inicio = "";
                                     if(producoes[i].tipo!="ID")
                                        warning_aux_primeiro = producoes[i].nome;
                                     else //tem que pegar o primeiro do id
                                     {
                                        for(int b = 0;b<guarda_ids.size();b++)
                                        {
                                            if(producoes[i].nome==guarda_ids[b].id)
                                            {
                                                aux_fim = guarda_ids[b].fim;
                                                aux_inicio = guarda_ids[b].inicio;
                                                break;
                                            }
                                        }
                                        warning_aux_primeiro = aux_inicio;
                                        warning_aux_ultimo = aux_fim;
                                    }

                                     while(cont_repita>0)
                                     {
                                         i++;
                                          if(producoes[i].nome=="fimrepita"||producoes[i].nome=="fimpara")
                                            cont_repita--;
                                          else if(producoes[i].nome=="repita"||producoes[i].nome=="enquanto")
                                            cont_repita++;
                                          else
                                          {
                                               if(producoes[i].tipo!="ID")
                                                    warning_aux_ultimo = producoes[i].nome;
                                               else
                                               {
                                                   for(int b = 0;b<guarda_ids.size();b++)
                                                    {
                                                        if(producoes[i].nome==guarda_ids[b].id)
                                                        {
                                                        aux_fim = guarda_ids[b].fim;
                                                        aux_inicio = guarda_ids[b].inicio;
                                                        break;
                                                        }
                                                    }
                                                warning_aux_ultimo = aux_fim;
                                               }
                                          }
                                     }
                                     if(warning_aux_ultimo=="")
                                        warning_aux_ultimo=warning_aux_primeiro;//achei a ultima instrucao
                                }
                                i = salvo;
                                if(warning_aux_primeiro=="vire para esquerda" && warning_aux_ultimo=="vire para direita")
                                    cout<<"WARNING! NA LINHA "<<producoes[i].linha<<" - 'vire para esquerda seguido' de 'vire para direita' implicito em Loop"<<endl;

                                else if(warning_aux_primeiro=="vire para direita" && warning_aux_ultimo=="vire para esquerda")
                                    cout<<"WARNING! NA LINHA "<<producoes[i].linha<<" - 'vire para direita seguido' de 'vire para esquerda' implicito em Loop"<<endl;

                                else if(warning_aux_primeiro=="mova" && warning_aux_ultimo!= "aguarde ate robo pronto")
                                 cout<<"WARNING! NA LINHA "<<producoes[i].linha<<" - Nao indicou 'robo pronto' implicito em Loop"<<endl;
                            }
                        }
                    i++;
                }
             }

         }
         if(correct==1)
            cout<<"SEMANTICAMENTE CORRETO!"<<endl;

   }


   cout<<endl;
   cout<<"--------------------"<<endl;
   cout<<"--GERACAO DE CODIGO--"<<endl;
   cout<<"--------------------"<<endl;
  //for(int i =0;i<producoes.size();i++)// ((((PARA VERIFICAR AS PRODUCÕES DO VETOR))))
 // cout<<producoes[i].nome<<endl;
  stack<string>indice_loop;

   if(correct==1)//só gera o código se tiver tudo ok
   {
      vector<instru_traducao> save_instru;
      int cont_loop = 0;

      for(int i = 0; i<producoes.size();i++)
        {
            int ids_salvos = 0;
            while(producoes[i].nome == "definainstrucao") //traduz a instruçação
            {
                instru_traducao aux;
                aux.nome=guarda_ids[ids_salvos].id;
                i++;
                if(i<producoes.size()-1 && (producoes[i].nome!="definainstrucao" && producoes[i].nome!="execucaoinicio")) //existe um comando
                {
                    while(producoes[i].nome!="definainstrucao" &&  producoes[i].nome!="execucaoinicio")
                    {
                        if(producoes[i].tipo=="Instrucao")
                        {
                            if(producoes[i].nome == "vire para esquerda")
                            {
                                aux.traducao.push_back("MOV AL, 2");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("MOV AL, 0");
                                aux.traducao.push_back("OUT 9, AL");
                            }
                            else if(producoes[i].nome == "vire para direita")
                            {
                                    aux.traducao.push_back("MOV AL, 3");
                                    aux.traducao.push_back("OUT 9, AL");
                                    aux.traducao.push_back("MOV AL, 0");
                                    aux.traducao.push_back("OUT 9, AL");
                            }
                            else if(producoes[i].nome == "pare")
                            {
                                    aux.traducao.push_back("MOV AL, 0");
                                    aux.traducao.push_back("OUT 9, AL");
                            }
                            else if(producoes[i].nome == "mova")
                            {
                                    if(i<producoes.size()-1 &&producoes[i+1].tipo=="Numero")
                                    {
                                            cont_loop++;
                                            stringstream ss;
                                            ss << cont_loop;
                                            string str = ss.str();
                                            aux.traducao.push_back("MOV CX, "+producoes[i+1].nome);
                                            aux.traducao.push_back("l"+str+":");
                                            aux.traducao.push_back("MOV AL, 1");
                                            aux.traducao.push_back("OUT 9, AL");
                                            aux.traducao.push_back("MOV AL, 0");
                                            aux.traducao.push_back("OUT 9, AL");
                                            aux.traducao.push_back("DEC CX");
                                            aux.traducao.push_back("JNZ l"+cont_loop);
                                    }
                                    else
                                    {
                                        aux.traducao.push_back("MOV AL, 1");
                                        aux.traducao.push_back("OUT 9, AL");
                                        aux.traducao.push_back("MOV AL, 0");
                                        aux.traducao.push_back("OUT 9, AL");
                                    }
                            }
                            else if(producoes[i].nome == "apague lampada")
                            {
                                aux.traducao.push_back("MOV AL, 6");
                                aux.traducao.push_back("OUT 9, AL");
                            }
                            else if(producoes[i].nome == "acenda lampada")
                            {
                                aux.traducao.push_back("MOV AL, 5");
                                aux.traducao.push_back("OUT 9, AL");
                            }
                            else if(producoes[i].nome == "finalize")
                            {
                                i=producoes.size(); // finaliza instruções
                            }
                            else if(producoes[i].nome == "aguarde ate robo pronto"||producoes[i].nome == "aguarde ate robo parado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("IN AX,11");
                                aux.traducao.push_back("CMP AX,00000000b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000001b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000100b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000101b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("JMP l"+str);
                                aux.traducao.push_back("fim_l"+str+":");
                            }
                            else if(producoes[i].nome == "aguarde ate robo movimentando")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("IN AL,10");
                                aux.traducao.push_back("CMP AL,0");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("JMP l"+str);
                                aux.traducao.push_back("fim_l"+str+":");
                            }
                            else if(producoes[i].nome == "aguarde ate robo ocupado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("IN AX,11");
                                aux.traducao.push_back("CMP AX,00000010b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000011b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000110b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000111b");
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("JMP l"+str);
                                aux.traducao.push_back("fim_l"+str+":");
                            }
                            else if(producoes[i].nome == "aguarde ate lampada acesa a frente"||producoes[i].nome == "aguarde ate lampada apagada a frente")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                if(producoes[i].nome == "aguarde ate lampada acesa a frente"){
                                    aux.traducao.push_back("CMP AL,00000111b");
                                }
                                else{
                                    aux.traducao.push_back("CMP AL,00001000b");
                                }
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("JMP l"+str);
                                aux.traducao.push_back("fim_l"+str+":");

                            }
                            else if(producoes[i].nome == "aguarde ate lampada acesa a esquerda"||producoes[i].nome == "aguarde ate lampada apagada a esquerda"||
                            producoes[i].nome == "aguarde ate lampada apagada a direita"||producoes[i].nome == "aguarde ate lampada acesa a direita")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                if(producoes[i].nome == "aguarde ate lampada acesa a direita"){
                                    aux.traducao.push_back("CMP AL,00001011b");
                                }
                                else if(producoes[i].nome == "aguarde ate lampada apagada a direita"){
                                    aux.traducao.push_back("CMP AL,00001100b");
                                }
                                else if(producoes[i].nome == "aguarde ate lampada apagada a esquerda"){
                                    aux.traducao.push_back("CMP AL,00001010b");
                                }
                                else{
                                    aux.traducao.push_back("CMP AL,00001001b");
                                }
                                aux.traducao.push_back("JE fim_l"+str);
                                aux.traducao.push_back("jmp l"+str);
                                aux.traducao.push_back("fim_l"+str+":");
                    //retorna para onde estava//

                            }
                            else if(producoes[i].nome == "aguarde ate frente robo bloqueada"||producoes[i].nome == "aguarde ate esquerda robo bloqueada"||
                            producoes[i].nome == "aguarde ate direita robo bloqueada")
                            {   cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                if(producoes[i].nome == "aguarde ate frente robo bloqueada"){
                                    aux.traducao.push_back("CMP AL,11111111b");
                                }
                                else if(producoes[i].nome == "aguarde ate esquerda robo bloqueada"){
                                    aux.traducao.push_back("CMP AL,11110000b");
                                }
                                else{
                                     aux.traducao.push_back("CMP AL,00001111b");
                                }
                                aux.traducao.push_back("JE fim_l");
                                aux.traducao.push_back("jmp l"+str);
                                aux.traducao.push_back("fim_l"+str);
                            }
                        }
                        else if(producoes[i].nome=="repita")
                        {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                aux.traducao.push_back("MOV CX, "+producoes[i+1].nome);
                                aux.traducao.push_back("l"+str+":");
                        }
                        else if(producoes[i].nome=="fimrepita")
                        {
                            aux.traducao.push_back("DEC CX");
                            aux.traducao.push_back("JNZ l"+indice_loop.top());
                            indice_loop.pop();
                        }
                        else if(producoes[i].nome=="enquanto")
                        {
                            cont_loop++;
                            stringstream ss;
                            ss << cont_loop;
                            string str = ss.str();
                            indice_loop.push(str);
                            aux.traducao.push_back("l"+str+":");
                            if(producoes[i+1].nome=="esquerda robo bloqueada"||producoes[i+1].nome=="direita robo bloqueada"||producoes[i+1].nome=="frente robo bloqueada")
                            {
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");

                                if(producoes[i+1].nome == "frente robo bloqueada"){
                                    aux.traducao.push_back("CMP AL,11111111b");
                                }
                                else if(producoes[i+1].nome == "esquerda robo bloqueada"){
                                    aux.traducao.push_back("CMP AL,11110000b");
                                }
                                else{
                                     aux.traducao.push_back("CMP AL,00001111b");
                                }
                                aux.traducao.push_back("JNE fim_l"+str);
                            }
                             else if(producoes[i+1].nome == "lampada acesa a esquerda"||producoes[i+1].nome == "lampada apagada a esquerda"||
                            producoes[i+1].nome == "lampada apagada a direita"||producoes[i+1].nome == "lampada acesa a direita")
                            {
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                 if(producoes[i+1].nome == "lampada apagada a esquerda"){
                                    aux.traducao.push_back("CMP AL,00001010b");
                                }
                                if(producoes[i+1].nome == "lampada acesa a direita"){
                                    aux.traducao.push_back("CMP AL,00001011b");
                                }
                                if(producoes[i+1].nome == "lampada apagada a direita"){
                                    aux.traducao.push_back("CMP AL,00001100b");
                                }
                                else{
                                    aux.traducao.push_back("CMP AL,00001001b");
                                }
                                 aux.traducao.push_back("JNE fim_l"+str);
                            }
                            else if(producoes[i+1].nome == "lampada acesa a frente"||producoes[i+1].nome == "lampada apagada a frente")
                            {
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                 if(producoes[i+1].nome == "lampada acesa a frente"){
                                    aux.traducao.push_back("CMP AL,00000111b");
                                }
                                else{
                                    aux.traducao.push_back("CMP AL,00001000b");
                                }
                                aux.traducao.push_back("JNE fim_l"+str);
                            }

                            else if(producoes[i+1].nome =="robo ocupado")
                            {

                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("IN AX,11");
                                aux.traducao.push_back("CMP AX,00000010b");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000011b");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000110b");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000111b");
                                aux.traducao.push_back("JNE fim_l"+str);
                            }

                            else if(producoes[i+1].nome == "robo movimentando")
                            {
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("IN AL,10");
                                aux.traducao.push_back("CMP AL,0");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("JMP l"+str);
                                aux.traducao.push_back("fim_l"+str+":");
                            }
                            else if(producoes[i+1].nome =="robo pronto"||producoes[i+1].nome =="robo parado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("IN AX,11");
                                aux.traducao.push_back("CMP AX,00000000b");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000001b");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000100b");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("CMP AX,00000101b");
                                aux.traducao.push_back("JNE fim_l"+str);
                            }
                            i++;
                        }
                         else if(producoes[i].nome=="fimpara")
                         {
                                aux.traducao.push_back("JMP l"+indice_loop.top());
                                aux.traducao.push_back("fim_l"+indice_loop.top()+":");
                                indice_loop.pop();
                         }
                         else if(producoes[i].nome=="se")
                         {
                            if(producoes[i+1].nome=="esquerda robo bloqueada"||producoes[i+1].nome=="direita robo bloqueada"||producoes[i+1].nome=="frente robo bloqueada")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                if(producoes[i+1].nome == "frente robo bloqueada"){
                                    aux.traducao.push_back("CMP AL,11111111b");
                                }
                                else if(producoes[i+1].nome == "esquerda robo bloqueada"){
                                    aux.traducao.push_back("CMP AL,11110000b");
                                }
                                else{
                                     aux.traducao.push_back("CMP AL,00001111b");
                                }
                                aux.traducao.push_back("JNE fim_se"+str); //se não satisfaz, vai para final do se
                            }
                            else if(producoes[i+1].nome == "lampada acesa a esquerda"||producoes[i+1].nome == "lampada apagada a esquerda"||
                                    producoes[i+1].nome == "lampada apagada a direita"||producoes[i+1].nome == "lampada acesa a direita")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                 if(producoes[i+1].nome == "lampada apagada a esquerda"){
                                    aux.traducao.push_back("CMP AL,00001010b");
                                }
                                if(producoes[i+1].nome == "lampada acesa a direita"){
                                    aux.traducao.push_back("CMP AL,00001011b");
                                }
                                if(producoes[i+1].nome == "lampada apagada a direita"){
                                    aux.traducao.push_back("CMP AL,00001100b");
                                }
                                else{
                                    aux.traducao.push_back("CMP AL,00001001b");
                                }
                                aux.traducao.push_back("JNE fim_se"+str); //se não satisfaz, vai para final do se
                            }
                            else if(producoes[i+1].nome == "lampada acesa a frente"||producoes[i+1].nome == "lampada apagada a frente")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                if(producoes[i+1].nome == "lampada acesa a frente"){
                                    aux.traducao.push_back("CMP AL,00000111b");
                                }
                                else{
                                    aux.traducao.push_back("CMP AL,00001000b");
                                }
                                aux.traducao.push_back("JNE fim_se"+str); //se não satisfaz, vai para final do se
                            }
                            else if(producoes[i+1].nome =="robo pronto"||producoes[i+1].nome =="robo parado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                aux.traducao.push_back("IN AX,11");
                                aux.traducao.push_back("CMP AX,00000000b");
                                aux.traducao.push_back("JNE fim_se"+str);
                                aux.traducao.push_back("CMP AX,00000001b");
                                aux.traducao.push_back("JNE fim_se"+str);
                                aux.traducao.push_back("CMP AX,00000100b");
                                aux.traducao.push_back("JNE fim_se"+str);
                                aux.traducao.push_back("CMP AX,00000101b");
                                aux.traducao.push_back("JNE fim_se"+str);
                            }
                             else if(producoes[i+1].nome =="robo ocupado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                aux.traducao.push_back("MOVE AL,4");
                                aux.traducao.push_back("OUT 9, AL");
                                aux.traducao.push_back("IN AL, 10");
                                aux.traducao.push_back("IN AX,11");
                                aux.traducao.push_back("CMP AX,00000010b");
                                aux.traducao.push_back("JNE fim_se"+str);
                                aux.traducao.push_back("CMP AX,00000011b");
                                aux.traducao.push_back("JNE fim_se"+str);
                                aux.traducao.push_back("CMP AX,00000110b");
                                aux.traducao.push_back("JNE fim_se"+str);
                                aux.traducao.push_back("CMP AX,00000111b");
                                aux.traducao.push_back("JNE fim_se"+str);
                            }
                            else if(producoes[i+1].nome == "robo movimentando")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                aux.traducao.push_back("IN AL,10");
                                aux.traducao.push_back("CMP AL,0");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("JMP l"+str);
                                aux.traducao.push_back("fim_l"+str+":");
                            }
                            i++; //pula condição
                         }
                         else if(producoes[i].nome=="fimse")
                         {
                             if(producoes[i+1].nome=="senao")
                             {
                                 aux.traducao.push_back("JUMP fim_senao"+indice_loop.top());
                                 indice_loop.push(indice_loop.top());
                                 i++;
                             }
                             aux.traducao.push_back("fim_se"+indice_loop.top());
                             indice_loop.pop();
                         }
                         else if(producoes[i].nome=="fimsenao")
                         {
                             aux.traducao.push_back("fim_senao"+indice_loop.top()+":");
                             indice_loop.pop();
                         }
                         if(producoes[i].tipo=="ID")
                         {
                             for(int i = 0; i <save_instru.size();i++)
                             {
                                 if(save_instru[i].nome==producoes[i].nome)
                                 {
                                     for(int j = 0; j<save_instru[i].traducao.size();j++)
                                     {
                                         aux.traducao.push_back(save_instru[i].traducao[j]);
                                     }
                                     break;
                                 }
                             }
                         }

                        i++;
                    }
                    ids_salvos++;
                    save_instru.push_back(aux);
                    if(producoes[i].nome=="execucaoinicio")
                    {
                        cout<<"MOV AL, 0"<<endl;  //inicializa zerando tudo
                        cout<<"OUT 9, AL"<<endl;
                        i++;
                        while(i<producoes.size())
                        {
                            if(producoes[i].tipo=="Instrucao")
                            {
                                if(producoes[i].nome == "vire para esquerda")
                                {
                                    cout<<"MOV AL, 2"<<endl;
                                    cout<<"OUT 9, AL"<<endl;
                                    cout<<"MOV AL, 0"<<endl;
                                    cout<<"OUT 9, AL"<<endl;
                                }
                                else if(producoes[i].nome == "vire para direita")
                                {
                                        cout<<"MOV AL, 3"<<endl;
                                        cout<<"OUT 9, AL"<<endl;
                                        cout<<"MOV AL, 0"<<endl;
                                        cout<<"OUT 9, AL"<<endl;
                                }
                                else if(producoes[i].nome == "pare")
                                {
                                        cout<<"MOV AL, 0"<<endl;
                                        cout<<"OUT 9, AL"<<endl;
                                }
                                else if(producoes[i].nome == "mova")
                                {
                                    if(i<producoes.size()-1 &&producoes[i+1].tipo=="Numero")
                                    {
                                            cont_loop++;
                                            stringstream ss;
                                            ss << cont_loop;
                                            string str = ss.str();
                                            cout<<"MOV CX, "<<producoes[i+1].nome<<endl;
                                            cout<<"l"<<cont_loop<<":"<<endl;
                                            cout<<"MOV AL, 1"<<endl;
                                            cout<<"OUT 9, AL"<<endl;
                                            cout<<"MOV AL, 0"<<endl;
                                            cout<<"OUT 9, AL"<<endl;
                                            cout<<"DEC CX"<<endl;
                                            cout<<"JNZ l"<<cont_loop<<endl;
                                    }
                                    else
                                    {
                                        cout<<"MOV AL, 1"<<endl;
                                        cout<<"OUT 9, AL"<<endl;
                                        cout<<"MOV AL, 0"<<endl;
                                        cout<<"OUT 9, AL"<<endl;
                                    }
                            }
                            else if(producoes[i].nome == "apague lampada")
                            {
                                cout<<"MOV AL, 6"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                            }
                            else if(producoes[i].nome == "acenda lampada")
                            {
                                cout<<"MOV AL, 5"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                            }
                            else if(producoes[i].nome == "finalize")
                            {
                                i=producoes.size(); // finaliza instruções
                            }
                             else if(producoes[i].nome == "aguarde ate robo pronto"||producoes[i].nome == "aguarde ate robo parado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"l"<<str<<":"<<endl;
                                cout<<"IN AX,11"<<endl;
                                cout<<"CMP AX,00000000b"<<endl;
                                cout<<"JE fim_l"<<str<<endl;
                                cout<<"CMP AX,00000001b"<<endl;
                                cout<<"JE fim_l"<<str<<endl;
                                cout<<"CMP AX,00000100b"<<endl;
                                cout<<"JE fim_l"<<str<<endl;
                                cout<<"CMP AX,00000101b"<<endl;
                                cout<<"JE fim_l"<<str<<endl;
                                cout<<"JMP l"<<str<<endl;
                                cout<<"fim_l"<<str<<":"<<endl;
                            }
                            else if(producoes[i].nome == "aguarde ate robo movimentando")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                aux.traducao.push_back("l"+str+":");
                                aux.traducao.push_back("IN AL,10");
                                aux.traducao.push_back("CMP AL,0");
                                aux.traducao.push_back("JNE fim_l"+str);
                                aux.traducao.push_back("JMP l"+str);
                                aux.traducao.push_back("fim_l"+str+":");
                            }
                            else if(producoes[i].nome == "aguarde ate robo ocupado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"l"<<str<<":"<<endl;
                                cout<<"IN AX,11"<<endl;
                                cout<<"CMP AX,00000010b"<<endl;
                                cout<<"JE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000011b"<<endl;
                                cout<<"JE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000110b"<<endl;
                                cout<<"JE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000111b"<<endl;
                                cout<<"JE fim_l"<<cont_loop<<endl;
                                cout<<"JMP l"<<cont_loop<<endl;
                                cout<<"fim_l"<<cont_loop<<":"<<endl;
                            }
                            else if(producoes[i].nome == "aguarde ate lampada acesa a frente"||producoes[i].nome == "aguarde ate lampada apagada a frente")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"l"<<cont_loop<<":"<<endl;
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                if(producoes[i].nome == "aguarde ate lampada acesa a frente"){
                                    cout<<"CMP AL,00000111b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001000b"<<endl;
                                }
                                cout<<"JE fim_l"<<cont_loop<<endl;
                                cout<<"JMP l"<<cont_loop<<endl;
                                cout<<"fim_l"<<cont_loop<<":"<<endl;
                            }
                            else if(producoes[i].nome == "aguarde ate lampada acesa a esquerda"||producoes[i].nome == "aguarde ate lampada apagada a esquerda"||
                            producoes[i].nome == "aguarde ate lampada apagada a direita"||producoes[i].nome == "aguarde ate lampada acesa a direita")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"l"<<cont_loop<<":"<<endl;
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                if(producoes[i].nome == "aguarde ate lampada acesa a direita"){
                                    cout<<"CMP AL,00001011b"<<endl;
                                }
                                else if(producoes[i].nome == "aguarde ate lampada apagada a direita"){
                                    cout<<"CMP AL,00001100b"<<endl;
                                }
                                else if(producoes[i].nome == "aguarde ate lampada apagada a esquerda"){
                                    cout<<"CMP AL,00001010b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001001b"<<endl;
                                }
                                cout<<"JE fim_l"<<cont_loop<<endl;
                                cout<<"JMP l"<<cont_loop<<endl;
                                cout<<"fim_l"<<cont_loop<<":"<<endl;
                            }
                            else if(producoes[i].nome == "aguarde ate frente robo bloqueada"||producoes[i].nome == "aguarde ate esquerda robo bloqueada"||
                            producoes[i].nome == "aguarde ate direita robo bloqueada")
                            {   cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"l"<<cont_loop<<":"<<endl;
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                if(producoes[i].nome == "aguarde ate frente robo bloqueada"){
                                    cout<<"CMP AL,11111111b"<<endl;
                                }
                                else if(producoes[i].nome == "aguarde ate esquerda robo bloqueada"){
                                    cout<<"CMP AL,11110000b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001111"<<endl;
                                }
                                cout<<"JE fim_l"<<cont_loop<<endl;
                                cout<<"JMP "<<"l"<<cont_loop<<endl;
                                cout<<"fim_l"<<cont_loop<<":"<<endl;
                            }
                        }
                        else if(producoes[i].nome=="repita")
                        {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                cout<< "MOV CX, "+producoes[i+1].nome<<endl;
                                cout<<"l"<<str<<":"<<endl;
                        }
                        else if(producoes[i].nome=="fimrepita")
                        {
                            cout<<"DEC CX"<<endl;
                            cout<<"JNZ l"<<indice_loop.top()<<endl;
                            indice_loop.pop();
                        }
                        else if(producoes[i].nome=="enquanto")
                        {
                            cont_loop++;
                            stringstream ss;
                            ss << cont_loop;
                            string str = ss.str();
                            indice_loop.push(str);
                            cout<<"l"+str+":"<<endl;
                            if(producoes[i+1].nome=="esquerda robo bloqueada"||producoes[i+1].nome=="direita robo bloqueada"||producoes[i+1].nome=="frente robo bloqueada")
                            {
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;

                                if(producoes[i+1].nome == "frente robo bloqueada"){
                                    cout<<"CMP AL,11111111b"<<endl;
                                }
                                else if(producoes[i+1].nome == "esquerda robo bloqueada"){
                                    cout<<"CMP AL,11110000b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001111"<<endl;
                                }
                                cout<<"JNE fim_l"+str<<endl;
                            }
                             else if(producoes[i+1].nome == "lampada acesa a esquerda"||producoes[i+1].nome == "lampada apagada a esquerda"||
                            producoes[i+1].nome == "lampada apagada a direita"||producoes[i+1].nome == "lampada acesa a direita")
                            {
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                 if(producoes[i+1].nome == "lampada apagada a esquerda"){
                                    cout<<"CMP AL,00001010b"<<endl;
                                }
                                if(producoes[i+1].nome == "lampada acesa a direita"){
                                    cout<<"CMP AL,00001011b"<<endl;
                                }
                                if(producoes[i+1].nome == "lampada apagada a direita"){
                                    cout<<"CMP AL,00001100b"<<endl;
                                }
                                else{
                                    aux.traducao.push_back("CMP AL,00001001b");
                                    cout<<"CMP AL,00001001b"<<endl;
                                }
                                 aux.traducao.push_back("JNE fim_l"+str);
                                 cout<<"JNE fim_l"+str<<endl;
                            }
                            else if(producoes[i+1].nome == "lampada acesa a frente"||producoes[i+1].nome == "lampada apagada a frente")
                            {
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                 if(producoes[i+1].nome == "lampada acesa a frente"){
                                    cout<<"CMP AL,00000111b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001000b"<<endl;
                                }
                                cout<<"JNE fim_l"+str<<endl;
                            }

                            else if(producoes[i+1].nome =="robo ocupado")
                            {
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"IN AX,11"<<endl;
                                cout<<"CMP AX,00000010b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000011b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000110b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000111b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                            }
                            else if(producoes[i+1].nome == "robo movimentando")
                            {
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"IN AL,10"<<endl;
                                cout<<"CMP AL,0"<<endl;
                                cout<<"JNE fim_l"<<str<<endl;
                                cout<<"JMP l"<<str<<endl;
                                cout<<"fim_l"<<str<<":"<<endl;
                            }
                            else if(producoes[i+1].nome =="robo pronto"||producoes[i+1].nome =="robo parado")
                            {
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                cout<<"IN AX,11"<<endl;
                                cout<<"CMP AX,00000010b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000011b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000110b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                                cout<<"CMP AX,00000111b"<<endl;
                                cout<<"JNE fim_l"<<cont_loop<<endl;
                            }
                            i++;
                        }
                         else if(producoes[i].nome=="fimpara")
                         {
                                cout<<"JMP l"+indice_loop.top()<<endl;
                                cout<<"fim_l"+indice_loop.top()+":"<<endl;
                                indice_loop.pop();
                         }
                         else if(producoes[i].nome=="se")
                         {
                            if(producoes[i+1].nome=="esquerda robo bloqueada"||producoes[i+1].nome=="direita robo bloqueada"||producoes[i+1].nome=="frente robo bloqueada")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                if(producoes[i+1].nome == "frente robo bloqueada"){
                                    cout<<"CMP AL,11111111b"<<endl;
                                }
                                else if(producoes[i+1].nome == "esquerda robo bloqueada"){
                                    cout<<"CMP AL,11110000b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001111"<<endl;
                                }
                                cout<<"JNE fim_se"+str<<endl;
                            }
                            else if(producoes[i+1].nome == "lampada acesa a esquerda"||producoes[i+1].nome == "lampada apagada a esquerda"||
                                    producoes[i+1].nome == "lampada apagada a direita"||producoes[i+1].nome == "lampada acesa a direita")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                 if(producoes[i+1].nome == "lampada apagada a esquerda"){
                                    cout<<"CMP AL,00001010b"<<endl;
                                }
                                if(producoes[i+1].nome == "lampada acesa a direita"){
                                    cout<<"CMP AL,00001011b"<<endl;
                                }
                                if(producoes[i+1].nome == "lampada apagada a direita"){
                                    cout<<"CMP AL,00001100b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001001b"<<endl;
                                }
                                cout<<"JNE fim_se"<<str<<endl;
                            }
                            else if(producoes[i+1].nome == "lampada acesa a frente"||producoes[i+1].nome == "lampada apagada a frente")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                if(producoes[i+1].nome == "lampada acesa a frente"){
                                    cout<<"CMP AL,00000111b"<<endl;
                                }
                                else{
                                    cout<<"CMP AL,00001000b"<<endl;
                                }
                                cout<<"JNE fim_se"+str<<endl;
                            }
                            else if(producoes[i+1].nome =="robo pronto"||producoes[i+1].nome =="robo parado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                cout<<"CMP AX,00000000b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                                cout<<"CMP AX,00000001b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                                cout<<"CMP AX,00000100b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                                cout<<"CMP AX,00000101b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                            }
                             else if(producoes[i+1].nome =="robo ocupado")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                cout<<"MOVE AL,4"<<endl;
                                cout<<"OUT 9, AL"<<endl;
                                cout<<"IN AL, 10"<<endl;
                                cout<<"CMP AX,00000010b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                                cout<<"CMP AX,00000011b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                                cout<<"CMP AX,00000110b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                                cout<<"CMP AX,00000111b"<<endl;
                                cout<<"JNE fim_se"<<cont_loop<<endl;
                            }
                             else if(producoes[i+1].nome == "robo movimentando")
                            {
                                cont_loop++;
                                stringstream ss;
                                ss << cont_loop;
                                string str = ss.str();
                                indice_loop.push(str);
                                cout<<"IN AL,10"<<endl;
                                cout<<"CMP AL,0"<<endl;
                                cout<<"JNE fim_l"<<str<<endl;
                                cout<<"JMP l"<<str<<endl;
                                cout<<"fim_l"<<str<<":"<<endl;
                            }
                            i++; //pula condição
                         }
                         else if(producoes[i].nome=="fimse")
                         {
                             if(producoes[i+1].nome=="senao")
                             {
                                 cout<<"JUMP fim_senao"<<indice_loop.top()<<endl;
                                 indice_loop.push(indice_loop.top());
                                 i++;
                             }
                             cout<<"fim_se"<<indice_loop.top()<<":"<<endl;
                             indice_loop.pop();
                         }
                         else if(producoes[i].nome=="fimsenao")
                         {
                             cout<<"fim_senao"<<indice_loop.top()<<":"<<endl;
                             indice_loop.pop();
                         }
                         if(producoes[i].tipo=="ID")
                         {
                             for(int k = 0; k <save_instru.size();k++)
                             {
                               //  cout<<"aqui :"<<save_instru[i].nome<<endl;
                               //  cout<<producoes[i].nome<<endl;
                                 if(save_instru[k].nome==producoes[i].nome)
                                 {
                                     for(int j = 0; j<save_instru[k].traducao.size();j++)
                                     {
                                         cout<<save_instru[k].traducao[j]<<endl;
                                     }
                                     break;
                                 }
                             }
                         }

                        i++;
                        }
                    }
                }

            }
        }
        cout<<"CODIGO GERADO COM SUCESSO!"<<endl;
   }
 }
 myfile.close();
 return 0;
}

