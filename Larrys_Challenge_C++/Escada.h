#pragma once
#include "bibliotecas.h"
#include "Interativo.h"

class Escada : public Interativo
{
private:
	int tipo;

public:
	Escada();
	Escada(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _tipo);
	~Escada();
	void existir();
	int getTipo()const;
};

