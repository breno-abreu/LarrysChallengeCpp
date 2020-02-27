#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class Porta : public Interativo
{
public:
	Porta();
	Porta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _conexao);
	~Porta();
	void existir();
};

