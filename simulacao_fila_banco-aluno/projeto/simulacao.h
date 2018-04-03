#ifndef OTIMIZACAO_H
#define OTIMIZACAO_H
#include "globais.h"
#include <vector>
#include "Libs/pintor.h"
#include <algorithm>
#include <time.h>//funcao time
#include <stdlib.h> //funcao srand

using namespace std;

//gera um numero entre min e max, [min, max]
int rand_min_max(int min, int max);
//so executa uma vez
//Calcula o lucro dados os parametros passados e os valores em globais.h
int calcular_lucro(int cli_min, int cli_max,
                   int pac_min, int pac_max,
                   int doc_min, int doc_max,
                   int num_caixas);

//funcao 100 vezes calcular lucro p/ cada qtd de caixas
//Calcula e retorna a quantidade de caixas que maximiza
//o lucro do banco.
//Para cada quantidade de caixa rode a simulacao N_EXEC_TESTE vezes
//e tire a média do lucro. Retorne a quantidade de caixas
//que gerar a maior média.
int otimizar_lucro(int cli_min, int cli_max,
                   int pac_min, int pac_max,
                   int doc_min, int doc_max);


//Essa simulação é apenas uma mostragem de como
//funciona a visualização.
void simulacao();

//metodo auxiliar chamado por
void testar(bool resultado);

//executa todos os testes
void executar_testes();

#endif // OTIMIZACAO_H
