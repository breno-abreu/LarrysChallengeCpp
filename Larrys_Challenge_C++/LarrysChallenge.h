#pragma once
#include "bibliotecas.h"
#include "Fase.h"
#include "GerenciadorEntidades.h"
#include "GerenciadorPersistencia.h"
#include "Menu.h"

class LarrysChallenge
{
private:
	bool opmenu;
	const float alturaTela;
	const float comprimentoTela;
	Fase* fase;
	GerenciadorEntidades* gerenciadorEntidades;
	GerenciadorPersistencia* gerenciadorPersistencia;
	int opcao;
	Menu* menu;
	RenderWindow* window;
	View* view;

public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
};

