#pragma once
#include "bibliotecas.h"
#include "Barreira.h"

class Coluna : public Barreira
{
public:
	Coluna();
	Coluna(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Coluna();
	void existir();
};

