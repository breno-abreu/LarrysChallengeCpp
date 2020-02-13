#pragma once
#include "bibliotecas.h"
#include "Letal.h"

class Abismo : public Letal
{
public:
	Abismo();
	Abismo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _xPos, const int _yPos);
	~Abismo();
	void existir();
};

