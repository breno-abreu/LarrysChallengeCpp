#pragma once
#include "bibliotecas.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	bool acao;

public:
	Jogador();
	Jogador(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Jogador();
	void existir();
	bool getAcao()const;


};

