#include "Item.h"

Item::Item()
{
	tipo = 0;
}
Item::Item(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _tipo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo)
{
	tipo = _tipo;
}
Item::~Item()
{

}

void Item::existir()
{
	//entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
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
