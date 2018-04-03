#ifndef GLOBAIS_H
#define GLOBAIS_H

//Cada dia possui 6 horas de trabalho
//60 minutos x 6 horas = 360 minutos
//cada minuto eh um turno.
const int TURNOS_DIA = 360;

//A paciencia maxima pode ser alterada.
//Ela é usada para criar o efeito de cores
//na visualização da simulação.
const int MAX_PACIENCIA = 20;

//A quantidade máxima de caixas não pode ser alterada.
const int MAX_CAIXAS = 10;

//Esse valor determina o quanto o banco por caixa por dia de trabalho
const int CUSTO_CAIXA_DIA = 100;

//numero de simulacoes de teste para cada caixa
const int N_EXEC_TESTE = 100;

#endif // GLOBAIS_H
