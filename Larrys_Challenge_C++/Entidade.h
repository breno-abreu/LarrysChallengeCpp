#pragma once
#include "bibliotecas.h"

class Entidade
{
protected:
	bool existe;
	float proporcao;
	FloatRect hitBox;
	int classe;
	int codigo;
	int conexao;
	int contAnimacao;
	int contFrames;
	int profundidade;
	IntRect coordenadasTile;
	int velAnimacao;
	RectangleShape entidade;
	RenderWindow* window;
	Texture* textura;
	Vector2f coordenadas;
	Vector2f dimensoes;
	Vector2f dimensoesAux;
	Vector2i quantidadeTile;

public:
	Entidade();
	Entidade(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Entidade();
	bool getExiste() const;
	FloatRect getHitBox() const;
	int getClasse()const;
	int getCodigo()const;
	int getConexao()const;
	int getProfundidade() const;
	Vector2f getCoordenadas() const;
	Vector2f getDimensoes() const;
	virtual void existir() = 0;
	void setExiste(const bool _existe);
	void setxEntidade(const float x);
	void setyEntidade(const float y);
};

