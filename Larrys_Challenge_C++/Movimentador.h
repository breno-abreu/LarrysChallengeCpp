#pragma once
#include "bibliotecas.h"
#include "SuperficieInterativa.h"

class Movimentador : public SuperficieInterativa
{
private:
	int direcao;

public:
	Movimentador();
	Movimentador(RenderWindow* _window, Texture *_textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao);
	~Movimentador();
	void existir();
	int getDirecao()const;



};

