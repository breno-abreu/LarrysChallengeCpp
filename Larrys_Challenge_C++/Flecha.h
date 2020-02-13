#pragma once
#include "bibliotecas.h"
#include "Letal.h"

class Flecha : public Letal
{
private:
	int direcao;
	float velocidade;

public:
	Flecha();
	Flecha(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao);
	~Flecha();
	void existir();
};

