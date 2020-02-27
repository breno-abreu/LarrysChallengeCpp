#pragma once
#include "bibliotecas.h"
#include "Letal.h"

class Espinhos : public Letal
{
private:
	bool desativado;
	bool ativado;


public:
	Espinhos();
	Espinhos(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _conexao);
	~Espinhos();
	void existir();
	void setAtivado(const bool _ativado);
	bool getAtivado()const;
	bool getDesativado()const;

};

