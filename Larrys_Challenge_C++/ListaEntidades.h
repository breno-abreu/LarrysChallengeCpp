#pragma once
#include "bibliotecas.h"
#include "Entidade.h"
#include "Jogador.h"

class ListaEntidades
{
private:
	list<Entidade*> listaEntidades;
	int codigo;
	RenderWindow* window;

public:
	ListaEntidades();
	ListaEntidades(RenderWindow* _window);
	~ListaEntidades();
	void adicionar_entidade(const int cx, const int cy);
	void excluir_entidade(const int cx, const int cy);
	void percorrer();
	void limpar();
	void ordenar();
	bool vazio();
	list<Entidade*> getLista();
	void setLista(list<Entidade*> lista);
};

