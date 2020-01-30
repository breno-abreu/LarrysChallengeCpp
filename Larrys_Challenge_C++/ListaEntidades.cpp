#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
	codigo = 0;
}

ListaEntidades::ListaEntidades(RenderWindow* _window)
{
	codigo = 0;
	window = _window;
}

ListaEntidades::~ListaEntidades()
{
	limpar();
}

void ListaEntidades::adicionar_entidade(int cx, int cy)
{
	codigo++;
	Entidade* entidade;
	Jogador* jogador = new Jogador(window, cx, cy, codigo);
	entidade = static_cast<Jogador*>(jogador);
	listaEntidades.push_back(entidade);
	ordenar();
}
void ListaEntidades::excluir_entidade(int cx, int cy)
{
	list<Entidade*>::reverse_iterator itr;
	for (itr = listaEntidades.rbegin(); itr != listaEntidades.rend(); itr++) {
		if (cx > (*itr)->getCoordenadas().x && cx < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x
			&& cy >(*itr)->getCoordenadas().y && cy < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y) {
			listaEntidades.erase(next(itr).base());
			break;
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
