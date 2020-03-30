#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "Jogador.h"

#include "Movimentador.h"
#include "Botao.h"
#include "Interruptor.h"
#include "Bau.h"
#include "Fase.h"
#include "GerenciadorEntidades.h"
#include "GerenciadorPersistencia.h"
#include "Menu.h"

class LarrysChallenge
{
private:
	bool opmenu;
	int opcao;
	RenderWindow* window;
	ListaEntidades* listaEntidades;
	Jogador* jogador;
	Botao* botao;
	Menu* menu;
	Interruptor* interruptor;
	Bau* bau;
	Text* texto;
	Font* fonte;
	bool aux;
	bool aux2;
	Fase* fase;
	GerenciadorPersistencia* gerenciadorPersistencia;

	GerenciadorEntidades* gerenciadorEntidades;

	View* view;
	const float comprimentoTela;
	const float alturaTela;


	list<Letal*> listaLetais;
	list<Barreira*> listaBarreiras;
	list<Interativo*> listaInterativos;
	list<SuperficieInterativa*> listaSuperficiesInterativas;
	list<Caixa*> listaCaixas;
	list<Flecha*> listaFlechas;
	list<Inimigo*> listaInimigos;
	list<Personagem*> listaPersonagens;
	list<Item*> listaItens;


public:
	LarrysChallenge();
	~LarrysChallenge();
	void executar();
};

