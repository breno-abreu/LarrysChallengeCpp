#include "Personagem.h"

Personagem::Personagem()
{
	direcao = BAIXO;
	velocidade = 5;
}

Personagem::Personagem(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo)
{
	direcao = BAIXO;
	velocidade = 7;
}
Personagem::~Personagem()
{

}

float Personagem::getVelocidade()const
{
	return velocidade;
}