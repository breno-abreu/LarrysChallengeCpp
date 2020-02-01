#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class Botao : public Interativo
{


public:
	Botao();
	Botao(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Botao();
	void existir();
};

