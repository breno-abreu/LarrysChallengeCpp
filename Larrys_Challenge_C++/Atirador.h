#pragma once
#include "bibliotecas.h"
#include "Barreira.h"

class Atirador : public Barreira
{
private:
	int direcao;
	int contAtivar;
	int velAtivar;
	bool ativado;
	bool atirar;

public:
	Atirador();
	Atirador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao, const int _conexao);
	~Atirador();
	void existir();
	bool getAtivado()const;
	void setAtivado(const bool _ativado);
	bool getAtirar()const;
	void setAtirar(const bool _atirando);
	int getDirecao()const;
};

