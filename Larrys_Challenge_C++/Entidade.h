#pragma once
#include "bibliotecas.h"

class Entidade
{
protected:
	int codigo;
	float cx;
	float cy;
	int profundidade;
	int comprimento;
	int altura;
	bool existe;
	float proporcao;
	RenderWindow* window;
	RectangleShape* entidade;
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

