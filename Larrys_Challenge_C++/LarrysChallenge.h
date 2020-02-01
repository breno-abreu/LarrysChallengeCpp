#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Zumbi.h"
#include "Movimentador.h"
#include "Botao.h"
#include "Interruptor.h"
#include "Bau.h"

class LarrysChallenge
{
private:
	RenderWindow* window;
	ListaEntidades* listaEntidades;
	Jogador* jogador;
	Zumbi* zumbi;
	Movimentador* movimentador;
	Movimentador* movimentador2;
	Movimentador* movimentador3;
	Botao* botao;
	Interruptor* interruptor;
	Bau* bau;
	bool aux;


public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
};

