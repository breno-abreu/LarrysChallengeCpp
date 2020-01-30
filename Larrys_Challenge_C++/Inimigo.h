#pragma once
#include "bibliotecas.h"
#include "Personagem.h"

class Inimigo : public Personagem
{


public:
	Inimigo();
	Inimigo(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Inimigo();
	virtual void existir() = 0;
};

