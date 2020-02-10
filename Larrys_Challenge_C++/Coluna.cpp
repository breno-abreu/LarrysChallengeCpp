#include "Coluna.h"
Coluna::Coluna()
{

}
Coluna::Coluna(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Barreira(_window, _textura, cx, cy, _profundidade, _codigo)
{

}
Coluna::~Coluna()
{

}
void Coluna::existir()
{
	window->draw(entidade);
}