#include "Caixa.h"

Caixa::Caixa()
{
	peso = 0;
}
Caixa::Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	tipo = _tipo;

	if (tipo == LEVE)
		peso = 3;
	else
		peso = 5;

	bloqueado = false;

	hitBox.height = int(dimensoesAux.y);
	hitBox.width = int(dimensoesAux.x);
	hitBox.left = int(coordenadas.x);
	hitBox.top = int(coordenadas.y);
}
Caixa::~Caixa()
{

}
void Caixa::existir()
{
	hitBox.width = dimensoesAux.x;
	hitBox.height = dimensoesAux.y;
	hitBox.left = coordenadas.x;
	hitBox.top = coordenadas.y;

	

	entidade.setPosition(coordenadas.x, coordenadas.y);
	window->draw(entidade);
}
void Caixa::setPeso(const float _peso)
{
	peso = _peso;
}
float Caixa::getPeso()const
{
	return peso;
}
int Caixa::getTipo()const
{
	return tipo;
}
