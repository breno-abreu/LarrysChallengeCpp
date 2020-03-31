#pragma once
#include "bibliotecas.h"
#include "Entidade.h"

class Caixa : public Entidade
{
private:
	bool bloqueadoBaixo;
	bool bloqueadoCima;
	bool bloqueadoDireita;
	bool bloqueadoEsquerda;
	float peso;
	int contato;
	int tipo;

public:
	Caixa();
	Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo);
	~Caixa();
	bool getBloqueadoBaixo()const;
	bool getBloqueadoCima()const;
	bool getBloqueadoDireita()const;
	bool getBloqueadoEsquerda()const;
	float getPeso()const;
	int getContato()const;
	int getTipo()const;
	void existir();
	void setBloqueadoBaixo(const bool _bloqueado);
	void setBloqueadoCima(const bool _bloqueado);
	void setBloqueadoDireita(const bool _bloqueado);
	void setBloqueadoEsquerda(const bool _bloqueado);
	void setContato(const int _contato);
	void setPeso(const float _peso);
};

