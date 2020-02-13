#pragma once
#include "bibliotecas.h"
#include "Personagem.h"

class Inimigo : public Personagem
{


public:
	Inimigo();
	Inimigo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Inimigo();
	virtual void existir() = 0;
};

