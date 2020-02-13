#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Letal : public Entidade
{
public:
	Letal();
	Letal(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Letal();
	virtual void existir() = 0;
};

