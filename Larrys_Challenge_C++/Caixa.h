#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Caixa : public Entidade
{
private:
	float peso;
	int tipo;
	bool bloqueado;

public:
	Caixa();
	Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo);
	~Caixa();
	void existir();
	void setPeso(const float _peso);
	float getPeso()const;
	int getTipo()const;

};

