#include "Espinhos.h"
Espinhos::Espinhos()
{

}
Espinhos::Espinhos(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Letal(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	/*quantidadeTile.x = 7;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.y * proporcao;
	entidade.setSize(dimensoesAux);*/
	desativado = true;
}
Espinhos::~Espinhos()
{

}
void Espinhos::existir()
{
	if (contAnimacao >= velAnimacao) {
		coordenadasTile.width = contFrames * dimensoes.x;
		contFrames++;
		if (contFrames >= 7)
			contFrames = 0;

		contAnimacao = 0;
	}
	contAnimacao++;

	if (contFrames == 0)
		desativado = true;
	else
		desativado = false;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}

bool Espinhos::getDesativado()const
{
	return desativado;
}