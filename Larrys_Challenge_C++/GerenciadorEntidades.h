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
	Texture a;
	Texture t_blueorb;
	Texture t_redorb;
	Texture t_greenorb;
	Texture t_moeda;
	Texture f;
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
	Texture u;
	Texture v;
	Texture w;
	Texture x;
	Texture t_movimentador;
	Texture t_rato;
	Texture aa;
	Texture ab;
	Texture t_esqueleto;
	Texture ad;
	Texture ae;
	Texture af;
	Texture ag;
	Texture ah;
	Texture ai;
	Texture aj;
	Texture t_zumbi;

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
	GerenciadorEntidades(RenderWindow *_window);
	~GerenciadorEntidades();
	void adicionar_entidade(const float cx, const float cy, const int tipo, const int codigo);
};

