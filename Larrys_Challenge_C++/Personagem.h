#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Personagem : public Entidade
{
protected:
	float velocidade;
	int direcao;

public:
	Personagem();
	Personagem(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Personagem();
	virtual void existir() = 0;
	float getVelocidade()const;

};

