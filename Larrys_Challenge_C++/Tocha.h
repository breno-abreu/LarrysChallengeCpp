#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Tocha : public Entidade
{
public:
	Tocha();
	Tocha(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Tocha();
	void existir();
};

