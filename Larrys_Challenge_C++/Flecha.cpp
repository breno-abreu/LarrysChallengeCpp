#include "Flecha.h"

Flecha::Flecha()
{
	direcao = 0;
	velocidade = 0;
}
Flecha::Flecha(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _direcao):
	Letal(_window, _textura, cx, cy, _profundidade, _codigo)
{
	direcao = _direcao;
	velocidade = 6.0;
}
Flecha::~Flecha()
{

}
void Flecha::existir()
{
	if (direcao == DIREITA)
		coordenadas.x += velocidade;
	else if (direcao == ESQUERDA)
		coordenadas.x -= velocidade;
	else if (direcao == CIMA)
		coordenadas.y -= velocidade;
	else if (direcao == BAIXO)
		coordenadas.y += velocidade;
	
	entidade.setPosition(coordenadas);
	window->draw(entidade);
}