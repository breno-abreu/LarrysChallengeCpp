#include "Botao.h"

Botao::Botao()
{
	ativado = false;
}
Botao::Botao(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	SuperficieInterativa(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	/*quantidadeTile.x = 2;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	entidade.setSize(dimensoesAux);*/
	coordenadasTile.height = 0;
	coordenadasTile.width = 0;
	ativado = false;
	existe = false;

	hitBox.width = int(dimensoesAux.x - 24);
	hitBox.height = int(dimensoesAux.y - 36);
	hitBox.left = int(coordenadas.x - (dimensoesAux.x / 2) + 10);
	hitBox.top = int(coordenadas.y - (dimensoesAux.y / 2));
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
	//entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}

