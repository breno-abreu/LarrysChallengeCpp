#include "Coluna.h"
Coluna::Coluna()
{

}
Coluna::Coluna(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Barreira(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{

}
Coluna::~Coluna()
{

}
void Coluna::existir()
{
	window->draw(entidade);
}