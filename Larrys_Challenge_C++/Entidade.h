#pragma once
#include "bibliotecas.h"

class Entidade
{
protected:
	int codigo;
	Vector2f coordenadas;
	int profundidade;
	Vector2f dimensoes;
	bool existe;
	float proporcao;
	int contAnimacao;
	int velAnimacao;
	int contFrames;
	
	IntRect coordenadasTile;
	Vector2i quantidadeTile;
	RenderWindow* window;
	RectangleShape entidade;
	Texture* textura;


public:
	Entidade();
	Entidade(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Entidade();
	virtual void existir() = 0;
	int getProfundidade() const;
	Vector2f getDimensoes() const;
	bool getExistir() const;
	Vector2f getCoordenadas() const;
};

