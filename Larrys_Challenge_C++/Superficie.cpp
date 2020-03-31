#include "Superficie.h"

Superficie::Superficie()
{

}

Superficie::Superficie(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{

}

Superficie::~Superficie()
{

}

void Superficie::existir()
{
	window->draw(entidade);
}