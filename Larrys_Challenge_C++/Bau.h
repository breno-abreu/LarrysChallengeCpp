#pragma once
#include "bibliotecas.h"
#include "Interativo.h"


class Bau : public Interativo
{
private:
	bool fim;


public:
	Bau();
	Bau(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Bau();
	void existir();
	
};

