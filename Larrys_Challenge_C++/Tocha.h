#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Tocha : public Entidade
{
public:
	Tocha();
	Tocha(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Tocha();
	void existir();
};

