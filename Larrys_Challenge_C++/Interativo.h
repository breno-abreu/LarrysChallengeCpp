#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Interativo : public Entidade
{
protected:
	bool ativado;

public:
	Interativo();
	Interativo(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Interativo();
	virtual void existir() = 0;
	bool getAtivado()const;
	void setAtivado(const bool _ativado);
};

