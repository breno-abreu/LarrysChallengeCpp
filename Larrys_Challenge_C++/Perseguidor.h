#pragma once
#include "bibliotecas.h"
#include "Inimigo.h"

class Perseguidor : public Inimigo
{
private:
	float distanciaJogadorPadrao;
	float distanciaOrigemPadrao;
	int direcao;
	Vector2f coordenadasAlvo;
	Vector2f coordenadasJogador;
	Vector2f coordenadasOrigem;

public:
	Perseguidor();
	Perseguidor(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const float _velocidade);
	~Perseguidor();
	float getDistanciaJogador()const;
	float getDistanciaJogadorPadrao()const;
	float getDistanciaOrigem()const;
	float getDistanciaOrigemPadrao()const;
	float getxOrigem()const;
	float getyOrigem()const;
	int getDirecao()const;
	void existir();
	void perseguir(const bool _perseguir);
	void setCoodenadasAlvo(const float jx, const float jy);
	void setCoodenadasJogador(const float jx, const float jy);
};

