#pragma once
#include "bibliotecas.h"
#include "SuperficieInterativa.h"

class ParedeLevadica : public SuperficieInterativa
{
private:
	bool ativado;
	bool fimAnimacao;
	bool emCima;
	bool barreira;

public:
	ParedeLevadica();
	ParedeLevadica(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~ParedeLevadica();
	void existir();
	void setAtivado(const bool _ativado);
	bool getAtivado()const;
	void setEmCima(const bool _emCima);
	bool getEmCima()const;
	bool getBarreira()const;
};

