#pragma once
#include "bibliotecas.h"
#include "SuperficieInterativa.h"

class ParedeLevadica : public SuperficieInterativa
{
private:
	bool ativado;
	bool fimAnimacao;
	bool emCima;

public:
	ParedeLevadica();
	ParedeLevadica(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo);
	~ParedeLevadica();
	void existir();
	void setAtivado(const bool _ativado);
	bool getAtivado()const;
};

