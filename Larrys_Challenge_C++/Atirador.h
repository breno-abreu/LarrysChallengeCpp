#pragma once
#include "bibliotecas.h"
#include "Barreira.h"

class Atirador : public Barreira
{
private:
	int direcao;
	int contAtivar;
	int velAtivar;
	bool ativo;

public:
	Atirador();
	Atirador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _direcao);
	~Atirador();
	void existir();
	bool getAtivo()const;
	int getDirecao()const;
};

