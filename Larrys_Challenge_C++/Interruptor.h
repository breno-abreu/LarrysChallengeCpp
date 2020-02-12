#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class Interruptor : public Interativo
{


public:
	Interruptor();
	Interruptor(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Interruptor();
	void existir();
};

