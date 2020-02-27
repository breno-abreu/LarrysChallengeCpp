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
	Vector2f dimensoesAux;
	FloatRect hitBox;
	int conexao;
	int classe;
	IntRect coordenadasTile;
	Vector2i quantidadeTile;
	RenderWindow* window;
	RectangleShape entidade;
	Texture* textura;

	


public:
	Entidade();
	Entidade(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Entidade();
	virtual void existir() = 0;
	int getProfundidade() const;
	Vector2f getDimensoes() const;
	bool getExiste() const;
	Vector2f getCoordenadas() const;
	void setExiste(const bool _existe);
	void setxEntidade(const float x);
	void setyEntidade(const float y);
	int getCodigo()const;
	int getClasse()const;
	FloatRect getHitBox() const;
	int getConexao()const;
};

