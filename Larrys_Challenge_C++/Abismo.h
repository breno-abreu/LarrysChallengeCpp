#pragma once
#include "bibliotecas.h"
#include "Letal.h"

class Abismo : public Letal
{
public:
	Abismo();
	Abismo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int xTile, const int yTile);
	~Abismo();
	void existir();
};

