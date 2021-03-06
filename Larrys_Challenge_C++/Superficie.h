#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Superficie : public Entidade
{
public:
	Superficie();
	Superficie(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Superficie();
	void existir();
};

