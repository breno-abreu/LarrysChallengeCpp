#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Zumbi.h"

class LarrysChallenge
{
private:
	RenderWindow* window;
	ListaEntidades* listaEntidades;
	Jogador* jogador;
	Zumbi* zumbi;


public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
};

