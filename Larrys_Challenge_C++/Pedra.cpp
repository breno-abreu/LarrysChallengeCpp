#include "Pedra.h"

Pedra::Pedra()
{

}
Pedra::Pedra(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Barreira(_window, _textura, cx, cy, _profundidade, _codigo)
{

}
Pedra::~Pedra()
{

}
void Pedra::existir()
{
	window->draw(entidade);
}
