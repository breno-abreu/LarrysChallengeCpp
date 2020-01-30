#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"

class LarrysChallenge
{
private:
	RenderWindow* window;
	ListaEntidades* listaEntidades;

public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
};

