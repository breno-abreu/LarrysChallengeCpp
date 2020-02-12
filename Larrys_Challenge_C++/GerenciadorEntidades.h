#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "Abismo.h"
#include "Atirador.h"
#include "Barreira.h"
#include "Bau.h"
#include "Botao.h"
#include "Caixa.h"
#include "Coluna.h"
#include "Escada.h"
#include "Espinhos.h"
#include "Flecha.h"
#include "Inimigo.h"
#include "Interativo.h"
#include "Interruptor.h"
#include "Item.h"
#include "Jogador.h"
#include "Letal.h"
#include "Movimentador.h"
#include "Obstaculo.h"
#include "ParedeLevadica.h"
#include "PassagemSecreta.h"
#include "Pedra.h"
#include "Personagem.h"
#include "Porta.h"
#include "Superficie.h"
#include "SuperficieInterativa.h"
#include "Tocha.h"
#include "Perseguidor.h"
#include "Rato.h"

class GerenciadorEntidades
{
private:
	RenderWindow* window;
	Texture t_flecha;
	Texture t_blueorb;
	Texture t_redorb;
	Texture t_greenorb;
	Texture t_moeda;
	Texture t_chave;
	Texture t_paredelevadica;
	Texture t_caixaleve;
	Texture t_caixapesada;
	Texture t_chao;
	Texture t_jogador;
	Texture t_bau;
	Texture t_colunahorizontal;
	Texture t_colunaverticaldireita;
	Texture t_colunaverticalesquerda;
	Texture t_colunaverticaldireitab;
	Texture t_colunaverticalesquerdab;
	Texture t_parede;
	Texture t_passagemsecreta;
	Texture t_abismo;
	Texture t_porta;
	Texture t_umbralhorizontal;
	Texture t_umbralverticaldireita;
	Texture t_umbralverticalesquerda;
	Texture t_movimentador;
	Texture t_rato;
	Texture t_pedra;
	Texture t_atirador;
	Texture t_esqueleto;
	Texture t_espinhos;
	Texture t_escada;
	Texture t_interruptor;
	Texture t_botao;
	Texture t_topocolunadireita;
	Texture t_topocolunaesquerda;
	Texture t_tocha;
	Texture t_zumbi;

	list<Letal*> listaLetais;
	list<Barreira*> listaBarreiras;
	list<Interativo*> listaInterativos;
	list<SuperficieInterativa*> listaSuperficiesInterativas;
	list<Caixa*> listaCaixas;
	list<Flecha*> listaFlechas;
	list<Inimigo*> listaInimigos;
	list<Personagem*> listaPersonagens;
	list<Item*> listaItens;



	/*int profundidade[37] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 0,
							3, 2, 4, 4, 4, 2, 2, 1, 1, 1, 
							2, 4, 4, 4, 1, 3, 3, 3, 3, 2,
							2, 2, 2, 4, 4, 2, 3};

	Texture* texturas[60] = { &a, &b, &c, &d, &e, &f, &g, &h, &i, &j,
							  &k, &l, &m, &n, &o, &p, &q, &r, &s, &t,
							  &u, &v, &w, &x, &y, &z, &aa, &ab, &ac, &ad,
							  &ae, &af, &ag, &ah, &ai, &aj, &ak};*/


public:
	GerenciadorEntidades();
	GerenciadorEntidades(RenderWindow *_window, list<Letal*> _listaLetais, list<Barreira*> _listaBarreiras,
						 list<Interativo*> _listaInterativos, list<SuperficieInterativa*> _listaSuperficiesInterativas,
						 list<Caixa*> _listaCaixas, list<Flecha*> _listaFlechas, list<Inimigo*> _listaInimigos,
						 list<Personagem*> _listaPersonagens, list<Item*> _listaItens);
	~GerenciadorEntidades();
	Entidade* adicionar_entidade(const float cx, const float cy, const int tipo, const int codigo);
};

