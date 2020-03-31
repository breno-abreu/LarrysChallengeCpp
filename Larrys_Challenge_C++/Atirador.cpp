#include "Atirador.h"
Atirador::Atirador()
{
	direcao = 0;
	contAtivar = 0;
	velAtivar = 0;
	atirar = false;
}

Atirador::Atirador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao, const int _conexao):
	Barreira(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	direcao = _direcao;
	contAtivar = 0;
	velAtivar = 60;
	conexao = _conexao;
	atirar = false;
	coordenadasTile.height = 0;
	classe = 1;
	ativado = true;

	if (direcao == BAIXO)
		coordenadasTile.width = 0;
	else if (direcao == ESQUERDA)
		coordenadasTile.width = dimensoes.x;
	else if (direcao == DIREITA)
		coordenadasTile.width = 2 * dimensoes.x;
	else if (direcao == CIMA)
		coordenadasTile.width = 3 * dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));

}

Atirador::~Atirador()
{

}

void Atirador::existir()
{
	if (ativado) {
		if (atirar)
			atirar = false;

		if (contAtivar >= velAtivar) {
			contAtivar = 0;
			atirar = true;
		}
		contAtivar++;
	}
	window->draw(entidade);
}

int Atirador::getDirecao()const
{
	return direcao;
}

bool Atirador::getAtivado()const
{
	return ativado;
}

void Atirador::setAtivado(const bool _ativado)
{
	ativado = _ativado;
}

bool Atirador::getAtirar()const
{
	return atirar;
}

void Atirador::setAtirar(const bool _atirar)
{
	atirar = _atirar;
}