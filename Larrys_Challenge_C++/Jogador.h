#pragma once
#include "bibliotecas.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	bool acao;

public:
	Jogador();
	~Jogador();
	void existir();
	void movimentarDireita();
	void movimentarEsquerda();
	void movimentarCima();
	void movimentarBaixo();
	bool getAcao()const;


};

