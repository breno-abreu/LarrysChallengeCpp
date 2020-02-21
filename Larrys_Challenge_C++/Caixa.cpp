#include "Caixa.h"

Caixa::Caixa()
{
	tipo = 0;
	bloqueado = false;
	peso = 0;
}
Caixa::Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _tipo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	tipo = _tipo;

	if (tipo == LEVE)
		peso = 2;
	else
		peso = 4;

	bloqueado = false;

	hitBox.width = 5;
	hitBox.height = 0;
	hitBox.left = 5;
	hitBox.top = 0;
}
Caixa::~Caixa()
{

}
void Caixa::existir()
{
	entidade.setPosition(coordenadas);
	/*RectangleShape aux;
	aux.setFillColor(Color::Transparent);
	aux.setPosition(Vector2f(hitBox.left, hitBox.top));
	aux.setSize(Vector2f(hitBox.width, hitBox.height));
	aux.setOutlineColor(Color::Red);
	aux.setOutlineThickness(2);*/

	//window->draw(aux);
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
