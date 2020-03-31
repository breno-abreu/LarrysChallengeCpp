#include "Porta.h"
Porta::Porta()
{

}

Porta::Porta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _conexao):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	conexao = _conexao;
	coordenadasTile.height = 0;
	classe = 2;
	ativado = false;

	hitBox.width = 0;
	hitBox.height = -44;
	hitBox.left = 0;
	hitBox.top = 0;
}

Porta::~Porta()
{

}

void Porta::existir()
{
	if(!ativado)
		coordenadasTile.width = 0;
	else
		coordenadasTile.width = dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}