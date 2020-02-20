#include "Porta.h"
Porta::Porta()
{

}
Porta::Porta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	/*quantidadeTile.x = 2;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.y * proporcao;
	entidade.setSize(dimensoesAux);*/
	coordenadasTile.height = 0;
	classe = 2;
	ativado = false;

	hitBox.width = int(dimensoesAux.x);
	hitBox.height = int(dimensoesAux.y - 36);
	hitBox.left = int(coordenadas.x - (dimensoesAux.x / 2));
	hitBox.top = int(coordenadas.y - (dimensoesAux.y / 2));
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