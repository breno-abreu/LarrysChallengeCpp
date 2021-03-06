#include "Bau.h"

Bau::Bau()
{

}

Bau::Bau(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	coordenadasTile.height = 0;
	coordenadasTile.width = 0;
	velAnimacao = 7;
	classe = 3;
	fim = false;
}

Bau::~Bau()
{

}

void Bau::existir()
{
	if (ativado && !fim) {
		if (contAnimacao >= velAnimacao) {
			coordenadasTile.width = contFrames * dimensoes.x;
			contFrames++;
			if (contFrames >= 6) {
				ativado = false;
				fim = true;
			}
			contAnimacao = 0;
		}
		contAnimacao++;
	}
	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}

bool Bau::getFim()
{
	return fim;
}
