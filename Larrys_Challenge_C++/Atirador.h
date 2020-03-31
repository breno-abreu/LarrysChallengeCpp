#pragma once
#include "bibliotecas.h"
#include "Barreira.h"

class Atirador : public Barreira
{
private:
	bool atirar;
	bool ativado;
	int contAtivar;
	int direcao;
	int velAtivar;

public:
	Atirador();
	Atirador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao, const int _conexao);
	~Atirador();
	bool getAtirar()const;
	bool getAtivado()const;
	int getDirecao()const;
	void existir();
	void setAtirar(const bool _atirando);
	void setAtivado(const bool _ativado);
};

