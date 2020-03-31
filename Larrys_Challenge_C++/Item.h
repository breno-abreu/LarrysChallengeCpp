#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Item : public Entidade
{
private:
	int tipo;

public:
	Item();
	Item(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo);
	~Item();
	int getTipo()const;
	void existir();
	void setTipo(const int _tipo);
};

