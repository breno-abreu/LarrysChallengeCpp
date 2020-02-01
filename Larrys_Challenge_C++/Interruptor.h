#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class Interruptor : public Interativo
{


public:
	Interruptor();
	Interruptor(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Interruptor();
	void existir();
};

