#include "Interruptor.h"

Interruptor::Interruptor()
{

}
Interruptor::Interruptor(RenderWindow* _window, const float cx, const float cy, const int _codigo):
	Interativo(_window, cx, cy, _codigo)
{
	textura->loadFromFile("Tiny Dungeon Pack/Misc/Switches/Switch_blue_orange.png");
	quantidadeTile.x = 2;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(dimensoes);
	entidade.setTexture(textura);
	coordenadasTile.height = 0;
	coordenadasTile.width = 0;
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
