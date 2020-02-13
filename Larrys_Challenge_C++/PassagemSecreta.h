#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class PassagemSecreta : public Interativo
{
public:
	PassagemSecreta();
	PassagemSecreta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~PassagemSecreta();
	void existir();
};

