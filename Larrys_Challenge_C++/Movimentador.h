#pragma once
#include "bibliotecas.h"
#include "Obstaculo.h"

class Movimentador : public Obstaculo
{
private:
	int direcao;

public:
	Movimentador();
	Movimentador(RenderWindow* _window, const float cx, const float cy, const int _codigo, const int _direcao);
	~Movimentador();
	void existir();
	int getDirecao()const;



};

