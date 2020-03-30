#pragma once
#include "bibliotecas.h"
#include "GerenciadorPersistencia.h"

class Menu
{
private:
	int opcao;
	int opcaoSelecionada;
	int nfase;
	int quantidadeFases;
	bool auxDireita;
	bool auxEsquerda;
	RenderWindow* window;
	Font fonte;
	Text iniciarJogo;
	Text sair;
	Text fase;
	GerenciadorPersistencia* gerenciadorPersistencia;

public:
	Menu(RenderWindow* _window);
	~Menu();
	int executar();
	int getFase();
	void resetOpcaoSelecionada();
};

