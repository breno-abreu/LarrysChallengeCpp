#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Interativo : public Entidade
{
protected:
	bool ativado;

public:
	Interativo();
	Interativo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Interativo();
	bool getAtivado()const;
	virtual void existir() = 0;
	void setAtivado(const bool _ativado);
};

