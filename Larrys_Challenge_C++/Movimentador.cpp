#include "Movimentador.h"

Movimentador::Movimentador()
{
	direcao = 0;
}
Movimentador::Movimentador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao) :
	SuperficieInterativa(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	direcao = _direcao;
	/*quantidadeTile.x = 4;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	entidade.setSize(dimensoesAux);*/

	if (direcao == ESQUERDA)
		coordenadasTile.width = 0;
	else if (direcao == BAIXO)
		coordenadasTile.width = dimensoes.x;
	else if (direcao == CIMA)
		coordenadasTile.width = 2 * dimensoes.x;
	else if (direcao == DIREITA)
		coordenadasTile.width = 3 * dimensoes.x;
	
		
	coordenadasTile.height = 0;
	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
}
Movimentador::~Movimentador()
{

}
void Movimentador::existir()
{
	entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}

int Movimentador::getDirecao()const
{
	return direcao;
}
