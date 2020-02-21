#include "Abismo.h"
Abismo::Abismo()
{

}
Abismo::Abismo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _xPos, const int _yPos):
	Letal(_window, _textura, cx, cy, _profundidade, codigo, _xTile, _yTile)
{
	/*quantidadeTile.x = 6;
	quantidadeTile.y = 3;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;*/
	coordenadasTile.width = _xPos * dimensoes.x;
	coordenadasTile.height = _yPos * dimensoes.y;
	//entidade.setSize(dimensoesAux);
	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));

	hitBox.width = -16;
	hitBox.height = -36;
	hitBox.left = 16;
	hitBox.top = 8;
}
Abismo::~Abismo()
{

}
void Abismo::existir()
{
	window->draw(entidade);
}