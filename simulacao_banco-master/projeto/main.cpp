#include <random>
#include "Libs/pintor.h"

#include <vector>
#include "Libs/pintor.h"
#include <algorithm>
#include <time.h>//funcao time
#include <stdlib.h> //funcao srand

using namespace std;

const int TURNOS_DIA = 360;
const int MAX_CAIXAS = 10;
const int CUSTO_CAIXA_DIA = 100;
const int N_EXEC_TESTE = 100;
int rand_mm(int min, int max){
    static int init = 1;
    if(init){
        init = 0;
        srand(time(NULL));
    }
    return rand() % (max - min + 1) + min;
}


int min_pac = 1, max_pac = 10;
int min_doc = 1, max_doc = 5;





int calcular(int min_cliente, int max_cliente, int min_pac, int max_pac, int min_doc, int numCaixa){
    const unsigned int tempo = TURNOS_DIA;

    std::vector<Cliente*> caixa(numCaixa);
    std::list<Cliente*> fila;

    int custos = numCaixa * CUSTO_CAIXA_DIA;

    for(unsigned int i = 0; i < numCaixa; i++){
        caixa[i] = nullptr;

    }

    int total = 0;

    for (unsigned int i = 0; i < tempo; i++)
    {
        int newcliente = rand_mm(min_cliente, max_cliente);
        for(int i = 0; i < newcliente; i++)
                fila.push_back(new Cliente(rand_mm(min_pac, max_pac), rand_mm(min_doc, max_doc)));



        for(int i = 0; i < numCaixa; i++){
            if(caixa[i] != nullptr){
                if(caixa[i] == nullptr && !fila.empty())
                    caixa[i] = fila.front();

                fila.pop_front();
            }
        }
//        list<Cliente*>::iterator it;
//        for(it = fila.begin(); it != fila.end(); it++){
//            if((*it)->paciencia == 0){
//                fila.erase(it);
//            }
//            else{
//                (*it)->paciencia--;
//            }
//        }

        auto it = fila.begin();
        while(it != fila.end()){
            Cliente *c = *it;
            c->paciencia--;
            if(c->paciencia == 0){
                it = fila.erase(it);
                delete (c);
            }else{
                it++;
            }
        }

        for(int i = 0; i < numCaixa; i++){
            if(caixa[i] != nullptr){
                Cliente *c = caixa[i];
                c->documentos--;
                total++;
                if(c->documentos == 0){
                    caixa[i] == nullptr;
                    delete (c);
                }
            }
        }
    }


    for(int i = 0; i < numCaixa; i++)
        if(caixa[i] != nullptr)
            delete (caixa[i]);

    while(!fila.empty()){
        Cliente *c = fila.front();
        fila.pop_front();
        delete (c);
    }

    return total - custos;

}

int otimizar (int min_cliente, int max_cliente, int min_pac, int max_pac, int min_doc, int max_doc){

    float media = 0;
    float maior = 0;
    int ncx;


    for(int i = 1;  i <= 10; i++){
        media = 0;
        for(int j = 0; j < N_EXEC_TESTE; j++){
            media += calcular(min_cliente, max_cliente, min_pac, max_pac, min_doc, max_doc);
        }
        media = media/N_EXEC_TESTE;

        if(media > maior){
            maior = media;
            ncx = media;
        }

    }

    cout << "media do caixa: " << ncx << endl;
    return ncx;

}

void testes(){
    auto testar = [](bool result){
        cout << (result? "passou!" : "falhou!") << endl;
    };

    cout << "simular 1 caso: ";
    testar(otimizar(0, 1, 1, 60, 1, 10) == 4);

    cout << "simular 2 caso: ";
    testar(otimizar(0, 2, 1, 20, 1, 10) == 8);

    cout << "simular 3 caso: ";
    testar(otimizar(0, 5, 1, 25, 1, 10) == 10);

    cout << "simular 4 caso: ";
    testar(otimizar(0, 4, 1, 5, 1, 2) == 6 || 7);

}





int main ()
{


    testes();
    return 0;
}
