#include "Interruptor.h"

Interruptor::Interruptor()
{

}
Interruptor::Interruptor(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _conexao):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	/*quantidadeTile.x = 2;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	entidade.setSize(dimensoesAux);*/
	conexao = _conexao;
	coordenadasTile.height = 0;
	coordenadasTile.width = 0;

	hitBox.width = 11;
	hitBox.height = -24;
	hitBox.left = 9;
	hitBox.top = 0;
}
Interruptor::~Interruptor()
{

}
void Interruptor::existir()
{
	if (!ativado)
		coordenadasTile.width = 0;

	else
		coordenadasTile.width = dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}
