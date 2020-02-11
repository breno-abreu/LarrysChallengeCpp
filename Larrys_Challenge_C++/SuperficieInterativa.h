#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class SuperficieInterativa : public Entidade
{
public:
	SuperficieInterativa();
	SuperficieInterativa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~SuperficieInterativa();
	virtual void existir() = 0;
};

