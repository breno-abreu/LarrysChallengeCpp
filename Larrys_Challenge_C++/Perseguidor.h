#pragma once
#include "bibliotecas.h"
#include "Inimigo.h"

class Perseguidor : public Inimigo
{
	Vector2f coordenadasJogador;

public:
	Perseguidor();
	Perseguidor(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const float _velocidade);
	~Perseguidor();
	void existir();
	void setCoodenadasJogador(const float jx, const float jy);


};

