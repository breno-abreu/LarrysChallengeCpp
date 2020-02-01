#pragma once
#include "bibliotecas.h"
#include "Entidade.h"


class Obstaculo : public Entidade
{

public:
	Obstaculo();
	Obstaculo(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Obstaculo();
	virtual void existir() = 0;
};

