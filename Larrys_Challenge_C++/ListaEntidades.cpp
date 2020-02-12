#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
	codigo = 0;
}

ListaEntidades::ListaEntidades(RenderWindow* _window, GerenciadorEntidades* _gerenciador)
{
	codigo = 0;
	window = _window;
	gerenciadorEntidades = _gerenciador;
}

ListaEntidades::~ListaEntidades()
{
	limpar();
}

void ListaEntidades::adicionar_entidade(const float cx, const float cy, const int tipo)
{
	codigo++;
	Entidade* entidade = gerenciadorEntidades->adicionar_entidade(cx, cy, tipo, codigo);
	listaEntidades.push_back(entidade);
	ordenar();
}
void ListaEntidades::excluir_entidade(const int _codigo)
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		if ((*itr)->getCodigo() == _codigo) {
			listaEntidades.erase(itr);
		}
	}
}
void ListaEntidades::percorrer()
{
	list<Entidade*>::iterator itr;
	for (itr = listaEntidades.begin(); itr != listaEntidades.end(); itr++) {
		(*itr)->existir();
	}
}
void ListaEntidades::limpar()
{
	listaEntidades.clear();
	codigo = 0;
}
void ListaEntidades::ordenar()
{
	listaEntidades.sort([](Entidade* a, Entidade* b) {return a->getProfundidade() < b->getProfundidade(); });
}

bool ListaEntidades::vazio()
{
	return listaEntidades.empty();
}

list<Entidade*> ListaEntidades::getLista()
{
	return listaEntidades;
}

void ListaEntidades::setLista(list<Entidade*> lista)
{
	listaEntidades = lista;
}
