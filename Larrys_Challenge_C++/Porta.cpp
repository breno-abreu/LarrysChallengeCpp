#include "Porta.h"
Porta::Porta()
{

}
Porta::Porta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo)
{

}
Porta::~Porta()
{

}
void Porta::existir()
{
	if(ativado)
		coordenadasTile.width = 0;
	else
		coordenadasTile.width = dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}