#pragma once
#include "bibliotecas.h"

class Entidade
{
protected:
	int codigo;
	Vector2f coordenadas;
	int profundidade;
	IntRect dimensoes;
	bool existe;
	float proporcao;
	int contAnimacao;
	int velAnimacao;
	int xTile;
	int yTile;
	int contFrames;
	
	IntRect coordenadasTile;
	Vector2i quantidadeTile;
	RenderWindow* window;
	RectangleShape entidade;
	Texture* textura;


public:
	Entidade();
	~Entidade();
	virtual void existir() = 0;
	float getcx() const;
	float getcy() const;
	int getProfundidade() const;
	int getComprimento() const;
	int getAltura() const;
	bool getExistir() const;
};

