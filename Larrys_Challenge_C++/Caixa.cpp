#include "Caixa.h"

Caixa::Caixa()
{
	peso = 0;
}
Caixa::Caixa(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const float _peso):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo)
{
	peso = _peso;
}
Caixa::~Caixa()
{

}
void Caixa::existir()
{
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