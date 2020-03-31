#include "Coluna.h"
Coluna::Coluna()
{

}

Coluna::Coluna(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo):
	Barreira(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	if (_tipo == HORIZONTAL)
		hitBox.height = -dimensoesAux.y / 2;
	else if (_tipo == VERTICALDIREITA)
		hitBox.width = -dimensoesAux.x / 2;
	else if (_tipo == VERTICALESQUERDA) 
		hitBox.left = dimensoesAux.x / 2;
}

Coluna::~Coluna()
{
	
}

void Coluna::existir()
{
	window->draw(entidade);
}