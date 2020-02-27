#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Caixa : public Entidade
{
private:
	float peso;
	int tipo;
	bool bloqueadoDireita;
	bool bloqueadoEsquerda;
	bool bloqueadoCima;
	bool bloqueadoBaixo;

public:
	Caixa();
	Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo);
	~Caixa();
	void existir();
	void setPeso(const float _peso);
	float getPeso()const;
	int getTipo()const;
	bool getBloqueadoDireita()const;
	void setBloqueadoDireita(const bool _bloqueado);
	bool getBloqueadoEsquerda()const;
	void setBloqueadoEsquerda(const bool _bloqueado);
	bool getBloqueadoCima()const;
	void setBloqueadoCima(const bool _bloqueado);
	bool getBloqueadoBaixo()const;
	void setBloqueadoBaixo(const bool _bloqueado);
};

