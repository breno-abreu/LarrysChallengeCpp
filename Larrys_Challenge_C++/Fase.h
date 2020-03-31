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
	GerenciadorEntidades* gerenciadorEntidades;
	Jogador* jogador;
	list<Barreira*> listaBarreiras;
	list<Caixa*> listaCaixas;
	list<Flecha*> listaFlechas;
	list<Inimigo*> listaInimigos;
	list<Interativo*> listaInterativos;
	list<Item*> listaItens;
	list<Letal*> listaLetais;
	list<Personagem*> listaPersonagens;
	list<SuperficieInterativa*> listaSuperficiesInterativas;
	ListaEntidades* listaEntidades;
	RenderWindow* window;

public:
	Fase();
	Fase(RenderWindow* _window);
	~Fase();
	bool getJogadorVivo()const;
	bool verificar_colisao_aux(Entidade* a, Entidade* b);
	bool verificar_colisao(Entidade* a, Entidade* b);
	Vector2f getCoordenadasJogador()const;
	void adicionar_entidade(const float cx, const float cy, const int tipo, const int conexao);
	void atiradores();
	void ativador_atirador();
	void ativador_espinhos();
	void ativador_porta();
	void caixa_barreira();
	void checar_fim_de_jogo();
	void excluir_entidades();
	void executar();
	void flecha_barreira();
	void flecha_caixa();
	void jogador_abismo();
	void jogador_barreira();
	void jogador_caixas();
	void jogador_espinhos();
	void jogador_flecha();
	void jogador_inimigo();
	void jogador_interativo();
	void jogador_item();
	void jogador_movimentador();
	void jogador_parede_levadica();
	void jogador_portais();
	void objetos_botao();
	void perseguidor_barreira();
	void perseguidor();
	void rato_barreira();
};

