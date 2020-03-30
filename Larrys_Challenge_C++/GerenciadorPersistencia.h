#pragma once
#include "bibliotecas.h"
#include "Fase.h"


class GerenciadorPersistencia
{
public:
	GerenciadorPersistencia();
	~GerenciadorPersistencia();
	bool pesquisar_lista_arquivos(const string nomeArquivo);
	void listar_arquivos();
	Fase* carregar(const int _fase, RenderWindow* _window);
	int getQuantidadeFases();
};

