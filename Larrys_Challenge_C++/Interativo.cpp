#include "Interativo.h"

Interativo::Interativo()
{
	ativado = false;
}

Interativo::Interativo(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	ativado = false;
}

Interativo::~Interativo()
{

}

bool Interativo::getAtivado()const
{
	return ativado;
}

void Interativo::setAtivado(const bool _ativado)
{
	ativado = _ativado;
}
