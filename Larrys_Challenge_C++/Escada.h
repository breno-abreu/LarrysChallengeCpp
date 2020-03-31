#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class Escada : public Interativo
{
private:
	int tipo;

public:
	Escada();
	Escada(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo, const int _conexao);
	~Escada();
	int getTipo()const;
	void existir();
};

