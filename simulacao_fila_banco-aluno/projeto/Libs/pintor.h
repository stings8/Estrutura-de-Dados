#ifndef BANCO_H
#define BANCO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>

#include "Libs/assetmanager.h"

struct Cliente
{
    int paciencia;
    int documentos;
    Cliente(int paciencia, int documentos)
    {
        this->paciencia = paciencia;
        this->documentos = documentos;
    }
};

class Pintor
{
public:

    Pintor();
    ~Pintor();

    //sleep_time: o tempo em milissegundos no qual o desenho eh mostrado.
    void desenhar(std::vector<Cliente*> &caixa, std::list<Cliente*> &fila, int sleep_time = 300);

private:
    // Janela
    int unidade;
    unsigned int altura;
    unsigned int largura;
    sf::RenderWindow janela;
    sf::Text excedenteFila;

    // Cenario
    sf::RectangleShape chao;
    std::vector<sf::CircleShape> clientesCaixa;
    std::vector<sf::CircleShape> clientesFila;
    std::vector<sf::RectangleShape> cenario;
    std::vector<sf::RectangleShape> grade;

    // Gerenciador de arquivos
    AssetManager manager;

    // Desenha cliente
    void desenharCliente(Cliente const* clienteInfo, sf::CircleShape &clienteShape);

    // Metodos de inicializacao
    void preencherCaixa();
    void preencherFila();
    void criarCenario();
    void criarGrade();
    sf::RectangleShape novaLinha(float comprimento, float largura = 2.0f);

};

#endif // BANCO_H
