#include "Personagem.h"

Personagem::Personagem()
{
	direcao = BAIXO;
	velocidade = 5;
}

Personagem::Personagem(RenderWindow* _window, const float cx, const float cy, const int _codigo):
	Entidade(_window, cx, cy, _codigo)
{
	direcao = BAIXO;
	velocidade = 7;
}
Personagem::~Personagem()
{

}