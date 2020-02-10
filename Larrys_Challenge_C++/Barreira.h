#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Barreira : public Entidade
{
public:
	Barreira();
	Barreira(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Barreira();
	virtual void existir() = 0;
};

