#include "simulacao.h"

int rand_min_max(int min, int max){
    static int init = 1;
    if(init){
        init = 0;
        srand(time(NULL));
    }
    return rand() % (max - min + 1) + min;
}

void simulacao(){
    Pintor pintor;
    int min_pac = 1, max_pac = 10;
    int min_doc = 1, max_doc = 5;



    // Tempo da simulação
    const unsigned int tempo = TURNOS_DIA;
    const unsigned int numCaixas = 3;

    // Estruturas para representar os clientes
    // no caixa e na fila
    std::vector<Cliente*> caixa(numCaixas);
    std::list<Cliente*> fila;

    int qtd = 5;
    for(int i = 0; i < qtd; i++)
        fila.push_back(new Cliente(rand_min_max(min_pac, max_pac),
                                   rand_min_max(min_doc, max_doc)));

    caixa[0] = new Cliente(MAX_PACIENCIA/3, min_doc);
    caixa[1] = new Cliente(MAX_PACIENCIA, max_doc);

    for (unsigned int i = 0; i < tempo; i++)
    {
        //desenha e espera 300 milisegundos
        Cliente *a = caixa[0];
        a->paciencia = rand() % MAX_PACIENCIA ;
        pintor.desenhar(caixa, fila, 300);
        Cliente *c = caixa[1];
        c->paciencia = rand() % MAX_PACIENCIA + 1;
        pintor.desenhar(caixa, fila, 300);
    }

    delete caixa[1];
    caixa[1] = nullptr;
    for(int i = 1; i < qtd; i++){
        delete fila.front();
        fila.pop_front();
    }

}







//void executar_testes(){
//    //funcao auxiliar
//    auto testar = [](bool resultado){
//        cout << (resultado? "Passou!" : "Falhou!") << endl;
//    };
//    /*
//    int calcularQtdOtimaCaixas(int cli_min, int cli_max,
//                               int pac_min, int pac_max,
//                               int doc_min, int doc_max);
//    */

//    cout << "Simulacao 1: ";
//    testar(otimizar_lucro(0, 1, 1, 60, 1, 10) == 4);

//    cout << "Simulacao 2: ";
//    testar(otimizar_lucro(0, 2, 1, 20, 1, 10) == 8);

//    cout << "Simulacao 3: ";
//    testar(otimizar_lucro(0, 5, 1, 25, 1, 10) == 10);

//    cout << "Simulacao 4: ";
//    testar(otimizar_lucro(0, 4, 1, 5, 1, 2) == 6);

//    cout << "Simulacao 5: ";
//    testar(otimizar_lucro(1, 2, 1, 15, 1, 2) == 5);
//}
