#include "Escada.h"
Escada::Escada()
{
	tipo = 0;
}
Escada::Escada(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	tipo = _tipo;
	coordenadasTile.height = 0;

	/*quantidadeTile.x = 2;
	quantidadeTile.y = 1;
	dimensoes.x = textura->getSize().x / quantidadeTile.x;
	dimensoes.y = textura->getSize().y / quantidadeTile.y;
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.y * proporcao;
	entidade.setSize(dimensoesAux);*/

	if (tipo == CIMA)
		coordenadasTile.width = 0;
	else if(tipo == BAIXO)
		coordenadasTile.width = dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
}
Escada::~Escada()
{
	
}
void Escada::existir()
{
	window->draw(entidade);
}
int Escada::getTipo()const
{
	return tipo;
}