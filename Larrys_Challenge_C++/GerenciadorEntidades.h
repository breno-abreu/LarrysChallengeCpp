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

	Bau* bauA;
	int quantidadeMoedas;
	Jogador* jogadorJ;
	list<Abismo*> listaAbismo;
	list<Atirador*> listaAtiradores;
	list<Barreira*> listaBarreiras;
	list<Botao*> listaBotoes;
	list<Caixa*> listaCaixas;
	list<Entidade*> listaBarreirasCaixas;
	list<Entidade*> listaObjetos;
	list<Espinhos*> listaEspinhos;
	list<Flecha*> listaFlechas;
	list<Inimigo*> listaInimigos;
	list<Interativo*> listaInterativos;
	list<Interativo*> listaPortais;
	list<Interruptor*> listaInterruptores;
	list<Item*> listaItens;
	list<Letal*> listaLetais;
	list<Movimentador*> listaMovimentadores;
	list<ParedeLevadica*> listaParedesLevadicas;
	list<Perseguidor*> listaPerseguidores;
	list<Personagem*> listaPersonagens;
	list<Porta*> listaPortas;
	list<Rato*> listaRatos;
	list<SuperficieInterativa*> listaSuperficiesInterativas;

public:
	GerenciadorEntidades();
	GerenciadorEntidades(RenderWindow *_window);
	~GerenciadorEntidades();
	Bau* getBau()const;
	Entidade* adicionar_entidade(const float cx, const float cy, const int tipo, const int codigo, const int conexao);
	int getQuantidadeMoedas()const;
	Jogador* getJogador()const;
	list<Abismo*> getListaAbismo()const;
	list<Atirador*> getListaAtiradores()const;
	list<Barreira*> getListaBarreiras()const;
	list<Botao*> getListaBotoes()const;
	list<Caixa*> getListaCaixas()const;
	list<Entidade*> getListaBarreirasCaixas()const;
	list<Entidade*> getListaObjetos()const;
	list<Espinhos*> getListaEspinhos()const;
	list<Flecha*> getListaFlechas()const;
	list<Inimigo*> getListaInimigos()const;
	list<Interativo*> getListaInterativos()const;
	list<Interativo*> getListaPortais()const;
	list<Interruptor*> getListaInterruptores()const;
	list<Item*> getListaItens()const;
	list<Letal*> getListaLetais()const;
	list<Movimentador*> getListaMovimentadores()const;
	list<ParedeLevadica*> getListaParedesLevadicas()const;
	list<Perseguidor*> getListaPerseguidores()const;
	list<Personagem*> getListaPersonagens()const;
	list<Porta*> getListaPortas()const;
	list<Rato*> getListaRatos()const;
	list<SuperficieInterativa*> getListaSuperficiesInterativas()const;
	void excluir_flechas();
	void excluir_itens();
	void setQuantidadeMoedas(const int _quantidadeMoedas);
};

