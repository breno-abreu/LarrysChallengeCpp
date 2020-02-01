#include "Movimentador.h"

Movimentador::Movimentador()
{

}
Movimentador::Movimentador(RenderWindow* _window, const float cx, const float cy, const int _codigo, const int _direcao) :
	Obstaculo(_window, cx, cy, _codigo)
{
	direcao = _direcao;

	if(direcao == BAIXO)
		textura->loadFromFile("Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_down.png");
	else if(direcao == CIMA)
		textura->loadFromFile("Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_up.png");
	else if (direcao == DIREITA)
		textura->loadFromFile("Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_right.png");
	else
		textura->loadFromFile("Tiny Dungeon Pack/Traps/Pushing_floor/Floor_push_left.png");


	quantidadeTile.x = 1;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(dimensoes);
	entidade.setTexture(textura);
}
Movimentador::~Movimentador()
{

}
void Movimentador::existir()
{
	entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}

int Movimentador::getDirecao()const
{
	return direcao;
}
