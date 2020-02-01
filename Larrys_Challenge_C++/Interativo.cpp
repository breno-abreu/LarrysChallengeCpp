#include "Interativo.h"

Interativo::Interativo()
{
	ativado = false;
}
Interativo::Interativo(RenderWindow* _window, const float cx, const float cy, const int _codigo):
	Entidade(_window, cx, cy, _codigo)
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
