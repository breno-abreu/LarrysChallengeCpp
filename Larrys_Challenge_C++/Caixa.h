#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Caixa : public Entidade
{
private:
	float peso;

public:
	Caixa();
	Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const float _peso);
	~Caixa();
	void existir();
	void setPeso(const float _peso);
	float getPeso()const;

};
