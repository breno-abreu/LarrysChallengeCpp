#pragma once
#include "bibliotecas.h"
#include "Inimigo.h"


class Rato : public Inimigo
{
public:
	Rato();
	Rato(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao);
	~Rato();
	void existir();
};

