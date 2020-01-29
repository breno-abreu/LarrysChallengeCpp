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
	~Personagem();
	virtual void existir() = 0;
	virtual void movimentarDireita() = 0;
	virtual void movimentarEsquerda() = 0;
	virtual void movimentarCima() = 0;
	virtual void movimentarBaixo() = 0;

};

