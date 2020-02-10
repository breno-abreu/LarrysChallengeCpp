#include "Superficie.h"

Superficie::Superficie()
{

}

Superficie::Superficie(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo)
{

}

Superficie::~Superficie()
{

}

void Superficie::existir()
{
	//entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}