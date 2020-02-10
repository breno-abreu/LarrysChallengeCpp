#include "Atirador.h"
Atirador::Atirador()
{
	direcao = 0;
	contAtivar = 0;
	velAtivar = 0;
	ativo = false;
}
Atirador::Atirador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _direcao):
	Barreira(_window, _textura, cx, cy, _profundidade, _codigo)
{
	direcao = _direcao;
	contAtivar = 0;
	velAtivar = 10;
	ativo = false;
}
Atirador::~Atirador()
{

}
void Atirador::existir()
{
	if (ativo)
		ativo = false;

	if (contAtivar >= velAtivar) {
		contAtivar = 0;
		ativo = true;
	}
	contAtivar++;
	window->draw(entidade);
}

bool Atirador::getAtivo()const
{
	return ativo;
}
int Atirador::getDirecao()const
{
	return direcao;
}