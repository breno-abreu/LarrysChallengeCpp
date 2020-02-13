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
	Personagem(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Personagem();
	virtual void existir() = 0;
	float getVelocidade()const;
};

