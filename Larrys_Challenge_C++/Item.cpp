#include "Item.h"

Item::Item()
{
	tipo = 0;
}

Item::Item(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	tipo = _tipo;
	hitBox.width = 20;
	hitBox.height = 12;
	hitBox.left = 5;
	hitBox.top = 20;
}

Item::~Item()
{

}

void Item::existir()
{
	window->draw(entidade);
}

void Item::setTipo(const int _tipo)
{
	tipo = _tipo;
}

int Item::getTipo()const
{
	return tipo;
}
