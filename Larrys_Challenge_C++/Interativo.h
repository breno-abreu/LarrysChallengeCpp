#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Interativo : public Entidade
{
protected:
	bool ativado;

public:
	Interativo();
	Interativo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Interativo();
	virtual void existir() = 0;
	bool getAtivado()const;
	void setAtivado(const bool _ativado);
};

