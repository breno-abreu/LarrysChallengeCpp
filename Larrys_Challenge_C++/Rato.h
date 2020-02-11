#pragma once
#include "bibliotecas.h"
#include "Personagem.h"

class Rato : public Personagem
{
public:
	Rato();
	Rato(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _direcao);
	~Rato();
	void existir();
};

