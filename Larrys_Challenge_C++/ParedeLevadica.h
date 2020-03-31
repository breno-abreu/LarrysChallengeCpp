#pragma once
#include "bibliotecas.h"
#include "SuperficieInterativa.h"

class ParedeLevadica : public SuperficieInterativa
{
private:
	bool ativado;
	bool barreira;
	bool emCima;
	bool fimAnimacao;

public:
	ParedeLevadica();
	ParedeLevadica(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~ParedeLevadica();
	bool getAtivado()const;
	bool getBarreira()const;
	bool getEmCima()const;
	void existir();
	void setAtivado(const bool _ativado);
	void setEmCima(const bool _emCima);
};

