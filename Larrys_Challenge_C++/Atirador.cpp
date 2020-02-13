#include "Atirador.h"
Atirador::Atirador()
{
	direcao = 0;
	contAtivar = 0;
	velAtivar = 0;
	ativo = false;
}
Atirador::Atirador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _direcao, const int _xTile, const int _yTile):
	Barreira(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	direcao = _direcao;
	contAtivar = 0;
	velAtivar = 10;
	ativo = false;
	coordenadasTile.height = 0;
	/*quantidadeTile.x = 4;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.y * proporcao;
	entidade.setSize(dimensoesAux);*/

	if (direcao == BAIXO)
		coordenadasTile.width = 0;
	else if (direcao == ESQUERDA)
		coordenadasTile.width = dimensoes.x;
	else if (direcao == DIREITA)
		coordenadasTile.width = 2 * dimensoes.x;
	else if (direcao == CIMA)
		coordenadasTile.width = 3 * dimensoes.x;
}
Atirador::~Atirador()
{

}
void Atirador::existir()
{
	if (ativo)
		ativo = false;

	if (contAtivar >= velAtivar) {
		contAtivar = 0;
		ativo = true;
	}
	contAtivar++;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}

bool Atirador::getAtivo()const
{
	return ativo;
}
int Atirador::getDirecao()const
{
	return direcao;
}