#pragma once
#include "bibliotecas.h"
#include "ListaEntidades.h"
#include "GerenciadorEntidades.h"
#include "Flecha.h"
#include "Letal.h"
#include "Barreira.h"
#include "Interativo.h"
#include "SuperficieInterativa.h"
#include "Caixa.h"
#include "Inimigo.h"
#include "Personagem.h"
#include "Item.h"
#include "Abismo.h"
#include "Inimigo.h"
#include "ParedeLevadica.h"
#include "Atirador.h"

class Fase
{
private:
	list<Letal*> listaLetais;
	list<Barreira*> listaBarreiras;
	list<Interativo*> listaInterativos;
	list<SuperficieInterativa*> listaSuperficiesInterativas;
	list<Caixa*> listaCaixas;
	list<Flecha*> listaFlechas;
	list<Inimigo*> listaInimigos;
	list<Personagem*> listaPersonagens;
	list<Item*> listaItens;
	RenderWindow* window;
	ListaEntidades* listaEntidades;
	GerenciadorEntidades* gerenciadorEntidades;
	Jogador* jogador;

public:
	Fase();
	Fase(RenderWindow* _window);
	~Fase();
	void adicionar_entidade(const float cx, const float cy, const int tipo, const int conexao);
	void executar();
	void jogador_item();
	void jogador_barreira();
	void jogador_abismo();
	void jogador_inimigo();
	void jogador_movimentador();
	void jogador_parede_levadica();
	void jogador_espinhos();
	void jogador_interativo();
	void jogador_caixas();
	void jogador_portais();
	Vector2f getCoordenadasJogador()const;
	bool getJogadorVivo()const;
	void excluir_entidades();
	void atiradores();
	void flecha_barreira();
	void jogador_flecha();
	bool verificar_colisao(Entidade* a, Entidade* b);
	void flecha_caixa();
	void objetos_botao();
	void caixa_barreira();
	void ativador_espinhos();
	void ativador_atirador();
	void ativador_porta();
	void perseguidor();
	void perseguidor_barreira();
	void rato_barreira();
	bool verificar_colisao_aux(Entidade* a, Entidade* b);
};

