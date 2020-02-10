#include "Abismo.h"
Abismo::Abismo()
{

}
Abismo::Abismo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int xTile, const int yTile)
{
	quantidadeTile.x = 6;
	quantidadeTile.y = 3;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	coordenadasTile.width = xTile;
	coordenadasTile.height = yTile;
	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
}
Abismo::~Abismo()
{

}
void Abismo::existir()
{
	window->draw(entidade);
}