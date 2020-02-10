#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Letal : public Entidade
{
public:
	Letal();
	Letal(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Letal();
	virtual void existir() = 0;
};

