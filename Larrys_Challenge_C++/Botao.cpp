#include "Botao.h"

Botao::Botao()
{
	ativado = false;
}
Botao::Botao(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	SuperficieInterativa(_window, _textura, cx, cy, _profundidade, _codigo)
{
	textura->loadFromFile("Tiny Dungeon Pack/Misc/Switches/Switch_press.png");
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
	ativado = false;
	existe = false;
}
Botao::~Botao()
{

}
void Botao::existir()
{
	if (!ativado)
		coordenadasTile.width = 0;

	else
		coordenadasTile.width = dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}

