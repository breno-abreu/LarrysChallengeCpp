#include "Caixa.h"

Caixa::Caixa()
{
	tipo = 0;
	bloqueadoDireita = false;
	bloqueadoEsquerda = false;
	bloqueadoCima = false;
	bloqueadoBaixo = false;
	peso = 0;
}

Caixa::Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	tipo = _tipo;

	if (tipo == LEVE) {
		peso = 2;
		hitBox.width = 0;
		hitBox.height = 0;
		hitBox.left = 5;
		hitBox.top = 0;
	}
		
	else {
		peso = 4;
		hitBox.width = 6;
		hitBox.height = 0;
		hitBox.left = 6;
		hitBox.top = 0;
	}
		
	bloqueadoDireita = false;
	bloqueadoEsquerda = false;
	bloqueadoCima = false;
	bloqueadoBaixo = false;
}

Caixa::~Caixa()
{

}
void Caixa::existir()
{
	entidade.setPosition(coordenadas);
	window->draw(entidade);
}

void Caixa::setPeso(const float _peso)
{
	peso = _peso;
}

float Caixa::getPeso()const
{
	return peso;
}

int Caixa::getTipo()const
{
	return tipo;
}

bool Caixa::getBloqueadoDireita()const
{
	return bloqueadoDireita;
}

void Caixa::setBloqueadoDireita(const bool _bloqueado)
{
	bloqueadoDireita = _bloqueado;
}

bool Caixa::getBloqueadoEsquerda()const
{
	return bloqueadoEsquerda;
}

void Caixa::setBloqueadoEsquerda(const bool _bloqueado)
{
	bloqueadoEsquerda = _bloqueado;
}

bool Caixa::getBloqueadoCima()const
{
	return bloqueadoCima;
}

void Caixa::setBloqueadoCima(const bool _bloqueado)
{
	bloqueadoCima = _bloqueado;
}

bool Caixa::getBloqueadoBaixo()const
{
	return bloqueadoBaixo;
}

void Caixa::setBloqueadoBaixo(const bool _bloqueado)
{
	bloqueadoBaixo = _bloqueado;
}

void Caixa::setContato(const int _contato)
{
	contato = _contato;
}

int Caixa::getContato()const
{
	return contato;
}
