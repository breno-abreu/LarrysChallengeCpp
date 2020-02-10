#pragma once
#include "bibliotecas.h"
#include "Barreira.h"

class Pedra : public Barreira
{
public:
	Pedra();
	Pedra(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Pedra();
	void existir();
};

