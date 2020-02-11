#pragma once
#include "bibliotecas.h"
#include "Letal.h"

class Espinhos : public Letal
{
public:
	Espinhos();
	Espinhos(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~Espinhos();
	void existir();

};

