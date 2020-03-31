#pragma once
#include "bibliotecas.h"
#include "SuperficieInterativa.h"

class Botao : public SuperficieInterativa
{
private:
	bool emCima;

public:
	Botao();
	Botao(RenderWindow* _window, Texture *_textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _conexao);
	~Botao();
	bool getEmCima()const;
	void existir();
	void setEmCima(const bool _emCima);
};

