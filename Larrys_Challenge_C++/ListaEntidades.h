#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "Jogador.h"
#include "GerenciadorEntidades.h"

class ListaEntidades
{
private:
	list<Entidade*> listaEntidades;
	int codigo;
	RenderWindow* window;
	GerenciadorEntidades* gerenciadorEntidades;

public:
	ListaEntidades();
	ListaEntidades(RenderWindow* _window, GerenciadorEntidades* _gerenciador);
	~ListaEntidades();
	void adicionar_entidade(const float cx, const float cy, const int tipo, const int conexao);
	void excluir_entidades();
	void percorrer();
	void limpar();
	void ordenar();
	bool vazio();
	list<Entidade*> getLista();
	void setLista(list<Entidade*> lista);
};

