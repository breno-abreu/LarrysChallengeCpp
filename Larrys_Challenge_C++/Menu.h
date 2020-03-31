#pragma once
#include "bibliotecas.h"
#include "GerenciadorPersistencia.h"

class Menu
{
private:
	bool auxDireita;
	bool auxEsquerda;
	Font fonte;
	GerenciadorPersistencia* gerenciadorPersistencia;
	int nfase;
	int opcao;
	int opcaoSelecionada;
	int quantidadeFases;
	RenderWindow* window;
	Text fase;
	Text iniciarJogo;
	Text sair;

public:
	Menu(RenderWindow* _window);
	~Menu();
	int executar();
	int getFase();
	void resetOpcaoSelecionada();
};

