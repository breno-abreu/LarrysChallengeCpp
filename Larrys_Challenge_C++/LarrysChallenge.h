#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "Jogador.h"

#include "Movimentador.h"
#include "Botao.h"
#include "Interruptor.h"
#include "Bau.h"
#include "GerenciadorEntidades.h"

class LarrysChallenge
{
private:
	RenderWindow* window;
	ListaEntidades* listaEntidades;
	Jogador* jogador;

	Movimentador* movimentador;
	Movimentador* movimentador2;
	Movimentador* movimentador3;
	Botao* botao;
	Interruptor* interruptor;
	Bau* bau;
	Text* texto;
	Font* fonte;
	bool aux;
	bool aux2;

	GerenciadorEntidades* gerenciadorEntidades;


	list<Letal*> listaLetais;
	list<Barreira*> listaBarreiras;
	list<Interativo*> listaInterativos;
	list<SuperficieInterativa*> listaSuperficiesInterativas;
	list<Caixa*> listaCaixas;
	list<Flecha*> listaFlechas;
	list<Inimigo*> listaInimigos;
	list<Personagem*> listaPersonagens;
	list<Item*> listaItens;


public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
};

