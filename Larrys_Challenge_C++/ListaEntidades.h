#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "Jogador.h"
#include "GerenciadorEntidades.h"

class ListaEntidades
{
private:
	GerenciadorEntidades* gerenciadorEntidades;
	int codigo;
	list<Entidade*> listaEntidades;
	RenderWindow* window;

public:
	ListaEntidades();
	ListaEntidades(RenderWindow* _window, GerenciadorEntidades* _gerenciador);
	~ListaEntidades();
	bool vazio();
	list<Entidade*> getLista();
	void adicionar_entidade(const float cx, const float cy, const int tipo, const int conexao);
	void excluir_entidades();
	void limpar();
	void ordenar();
	void percorrer();
	void setLista(list<Entidade*> lista);
};

