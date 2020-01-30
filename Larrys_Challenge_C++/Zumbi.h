#pragma once
#include "bibliotecas.h"
#include "Inimigo.h"

class Zumbi : public Inimigo
{
	Vector2f coordenadasJogador;

public:
	Zumbi();
	Zumbi(RenderWindow* _window, const float cx, const float cy, const int _codigo);
	~Zumbi();
	void existir();
	void setCoodenadasJogador(const float jx, const float jy);


};

