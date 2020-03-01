#pragma once
#include "bibliotecas.h"
#include "Inimigo.h"

class Perseguidor : public Inimigo
{
private:
	Vector2f coordenadasJogador;
	Vector2f coordenadasAlvo;
	Vector2f coordenadasOrigem;
	int direcao;
	float distanciaOrigemPadrao;
	float distanciaJogadorPadrao;


public:
	Perseguidor();
	Perseguidor(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const float _velocidade);
	~Perseguidor();
	void existir();
	void setCoodenadasJogador(const float jx, const float jy);
	void setCoodenadasAlvo(const float jx, const float jy);
	int getDirecao()const;
	float getDistanciaOrigem()const;
	float getxOrigem()const;
	float getyOrigem()const;
	float getDistanciaOrigemPadrao()const;
	float getDistanciaJogador()const;
	float getDistanciaJogadorPadrao()const;
	void perseguir(const bool _perseguir);


};

