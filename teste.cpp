#include <bits/stdc++.h>
using namespace std;
struct keyword{
string nome;
string tipo;
};

void inv (stack<string> & guarda, stack<string> & inverte, vector<keyword> & tabela){
    while(guarda.size()>0) //se existem palavras que eram dependente desta
    {
        inverte.push(guarda.top());
        guarda.pop();
    }
    while(inverte.size()>0)
    {
        if(inverte.top()=="direita"||inverte.top()=="esquerda"){ //se for esquerda ou direita, vira palavra chave
            keyword g;
            g.nome = inverte.top();
            g.tipo = "Sentido";
            tabela.push_back(g);
            cout<<inverte.top()<<"  Sentido"<<endl;
            inverte.pop();
        }
        else{
            keyword g;
            g.nome = inverte.top();
            g.tipo = "ID";
            tabela.push_back(g);
            cout<<inverte.top()<<"  ID"<<endl;
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
  stack<string>guarda; //guarda combinações de palavras chave
  stack<string>inverte;
  int estado =0;

  //============PALAVRAS CHAVE======================================================

  aux.nome = "programainicio", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "fimprograma", aux.tipo = "Programa", reserved_words.push_back(aux);
  aux.nome = "execucaoinicio", aux.tipo = "Pograma", reserved_words.push_back(aux);
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
      if(coment!=1){
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
         else if(buffer[k]!=' '&&(ascll>122||(ascll<97&&ascll>57)||ascll<48)&&ascll!=10)//caracter invalido (10 = fim da linha)
         {
                 aux_palavra = aux_palavra + buffer[k];
                 error = 1;
         }
      }
        if(buffer[k]==' '||buffer[k]=='\n'|| k == buffer.size()-1){//possivel palavra encontrada
            bool achou = 0;
            if(buffer[k]=='\n'&&aux_palavra.size()==0){
                 coment=0;
                 if(col>0)
                 {
                     lin++;
                     col=0;
                 }
            }
            if(aux_palavra.size()>0)//se foi gerada uma palavra
            {
                if(buffer[k]==' '&&error==0)
                    col++;
                if(buffer[k]=='\n'&&error==0)
                {
                    col=0;
                    lin++;
                    coment=0;
                }
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
                        guarda.push(aux_palavra); //coloca na fila
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
                            tabela.push_back(g);
                            //cout<<aux_palavra<<" Sentido"<<endl;
                        }
                        else{
                            keyword g;
                            g.nome = aux_palavra;
                            g.tipo = "ID";
                            tabela.push_back(g);
                            //cout<<aux_palavra<<"  ID"<<endl;
                        }
                        retorna=0;
                        estado=0;
                    }

                    else if(estado==1&&(aux_palavra=="apagada"||aux_palavra=="acesa"||aux_palavra=="robo"||aux_palavra=="movimentando"||aux_palavra=="parado"
                        ||aux_palavra=="ocupado"||aux_palavra=="pronto"||aux_palavra=="ate"||aux_palavra=="lampada"||aux_palavra=="para"))
                    {
                          if(guarda.top()=="lampada")
                          {
                              if(aux_palavra=="acesa"||aux_palavra=="apagada")
                              {
                                  if(k<buffer.size()-1){ //da para continuar
                                    guarda.push(aux_palavra);
                                    estado++;
                                    retorna=0;
                                  }
                                  else{ //não é possivel combinar
                                    guarda.push(aux_palavra);
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
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra para aux_palavra
                              }
                          }

                          else if(guarda.top()=="robo")
                          {
                              if(aux_palavra=="pronto"||aux_palavra=="parado"||aux_palavra=="ocupado") //eh uma palavra reservada
                              {

                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Condicao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top()+' '+aux_palavra;
                                  g.tipo = "Condicao";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else// robo eh id
                              {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top();
                                  g.tipo = "ID";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }

                          else if(guarda.top()=="acenda"||guarda.top()=="apague")
                          {
                              if(aux_palavra=="lampada")
                              {
                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top()+' '+aux_palavra;
                                  g.tipo = "Instrucao";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else
                              {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top();
                                  g.tipo = "ID";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }
                          else if(guarda.top()=="vire")
                          {
                               if(aux_palavra=="para")
                              {
                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top()+' '+aux_palavra;
                                  g.tipo = "Instrucao";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                              }
                              else
                              {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top();
                                  g.tipo = "ID";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                              }
                          }

                          else if(guarda.top()=="aguarde")
                          {
                             if(aux_palavra=="ate")
                             {
                                  //cout<<guarda.top()<<" "<<aux_palavra<<"  "<<"Instrucao"<<endl;
                                  keyword g;
                                  g.nome = guarda.top()+' '+aux_palavra;
                                  g.tipo = "Instrucao";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  retorna=0;
                                  estado=0; //reseta estado
                             }
                             else
                             {
                                  //cout<<guarda.top()<<" ID"<<endl;
                                  keyword g;
                                  g.nome = guarda.top();
                                  g.tipo = "ID";
                                  tabela.push_back(g);
                                  guarda.pop();
                                  estado--; //volta 1 estado
                                  retorna=1; //nova possivel palavra
                             }
                           }
                          else if(guarda.top()=="esquerda"||guarda.top()=="direita"||guarda.top()=="frente")
                          {
                               if(aux_palavra=="robo")
                              {

                                 if(k<buffer.size()-1){ //da para continuar
                                    guarda.push(aux_palavra);
                                    estado++;
                                    retorna=0;
                                  }
                                  else{  //não da para alocar outra palavra na sequencia
                                      guarda.push(aux_palavra);
                                      inv (guarda,inverte,tabela);
                                      estado=0;
                                      retorna=0;
                                  }
                              }
                              else // guarda.top é sentido ou id
                              {
                                   if(guarda.top()=="direita"||guarda.top()=="esquerda"){ //se for esquerda ou direita, vira palavra chave
                                        keyword g;
                                        g.nome = guarda.top();
                                        g.tipo = "Sentido";
                                        tabela.push_back(g);
                                        //cout<<guarda.top()<<"  Sentido"<<endl;
                                        guarda.pop();
                                    }
                                    else{
                                        keyword g;
                                        g.nome = guarda.top();
                                        g.tipo = "ID";
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
                    if(guarda.top()=="robo"){
                        if(aux_palavra=="bloqueada") //palavra chave formada
                        {
                              string forma = "";
                              guarda.push(aux_palavra);
                              while(guarda.size()>0)
                              {
                                 inverte.push(guarda.top());
                                 guarda.pop();
                              }
                              while(inverte.size()>0)
                              {
                                 forma = forma+inverte.top()+' '; //concatena
                                 inverte.pop();
                              }
                               //cout<<forma<<" Condicao"<<endl;
                               keyword g;
                               g.nome = forma;
                               g.tipo = "Condicao";
                               tabela.push_back(g);
                               retorna=0; //combinação completa
                               estado=0; // solicita novo token
                         }
                         else//cadeia não combina - entrada 'a'
                              {
                                  guarda.push(aux_palavra);
                                  inv (guarda,inverte,tabela);
                                  estado=0;  //novo token
                                  retorna=0; //solicita nova palavra
                              }
                        }

                        else if(guarda.top()=="acesa"||guarda.top()=="apagada")
                        {
                              if(aux_palavra=="a")
                              {

                                    if(k<buffer.size()-1){ //da para continuar
                                    guarda.push(aux_palavra);
                                    estado++;
                                    retorna=0;
                                    }
                                    else //não combina
                                    {
                                        guarda.push(aux_palavra);
                                        inv (guarda,inverte,tabela);
                                        estado=0; //novo token
                                        retorna=0; //solicita nova palavra
                                    }
                              }
                              else//não combina
                              {
                                  guarda.push(aux_palavra);
                                  inv (guarda,inverte,tabela);
                                  estado=0;  //novo token
                                  retorna=0; //solicita nova palavra
                              }
                      }

                }
                 else if(estado==3&&(aux_palavra=="direita"||aux_palavra=="esquerda"||aux_palavra=="frente")) //só tem uma forma de chegar aqui
                 {
                            guarda.push(aux_palavra);
                                   while(guarda.size()>0)
                                    {
                                        inverte.push(guarda.top());
                                        guarda.pop();
                                    }
                                    string forma = "";
                                    while(inverte.size()>0)
                                    {
                                            forma = forma+inverte.top()+' ';
                                            inverte.pop();
                                    }
                                    //cout<<forma<<"  Condicao"<<endl;
                                    keyword g;
                                    g.nome = forma;
                                    g.tipo = "Condicao";
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
                            tabela.push_back(g);
                        }
                        else{
                            //cout<<aux_palavra<<" Sentido"<<endl;
                            keyword g;
                            g.nome = aux_palavra;
                            g.tipo = "Sentido";
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
                                if(inverte.top()!="esquerda"&&inverte.top()!="direita")
                                {
                                    //cout<<inverte.top()<<" ID"<<endl;
                                    keyword g;
                                    g.nome = inverte.top();
                                    g.tipo = "ID";
                                    tabela.push_back(g);
                                    inverte.pop();
                                }
                                else{
                                    //cout<<inverte.top()<<" Sentido"<<endl;
                                    keyword g;
                                    g.nome = inverte.top();
                                    g.tipo = "Sentido";
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
   int state = 0;
    for(int i =0;i<tabela.size();i++){

        int retorna=1;
        while(retorna==1)
        {
            if(state == 0 && (tabela[i].nome=="definainstrucao" || tabela[i].nome=="repita" || tabela[i].nome=="enquanto" || tabela[i].nome=="se"
                        || tabela[i].nome=="mova" || tabela[i].nome=="vire para" || tabela[i].nome == "aguarde ate")){
                        state++;
                        save.push(tabela[i]);
                        retorna=0;
            }
            else if(state == 0 &&(tabela[i].nome=="fimrepita"||tabela[i].nome=="fimse"||tabela[i].nome=="fimpara"))//encerra loops de comando
            {
                if(save.size()==0){ //se comando não foi bem sucedido
                    cout<<"Erro na expressao "<<tabela[i].nome<<endl;
                    retorna = 0;
                    state = 0;
                }
                else
                {
                    if(tabela[i].nome=="fimrepita")
                    {
                        while(save.top().nome!="repita") //deleta 1 loop ok
                        {
                            base.push(save.top());
                            save.pop();
                        }
                        if(save.top().nome=="repita")
                            base.push(save.top());
                        save.pop();
                        cout<<"Expressao correta: ";
                        while(base.size()>0)
                        {
                            cout<<base.top().nome<<" ";
                            base.pop();
                        }
                        retorna = 0;
                        cout<<tabela[i].nome<<endl;
                    }
                     if(tabela[i].nome=="fimse")
                    {
                        while(save.top().nome!="se") //deleta 1 loop ok
                        {
                            base.push(save.top());
                            save.pop();
                        }
                        if(save.top().nome=="se")
                            base.push(save.top());
                        save.pop();
                        cout<<"Expressao correta: ";
                        while(base.size()>0)
                        {
                            cout<<base.top().nome<<" ";
                            base.pop();
                        }
                        retorna = 0;
                        cout<<tabela[i].nome<<endl;
                    }
                     if(tabela[i].nome=="fimpara")
                    {
                        while(save.top().nome!="enquanto") //deleta 1 loop ok
                        {
                            base.push(save.top());
                            save.pop();
                        }
                        if(save.top().nome=="enquanto")
                            base.push(save.top());
                        save.pop();
                        cout<<"Expressao correta: ";
                        while(base.size()>0)
                        {
                            cout<<base.top().nome<<" ";
                            base.pop();
                        }
                        retorna = 0;
                        cout<<tabela[i].nome<<endl;
                    }

                }
            }

            else if(state == 0 && save.top().nome=="como")
            {
                if(save.size()>0)
                {
                    cout<<"Expressao correta: ";
                    while(save.size()>0)
                    {
                        base.push(save.top());
                        save.pop();
                    }
                    while(base.size()>0)
                    {
                        cout<<base.top().nome<<" ";
                        base.pop();
                    }
                    cout<<endl;
                }
                else{
                    cout<<"Expressão errada: "<<tabela[i].nome<<endl;
                }
                retorna = 0;
                state = 0;
            }
            else if(state ==1 && (tabela[i].tipo=="ID" || tabela[i].tipo=="Numero" || tabela[i].tipo=="Condicao" || tabela[i].tipo =="Sentido" ))
            {
                if(save.top().nome=="definainstrucao") //definainstrucao id
                {
                    if(tabela[i].tipo=="ID")
                    {
                        state++;
                        save.push(tabela[i]);
                        retorna=0;
                    }
                    else{
                        cout<<"ERRO SINTATICO"<<endl;
                        save.pop();
                        state--;
                        retorna=1;
                    }
                }

                else if(save.top().nome=="repita")    //repita n
                {
                    if(tabela[i].tipo=="Numero")
                    {
                        state++;
                        save.push(tabela[i]);
                        retorna=0;
                    }
                    else{
                        cout<<"ERRO SINTATICO";
                        save.pop();
                        state--;
                        retorna=1;
                    }
                }

                else if(save.top().nome=="enquanto")    //enquanto condicao
                {
                    if(tabela[i].tipo=="Condicao")
                    {
                        state++;
                        save.push(tabela[i]);
                        retorna=0;
                    }
                     else{
                        cout<<"ERRO SINTATICO";
                        save.pop();
                        state--;
                        retorna=1;
                    }
                }

                else if(save.top().nome=="se")        //se condicao
                {
                    if(tabela[i].tipo=="Condicao")
                    {
                        state++;
                        save.push(tabela[i]);
                        retorna=0;
                    }
                     else{
                        cout<<"ERRO SINTATICO";
                        save.pop();
                        state--;
                        retorna=1;
                    }
                }

                else if(save.top().nome=="mova")        //mova(ok)
                {
                    if(tabela[i].tipo=="Numero")
                    {
                        state++;
                        save.push(tabela[i]);
                        retorna=0;
                    }
                     else{ //numero opcional
                        state = 0;
                        retorna = 1;
                        save.pop();
                        cout<<"Expressao correta: "<<save.top().nome<<endl; //montar arvore
                    }
                }

                else if(save.top().nome=="vire para")       //vire para (ok)
                {
                    if(tabela[i].tipo=="Sentido")
                    {
                        state = 0;
                        retorna=0;
                        cout<<"Expressao correta: "<<save.top().nome<<" "<<tabela[i].nome<<endl; //montar arvore
                        save.pop();
                    }
                     else{
                        cout<<"ERRO SINTATICO";
                        save.pop();
                        state--;
                        retorna=1;
                    }
                }

                 else if(save.top().nome=="aguarde ate")            //aguarde ate condicao (ok)
                {
                    if(tabela[i].tipo=="Condicao")
                    {
                        state = 0;
                        save.pop();
                        retorna=0;
                        cout<<"Expressao correta: "<<save.top().nome<<" "<<tabela[i].tipo<<endl; //montar arvore
                    }
                     else{
                        cout<<"ERRO SINTATICO";
                        save.pop();
                        state--;
                        retorna=1;
                    }
                }


            }

            else if(state==2&&(tabela[i].nome=="como"||tabela[i].nome=="vezes"||tabela[i].nome=="faca"||tabela[i].nome=="entao"||tabela[i].nome=="passos"))
            {
                if(save.top().tipo=="ID")    //definainstrucao id como
                {
                    if(tabela[i].nome=="como")
                    {
                        state++;
                        save.push(tabela[i]);
                        retorna=0;
                    }
                    else{
                        cout<<"ERRO SINTATICO"<<endl;
                        keyword xx = save.top();
                        save.pop();
                        save.pop();
                        save.push(xx);
                        state--;
                        retorna=1;
                    }
                }
                //////////////////////////////////////////////////////////////////
                if(save.top().tipo=="Numero")     //mova [n] [passos](ok) // repita n vezes
                {

                    while(save.size()>0&&(save.top().nome!="mova"||save.top().nome!="repita"))
                    {
                        base.push(save.top());
                        save.pop();
                    }
                    if(tabela[i].nome=="passos")
                    {
                        if(base.top().nome=="mova")
                        {
                            state = 0;
                            retorna = 0;
                            string exp ="";
                            while(base.size()>0)
                            {
                                    exp=exp+base.top().nome+" ";
                                    base.pop();
                            }
                            cout<<"Expressao correta: "<<exp+tabela[i].nome<<endl; //montar arvore
                        }
                        else{ //base é repita
                            cout<<"ERRO SINTATICO"<<endl;
                            while(base.size()>0)
                                base.pop();
                            while(save.size()>0)
                                save.pop();
                        }

                    }
                    else if(tabela[i].nome=="vezes"){
                         if(base.top().nome=="mova") //aceita do msm jeito
                        {
                            state = 0;
                            retorna = 1;
                            cout<<"Expressao correta: "<<base.top().nome<<" "; //montar arvore
                            base.pop();
                            cout<<base.top().nome<<endl;
                            base.pop();
                        }
                        else //é repita (aceita)
                        {
                            state++;
                            retorna = 0;
                            while(base.size()>0)
                            {
                                save.push(base.top());
                                base.pop();
                            }
                            save.push(tabela[i]);

                        }

                    }
                    else //nao é vezes, nem passos
                    {
                         if(base.top().nome=="mova") //aceita do msm jeito
                        {
                            state = 0;
                            retorna = 1;
                            cout<<"Expressao correta: "<<base.top().nome<<" "; //montar arvore
                            base.pop();
                            cout<<base.top().nome<<endl;
                            base.pop();
                        }
                         else{ //base é repita
                            cout<<"ERRO SINTATICO"<<endl;
                            base.pop();
                            state--;
                            retorna=1;
                            save.push(base.top());
                            base.pop();
                        }
                    }
                }//mova n passo // repita n vezes
                 /////////////////////////////////////////////////
                  if(save.top().tipo=="Condicao")  //enquanto condicao faca // se condicao entao
                  {
                       while(save.size()>0)
                        {
                        base.push(save.top());
                        save.pop();
                        }
                        if(tabela[i].nome=="faca")
                        {
                            if(base.top().nome=="enquanto")
                            {
                                state++;
                                retorna = 0;
                                while(base.size()>0)
                                {
                                save.push(base.top());
                                base.pop();
                                }
                                save.push(tabela[i]);
                            }
                            else{ //base é se
                                cout<<"ERRO SINTATICO"<<endl;
                                base.pop();
                                state--;
                                retorna=1;
                                save.push(base.top());
                                base.pop();
                            }
                        }
                        else if(tabela[i].nome=="entao")
                        {
                             if(base.top().nome=="se")
                            {
                                state++;
                                retorna = 0;
                                while(base.size()>0)
                                {
                                save.push(base.top());
                                base.pop();
                                }
                                save.push(tabela[i]);
                            }
                            else{ //base é enquanto
                                cout<<"ERRO SINTATICO"<<endl;
                                base.pop();
                                state--;
                                retorna=1;
                                save.push(base.top());
                                base.pop();
                            }
                        }
                        else{// nao eh enquanto nem faca
                                cout<<"ERRO SINTATICO"<<endl;
                                base.pop();
                                state--;
                                retorna=1;
                                save.push(base.top());
                                base.pop();
                        }
                  }

            }

            else if(state == 3 && tabela[i].tipo=="Bloco"||tabela[i].tipo=="Iteracao"||tabela[i].tipo=="Laco"||tabela[i].tipo=="Condicioal"||
                    tabela[i].tipo=="Instrucao"||tabela[i].tipo=="ID") //tipos de comando (ID pode estar definido ou não - semantico)
            {
                if(tabela[i].tipo=="Bloco"){
                   if(tabela[i].nome=="inicio")
                   {
                       save.push(tabela[i]);
                       retorna = 0;
                       state=3;

                   }
                   else
                   {
                       if(save.top().nome=="inicio")
                       {
                           cout<<"Expressão correta :";
                           cout<<save.top().nome<<" "<<tabela[i].nome<<endl;
                           save.pop();
                           retorna = 0;
                           state = 0;
                       }
                       else
                       {
                           cout<<"Erro na expressao"<<endl;
                           {
                               while(save.size()<0)
                               {
                                   base.push(save.top());
                                   save.pop();
                               }
                               while(base.size()>0)
                               {
                                   cout<<base.top().nome<<" ";
                                   base.pop();
                               }
                               cout<<endl;
                           }
                           retorna = 0;
                           state = 0;
                       }
                   }
                }
                else if(tabela[i].nome=="repita"||tabela[i].nome=="se"||tabela[i].nome=="enquanto"||tabela[i].nome=="mova"||tabela[i].nome=="vire para"
                   ||tabela[i].nome=="aguarde ate")

                {
                      save.push(tabela[i]);
                      retorna = 0;
                      state=1;
                }
                else if(tabela[i].tipo=="Instrucao"||tabela[i].tipo=="ID")
                {
                    cout<<"Expressao correta: "<<tabela[i].nome<<endl;
                    retorna = 0;
                    state = 0;
                }
                else{
                    cout<<"ERRO"<<endl;
                     retorna = 0;
                     state = 0;
                     while(save.size()>0)
                        save.pop();
                }
            }

             else
            {
                cout<<"Erro na expressao ";

                while(save.size()>0)
                {
                    base.push(save.top());
                    save.pop();
                }
                while(base.size()>0)
                {
                    cout<<base.top().nome<<" ";
                    base.pop();
                }
                cout<<tabela[i].nome<<endl;
                retorna = 0;
                state = 0;
            }
        }
    }
    while(save.size()>0)
    {
        base.push(save.top());
        save.pop();
    }
    if(base.size()>0)
        cout<<"Erro na expressao: ";
    while(base.size()>0){
        cout<<base.top().nome<<" ";
        base.pop();
    }


    myfile.close();
    return 0;
}
