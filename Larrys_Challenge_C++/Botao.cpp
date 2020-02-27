#include "Botao.h"

Botao::Botao()
{
	ativado = false;
}
Botao::Botao(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _conexao):
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
	conexao = _conexao;
	hitBox.width = -10;
	hitBox.height = -10;
	hitBox.left = 10;
	hitBox.top = 10;

	emCima = false;
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
void Botao::setEmCima(const bool _emCima)
{
	emCima = _emCima;
}
bool Botao::getEmCima()const
{
	return emCima;
}


