#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class Porta : public Interativo
{
public:
	Porta();
	Porta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Porta();
	void existir();
};

